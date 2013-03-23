//
//  ArchiveClip.cpp
//  Tribeca_Clip_Sequencer
//
//  Created by Ben McChesney on 3/21/13.
//
//

#include "ArchiveClip.h"

void ArchiveClip::setup ( string videoPath )
{
    alpha = 255.0f ;
    setPixelFormat(OF_PIXELS_RGB );
    ofQTKitDecodeMode decodeMode = OF_QTKIT_DECODE_TEXTURE_ONLY;
    path = videoPath ;
}

void ArchiveClip::loadFromPath( )
{
    loadMovie( path , OF_QTKIT_DECODE_TEXTURE_ONLY ) ;
    w = getWidth() ;
    h = getHeight() ;
    firstFrame() ;
}

void ArchiveClip::update ( )
{
    if ( isPlaying() )
    {
        ofQTKitPlayer::update( ) ;
    }
}

void ArchiveClip::draw ( )
{
    if( isPlaying() && alpha > 0.0f )
    {
        ofSetColor( 255 , alpha ) ;
        ofQTKitPlayer::draw( -w/2 , -h/2 ) ;
    }
}
