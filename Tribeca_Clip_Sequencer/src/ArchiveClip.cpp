//
//  ArchiveClip.cpp
//  Tribeca_Clip_Sequencer
//
//  Created by Ben McChesney on 3/21/13.
//
//

#include "ArchiveClip.h"

void ArchiveClip::setup ( string videoPath , float direction )
{
    alpha = 255.0f ; 
}

void ArchiveClip::update ( )
{
    if ( vid.isPlaying() )
    {
        vid.update( ) ;
    }
}

void ArchiveClip::draw ( )
{
    if( vid.isPlaying() )
    {
        ofSetColor( 255 , alpha ) ;
        vid.draw( 0 , 0 , ofGetWidth() , ofGetHeight() ) ; 
    }
}
