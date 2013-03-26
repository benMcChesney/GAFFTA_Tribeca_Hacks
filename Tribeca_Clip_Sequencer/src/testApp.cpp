#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    Tweenzor::init( ) ;
    
    ofBackground( 0, 0, 0) ;
    ofSetLogLevel( OF_LOG_VERBOSE ) ;
    
    collections.assign ( 5 , ClipCollection() ) ;
    
    collections[0].setup( "UP" ) ;
    collections[1].setup( "DOWN" ) ;
    collections[2].setup( "LEFT" ) ;
    collections[3].setup( "RIGHT" ) ;
    collections[4].setup( "STILL" ) ;
   // collections[4].bRepeatOne = true ;
    
    osc.setup( 12345 ) ;
    ofSetFrameRate( 30 ) ;
    
    direction = NORTH ; 
    collections[(int)direction].thaw( ) ;
}

//--------------------------------------------------------------
void testApp::update(){
    
   Tweenzor::update( ofGetElapsedTimeMillis() )  ;
    lastDirection = direction ;
    ofSetWindowTitle( "@" + ofToString( ofGetFrameRate() ) + " FPS " ) ;
    
    float maxSpeed = 0.25f ;
    float minSpeed = 0.95f ;
    
    float accSpeed = collections[(int)direction].clipSpeed ;
    while ( osc.hasWaitingMessages() )
    {
        ofxOscMessage m ;
        osc.getNextMessage( &m ) ;
        
        float deadZone = 0.25;
        
        if ( m.getAddress() == "/accel" )
        {
            float accelX = m.getArgAsFloat( 0 ) ;
            float accelY = m.getArgAsFloat( 1 ) ;
            
            float largerDir ; 
            if ( abs(accelX) > abs(accelY) )
            {
                accSpeed = accelX ;
                if ( accelX > 0 )
                {
                    direction = SOUTH ;
                }
                else
                {
                    direction = NORTH ;
                }
                accSpeed = ofMap ( abs(accelX) , deadZone , 1.0f , minSpeed , maxSpeed , true ) ;
                largerDir = accelX ; 
            }
            else
            {
                accSpeed = accelY ;
                if ( accelY < 0 )
                {
                    direction = EAST ;
                }
                else
                {
                    direction = WEST ;
                }
                accSpeed = ofMap ( abs(accelY) , deadZone , 1.0f , minSpeed , maxSpeed , true ) ;
                largerDir = accelY ;
            }
            if ( abs ( largerDir ) <= deadZone )
            {
                direction = STILL ;
            }
        }
        
        
        collections[ (int)direction ].clipCutOff = 1.0f - abs(accSpeed) ;
        
              
        if ( m.getAddress() == "/remix" )
        {
            collections[ (int)direction ].remix( m.getArgAsInt32( 0 ) ) ;
        }
    }
    
    if ( lastDirection - direction != 0 )
    {
        cout << lastDirection << " - " << direction << " = " << ( lastDirection - direction ) << endl ;
        collections[ (int)lastDirection ].freeze() ;
        cout<< "FREEZE COMPLETE " << endl ;
        collections[ (int)direction ].thaw( ) ;
        cout << "THAW COMPLETE " << endl ;
    }

    
    collections[ (int)direction ].update( ) ;
 
}

//--------------------------------------------------------------
void testApp::draw(){
    stringstream ss ;
    ss << "FACING : " << endl ;
    
    int currentCollection = (int)direction;
    
    ofPushMatrix() ;
        ofTranslate( ofGetWidth() / 2 , ofGetHeight() /2 ) ;
        ofScale ( 1.3, 1.3 ) ;
        collections[ (int)direction ].draw( ) ;
    ofPopMatrix() ;

    if ( direction == NORTH )
    {
        ss << "NORTH" ;
    }
    if ( direction == SOUTH )
    {
        ss << "SOUTH" ;
    }
    if ( direction == EAST )
    {
        ss << "EAST" ;
    }
    if ( direction == WEST )
    {
        ss << "WEST" ;
    }
    if ( direction == STILL )
    {
   //     ss << " STILL " ;
    } ;
        
    //ofDrawBitmapStringHighlight ( ss.str() , 15 , 15 ) ;
        
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
     lastDirection = direction ;
    
    cout << "key : " << key << endl ; 
    switch ( key )
    {
        case 'r':
        case 'R':
            collections[ (int)direction ].remix( 0 ) ;
            break ;
            
        case 356 :
            direction = EAST ;
            break ;
            
        case 357 :
            direction = NORTH ;
            break ;
        
        case 358 :
            direction = WEST ; 
            break ;
            
        case 359 :
            direction = SOUTH ;
            break ;
            
            
        default :
            direction = STILL ;
            break ; 
            
        
    }
    
    if ( lastDirection - direction != 0 )
    {
        cout << lastDirection << " - " << direction << " = " << ( lastDirection - direction ) << endl ;
        collections[ (int)lastDirection ].freeze() ;
        cout<< "FREEZE COMPLETE " << endl ;
        collections[ (int)direction ].thaw( ) ;
        cout << "THAW COMPLETE " << endl ;
    }

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