#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	ofBackground(225, 225, 225);
	ofSetCircleResolution(80);
    ofSetLogLevel(OF_LOG_VERBOSE);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	arrow.loadImage("arrow.png");
	arrow.setAnchorPercent(1.0, 0.5);
    
    sender.setup( "localHost"  , 98765 );
}


//--------------------------------------------------------------
void testApp::update()
{
    if( ofGetFrameNum() % 120 == 0 ){
		ofxOscMessage m;
		m.setAddress( "/misc/heartbeat" );
		m.addIntArg( ofGetFrameNum() );
		sender.sendMessage( m );
	}
    ofxOscMessage m ;
    m.setAddress( "accel" ) ;
    m.addFloatArg(  ofxAccelerometer.getForce().x ) ;
    m.addFloatArg(  ofxAccelerometer.getForce().y ) ;
    sender.sendMessage( m ) ; 
//    oscSender.sendMessage( m ) ;
    /*
    ofLog(OF_LOG_VERBOSE, "x = %f, y = %f", ofxAccelerometer.getForce().x, ofxAccelerometer.getForce().y);
     */
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(54);
	ofDrawBitmapString("Multitouch and Accel Example", 10, 20);

	float angle = 180 - RAD_TO_DEG * atan2( ofxAccelerometer.getForce().y, ofxAccelerometer.getForce().x );

	ofEnableAlphaBlending();
	ofSetColor(255);
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
		ofRotateZ(angle);
		arrow.draw(0,0);
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d down at (%d,%d)", touch.id, touch.x, touch.y);
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d moved at (%d,%d)", touch.id, touch.x, touch.y);
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d up at (%d,%d)", touch.id, touch.x, touch.y);
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d double tap at (%d,%d)", touch.id, touch.x, touch.y);
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

