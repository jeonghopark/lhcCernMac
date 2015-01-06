#ifndef SPECTRUMDRAWER
#define SPECTRUMDRAWER

#define BIT2 512

#include "ofMain.h"

class SpectrumDrawer{

public:

    SpectrumDrawer(int _minHz, int _maxHz);
	
    void spectrumDraw();
	
	void reloadTexture(int mode);
    void loadImageSpectrum(ofImage _img);
	
	void clearPixels();
	
	float getPixel(int x, int y);
	float getAmp(float x, float y);
	float getFreq(float y);
	
	int width;
	int height;
	int minHz;
	int maxHz;
	int offsetX;
	int offsetY;
	
	float pixels[10000][BIT2-1];
	float speed;
	float player;
	float ratio;
	
	GLuint textureSP;
	GLubyte image[10000][512][3];
	
    ofImage spectrumCaptureLoader;
	
};
#endif