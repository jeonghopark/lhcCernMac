//
//  LHCIgFileLoad.h
//  lhc_data_music
//
//  Created by JeongHo Park on 21.12.14.
//
//

// from ofxUnZip


#pragma once

#ifndef __lhc_data_music__LHCIgFileLoad__
#define __lhc_data_music__LHCIgFileLoad__

#include <zlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#include <sys/stat.h>
#include <dirent.h>

#include "unzip.h"
#define WRITEBUFFERSIZE (8192)

#include "ofMain.h"

class LHCIgFileLoad {
    
    int do_extract_currentfile(unzFile uf, string destinationDir, int* popt_overwrite);
    int do_extract(unzFile uf, string destinationDir,int opt_overwrite);
    int do_list(unzFile uf);
    
public:

    bool openFile(string zipFile, string destination);
    vector<ofBuffer> bufferEvent;
    
};


#endif /* defined(__lhc_data_music__LHCIgFileLoad__) */







