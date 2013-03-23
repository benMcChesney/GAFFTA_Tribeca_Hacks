#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxTweenzor.h"
#include "ClipCollection.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector<ClipCollection> collections ;
    /*
        vector<ArchiveClip*> northClips ;
        vector<ArchiveClip*> southClips ;
        vector<ArchiveClip*> eastClips ;
        vector<ArchiveClip*> westClips ;
        vector<ArchiveClip*> stillClips ; */
    
//        void loadFolderOfClips( string dirPath , vector<ArchiveClip*> * clipsRef ) ;
    
    
//        int currentDirection ;
//        int lastDirection ;
    
        ofxOscReceiver osc ;
    
        enum ScrollingDirection
        {
            NORTH,
            SOUTH,
            EAST,
            WEST,
            STILL
        };
    
        ScrollingDirection lastDirection ; 
        ScrollingDirection direction ;
    
        
    
    
};
