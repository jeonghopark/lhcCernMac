#include "LHCIgFileLoad.h"


bool LHCIgFileLoad::openFile(string zipFile, string destination) {
    zipFile = ofToDataPath(zipFile);
    destination = ofToDataPath(destination);
    unzFile uf = unzOpen(zipFile.c_str());
    
    bufferEvent.clear();
    

    if (uf==NULL)
    {
        printf("Cannot open %s\n",zipFile.c_str());
        return false;
    }
    // do_list(uf);
    
    mkdir(destination.c_str(), 0777);
    do_extract(uf, destination, 1);
    unzCloseCurrentFile(uf);
    
    return true;
}


int LHCIgFileLoad::do_extract_currentfile(unzFile uf, string destinationDir, int* popt_overwrite) {
    char filename_inzip[512];
    char* filename_withoutpath;
    char* filepath;
    char* p;
    int err=UNZ_OK;
    FILE *fout=NULL;
    void* buf;
    uInt size_buf;
    
    unz_file_info file_info;
    uLong ratio=0;
    err = unzGetCurrentFileInfo(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
    
    if (err!=UNZ_OK) {
        printf("error %d with zipfile in unzGetCurrentFileInfo\n",err);
        return err;
    }
    
    size_buf = WRITEBUFFERSIZE;
    buf = (void*)malloc(size_buf);
    if (buf==NULL) {
        printf("Error allocating memory\n");
        return UNZ_INTERNALERROR;
    }
    
    p = filename_withoutpath = filename_inzip;
    while ((*p) != '\0') {
        if (((*p)=='/') || ((*p)=='\\'))
            filename_withoutpath = p+1;
        p++;
    }
    
    if(strncmp(filename_inzip, "__MACOSX", 8)==0) {
        // ignore these guys
    } else if ((*filename_withoutpath)=='\0') {
        string path = ofToDataPath(destinationDir+"/"+string(filename_inzip), true);
        
        printf("creating directory: %s\n",path.c_str());
        if(mkdir(path.c_str(), 0777)!=0) {
            printf("Couldn't create dir %s\n", path.c_str());
        }
    } else {
        const char* write_filename;
        int skip=0;
        
        string path = ofToDataPath(destinationDir+"/"+string(filename_inzip), true);
        write_filename = filename_inzip;
        
        err = unzOpenCurrentFile(uf);
        if (err!=UNZ_OK) {
            printf("error %d with zipfile in unzOpenCurrentFile\n",err);
            return err;
        }
        
        if ((skip==0) && (err==UNZ_OK)) {
            
            string path = ofToDataPath(destinationDir+string(filename_withoutpath), true);
            
            fout=fopen(path.c_str(),"wb");
            
            //             some zipfile don't contain directory alone before file
            if ( (fout==NULL) && (filename_withoutpath!=(char*)filename_inzip) ) {
                char c=*(filename_withoutpath-1);
                *(filename_withoutpath-1)='\0';
                mkdir(path.c_str(), 0777);
                printf("mkdir %s\n", path.c_str());
                *(filename_withoutpath-1)=c;
                fout=fopen(path.c_str(),"wb");
            }
            
            if (fout==NULL){
                printf("error opening %s\n",path.c_str());
            }
            
        }
        
        if (fout!=NULL){
            //            printf(" extracting: %s\n",path.c_str());
            //
            do{
                err = unzReadCurrentFile(uf,buf,size_buf);
                if (err<0){
                    printf("error %d with zipfile in unzReadCurrentFile\n",err);
                    break;
                }
                if (err>0)
                    if (fwrite(buf,err,1,fout)!=1){
                        printf("error in writing extracted file\n");
                        err=UNZ_ERRNO;
                        break;
                    }
            }
            while (err>0);
            if (fout) {
                fclose(fout);
            }
            
            string path = ofToDataPath(destinationDir+string(filename_withoutpath), true);
            bufferEvent.push_back( ofBufferFromFile(path) );
            
            // remove temp Files !!!
            remove(path.c_str());

        }
        
        if (err==UNZ_OK){
            err = unzCloseCurrentFile (uf);
            if (err!=UNZ_OK){
                printf("error %d with zipfile in unzCloseCurrentFile\n",err);
            }
        }
        else
            unzCloseCurrentFile(uf); /* don't lose the error */
    }
    
    free(buf);
    return err;
    
}


int LHCIgFileLoad::do_extract(unzFile uf, string destinationDir,int opt_overwrite) {
    uLong i;
    unz_global_info gi;
    int err;
    FILE* fout=NULL;
    err = unzGetGlobalInfo (uf,&gi);
    if (err!=UNZ_OK)
        printf("error %d with zipfile in unzGetGlobalInfo \n",err);
    
    for (i=0;i<gi.number_entry;i++){
        if (do_extract_currentfile(uf,destinationDir,&opt_overwrite) != UNZ_OK)
            break;
        
        if ((i+1)<gi.number_entry){
            err = unzGoToNextFile(uf);
            if (err!=UNZ_OK){
                printf("error %d with zipfile in unzGoToNextFile\n",err);
                break;
            }
        }
    }
    
    
    return 0;
}


int LHCIgFileLoad::do_list(unzFile uf) {
    uLong i;
    unz_global_info gi;
    int err;
    
    err = unzGetGlobalInfo (uf,&gi);
    if (err!=UNZ_OK)
        printf("error %d with zipfile in unzGetGlobalInfo \n",err);
    printf(" Length  Method   Size  Ratio   Date    Time   CRC-32     Name\n");
    printf(" ------  ------   ----  -----   ----    ----   ------     ----\n");
    for (i=0;i<gi.number_entry;i++){
        char filename_inzip[256];
        unz_file_info file_info;
        uLong ratio=0;
        const char *string_method;
        char charCrypt=' ';
        err = unzGetCurrentFileInfo(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
        if (err!=UNZ_OK)
        {
            printf("error %d with zipfile in unzGetCurrentFileInfo\n",err);
            break;
        }
        if (file_info.uncompressed_size>0)
            ratio = (file_info.compressed_size*100)/file_info.uncompressed_size;
        
        /* display a '*' if the file is crypted */
        if ((file_info.flag & 1) != 0)
            charCrypt='*';
        
        if (file_info.compression_method==0)
            string_method="Stored";
        else
            if (file_info.compression_method==Z_DEFLATED){
                uInt iLevel=(uInt)((file_info.flag & 0x6)/2);
                if (iLevel==0)
                    string_method="Defl:N";
                else if (iLevel==1)
                    string_method="Defl:X";
                else if ((iLevel==2) || (iLevel==3))
                    string_method="Defl:F"; /* 2:fast , 3 : extra fast*/
            }
            else
                string_method="Unkn. ";
        
        printf("%7lu  %6s%c%7lu %3lu%%  %2.2lu-%2.2lu-%2.2lu  %2.2lu:%2.2lu  %8.8lx   %s\n",
               file_info.uncompressed_size,string_method,
               charCrypt,
               file_info.compressed_size,
               ratio,
               (uLong)file_info.tmu_date.tm_mon + 1,
               (uLong)file_info.tmu_date.tm_mday,
               (uLong)file_info.tmu_date.tm_year % 100,
               (uLong)file_info.tmu_date.tm_hour,(uLong)file_info.tmu_date.tm_min,
               (uLong)file_info.crc,filename_inzip);
        if ((i+1)<gi.number_entry){
            err = unzGoToNextFile(uf);
            if (err!=UNZ_OK){
                printf("error %d with zipfile in unzGoToNextFile\n",err);
                break;
            }
        }
    }
    
    return 0;
}


