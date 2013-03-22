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

class ArchiveClip
{
    public :
        ArchiveClip( ) { }
        ~ArchiveClip( ) { }
    
    
        void setup ( string videoPath , float direction ) ;
        void update ( ) :
        void draw ( ) ;
        
        float alpha ;
        
};

#endif
