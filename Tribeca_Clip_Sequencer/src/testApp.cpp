#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    dir.listDir( "bucket" ) ;
    
    cout << " dir.size() " << dir.size() << endl ;
    
    for ( int i = 0 ; i < dir.size() ; i++ )
    {
        string name = dir.getName( i ) ;
        int underscoreIndexFirst = name.find("_", 0 ) ;
        int underscoreIndexSecond = name.find("_", underscoreIndexFirst + 1 ) ;
        string underFirst = ofToUpper(name.substr( underscoreIndexFirst+1 , 1 )) ;
        string underSecond = ofToUpper(name.substr( underscoreIndexSecond+1 , 1 )) ;
        cout << "FIRST " << underFirst << " SECOND " << underSecond << " out of NAME " << name << endl ;
        bool bHorizontal = true ;
        if ( underFirst.compare( "V" ) == 0 )
            bHorizontal = false ;
        
        if ( bHorizontal == false )
        {
            float vSpeed = -1 ;
            if ( underSecond == "N" )
            {
                vSpeed = 1 ;
            }
            ArchiveClip * clip = new ArchiveClip( ) ;
            clip->setup( dir.getPath( i ) , vSpeed ) ;
            verticalClips.push_back( clip ) ;
        }
        else
        {
            float hSpeed = -1 ;
            if ( underSecond == "E" )
                hSpeed = 1 ;
            
            ArchiveClip * clip = new ArchiveClip( ) ;
            clip->setup( dir.getPath( i ) , hSpeed ) ;
            horizontalClips.push_back( clip ) ; 
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}