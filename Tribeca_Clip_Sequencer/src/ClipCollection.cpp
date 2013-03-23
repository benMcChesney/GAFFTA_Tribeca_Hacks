//
//  ClipCollection.cpp
//  Tribeca_Clip_Sequencer
//
//  Created by Ben McChesney on 3/22/13.
//
//

#include "ClipCollection.h"

void ClipCollection::setup ( string dirPath )
{
    currentIndex = 0 ;
    
    ofDirectory dir ;
    dir.listDir( dirPath ) ;
    
    clips.assign( dir.size() , ArchiveClip() ) ;
    
    //cout << "clip folder : " << dirPath << " now has : " << clipsRef->size() << " in it's vector " << endl ;
    for ( int i = 0 ; i < dir.size() ; i++ )
    {
        cout << "loading : " << dir.getPath( i ) << endl ; 
        clips[i].setup( dir.getPath( i ) ) ;
    }
    
    //clips[currentIndex].play( ) ;
    //clips[nextIndex].play( ) ;
    clips[0].loadFromPath()  ; 
    clipCutOff = 0.98f ;
    setClipSpeed( 1.0f ) ;
}

void ClipCollection::thaw ( )
{
    cout << "currentIndex is : " << currentIndex << endl ;
    clips[currentIndex].loadFromPath( ) ;
    cout << "loading happened ! " << endl;
    clips[currentIndex].firstFrame() ; 
    clips[currentIndex].play() ;
    
 //   clips[currentIndex].play( ) ;
   // transitionToNext() ;
}

void ClipCollection::freeze( )
{
    cout << "FREEZE BEGIN : " << currentIndex <<" is currentIndex " << endl ;
    clips[currentIndex].stop() ;
    clips[currentIndex].close() ;
    
    bool bOk = false ;
    while ( bOk == false )
    {
        int _nextIndex = ofRandom( 0 , (clips.size()-1) ) ;
        if ( _nextIndex != currentIndex )
        {
            bOk = true ;
            currentIndex = _nextIndex ;
        }
    }
}

void ClipCollection::remix( int touchId )
{
    //return;
   // cout << "TOUCH ID : " << touchId << endl ;
    float ratio = 0.25f / clips[currentIndex].getDuration() ;
    float offset = -ratio ;
    //if ( touchId < 0 )
    //    offset = -0.05f ;
    
    float position = clips[currentIndex].getPosition() ;
    position += offset ;
    if ( position < 0.0f )
        position = 0.0f ;
    if ( position > 1.0f )
        position = 1.0f ; 
    
    
    clips[currentIndex].setPosition( position ) ;
}

void ClipCollection::update ( )
{

    clips[ currentIndex ].update( ) ;
    //for ( int i = 0 ; i < clips.size() ; i++ )
    //{
//    }
    
    float leftoverThreshold = 0.25f ; //seconds
    
    //Get how many seconds are left...
    //float timeLeft = (1.0f -clips[currentIndex].getPosition()) * clips[currentIndex].getDuration() ;
    
    //cout << "clip CUT OFF " << clipCutOff << endl ;
    if ( clipCutOff >= 0.6 )
    {
        
        float _clipCutOff = 0.5 / clips[currentIndex].getDuration() ;
        if ( clips[currentIndex].getPosition()   > _clipCutOff )
        {
            //cout << " duration : " <<clips[currentIndex].getDuration() << endl ;
            //cout << "TILTING ! " << _clipCutOff << endl ;
            transitionToNext( ) ;
        }
        //float ratio = 0.25f / clips[currentIndex].getDuration() ;
        //float offset = -ratio ;
        
    }
    else if ( clips[currentIndex].getPosition() >= 0.98 )
    {
        //cout << "TRANSITIONING TO NEXT VIA UPDATE : !"  << endl ;
        //cout << "currentIndex " << currentIndex << " vs cutOff " << clipCutOff << endl ;
        transitionToNext( ) ;
    }
   // clips[nextIndex].update( ) ;
}

void ClipCollection::draw ( )
{

 //   for ( int i = 0 ; i < clips.size() ; i++ )
 //   {
        clips[ currentIndex ].draw( ) ;
 //   }
}

void ClipCollection::setClipSpeed ( float _clipSpeed )
{
    //for ( int i = 0 ; i < clips.size() ; i++ )
    //{
        
      //  clips[i].setSpeed( clipSpeed ) ;
    //}
    clipSpeed = _clipSpeed ; 
    //clips[currentIndex].setSpeed( clipSpeed ) ;
    //clips[currentIndex].update() ;
   // clips[nextIndex].setSpeed( clipSpeed ) ;
}


void ClipCollection::transitionToNext( )
{
   if ( clips[currentIndex].alpha != 255 ) return ;
    
    clips[currentIndex].alpha = 0 ;
    clips[currentIndex].stop() ;
    clips[currentIndex].close() ;
    
    //cout << "currentIndex : " << currentIndex << " vs clips.size() " << clips.size() << endl ;
    //Tweenzor::add( &clips[currentIndex].alpha , clips[currentIndex].alpha , 0.0f , 0.0f , 0.5f , EASE_OUT_QUAD ) ;
    
    bool bOk = false ;
    while ( bOk == false )
    {
        int _nextIndex = ofRandom( 0 , (clips.size()) ) ;
        if ( _nextIndex != currentIndex )
        {
            bOk = true ;
            currentIndex = _nextIndex ;
        }
    }
    //ofQTKitDecodeMode decodeMode = OF_QTKIT_DECODE_TEXTURE_ONLY;
    
//    return ;
    clips[currentIndex].loadFromPath( ) ;
    clips[currentIndex].firstFrame() ;
   // clips[currentIndex].setSpeed( clipSpeed) ;
    clips[currentIndex].play( ) ;
    
    clips[currentIndex].alpha = 255 ; 
    //Tweenzor::add( &clips[currentIndex].alpha , clips[currentIndex].alpha , 255.0f , 0.0f , 0.5f , EASE_OUT_QUAD ) ;
   // Tweenzor::add( &clips[currentIndex].alpha , clips[currentIndex].alpha , 0.0f , 0.0f , 0.5f , EASE_OUT_QUAD ) ;
}
