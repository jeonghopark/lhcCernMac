//https://github.com/dfeles/refreq
//https://github.com/mazbox/ofxUnZip

//http://opendata.cern.ch/record/301
//http://ispy.web.cern.ch/ispy/1.5.0/index.htm


#pragma once

#include "ofMain.h"
#include "PathData.h"

#include "SpectrumDrawer.h"

#include "LHCIgFileLoad.h"

#define BUFFER_SIZE 8192
#define SAMPLE_RATE 44100
#define INITIAL_BUFFER_SIZE 1024
#define BIT 512
#define EVENTSCALE 70

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioRequested (float * input, int bufferSize, int nChannels);
    void audioReceived (float * input, int bufferSize, int nChannels);
    
//    ofSoundStream soundStream;
    
    float lineRight;
    float lineLeft;
    
    int	maxHertz;
    
    double sineBufferRight[514];
    double sineBufferLeft[514];
    
    float remainderRight;
    float remainderLeft;
    float waveRight;
    float waveLeft;
    
    float ampRight[BIT];
    float ampLeft[BIT];
    int hertzScaleLeft[BIT];
    int hertzScaleRight[BIT];
    float phasesRight[BIT];
    float phasesLeft[BIT];
    
    SpectrumDrawer* spectrum;
    
    int captureH, captureW;
    
    ofEasyCam cam;
    
    vector<ofVec3f> vMeshPos;
    vector<ofVec3f> vMeshDir;
    vector<ofVec3f> vMeshPos1;
    vector<ofVec3f> vMeshDir1;
    vector<ofVec3f> vMeshPos2;
    vector<ofVec3f> vMeshDir2;
    
    float pointScale;
    float pointScaleDir;
    
    ofTrueTypeFont information;
    bool uiInformation;
    
    ofTrueTypeFont interface;
    int interfaceMenuIndex;

    PathData pathMake;
    
    void loadEvent(ofBuffer _b);
    
    vector<string> informationStream;
    
    vector<ofVec3f> boxVectorE(ofBuffer _b, string _p, float _l, float _r);
    vector<ofVec3f> boxVectorH(ofBuffer _b, string _p, float _l, float _r);
    
    void boxDraw( vector<ofVec3f> _vV, ofColor _c );
    
    vector<ofVec3f> EB;
    vector<ofVec3f> EE;
    vector<ofVec3f> ES;
    vector<ofVec3f> HB;
    vector<ofVec3f> HE;
    vector<ofVec3f> HF;
    
    bool nextButton, prevButton;
    
    float maxHz;
    float minHz;
    float lineSize;
    float speed;
    float volume;
    
    float rotateZFactor;
    float rotateZValue;
    
    int eventCount;
    
    void linePathHiddenCapture();
    
    float sizeSphere;
    float sphereSpeed;
    
    ofVec3f leftStart, rightStart;
    float leftVolumeRatio, rightVolumeRatio;
    
    ofVec3f protonPos;
    ofSpherePrimitive protonA, protonB;
    float protonSpeed;
    
    float hitTime;
    
    ofTrueTypeFont coordY, coordX;
    
    int scoreWidth, scoreHeight;
    
    LHCIgFileLoad lhcIgFileLoad;
    void openIgFile(string URL="");
    vector<ofBuffer> bufferEventCopy;

    bool trigger;
    
    ofMesh playCircleMesh;
    
    int score2DlineTop;
    
    void igLoadReset();
    
    bool allPlay;
    
    void interfaceSetting();
    void interfaceInsideCheck();
    void interfaceDrawing();
    
    ofRectangle openIGFile;
    ofRectangle nextEvent;
    ofRectangle prevEvent;
    ofRectangle autoPlay;
    ofRectangle resetView;
    bool bOpenIGFile, bOverOpenIGFile;
    bool bNextEvent, bOverNextEvent;
    bool bPrevEvent, bOverPrevEvent;
    bool bAutoPlay, bOverAutoPlay;
    bool bResetView, bOverResetView;
    
    ofRectangle speedCtrl;
    ofRectangle volumeCtrl;
    bool bOverSpeedCtrl, bOverVolumeCtrl;
    
    int interfaceW, interfaceH;
    
    ofImage openIGImg, nextEventImg, prevEventImg, autoPlayImg, resetViewImg, volumeImg, speedImg;
    
    float changeSpeedMouse;
    float changeVolumeMouse;

    
    ofImage informationIconImg;
    ofImage informationTextImg;
    bool bInformationIcon;
    bool bOverInformationIcon;
    ofRectangle informationIcon;
    
    
    float lineLeftXPos, lineRightXPos;
    
};
