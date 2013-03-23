//
//  ClipCollection.h
//  Tribeca_Clip_Sequencer
//
//  Created by Ben McChesney on 3/22/13.
//
//

#ifndef __Tribeca_Clip_Sequencer__ClipCollection__
#define __Tribeca_Clip_Sequencer__ClipCollection__

#include "ofMain.h"
#include "ArchiveClip.h"
#include "Tweenzor.h"

class ClipCollection
{
    public :
        ClipCollection ( ) { }
        ~ClipCollection ( ) { }
    
        void setup ( string dirPath ) ;
        void update ( ) ;
        void draw ( ) ;
    
        void thaw ( ) ;
        void freeze( ) ;
    
        int currentIndex ;
        float clipSpeed ;
        float clipCutOff ; 
        //int nextIndex ;
    
        void transitionToNext( ) ;
        void remix( int touchId ) ;
    
        vector<ArchiveClip> clips ;
        void setClipSpeed ( float clipSpeed ) ;
    
      
    
};

#endif /* defined(__Tribeca_Clip_Sequencer__ClipCollection__) */
