// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "MortonKey.h"

namespace Eegeo
{    
    namespace Streaming
    {
        struct QuadTreeNodeVisitParams
        {
            QuadTreeNodeVisitParams():key(0) {}
            
            MortonKey key;
            QuadTreeNode* parentNode;
            QuadTreeNode* node;
            uint slotsAboveInSceneGraph;
        };
    }
}