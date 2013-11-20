#pragma once

#include "ofMain.h"
#include "ofxCinderTimeline.h"

// BasicTween via https://github.com/cinder/Cinder/tree/master/samples/_timeline/BasicTween
class BasicTweenApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);

    ofxCinderTimeline::Timeline& timeline() { return *mTimeline; }

private:
	std::shared_ptr<ofxCinderTimeline::Timeline> mTimeline;
    ofxCinderTimeline::Anim<ofPoint> mBlackPos, mWhitePos;
};
