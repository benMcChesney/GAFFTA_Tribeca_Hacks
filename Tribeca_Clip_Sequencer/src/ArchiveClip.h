//
//  ArchiveClip.h
//  Tribeca_Clip_Sequencer
//
//  Created by Ben McChesney on 3/21/13.
//
//

#ifndef Tribeca_Clip_Sequencer_ArchiveClip_h
#define Tribeca_Clip_Sequencer_ArchiveClip_h

#include "ofMain.h"
#include "ofxTweenzor.h"

class ArchiveClip : public ofQTKitPlayer
{
    public :
        ArchiveClip( ) { }
        ~ArchiveClip( ) { } 
    
        void setup ( string videoPath ) ;
        void update ( ) ;
        void draw ( );

        string path ; 
        float alpha ;
        int w , h ;
    
        void loadFromPath ( ) ; 
};

#endif
