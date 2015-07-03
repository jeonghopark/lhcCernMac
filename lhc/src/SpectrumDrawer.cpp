#include "SpectrumDrawer.h"

int spectrumHeight = 512;
int spectrumWidth = 1280;

//--------------------------------------------------------------
SpectrumDrawer::SpectrumDrawer(int _minHz, int _maxHz){
    width = 0;
    height = 0;
    minHz = _minHz;
    maxHz = _maxHz;
    player = 0;
    speed = 1;
    ratio = 1;
    offsetX=0;
    offsetY=0;
}


//--------------------------------------------------------------
void SpectrumDrawer::spectrumDraw(){

    glEnable(GL_TEXTURE_2D);
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, textureSP);
    glBegin(GL_QUADS);
    
    float ratio = (float)(spectrumWidth)/(float)width;
    float offXRatio = (player-offsetX)/(float) width;
    
    float offYRatio = (offsetY)/(float) width;
    glTexCoord2f(0.0 + offYRatio, 0.0 + offXRatio);		glVertex3i(10, 10, 0);
    glTexCoord2f(0.0 + offYRatio, ratio + offXRatio);		glVertex3i(spectrumWidth-10, 10, 0);
    glTexCoord2f(1.0 + offYRatio, ratio + offXRatio);		glVertex3i(spectrumWidth-10, spectrumHeight+10, 0);
    glTexCoord2f(1.0 + offYRatio, 0.0 + offXRatio);		glVertex3i(10, spectrumHeight+10, 0);
    
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

}


//--------------------------------------------------------------
float SpectrumDrawer::getPixel(int x, int y){
    int _x;
    if(x+player-offsetX<0){
        _x = (width + int(x+player-offsetX))% height;
    }else {
        _x=int(x+player-offsetX)%width;
    }
    
    int _y;
    if(y-offsetY<0){
        _y =(height + int(y-offsetY))% height;
    }else {
        _y=int(y-offsetY) % height;
    }
    float c = pixels[_x][_y]/255.0;
    return c;
}


//--------------------------------------------------------------
void SpectrumDrawer::loadImageSpectrum(ofImage _img){

    spectrumCaptureLoader.clear();
    clearPixels();
    spectrumCaptureLoader = _img;
    ratio = (float) spectrumHeight/spectrumCaptureLoader.getHeight();
    spectrumCaptureLoader.resize(spectrumCaptureLoader.getWidth()*ratio, spectrumCaptureLoader.getHeight()*ratio);
    
    width = spectrumCaptureLoader.getWidth();
    height = spectrumCaptureLoader.getHeight();
    
    unsigned char * rawPixels = spectrumCaptureLoader.getPixels().getData();
    int r;
    int g;
    int b;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            r = rawPixels[((height-i) * width + j ) * 3];
            g = rawPixels[((height-i) * width + j ) * 3 + 1];
            b = rawPixels[((height-i) * width + j ) * 3 + 2];
            //pixels[i][j]=value/3;
            //spectrum->setPixel(i, j, r,g,b);
            
            pixels[j][i]=(r+g+b)/3.0;
            image[j][i][0]=(GLubyte) r;
            image[j][i][1]=(GLubyte) g;
            image[j][i][2]=(GLubyte) b;
            
        }
    }
    
    width = spectrumCaptureLoader.getWidth();
    height = spectrumCaptureLoader.getHeight();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(1, &textureSP);
    glBindTexture(GL_TEXTURE_2D, textureSP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, height, width, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glDisable(GL_TEXTURE_2D);
    
}


//--------------------------------------------------------------
float SpectrumDrawer::getAmp(float x, float y){
    float amp=0;
    if(height>0){
        amp = getPixel(x, y);
    }
    return amp;
}


//--------------------------------------------------------------
float SpectrumDrawer::getFreq(float y){
    float freq=0;
    
    if(height>0){
        y-=9;
        float yToFreq = (y/spectrumHeight)*maxHz;
        
        //TODO logarithmic scale
        freq = 1-(log(yToFreq)-log(minHz)) / (log(maxHz)-log(minHz));
        freq *= maxHz;
        //freq = 1-(yToFreq-minHz) / (maxHz-minHz);
        //freq= (spectrumHeight-y+minHz)/spectrumHeight*(maxHz-minHz);
    }
    return freq;
}


//--------------------------------------------------------------
void SpectrumDrawer::clearPixels(){
    for (int i=0; i<width; i++) {
        for (int n=0; n<height; n++) {
            pixels[i][n]=0;
        }
    }
}
