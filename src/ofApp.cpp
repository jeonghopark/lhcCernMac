#include "ofApp.h"

float sines[514]={0,0.012268,0.024536,0.036804,0.049042,0.06131,0.073547,0.085785,0.097992,0.1102,0.12241,0.13455,0.1467,0.15884,0.17093,0.18301,0.19507,0.20709,0.21909,0.23105,0.24295,0.25485,0.26669,0.2785,0.29025,0.30197,0.31366,0.32529,0.33685,0.34839,0.35986,0.37128,0.38266,0.39395,0.40521,0.41641,0.42752,0.4386,0.44958,0.46051,0.47137,0.48215,0.49286,0.50351,0.51407,0.52457,0.53497,0.54529,0.55554,0.5657,0.57578,0.58575,0.59567,0.60547,0.6152,0.62482,0.63437,0.6438,0.65314,0.66238,0.67151,0.68057,0.68951,0.69833,0.70706,0.7157,0.72421,0.7326,0.74091,0.74908,0.75717,0.76514,0.77298,0.7807,0.7883,0.79581,0.80316,0.81042,0.81754,0.82455,0.83142,0.8382,0.84482,0.85132,0.8577,0.86392,0.87006,0.87604,0.88187,0.8876,0.89319,0.89862,0.90396,0.90912,0.91415,0.91907,0.92383,0.92847,0.93295,0.93729,0.9415,0.94556,0.94949,0.95325,0.95691,0.96039,0.96375,0.96692,0.97,0.9729,0.97565,0.97827,0.98074,0.98306,0.98523,0.98724,0.98914,0.99084,0.99243,0.99387,0.99515,0.99628,0.99725,0.99808,0.99875,0.99927,0.99966,0.99988,0.99997,0.99988,0.99966,0.99927,0.99875,0.99808,0.99725,0.99628,0.99515,0.99387,0.99243,0.99084,0.98914,0.98724,0.98523,0.98306,0.98074,0.97827,0.97565,0.9729,0.97,0.96692,0.96375,0.96039,0.95691,0.95325,0.94949,0.94556,0.9415,0.93729,0.93295,0.92847,0.92383,0.91907,0.91415,0.90912,0.90396,0.89862,0.89319,0.8876,0.88187,0.87604,0.87006,0.86392,0.8577,0.85132,0.84482,0.8382,0.83142,0.82455,0.81754,0.81042,0.80316,0.79581,0.7883,0.7807,0.77298,0.76514,0.75717,0.74908,0.74091,0.7326,0.72421,0.7157,0.70706,0.69833,0.68951,0.68057,0.67151,0.66238,0.65314,0.6438,0.63437,0.62482,0.6152,0.60547,0.59567,0.58575,0.57578,0.5657,0.55554,0.54529,0.53497,0.52457,0.51407,0.50351,0.49286,0.48215,0.47137,0.46051,0.44958,0.4386,0.42752,0.41641,0.40521,0.39395,0.38266,0.37128,0.35986,0.34839,0.33685,0.32529,0.31366,0.30197,0.29025,0.2785,0.26669,0.25485,0.24295,0.23105,0.21909,0.20709,0.19507,0.18301,0.17093,0.15884,0.1467,0.13455,0.12241,0.1102,0.097992,0.085785,0.073547,0.06131,0.049042,0.036804,0.024536,0.012268,0,-0.012268,-0.024536,-0.036804,-0.049042,-0.06131,-0.073547,-0.085785,-0.097992,-0.1102,-0.12241,-0.13455,-0.1467,-0.15884,-0.17093,-0.18301,-0.19507,-0.20709,-0.21909,-0.23105,-0.24295,-0.25485,-0.26669,-0.2785,-0.29025,-0.30197,-0.31366,-0.32529,-0.33685,-0.34839,-0.35986,-0.37128,-0.38266,-0.39395,-0.40521,-0.41641,-0.42752,-0.4386,-0.44958,-0.46051,-0.47137,-0.48215,-0.49286,-0.50351,-0.51407,-0.52457,-0.53497,-0.54529,-0.55554,-0.5657,-0.57578,-0.58575,-0.59567,-0.60547,-0.6152,-0.62482,-0.63437,-0.6438,-0.65314,-0.66238,-0.67151,-0.68057,-0.68951,-0.69833,-0.70706,-0.7157,-0.72421,-0.7326,-0.74091,-0.74908,-0.75717,-0.76514,-0.77298,-0.7807,-0.7883,-0.79581,-0.80316,-0.81042,-0.81754,-0.82455,-0.83142,-0.8382,-0.84482,-0.85132,-0.8577,-0.86392,-0.87006,-0.87604,-0.88187,-0.8876,-0.89319,-0.89862,-0.90396,-0.90912,-0.91415,-0.91907,-0.92383,-0.92847,-0.93295,-0.93729,-0.9415,-0.94556,-0.94949,-0.95325,-0.95691,-0.96039,-0.96375,-0.96692,-0.97,-0.9729,-0.97565,-0.97827,-0.98074,-0.98306,-0.98523,-0.98724,-0.98914,-0.99084,-0.99243,-0.99387,-0.99515,-0.99628,-0.99725,-0.99808,-0.99875,-0.99927,-0.99966,-0.99988,-0.99997,-0.99988,-0.99966,-0.99927,-0.99875,-0.99808,-0.99725,-0.99628,-0.99515,-0.99387,-0.99243,-0.99084,-0.98914,-0.98724,-0.98523,-0.98306,-0.98074,-0.97827,-0.97565,-0.9729,-0.97,-0.96692,-0.96375,-0.96039,-0.95691,-0.95325,-0.94949,-0.94556,-0.9415,-0.93729,-0.93295,-0.92847,-0.92383,-0.91907,-0.91415,-0.90912,-0.90396,-0.89862,-0.89319,-0.8876,-0.88187,-0.87604,-0.87006,-0.86392,-0.8577,-0.85132,-0.84482,-0.8382,-0.83142,-0.82455,-0.81754,-0.81042,-0.80316,-0.79581,-0.7883,-0.7807,-0.77298,-0.76514,-0.75717,-0.74908,-0.74091,-0.7326,-0.72421,-0.7157,-0.70706,-0.69833,-0.68951,-0.68057,-0.67151,-0.66238,-0.65314,-0.6438,-0.63437,-0.62482,-0.6152,-0.60547,-0.59567,-0.58575,-0.57578,-0.5657,-0.55554,-0.54529,-0.53497,-0.52457,-0.51407,-0.50351,-0.49286,-0.48215,-0.47137,-0.46051,-0.44958,-0.4386,-0.42752,-0.41641,-0.40521,-0.39395,-0.38266,-0.37128,-0.35986,-0.34839,-0.33685,-0.32529,-0.31366,-0.30197,-0.29025,-0.2785,-0.26669,-0.25485,-0.24295,-0.23105,-0.21909,-0.20709,-0.19507,-0.18301,-0.17093,-0.15884,-0.1467,-0.13455,-0.12241,-0.1102,-0.097992,-0.085785,-0.073547,-0.06131,-0.049042,-0.036804,-0.024536,-0.012268,0,0.012268
};

string informationStremTitle[6] = {"Run :", "Event", "Lumi Section", "Orbit :", "Crossing :", "Data Recorded"};



//--------------------------------------------------------------
void ofApp::setup(){
    

#ifdef DEBUG
    
#else
    ofSetDataPathRoot("../Resources/data");
#endif

    
    
    ofEnableSmoothing();
    
    ofBackground( ofColor(5, 14, 36) );
//    ofSetupScreen();
    ofSetFrameRate(60);
//    ofEnableAlphaBlending();
    
//    ofEnablePointSprites();
    
//    ofEnableDepthTest();
    
    pointScale = 100;
    pointScaleDir = 100;
    
    scoreWidth = ofGetWidth();
    
    informationIconImg.load("information.png");
    informationTextImg.load("loadingImage_text.png");
    bInformationIcon = false;
    informationIcon.set(ofGetWidth()-50, 10, 50, 50);
    
    
    openIGImg.load("open.png");
    nextEventImg.load("next.png");
    prevEventImg.load("prev.png");
    autoPlayImg.load("auto.png");
    resetViewImg.load("reset.png");
    volumeImg.load("volume.png");
    speedImg.load("speed.png");
    
    coordX.load("verdana.ttf", 9);
    coordY.load("verdana.ttf", 9);
    information.load("verdana.ttf", 10);
    
    uiInformation = true;
    
    cam.setAutoDistance(false);
    cam.setDistance(500);
    
    
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);
    
    captureW = ofGetWidth();
    captureH = BIT;
    
    for(int i = 0; i < 514 ; i ++){
        sineBufferRight[i] = sines[i];
        sineBufferLeft[i] = sines[i];
    }
    
    maxHertz = 8000;
    spectrum = new SpectrumDrawer( 1, maxHertz );
    
    maxHz = 8000;
    minHz = 180;
    
    ofSoundStreamSetup( 2, 0, this, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4 );
    ofSoundStreamStop();
    
    lineLeft = 0;
    lineRight = 0;
    
    float _linePos = ofGetWidth() * 0.5;
    lineRightXPos = _linePos;
    lineLeftXPos = _linePos;
    
    lineRightXPos = _linePos;
    lineLeftXPos = _linePos;
    
    volume = 0.85;
    speed = 0.4;
    

    lineSize = 12;
    rotateZFactor = 0;
    
    lhcIgFileLoad.openFile("dimuon-Jpsi_0.ig", "LHC/");
    bufferEventCopy = lhcIgFileLoad.bufferEvent;
    
    
    if (lhcIgFileLoad.bufferEvent.size()>100) {
        eventCount = 1;
    } else {
        eventCount = 0;
    }
    
    waveRight = 0.0;
    waveLeft = 0.0;
    
    spectrum->clearPixels();
    
    loadEvent( bufferEventCopy[eventCount] );
    linePathHiddenCapture();
    
    sizeSphere = 0;
    sphereSpeed = 0;
    
    rightStart = ofVec3f( 0, 0, 500 );
    leftStart = ofVec3f( 0, 0, -500 );
    leftVolumeRatio = 0;
    rightVolumeRatio = 0;
    
    protonPos = ofVec3f( 0, 0, -500 );
    
    protonA.setRadius(3);
    protonB.setRadius(3);
    protonA.setPosition(protonPos);
    protonB.setPosition(-protonPos);
    
    nextButton = false;
    prevButton = false;
    
    trigger = false;
    
    playCircleMesh.setMode(OF_PRIMITIVE_LINES);
    playCircleMesh.enableColors();
    playCircleMesh.enableIndices();
    for (int i=0; i<=72; i++) {
        ofVec3f _v = ofVec3f( sin(ofDegToRad(i*5)), cos(ofDegToRad(i*5)), 0 );
        playCircleMesh.addVertex(_v);
        playCircleMesh.addColor(ofColor(255,30));
    }
    for (int i=0; i<72; i++) {
        playCircleMesh.addIndex(i);
        playCircleMesh.addIndex(i+1);
    }
    
    score2DlineTop = ofGetHeight()-460;
    
    interfaceW = 30;
    interfaceH = 30;
    allPlay = false;
    bAutoPlay = true;
    interfaceSetting();
    
    
    changeSpeedMouse = 0;
    changeVolumeMouse = 0;
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
    spectrum->maxHz = maxHz;
    spectrum->minHz = minHz;
    lineRight = lineSize;
    lineLeft = lineSize;
    
    if (allPlay) {
        
        protonSpeed = 50;
        
        if ( abs(protonPos.z)<100 && !trigger ) {
            trigger = true;
        } else {
            sizeSphere = 0;
        }
        
        if (trigger) {
            lineRightXPos += speed;
            lineLeftXPos -= speed;
            sizeSphere = (lineRightXPos - scoreWidth * 0.5) * 2.5;
        }
        
        if (lineRightXPos>scoreWidth-10){
            lineRightXPos = scoreWidth*0.5;
            sizeSphere = 0;
        }
        
        if (lineLeftXPos<10){
            lineLeftXPos = scoreWidth*0.5;
        }
    }
    
    
    if ( allPlay ) {
        for(int n = 0;n<BIT;n++){
            ampRight[n] = (ampRight[n]*lineRight + spectrum->getAmp(lineRightXPos, n))/(lineRight+1);
            hertzScaleRight[n] = int(spectrum->getFreq(n));
            ampLeft[n] = (ampLeft[n]*lineLeft + spectrum->getAmp(lineLeftXPos, n))/(lineLeft+1);
            hertzScaleLeft[n] = int(spectrum->getFreq(n));
        }
    }
    
    
    cam.worldToScreen(rightStart);
    cam.worldToScreen(leftStart);
    
    leftVolumeRatio = abs(sin(ofDegToRad((cam.getOrientationEuler().y-90)*0.5)));
    rightVolumeRatio = ofMap(leftVolumeRatio, 0, 1, 1, 0);
    
    pathMake.creatorUpdate(sizeSphere);
    
    protonPos = protonPos + ofVec3f(0, 0, protonSpeed);
    
    if (bAutoPlay) {
        rotateZFactor = 0.1;
        
        if (sizeSphere>400) {
            eventCount++;
            
            ofSoundStreamStop();
            allPlay = false;
            spectrum->clearPixels();
            lineRightXPos = scoreWidth * 0.5;
            lineLeftXPos = scoreWidth * 0.5;
            sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
            
            loadEvent( bufferEventCopy[eventCount%bufferEventCopy.size()] );
            linePathHiddenCapture();
            
            trigger = false;
            protonPos = ofVec3f( 0, 0, -1000 );
            hitTime = ofGetElapsedTimeMillis();
            lineLeft = lineSize;
            lineRight = lineSize;
            nextButton = true;
            allPlay = true;
            ofSoundStreamStart();
        }
    } else {
        rotateZFactor = 0;
    }
    
    rotateZValue = rotateZValue + rotateZFactor;
    
    pathMake.score2DTriggerDraw(lineLeftXPos - scoreWidth*0.5, lineRightXPos - scoreWidth*0.5, 0.4);
    
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(23, 114, 118), ofColor(5, 14, 36));
    ofNoFill();
    
    
    ofPushMatrix();
    
    cam.begin();
    
    ofRotateY(90);
    
    ofPushMatrix();
    float modelview[16];
    
    //    glPushMatrix();
    glGetFloatv(GL_MODELVIEW_MATRIX , modelview);
    
    for(int i=0; i<3; i++ )
        for(int j=0; j<3; j++ ) {
            if ( i==j )
                modelview[i*4+j] = 1.0;
            else
                modelview[i*4+j] = 0.0;
        }
    
    glLoadMatrixf(modelview);
    
    float _speedFactorSphere = sizeSphere * 1.05;
    for (int i=0; i<=playCircleMesh.getNumVertices(); i++) {
        ofVec3f _v  = ofVec3f( sin(ofDegToRad(i*5)) * _speedFactorSphere, cos(ofDegToRad(i*5)) * _speedFactorSphere, 0 );
        playCircleMesh.setVertex(i, _v);
    }
    playCircleMesh.draw();
    ofPopMatrix();
    
    
    ofRotateZ(rotateZValue);
    
    ofPushStyle();
    glLineWidth(1);
    ofSetColor(40, 40, 200, 120);
    ofDrawLine(leftStart, rightStart);
    ofPopStyle();
    
    if ((allPlay)&&!(protonPos.z>0)) {
        protonA.setPosition(protonPos);
        protonA.draw();
        protonB.setPosition(-protonPos);
        protonB.draw();
    }
    
    pathMake.pathPolyLineDraw();
    pathMake.particleMoving(sizeSphere);
    pathMake.creatorDraw();
    
    //    boxDraw( EB, ofColor(255,0,0,70) );
    //    boxDraw( EE, ofColor(255,0,0,70) );
    //    boxDraw( ES, ofColor(0,255,0,70) );
    //    boxDraw( HB, ofColor(100,100,255,70) );
    //    boxDraw( HE, ofColor(100,100,255,70) );
    //    boxDraw( HF, ofColor(200,200,255,70) );
    
    cam.end();
    
    
    ofPushMatrix();
    ofPushStyle();
    ofSetColor( 255, 30 );
    ofDrawLine(ofGetWidth()*0.5, score2DlineTop*1.2, ofGetWidth()*0.5, ofGetHeight()-10);
    //    ofDrawLine(ofGetWidth()*0.4, ofGetHeight()-10, ofGetWidth()*0.6, ofGetHeight()-10);
    
    ofSetColor( 140, 120, 210, 40 );
    glLineWidth(0.7);
    ofDrawLine(lineRightXPos + ofGetWidth()*0.5-scoreWidth*0.5, score2DlineTop*1.2, lineRightXPos + ofGetWidth()*0.5-scoreWidth*0.5, ofGetHeight()-10);
    ofDrawLine(lineLeftXPos + ofGetWidth()*0.5-scoreWidth*0.5, score2DlineTop*1.2, lineLeftXPos + ofGetWidth()*0.5-scoreWidth*0.5, ofGetHeight()-10);
    ofPopStyle();
    
    pathMake.score2dTriggerImg.draw( ofGetWidth()*0.5-scoreWidth*0.5, score2DlineTop );
    //        spectrum->spectrumDraw();
    ofPopMatrix();
    
    ofPopMatrix();
    
    
    if (uiInformation) {
        
        ofPushMatrix();
        ofPushStyle();
        ofDisableDepthTest();
        
        ofTranslate( 15, ofGetHeight()-75 );
        ofSetColor(255,150);
        
        information.drawString( informationStremTitle[1] + " - "  + ofToString(bufferEventCopy.size()) + " / " + ofToString((eventCount%bufferEventCopy.size())+1),
                               0, 20+0*15);
        information.drawString( "Num of Paticles", 0, 20+1*15 );
        information.drawString( informationStremTitle[5], 0, 20+2*15 );
        
        if (informationStream.size()>0) {
            information.drawString( ": " + informationStream[1], 130, 20+0*15 );
            information.drawString( ": " + informationStream[5], 130, 20+2*15 );
        }
        information.drawString( ": " + ofToString(pathMake.point3D.size()), 130, 20+1*15 );
        
        ofPopStyle();
        ofPopMatrix();
        
    }
    
    interfaceDrawing();
    
    
}



//--------------------------------------------------------------
void ofApp::loadEvent(ofBuffer _b) {
    
    vMeshPos1.clear();
    vMeshDir1.clear();
    vMeshPos2.clear();
    vMeshDir2.clear();
    
    EB.clear();
    EE.clear();
    ES.clear();
    HB.clear();
    HE.clear();
    HF.clear();
    
    informationStream.clear();
    
    ofBuffer buffer = _b;
    
    bool extraFound = false;
    bool extraFoundEvent = false;
    while ( !buffer.isLastLine() && !extraFound ) {
        string line = buffer.getNextLine();
        if  ( ofIsStringInString(line,"\"Extras_V1\":") && !ofIsStringInString(line, "pos_1") )  {
            extraFound = true;
            bool isFirstLine = true;
            extraFound = true;
            while (line != "]") {
                if (isFirstLine) {
                    line.erase(0,12);
                    isFirstLine = false;
                }
                
                int i = 0;
                while ((i = line.find_first_of( "()[]", i)) != std::string::npos) {
                    line.erase(i, 1);
                }
                
                vector<string> points = ofSplitString(line, ",");
                
                ofVec3f pos1T = ofVec3f( ofToFloat(points[0]), ofToFloat(points[1]), ofToFloat(points[2]) ) * pointScale;
                vMeshPos1.push_back(pos1T);
                ofVec3f dir1T = ofVec3f( ofToFloat(points[3]), ofToFloat(points[4]), ofToFloat(points[5]) ) * pointScaleDir;
                vMeshDir1.push_back(dir1T);
                ofVec3f pos2T = ofVec3f( ofToFloat(points[6]), ofToFloat(points[7]), ofToFloat(points[8]) ) * pointScale;
                vMeshPos2.push_back(pos2T);
                ofVec3f dir2T = ofVec3f( ofToFloat(points[9]), ofToFloat(points[10]), ofToFloat(points[11]) ) * pointScaleDir;
                vMeshDir2.push_back(dir2T);
                
                line = buffer.getNextLine();
            }
        }
    }
    
    ofBuffer bufferInfo = _b;
    bool extraFoundInfo = false;
    bool extraFoundEventInfo = false;
    while ( !bufferInfo.isLastLine() && !extraFoundInfo ) {
        string line2 = bufferInfo.getNextLine();
        if  ( ofIsStringInString(line2,"\'Collections\':") )  {
            
            extraFoundInfo = true;
            bool isFirstLineInfo = true;
            extraFoundEventInfo = true;
            while (line2 != "]") {
                if (isFirstLineInfo) {
                    line2.erase(0,30);
                    isFirstLineInfo = false;
                }
                
                int i = 0;
                while ((i = line2.find_first_of( " ", i)) != std::string::npos) {
                    line2.erase(i, 1);
                }
                
                vector<string> information = ofSplitString(line2, ",");
                
                for (int i=0; i<6; i++) {
                    informationStream.push_back(information[i]);
                }
                
                line2 = bufferInfo.getNextLine();
                
            }
        }
    }
    
    
    ofBuffer bufferEB = _b;
    EB = boxVectorE( bufferEB, "\"EBRecHits_V2\":", 0.25, 5 );
    
    ofBuffer bufferEE = _b;
    EE = boxVectorE( bufferEE, "\"EERecHits_V2\":", 0.8, 5 );
    
    ofBuffer bufferES = _b;
    ES = boxVectorE( bufferES, "\"ESRecHits_V2\":", 0.001, 500000 );
    
    ofBuffer bufferHB = _b;
    HB = boxVectorH( bufferHB, "\"HBRecHits_V2\":", 0.75, 0.075 );
    
    ofBuffer bufferHE = _b;
    HE = boxVectorH( bufferHE, "\"HERecHits_V2\":", 0.75, 0.075 );
    
    ofBuffer bufferHF = _b;
    HF = boxVectorH( bufferHF, "\"HFRecHits_V2\":", 3.0, 0.075 );
    
    pathMake.setup( vMeshPos1, vMeshDir1, vMeshPos2, vMeshDir2 );
    
}



//--------------------------------------------------------------
void ofApp::exit(){
    
//    std::exit(0);
    
}



//--------------------------------------------------------------
void ofApp::boxDraw( vector<ofVec3f> _vV, ofColor _c ){
    
    ofPushStyle();
    ofSetColor(_c);
    for (int i=0; i<_vV.size(); i+=8) {
        ofDrawLine( _vV[i+0], _vV[i+1] );
        ofDrawLine( _vV[i+1], _vV[i+2] );
        ofDrawLine( _vV[i+2], _vV[i+3] );
        ofDrawLine( _vV[i+3], _vV[i+0] );
        ofDrawLine( _vV[i+4], _vV[i+5] );
        ofDrawLine( _vV[i+5], _vV[i+6] );
        ofDrawLine( _vV[i+6], _vV[i+7] );
        ofDrawLine( _vV[i+7], _vV[i+4] );
        ofDrawLine( _vV[i+0], _vV[i+4] );
        ofDrawLine( _vV[i+1], _vV[i+5] );
        ofDrawLine( _vV[i+2], _vV[i+6] );
        ofDrawLine( _vV[i+3], _vV[i+7] );
    }
    ofPopStyle();
    
}



//--------------------------------------------------------------
vector<ofVec3f> ofApp::boxVectorE(ofBuffer _b, string _p, float _l, float _r) {
    
    vector<ofVec3f> _temp;
    _temp.clear();
    bool extraFound = false;
    bool extraFoundEvent = false;
    while ( !_b.isLastLine() && !extraFound ) {
        string _line = _b.getNextLine();
        if  ( ofIsStringInString(_line,_p) && !ofIsStringInString(_line, "energy") )  {
            extraFound = true;
            bool isFirstLine = true;
            extraFoundEvent = true;
            while (_line != "]") {
                if (isFirstLine) {
                    _line.erase(0,16);
                    isFirstLine = false;
                }
                
                int i = 0;
                while ((i = _line.find_first_of( "()[]", i)) != std::string::npos) {
                    _line.erase(i, 1);
                }
                
                vector<string> points = ofSplitString(_line, ",");
                
                if (ofToFloat(points[0]) > _l) {
                    
                    ofVec3f pos1T = ofVec3f( ofToFloat(points[5]), ofToFloat(points[6]), ofToFloat(points[7]) ) * pointScale;
                    _temp.push_back(pos1T);
                    ofVec3f dir1T = ofVec3f( ofToFloat(points[8]), ofToFloat(points[9]), ofToFloat(points[10]) ) * pointScaleDir;
                    _temp.push_back(dir1T);
                    ofVec3f pos2T = ofVec3f( ofToFloat(points[11]), ofToFloat(points[12]), ofToFloat(points[13]) ) * pointScale;
                    _temp.push_back(pos2T);
                    ofVec3f dir2T = ofVec3f( ofToFloat(points[14]), ofToFloat(points[15]), ofToFloat(points[16]) ) * pointScaleDir;
                    _temp.push_back(dir2T);
                    
                    float _scale = ofToFloat(points[0])*_r;
                    
                    ofVec3f pos1B = ofVec3f( ofToFloat(points[17]), ofToFloat(points[18]), ofToFloat(points[19]) ) * pointScale;
                    ofVec3f diff1 = pos1B-pos1T;
                    _temp.push_back( diff1 * _scale + pos1T);
                    ofVec3f dir1B = ofVec3f( ofToFloat(points[20]), ofToFloat(points[21]), ofToFloat(points[22]) ) * pointScaleDir;
                    ofVec3f diff2 = dir1B-dir1T;
                    _temp.push_back( diff2 * _scale + dir1T);
                    ofVec3f pos2B = ofVec3f( ofToFloat(points[23]), ofToFloat(points[24]), ofToFloat(points[25]) ) * pointScale;
                    ofVec3f diff3 = pos2B-pos2T;
                    _temp.push_back( diff3 * _scale + pos2T );
                    ofVec3f dir2B = ofVec3f( ofToFloat(points[26]), ofToFloat(points[27]), ofToFloat(points[28]) ) * pointScaleDir;
                    ofVec3f diff4 = dir2B-dir2T;
                    _temp.push_back( diff4 * _scale + dir2T );
                    
                }
                
                _line = _b.getNextLine();
                
            }
        }
    }
    
    return _temp;
    
}



//--------------------------------------------------------------
vector<ofVec3f> ofApp::boxVectorH(ofBuffer _b, string _p, float _l, float _r) {
    
    vector<ofVec3f> _temp;
    _temp.clear();
    
    bool extraFound = false;
    bool extraFoundEvent = false;
    while ( !_b.isLastLine() && !extraFound ) {
        string _line = _b.getNextLine();
        if  ( ofIsStringInString(_line,_p) && !ofIsStringInString(_line, "energy") )  {
            extraFound = true;
            bool isFirstLine = true;
            extraFoundEvent = true;
            while (_line != "]") {
                if (isFirstLine) {
                    _line.erase(0,16);
                    isFirstLine = false;
                }
                
                int i = 0;
                while ((i = _line.find_first_of( "()[]", i)) != std::string::npos) {
                    _line.erase(i, 1);
                }
                
                vector<string> points = ofSplitString(_line, ",");
                
                if (ofToFloat(points[0]) > _l) {
                    
                    ofVec3f pos1T = ofVec3f( ofToFloat(points[5]), ofToFloat(points[6]), ofToFloat(points[7]) ) * pointScale;
                    _temp.push_back(pos1T);
                    ofVec3f dir1T = ofVec3f( ofToFloat(points[8]), ofToFloat(points[9]), ofToFloat(points[10]) ) * pointScaleDir;
                    _temp.push_back(dir1T);
                    ofVec3f pos2T = ofVec3f( ofToFloat(points[11]), ofToFloat(points[12]), ofToFloat(points[13]) ) * pointScale;
                    _temp.push_back(pos2T);
                    ofVec3f dir2T = ofVec3f( ofToFloat(points[14]), ofToFloat(points[15]), ofToFloat(points[16]) ) * pointScaleDir;
                    _temp.push_back(dir2T);
                    
                    float _scale = ofToFloat(points[0])*_r;
                    
                    ofVec3f pos1B = ofVec3f( ofToFloat(points[17]), ofToFloat(points[18]), ofToFloat(points[19]) ) * pointScale;
                    ofVec3f diff1 = pos1B-pos1T;
                    _temp.push_back( diff1 * _scale + pos1T);
                    ofVec3f dir1B = ofVec3f( ofToFloat(points[20]), ofToFloat(points[21]), ofToFloat(points[22]) ) * pointScaleDir;
                    ofVec3f diff2 = dir1B-dir1T;
                    _temp.push_back( diff2 * _scale + dir1T);
                    ofVec3f pos2B = ofVec3f( ofToFloat(points[23]), ofToFloat(points[24]), ofToFloat(points[25]) ) * pointScale;
                    ofVec3f diff3 = pos2B-pos2T;
                    _temp.push_back( diff3 * _scale + pos2T );
                    ofVec3f dir2B = ofVec3f( ofToFloat(points[26]), ofToFloat(points[27]), ofToFloat(points[28]) ) * pointScaleDir;
                    ofVec3f diff4 = dir2B-dir2T;
                    _temp.push_back( diff4 * _scale + dir2T );
                    
                }
                
                _line = _b.getNextLine();
                
            }
        }
    }
    
    return _temp;
    
}



//--------------------------------------------------------------
void ofApp::linePathHiddenCapture(){
    
    ofPixels _p = pathMake.spectrum2DMake(0.4);
    _p.mirror(false, false);
    ofImage _captureImage;
    _captureImage.allocate(captureW, captureH, OF_IMAGE_COLOR);
    if ( _p.size()>0 ) {
        _captureImage.setFromPixels( _p.getPixels(), captureW, captureH, OF_IMAGE_COLOR );
        _captureImage.mirror(true, false);
        spectrum->loadImageSpectrum(_captureImage);
    }
    
}



//--------------------------------------------------------------
void ofApp::openIgFile(string URL){
    
    bufferEventCopy.clear();
    
    string _output;
    
    allPlay = false;
    
    if(URL==""){
        ofFileDialogResult result = ofSystemLoadDialog("Open File", false, "");
        
        if(result.bSuccess){
            URL = result.filePath;
            _output = "URL to open: \n "+URL;
            string extension;
            for(int i = URL.length()-3; i < URL.length(); i++){
                extension+=URL[i];
            }
            
            lhcIgFileLoad.openFile(URL, "../Resources/LHC/");
            
            int _index = lhcIgFileLoad.bufferEvent.size();
            if (_index>100) {
                for (int i=0; i<100; i++) {
                    bufferEventCopy.push_back(lhcIgFileLoad.bufferEvent[i+1]);
                }
            } else {
                bufferEventCopy = lhcIgFileLoad.bufferEvent;
            }
            
            eventCount = 0;

            
            trigger = false;
            protonPos = ofVec3f( 0, 0, -1000 );
            hitTime = ofGetElapsedTimeMillis();
            
            
            igLoadReset();
            
            loadEvent( bufferEventCopy[0] );
            linePathHiddenCapture();
            
        } else {
            
            igLoadReset();
            
            lhcIgFileLoad.openFile("data/sampleIG.ig", "../Resources/LHC/");
            bufferEventCopy = lhcIgFileLoad.bufferEvent;
            loadEvent( bufferEventCopy[0] );
            linePathHiddenCapture();
            
        }
    }
    
    
}



//--------------------------------------------------------------
void ofApp::igLoadReset(){
    
    lineLeft = 0;
    lineRight = 0;
    
    waveRight = 0.0;
    waveLeft = 0.0;
    
    allPlay = false;
    ofSoundStreamStop();
    spectrum->clearPixels();
    
    lineRightXPos = scoreWidth * 0.5;
    lineLeftXPos = scoreWidth * 0.5;
    sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case ' ':
            if (allPlay) {
                allPlay = false;
                ofSoundStreamStop();
                lineLeft = 0;
                lineRight = 0;
                trigger = false;
                protonPos = ofVec3f( 0, 0, -1000 );
                hitTime = ofGetElapsedTimeMillis();
                
                for(int i = 0; i < 514 ; i ++){
                    sineBufferRight[i] = sines[i];
                    sineBufferLeft[i] = sines[i];
                }
            } else {
                protonPos = ofVec3f( 0, 0, -1000 );
                hitTime = ofGetElapsedTimeMillis();
                lineLeft = lineSize;
                lineRight = lineSize;
                lineRightXPos = scoreWidth * 0.5;
                lineLeftXPos = scoreWidth * 0.5;
                sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
                allPlay = true;
                ofSoundStreamStart();
            }
            break;
            
        default:
            break;
    }
    
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    string _file;
    ofImage _pix;
    
    switch (key) {
        case 'c':
            _pix.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
            _pix.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            _file = "../../../"+ofGetTimestampString()+" Capture.png";
            _pix.saveImage( _file );
            break;
            
        case 'g':
            uiInformation = !uiInformation;
            break;
            
        default:
            break;
    }
    
}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    if (openIGFile.inside( x, y )) {
        bOverOpenIGFile = true;
        interfaceMenuIndex = 0;
    } else {
        bOverOpenIGFile = false;
    }
    
    if (nextEvent.inside( x, y )) {
        bOverNextEvent = true;
        interfaceMenuIndex = 1;
    } else {
        bOverNextEvent = false;
    }
    
    if (prevEvent.inside( x, y )) {
        bOverPrevEvent = true;
        interfaceMenuIndex = 2;
    } else {
        bOverPrevEvent = false;
    }
    
    if (autoPlay.inside( x, y )) {
        bOverAutoPlay = true;
        interfaceMenuIndex = 3;
    } else {
        bOverAutoPlay = false;
    }
    
    if (resetView.inside( x, y )) {
        bOverResetView = true;
        interfaceMenuIndex = 4;
    } else {
        bOverResetView = false;
    }
    
    if (speedCtrl.inside( x, y )) {
        bOverSpeedCtrl = true;
        interfaceMenuIndex = 5;
    } else {
        bOverSpeedCtrl = false;
    }
    
    if (volumeCtrl.inside( x, y )) {
        bOverVolumeCtrl = true;
        interfaceMenuIndex = 6;
    } else {
        bOverVolumeCtrl = false;
    }
    
    if (informationIcon.inside( x, y )) {
        bOverInformationIcon = true;
    } else {
        bOverInformationIcon = false;
    }
    
    if (!bOverOpenIGFile && !bOverNextEvent && !bOverPrevEvent && !bOverAutoPlay && !bOverResetView && !bOverSpeedCtrl && !bOverVolumeCtrl && !bInformationIcon)
        cam.enableMouseInput();
    
}



//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    float _minLimitY = openIGFile.getPosition().y + 10;
    float _maxLimitY = resetView.getPosition().y + 15;
    
    if (bOverSpeedCtrl) {
        cam.disableMouseInput();
        
        if (y < _minLimitY) {
            y = _minLimitY;
        } else if (y > _maxLimitY) {
            y = _maxLimitY;
        }
        
        changeSpeedMouse = (int)ofMap( y, _minLimitY, _maxLimitY, 100, -20 ) * 0.01;
        speed = 0.4 + changeSpeedMouse;
        
        speedCtrl.position = glm::vec3( ofGetWidth()-interfaceW-10-30, y-10, 0 );
        
    }
    
    if (bOverVolumeCtrl) {
        cam.disableMouseInput();
        
        if (y < _minLimitY) {
            y = _minLimitY;
        } else if (y > _maxLimitY) {
            y = _maxLimitY;
        }
        
        changeVolumeMouse = (int)ofMap( y, _minLimitY, _maxLimitY, 15, -85 ) * 0.01;
        volume = 0.85 + changeVolumeMouse;
        
        volumeCtrl.position = glm::vec3( ofGetWidth()-interfaceW-10-60, y-10, 0 );
        
    }
    
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (bufferEventCopy.size()>0) {
        
        if (nextEvent.inside( x, y ) && !bNextEvent ) {
            bNextEvent = true;
        }
        
        if (prevEvent.inside( x, y ) && !bPrevEvent ) {
            bPrevEvent = true;
        }
        
    }
    
}



//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (informationIcon.inside( x, y )) {
        bInformationIcon = !bInformationIcon;
    }
    
    if (openIGFile.inside( x, y )) {
        bOpenIGFile = true;
        
        openIgFile();
    }
    
    if (bufferEventCopy.size() > 0) {
        
        if (nextEvent.inside( x, y ) && bNextEvent ) {
            bNextEvent = false;
            
            eventCount++;
            
            ofSoundStreamStop();
            allPlay = false;
            spectrum->clearPixels();
            lineRightXPos = scoreWidth * 0.5;
            lineLeftXPos = scoreWidth * 0.5;
            sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
            
            trigger = false;
            protonPos = ofVec3f( 0, 0, -1000 );
            hitTime = ofGetElapsedTimeMillis();
            
            if (eventCount>bufferEventCopy.size()-1) eventCount = bufferEventCopy.size()-1;
            loadEvent( bufferEventCopy[eventCount] );
            linePathHiddenCapture();
            
        } else {
            bNextEvent = false;
        }
        
        
        if (prevEvent.inside( x, y ) && bPrevEvent ) {
            bPrevEvent = false;
            
            eventCount--;
            
            ofSoundStreamStop();
            allPlay = false;
            spectrum->clearPixels();
            lineRightXPos = scoreWidth * 0.5;
            lineLeftXPos = scoreWidth * 0.5;
            sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
            
            trigger = false;
            protonPos = ofVec3f( 0, 0, -1000 );
            hitTime = ofGetElapsedTimeMillis();
            
            if(eventCount<0) eventCount = 0;
            loadEvent(bufferEventCopy[eventCount]);
            linePathHiddenCapture();
        } else {
            bNextEvent = false;
        }
        
    }
    
    
    if (autoPlay.inside( x, y )) {
        bAutoPlay = !bAutoPlay;
    }
    
    if (resetView.inside( x, y )) {
        bResetView = true;
        
        lineRightXPos = scoreWidth * 0.5;
        lineLeftXPos = scoreWidth * 0.5;
        sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
        trigger = false;
        protonPos = ofVec3f( 0, 0, -1000 );
        hitTime = ofGetElapsedTimeMillis();
        
        cam.setPosition(-500, -30, 0);
        cam.setOrientation( ofVec3f(0, -90, 0) );
        
    }
    
}



//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    score2DlineTop = h - 460;
    
    trigger = false;
    protonPos = ofVec3f( 0, 0, -1000 );
    hitTime = ofGetElapsedTimeMillis();
    
    allPlay = false;
    ofSoundStreamStop();
    
    lineLeft = 0;
    lineRight = 0;
    
    lineRightXPos = scoreWidth * 0.5;
    lineLeftXPos = scoreWidth * 0.5;
    sizeSphere = (lineRightXPos - ofGetWidth() * 0.5) * 2.5;
    
    for(int i = 0; i < 514 ; i ++){
        sineBufferRight[i] = sines[i];
        sineBufferLeft[i] = sines[i];
    }
    
    interfaceSetting();
    
    informationIcon.set(ofGetWidth()-50, 10, 50, 50);
    
}



//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}



//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    if(allPlay){
        
        for (int i=0; i<bufferSize; i+=2){
            
            waveRight = 0.0;
            waveLeft = 0.0;
            
            for(int n=0; n<BIT; n+=1){
                
                if (ampLeft[n]>0.00001) {
                    phasesLeft[n] += 512./(44100.0/(hertzScaleLeft[n]));
                    
                    if ( phasesLeft[n] >= 511 ) phasesLeft[n] -=512;
                    
                    //                    remainderLeft = phasesLeft[n+1] - floor(phasesLeft[n+1]);
                    //                    waveLeft+=(float) ((1-remainderLeft) * sineBufferLeft[1+ (long) phasesLeft[n+1]] + remainderLeft * sineBufferLeft[2+(long) phasesLeft[n+1]])*ampLeft[n+1];
                    
                    waveLeft+=(sineBufferLeft[1+ (long) phasesLeft[n]])*ampLeft[n];
                }
                
                if (ampRight[n]>0.00001) {
                    phasesRight[n] += 512./(44100.0/(hertzScaleRight[n]));
                    
                    if ( phasesRight[n] >= 511 ) phasesRight[n] -=512;
                    
                    //                    remainderRight = phasesRight[n] - floor(phasesRight[n]);
                    //                    waveRight+=(float) ((1-remainderRight) * sineBufferRight[1+ (long) phasesRight[n]] + remainderRight * sineBufferRight[2+(long) phasesRight[n]])*ampRight[n];
                    
                    waveRight+=(sineBufferRight[1+ (long) phasesRight[n]])*ampRight[n];
                }
                
            }
            
            float leftOut;
            float rightOut;
            leftOut = waveLeft * volume * CLAMP(ofMap(sizeSphere, 0, 70, 0, 1), 0, 1 );
            rightOut = waveRight * volume * CLAMP(ofMap(sizeSphere, 0, 70, 0, 1), 0, 1 );
            
            float _volumeSpeed = 20.0;
            
            leftOut /= _volumeSpeed;
            if(leftOut>1.0) leftOut=1.0;
            if(leftOut<-1.0) leftOut=-1.0;
            
            rightOut /= _volumeSpeed;
            if(rightOut>1.0) rightOut=1.0;
            if(rightOut<-1.0) rightOut=-1.0;
            
            output[i*nChannels]     = (leftOut * leftVolumeRatio + rightOut * rightVolumeRatio) * 2.0;
            output[i*nChannels + 1] = (rightOut * leftVolumeRatio + leftOut * rightVolumeRatio) * 2.0;
        }
    }
    
}



//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}



//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}



//--------------------------------------------------------------
void ofApp::interfaceSetting(){
    
    int _w = ofGetWidth();
    int _h = ofGetHeight();
    
    float _width = interfaceW;
    float _height = interfaceH;
    
    float _x = _w-_width-10;
    float _y = -25;
    
    openIGFile.set( _x, _h-_height*5+_y, _width, _height);
    nextEvent.set( _x, _h-_height*4+_y, _width, _height);
    prevEvent.set( _x, _h-_height*3+_y, _width, _height);
    autoPlay.set( _x, _h-_height*2+_y, _width, _height);
    resetView.set( _x, _h-_height*1+_y, _width, _height);
    
    speedCtrl.set( _x-30, ofGetHeight()-55-15, 20, 20 );
    volumeCtrl.set( _x-60, ofGetHeight()-142-15, 20, 20 );
    
    
}



//--------------------------------------------------------------
void ofApp::interfaceDrawing(){
    
    ofPushStyle();
    ofNoFill();
    
    ofSetColor(73, 164, 168, 100);
    float _minLimitY = openIGFile.getPosition().y + 10;
    float _maxLimitY = resetView.getPosition().y + 15;
    ofDrawLine( speedCtrl.getPosition().x + 10, _minLimitY, speedCtrl.getPosition().x + 10, _maxLimitY );
    ofDrawLine( volumeCtrl.getPosition().x + 10, _minLimitY, volumeCtrl.getPosition().x + 10, _maxLimitY );
    
    ofDrawLine( speedCtrl.getPosition().x, ofGetHeight()-45-15, speedCtrl.getPosition().x + 20, ofGetHeight()-45-15 );
    ofDrawLine( volumeCtrl.getPosition().x, ofGetHeight()-132-15, volumeCtrl.getPosition().x + 20, ofGetHeight()-132-15 );
    
    ofColor _onImgAlpha = ofColor( 255, 220 );
    ofColor _offImgAlpha = ofColor(53, 144, 148);
    
    if (openIGFile.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        openIGImg.draw(openIGFile);
    } else {
        ofSetColor( _offImgAlpha );
        openIGImg.draw(openIGFile);
    }
    
    if (nextEvent.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        nextEventImg.draw(nextEvent);
    } else {
        ofSetColor( _offImgAlpha );
        nextEventImg.draw(nextEvent);
    }
    
    if (prevEvent.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        prevEventImg.draw(prevEvent);
    } else {
        ofSetColor( _offImgAlpha );
        prevEventImg.draw(prevEvent);
    }
    
    if (autoPlay.inside(mouseX, mouseY) || bAutoPlay) {
        ofSetColor( _onImgAlpha );
        autoPlayImg.draw(autoPlay);
    } else {
        ofSetColor( _offImgAlpha );
        autoPlayImg.draw(autoPlay);
    }
    
    if (resetView.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        resetViewImg.draw(resetView);
    } else {
        ofSetColor( _offImgAlpha );
        resetViewImg.draw(resetView);
    }
    
    if (speedCtrl.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        speedImg.draw(speedCtrl);
    } else {
        ofSetColor( _offImgAlpha );
        speedImg.draw(speedCtrl);
    }
    
    if (volumeCtrl.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        volumeImg.draw(volumeCtrl);
    } else {
        ofSetColor( _offImgAlpha );
        volumeImg.draw(volumeCtrl);
    }
    
    
    if (informationIcon.inside(mouseX, mouseY)) {
        ofSetColor( _onImgAlpha );
        informationIconImg.draw(informationIcon);
    } else {
        ofSetColor( _offImgAlpha );
        informationIconImg.draw(informationIcon);
    }
    
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor( _onImgAlpha );
    if (bInformationIcon) {
        informationTextImg.draw( ofGetWidth()-informationTextImg.getWidth()-50, 15, informationTextImg.getWidth(), informationTextImg.getHeight());
    }
    ofPopStyle();
    
}

