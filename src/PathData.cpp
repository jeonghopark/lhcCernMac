#include "PathData.h"

bool minX( float a, float b){
    return a < b;
}

bool maxX( float a, float b){
    return a > b;
}

//--------------------------------------------------------------
PathData::PathData(){
    
    creatorResolution = 18;
    
    lineStep = 34;
    
}


//--------------------------------------------------------------
void PathData::setup( vector<ofVec3f> _a, vector<ofVec3f> _b, vector<ofVec3f> _c, vector<ofVec3f> _d ) {
    
    
    pathResult.clear();
    lengthPath.clear();
    valueDegree.clear();
    twoPointsDegree.clear();
    lineDirection.clear();
    //    pathResult.resize( _a.size() );
    //    lengthPath.resize( _a.size() );
    //    lineDirection.resize( _a.size() );
    
    for (int i=0; i<_a.size(); i++) {
        //                pathResult[i] = curveFomulaCal( _a[i], _b[i], _c[i], _d[i] );
        pathResult.push_back( curveFomulaCal( _a[i], _b[i], _c[i], _d[i] ) );
        startPosition.push_back( _a[i] );
    }
    
    for (int i=0; i<_a.size(); i++) {
        lengthPath.push_back( lengthCal( curveFomulaCal( _a[i], _b[i], _c[i], _d[i] ) ) );
        valueDegree.push_back( degreeCal( curveFomulaCal( _a[i], _b[i], _c[i], _d[i] ) ) );
        twoPointsDegree.push_back( twoPointsDegreeCal( curveFomulaCal( _a[i], _b[i], _c[i], _d[i] ) ) );
        lineDirection.push_back( lineDirectionCal( curveFomulaCal( _a[i], _b[i], _c[i], _d[i] ) ) );
    }
    
    widthScreen = 1280;
    heightScreen = 1100;
    
    capturePixels.allocate(widthScreen, 512, OF_IMAGE_COLOR);
    
    pathPixels.setImageType(OF_IMAGE_COLOR);
    pathPixels.allocate(widthScreen, 512, OF_IMAGE_COLOR);
    
    score2D.setImageType(OF_IMAGE_COLOR_ALPHA);
    score2D.allocate(widthScreen, 512, OF_IMAGE_COLOR_ALPHA);
    score2dImg.allocate(widthScreen, 512, OF_IMAGE_COLOR_ALPHA);
    score2dTriggerImg.allocate(widthScreen, 512, OF_IMAGE_COLOR_ALPHA);
    
    for (int j=0; j<512; j++) {
        for (int i=0; i<widthScreen; i++) {
            pathPixels.setColor(i, j, ofColor(0));
            score2D.setColor(i, j, ofColor(0,0));
        }
    }
    
    pathPolyLineSetup();
    
    sphereElement.setResolution(6);
    sphereElement.setRadius(1.5);
    
    movingPointMesh.setMode(OF_PRIMITIVE_POINTS);
    movingPointMesh.enableColors();
    polarPosition();
    creatorSetting();
    
    //    if (pathPixels.size()>0) {
    //        score2DMake();
    //    }
    
}


//--------------------------------------------------------------
void PathData::close(){
    
    for (int i=0; i<point3D.size(); i++) {
        point3D[i].vboCreator.clear();
    }
    
}



//--------------------------------------------------------------
void PathData::curveDraw(){
    
    for (int i=0; i<pathResult.size(); i++) {
        curveFomulaDraw( pathResult[i] );
    }
    
}

//--------------------------------------------------------------
void PathData::energyDraw(){
    
    
}


//--------------------------------------------------------------
void PathData::histoDraw(){
    
    vector<float> _lengthSort = lengthPath;
    std::sort(_lengthSort.begin(), _lengthSort.end(), minX);
    
    ofPushStyle();
    glLineWidth(4);
    for (int i=0; i<_lengthSort.size(); i++) {
        
        float _x2 = _lengthSort[i];
        float _y2 = _lengthSort[i];
        
        float _alpha = ofMap( _y2, 0, 300, 100, 10 );
        
        ofSetColor( ofColor::fromHsb(255, 0, 255, _alpha) );
        ofLine( 10, 1000 - 10 - _y2, _x2+20, 1000 - 10 - _y2 );
        
    }
    ofPopStyle();
    
}

//--------------------------------------------------------------
void PathData::degreeDraw(){
    
    vector<float> _degreeSort = valueDegree;
    std::sort(_degreeSort.begin(), _degreeSort.end(), minX);
    
    ofPushStyle();
    glLineWidth(4);
    for (int i=0; i<_degreeSort.size(); i++) {
        
        float _x2 = _degreeSort[i];
        float _y2 = _degreeSort[i];
        
        if (_y2==0) {
            _y2 = 0;
        }
        
        float _alpha = ofMap( _y2, 0, 300, 100, 10 );
        
        ofSetColor( ofColor::fromHsb(255, 0, 255, _alpha) );
        ofLine( 500, 1000 - 10 - _y2, _x2+520, 1000 - 10 - _y2 );
        
    }
    ofPopStyle();
    
}



//--------------------------------------------------------------
void PathData::score2DTriggerDraw(float _l, float _r, float _f){
    
    vector<float> _degreeSort = valueDegree;
    std::sort(_degreeSort.begin(), _degreeSort.end(), minX);
    
    float _alpha = 140;
    float _lengthRatio = _f;
    float _degreeRatio = 8;
    
    ofPushStyle();
    
    for (int i=0; i<_degreeSort.size(); i++) {
        
        float _x2 = lengthPath[i] * 0.4;
        
        float _y2 = heightScreen - 80 - _degreeSort[i] * _degreeRatio;
        float _di = lineDirection[i];
        
//        cout << _degreeSort[i] << endl;
        
        float _baseFQ = 80;
        
        if (_di<0) {
            float _startL = pathPolyLines[i][0].length() * _lengthRatio + widthScreen * 0.5;
            for (int k=0; k>-(int)_x2; k--) {
                float _c = ofMap(k, -_x2, 0, 0, _alpha);
                if ((int)(_l - widthScreen * 0.5)==(k-(int)_startL)){
                    _c = 255;
                }
                score2D.setColor(k-(int)_startL, (int)_y2-512-_baseFQ, ofColor(255,_c));
//                for (int l=0; l<20; l++) {
//                    score2D.setColor(k-(int)_startL, _y2-512-_baseFQ-l+10, ofColor(255,255));
//                }
            }
        } else {
            float _startR = pathPolyLines[i][0].length() * _lengthRatio + widthScreen * 0.5;
            for (int k=0; k<(int)_x2; k++) {
                float _c = ofMap(k, 0, _x2, _alpha, 0);
                if ((int)(_r + widthScreen * 0.5)==(k+(int)_startR)){
                    _c = 255;
                }
                score2D.setColor(k+(int)_startR, (int)_y2-512-_baseFQ, ofColor(255,_c));
//                for (int k=0; k<5; k++) {
//                    score2D.setColor(_startR, _y2-512-_baseFQ-k+2, ofColor(255,255));
//                }
            }
        }
        
    }
    ofPopStyle();
    
    score2dTriggerImg.setFromPixels(score2D.getPixels(), widthScreen, 512, OF_IMAGE_COLOR_ALPHA);
    
}

//--------------------------------------------------------------
ofPixels PathData::spectrum2DMake(float _f){
    
    vector<float> _degreeSort = valueDegree;
    std::sort(_degreeSort.begin(), _degreeSort.end(), minX);
    
    
    float _alpha = 255;
    float _lengthRatio = _f;
    float _degreeRatio = 8;
    
    ofPushStyle();
    
    for (int i=0; i<_degreeSort.size(); i++) {
        
        float _x2 = lengthPath[i] * _lengthRatio;
        
        float _y2 = heightScreen - 80 - _degreeSort[i] * _degreeRatio;
        float _di = lineDirection[i];
        
        float _baseFQ = 80;
        
        if (_di<0) {
            float _startL = pathPolyLines[i][0].length() * _lengthRatio + widthScreen * 0.5;
            for (int i=0; i>-_x2; i--) {
                float _c = ofMap(i, -_x2, 0, 0, 255);
                pathPixels.setColor(i-(int)_startL, (int)_y2-512-_baseFQ, ofColor(_c));
                for (int k=0; k<5; k++) {
                    pathPixels.setColor(-_startL, _y2-512-_baseFQ-k+2, ofColor(255));
                }
            }
        } else {
            float _startR = pathPolyLines[i][0].length() * _lengthRatio + widthScreen * 0.5;
            for (int i=0; i<_x2; i++) {
                float _c = ofMap(i, 0, _x2, 255, 0);
                pathPixels.setColor(i+(int)_startR, (int)_y2-512-_baseFQ, ofColor(_c));
                for (int k=0; k<5; k++) {
                    pathPixels.setColor(_startR, _y2-512-_baseFQ-k+2, ofColor(255));
                }
            }
        }
        
    }
    ofPopStyle();
    
    return pathPixels;
    
    
}


//--------------------------------------------------------------
vector<ofVec3f> PathData::curveFomulaCal(ofVec3f _a, ofVec3f _b, ofVec3f _c, ofVec3f _d) {
    
    vector<ofVec3f> _vtest;
    
    float _eps = 0.09;
    ofVec3f controlPoint1 = _b;
    ofVec3f controlPoint2 = _d;
    
    float paramA = _d.normalize().dot(_b.normalize());
    float paramC = (_c-_a).normalize().dot((_c-_a).normalize());
    float paramD = _d.normalize().dot(_b.cross((_c-_a).normalize()));
    
    ofVec3f perp = _b.cross(_d);
    
    if ( std::abs(paramC) < _eps || (std::abs(paramA-1) < _eps && std::abs(paramD/paramC) < _eps) || (std::abs(perp.dot(perp)) < _eps)) {        
        _vtest.clear();
        _vtest.push_back( _a );
        _vtest.push_back( _c );
        
    } else {
        _vtest.clear();
        
        for(int i=0; i<lineStep; i++) {
            
            float t = (float)i/(lineStep-1);
            
            // calculate blending functions
            float b0 =  2*t*t*t - 3*t*t + 1;
            float b1 = -2*t*t*t + 3*t*t;
            float b2 = t*t*t - 2*t*t + t;
            float b3 = t*t*t - t*t;
            
            // calculate the x,y and z of the curve point
            float x = b0*_a.x + b1*_c.x + b2*controlPoint1.x + b3*controlPoint2.x ;
            float y = b0*_a.y + b1*_c.y + b2*controlPoint1.y + b3*controlPoint2.y ;
            float z = b0*_a.z + b1*_c.z + b2*controlPoint1.z + b3*controlPoint2.z ;
            
            _vtest.push_back( ofVec3f(x,y,z) );
            
        }
    }
    
    return _vtest;
    
}




//--------------------------------------------------------------
float PathData::lineDirectionCal( vector<ofVec3f> _v ){
    
    float _fDirection = 0;
    
    float _d = _v[_v.size()-1].z - _v[0].z;
    
    if (_d <= 0) {
        return _fDirection = -1;
    } else {
        return _fDirection = 1;
    }
    
}


//--------------------------------------------------------------
float PathData::lengthCal( vector<ofVec3f> _v ){
    
    float _fLength = 0;
    
    if (_v.size()==2) {
        return _fLength = abs((_v[1]-_v[0]).length());
    } else {
        for(int i=0; i<_v.size()-1; i++) {
            float _f = abs((_v[i+1]-_v[i]).length());
            _fLength = _fLength + _f;
        }
        return _fLength;
    }
    
}


//--------------------------------------------------------------
float PathData::degreeCal( vector<ofVec3f> _v ){
    
    float _fDegree = 0;
    
    if (_v.size()==2) {
        return _fDegree = 0;
    } else {
        for(int i=0; i<_v.size()-1; i++) {
            
            float fA = sqrt( _v[i+1].x * _v[i+1].x + _v[i+1].y * _v[i+1].y + _v[i+1].z * _v[i+1].z );
            float fB = sqrt( _v[i].x * _v[i].x + _v[i].y * _v[i].y + _v[i].z * _v[i].z );
            float fDot = _v[i+1].x * _v[i].x + _v[i+1].y * _v[i].y + _v[i+1].z * _v[i].z;
            
            float _f = acos(fDot/(fA*fB)) * 180 / PI;
            return _fDegree = abs(_fDegree + _f);
            
        }
        
    }
    
}

//--------------------------------------------------------------
float PathData::twoPointsDegreeCal( vector<ofVec3f> _v ){
    
    float _fDegree = 0;
    
    if (_v.size()==2) {
        return _fDegree = 0;
    } else {
        
        float fA1 = sqrt( _v[1].x * _v[1].x + _v[1].y * _v[1].y + _v[1].z * _v[1].z );
        float fB1 = sqrt( _v[0].x * _v[0].x + _v[0].y * _v[0].y + _v[0].z * _v[0].z );
        float fDot1 = _v[1].x * _v[0].x + _v[1].y * _v[0].y + _v[1].z * _v[0].z;
        float _f1 = acos(fDot1/(fA1*fB1)) * 180 / PI;
        
        int _num = _v.size()-1;
        float fA2 = sqrt( _v[_num].x * _v[_num].x + _v[_num].y * _v[_num].y + _v[_num].z * _v[_num].z );
        float fB2 = sqrt( _v[_num-1].x * _v[_num-1].x + _v[_num-1].y * _v[_num-1].y + _v[_num-1].z * _v[_num-1].z );
        float fDot2 = _v[_num].x * _v[_num-1].x + _v[_num].y * _v[_num-1].y + _v[_num].z * _v[_num-1].z;
        float _f2 = acos(fDot2/(fA2*fB2)) * 180 / PI;
        
        return _fDegree = abs(_f1) + abs(_f2);
        
        
    }
    
}



//--------------------------------------------------------------
void PathData::curveFomulaDraw( vector<ofVec3f> _v ){
    
    int _index = _v.size();
    
    glBegin(GL_LINE_STRIP);
    
    for (int i=0; i<_index; i++) {
        glColor4ub( 255, 255, 255, 220 );
        glVertex3f( _v[i].x, _v[i].y, _v[i].z );
    }
    
    glEnd();
    
}


//--------------------------------------------------------------
void PathData::pathPolyLineSetup(){
    
    pathPolyLines.clear();
    for (int i=0; i<pathResult.size(); i++){
        ofPolyline _p;
        _p.setClosed(false);
        for (int j=0; j<pathResult[i].size(); j++){
            _p.addVertex( pathResult[i][j].x, pathResult[i][j].y, pathResult[i][j].z );
        }
        pathPolyLines.push_back(_p);
        
    }
    
}


//--------------------------------------------------------------
void PathData::pathPolyLineDraw(){
    
    ofPushStyle();
    ofSetLineWidth(0.1);
    
    for (int i=0; i<pathPolyLines.size(); i++) {
        if (pathPolyLines[i].size()==2) {
            ofSetColor( 255,0,0, 160);
        } else {
            ofSetColor( 255,0,0, 200);
        }
        pathPolyLines[i].draw();
    }
    
    ofPopStyle();
    
}



//--------------------------------------------------------------
void PathData::particleMoving(float _f){
    
    ofPushStyle();
    
    float _alpha = 100;
    
    
    for(int i=0; i<pathPolyLines.size(); i++) {

        float _length = _f - glm::length(pathPolyLines[i][0]);
        
        ofVec3f _pos = pathPolyLines[i].getPointAtLength(_length);

        vector<glm::vec3> _tempPath = pathPolyLines[i].getVertices();
        
        int _indexChange;
        if (_tempPath.size()==2) _indexChange = 1;
        else _indexChange = lineStep - 1;
        
        if ( _f > glm::length(_tempPath[_indexChange]) ) {
            ofSetColor( 32, 48, 80, _alpha*0.5 );
            _pos = _tempPath[_indexChange];
        } else if ( _f < glm::length(pathPolyLines[i][0]) ) {
            ofSetColor( 240, 184, 161, _alpha*0.5 );
        } else {
            ofSetColor( 240, 248, 255, _alpha );
        }
        
        sphereElement.setPosition(_pos);
        sphereElement.draw();
        
    }
    
    ofPopStyle();
    
    
}


//--------------------------------------------------------------
void PathData::movingPointMeshUpdate(float _f){
    
    for (int i=0; i<pathPolyLines.size(); i++) {
        float _length = _f - pathPolyLines[i][0].length();
        
        ofVec3f _pos;
        _pos = pathPolyLines[i].getPointAtLength(_length);
        vector<glm::vec3> _tempPath = pathPolyLines[i].getVertices();
        
        if (_f>pathPolyLines[i][pathPolyLines[i].size()-1].length()) {
            _pos = _tempPath[pathPolyLines[i].size()-1];
        }
        
        movingPos = _pos;
        movingPointMesh.setVertex(i, _pos);
        
    }
    
}


//--------------------------------------------------------------
void PathData::polarPosition(){
    
    movingPointMesh.clear();
    
    point3D.resize(pathResult.size());
    
    for (int i = 0; i < pathResult.size(); i++){
        
        ofVec3f _point3D = ofVec3f( pathResult[i][0].x, pathResult[i][0].y, pathResult[i][0].z );
        movingPointMesh.addVertex(_point3D);
        
        ofColor _c = ofColor(255);
        movingPointMesh.addColor(_c);
        
    }
    
    float distance = 50;
    
    int numVerts = movingPointMesh.getNumVertices();
    for (int a = 0; a<numVerts; a++) {
        ofVec3f verta = movingPointMesh.getVertex(a);
        for (int b = a + 1; b<numVerts; b++) {
            ofVec3f vertb = movingPointMesh.getVertex(b);
            float _distanceM = verta.distance(vertb);
            if (_distanceM <= distance) {
                movingPointMesh.addIndex(a);
                movingPointMesh.addIndex(b);
            }
        }
    }
    
}



//--------------------------------------------------------------
void PathData::creatorSetting(){
    
    int _circleStep = (int)(360/creatorResolution);
    
    for (int i=0; i<point3D.size(); i++) {
        point3D[i].radiusCreater = 10;
        
        point3D[i].p1 = ofVec3f(0,0,0);
        point3D[i].p2 = movingPointMesh.getVertex(i);
        point3D[i].createrMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
        
        point3D[i].norm = (point3D[i].p2 - point3D[i].p1).normalize();
        
        point3D[i].u = point3D[i].norm.crossed(ofVec3f(1, 0, 0));
        point3D[i].v = point3D[i].norm.crossed(point3D[i].u);
        
        for (int t = 0; t <= 360+_circleStep; t+=_circleStep) {
            float _rad = ofDegToRad(t);
            ofVec3f pt = point3D[i].p2 + point3D[i].radiusCreater * cos(_rad) * point3D[i].u + point3D[i].radiusCreater * sin(_rad) * point3D[i].v;
            ofColor _c = ofColor(255,70);
            point3D[i].createrMesh.addColor(_c);
            point3D[i].createrMesh.addVertex(pt);
        }
    }
    
    for (int i=0; i<point3D.size(); i++) {
        point3D[i].vboCreator.enableColors();
        point3D[i].vboCreator.enableIndices();
        point3D[i].vboCreator.setMesh(point3D[i].createrMesh, GL_STATIC_DRAW);
    }
    
}


//--------------------------------------------------------------
void PathData::creatorDraw(){
    
    ofPushStyle();
    
    for (int i=0; i<point3D.size(); i++) {
        ofPushMatrix();
        //        ofTranslate(point3D[i].p2);
        point3D[i].vboCreator.draw(GL_LINE_STRIP, 0, creatorResolution+1);
        //        point3D[i].createrMesh.draw();
        ofPopMatrix();
    }
    
    ofPopStyle();
    
}

//--------------------------------------------------------------
void PathData::creatorUpdate(float _f){
    
    float _alpha = 130;
    int _circleStep = (int)(360/creatorResolution);
    
    for (int i=0; i<pathPolyLines.size(); i++) {
        float _length = _f - pathPolyLines[i][0].length();
        ofVec3f _pos = pathPolyLines[i].getPointAtLength(_length);
        
        vector<glm::vec3> _tempPath = pathPolyLines[i].getVertices();
        
        if (_f>_tempPath[pathPolyLines[i].size()-1].length()) {
            for (int t=0; t<=creatorResolution; t+=1) {
                point3D[i].createrMesh.setColor(t, ofColor(32, 48, 80, _alpha));
            }
            _pos = _tempPath[pathPolyLines[i].size()-1];
        } else if (_f < pathPolyLines[i][0].length()) {
            for (int t=0; t<=creatorResolution; t+=1) {
                point3D[i].createrMesh.setColor(t, ofColor( 240, 184, 161, _alpha ));
            }
            point3D[i].radiusCreater = 0;
        } else {
            for (int t=0; t<=creatorResolution; t+=1) {
                point3D[i].createrMesh.setColor(t, ofColor( 240, 184, 161, _alpha ));
            }
            point3D[i].radiusCreater = _pos.length()*0.07;
        }
        
        
        point3D[i].p1 = ofVec3f(0,0,0);
        point3D[i].p2 = _pos;
        point3D[i].norm = (point3D[i].p2 - point3D[i].p1).normalize();
        point3D[i].u = point3D[i].norm.crossed(ofVec3f(1, 0, 0));
        point3D[i].v = point3D[i].norm.crossed(point3D[i].u);
        
        for (int t = 0; t <= creatorResolution; t+=1) {
            float _rad = ofDegToRad(t*_circleStep);
            ofVec3f pt = point3D[i].p2 + point3D[i].radiusCreater * cos(_rad) * point3D[i].u + point3D[i].radiusCreater * sin(_rad) * point3D[i].v;
            point3D[i].createrMesh.setVertex(t, pt);
        }
        
        point3D[i].vboCreator.updateMesh(point3D[i].createrMesh);
        
    }
    
    
    
}

