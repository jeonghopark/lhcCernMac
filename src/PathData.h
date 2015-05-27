//
//  PathData.h
//  lhc_data_01
//
//  Created by JeongHo Park on 28.11.14.
//
//

#ifndef __lhc_data_01__PathData__
#define __lhc_data_01__PathData__

#include "ofMain.h"

typedef struct{
    
    ofVec3f degree3D;
    
    ofVec3f point3DRaw;
    
    ofVec3f p1;
    ofVec3f p2;
    
    ofVec3f norm;
    
    ofVec3f u; //x axis unit vector
    ofVec3f v;
    
    ofMesh createrMesh;
    float radiusCreater;
    ofVbo vboCreator;
    
    float theta;
    float phi;
    float radius;
    
    ofMesh createrPath;
    float createrPathRadius;
    
    ofVec3f p1Path;
    ofVec3f p2Path;
    
    ofVec3f normPath;
    
    ofVec3f uPath; //x axis unit vector
    ofVec3f vPath;

    
    
} Point3D;


class PathData{
    
public:

    PathData();
    
    void setup( ofVec3f _a, ofVec3f _b, ofVec3f _c, ofVec3f _d );
    void close();
    
    float pointScale;
    float pointScaleDir;
    
    void setup( vector<ofVec3f> _a, vector<ofVec3f> _b, vector<ofVec3f> _c, vector<ofVec3f> _d );
    vector<ofVec3f> curveFomulaCal( ofVec3f _a, ofVec3f _b, ofVec3f _c, ofVec3f _d );
    void curveFomulaDraw( vector<ofVec3f> _v );

    vector < vector<ofVec3f> > pathResult;
    
    void curveDraw();
    
    float lengthCal( vector<ofVec3f> _v );
    vector<float> lengthPath;
    void histoDraw();

    float degreeCal( vector<ofVec3f> _v );
    vector<float> valueDegree;
    void degreeDraw();

    float twoPointsDegreeCal( vector<ofVec3f> _v );
    vector<float> twoPointsDegree;

    
    vector<ofVec3f> startPosition;
    
    float widthScreen;
    float heightScreen;
    
    float lineDirectionCal( vector<ofVec3f> _v );
    vector<float> lineDirection;
    void curveAndLength();
    void score2DTriggerDraw(float _l, float _r, float _f);

    void energyDraw();
    
    ofPixels capturePixels;
    ofPixels spectrum2DMake(float _f);

    ofPixels pathPixels;
    ofPixels score2D;
    ofImage score2dImg;
    ofImage score2dTriggerImg;

    vector<ofPolyline> pathPolyLines;
    void pathPolyLineSetup();
    void pathPolyLineDraw();
    
    void particleMoving(float _f);
    
    ofSpherePrimitive sphereElement;
    
    ofVec3f movingPos;
    float radius;
    
    ofMesh movingPointMesh;
    void movingPointMeshUpdate(float _f);

    vector<Point3D> point3D;
    void polarPosition();
    void creatorSetting();
    void creatorUpdate(float _f);
    void creatorDraw();
    
    vector<ofVec3f> pointMoving;
    int creatorResolution;
    
    int lineStep;
    
};


#endif /* defined(__lhc_data_01__PathData__) */
