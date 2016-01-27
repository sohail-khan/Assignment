// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "QuadTreeCube.h"

namespace Eegeo
{
    namespace Streaming
    {
        class LodStreamMap
        {
        private:
            IResourceStream* m_pResourceStreamsByDepth[QuadTreeCube::NUM_OF_DEPTHS];
            int m_lastOccupiedDepth;
			
        public:
            LodStreamMap();
            
            LodStreamMap(IResourceStream& stream);
            
            IResourceStream* pStreamAtDepth(int depth) const;
        
            bool depthIsLastOccupied(int depth) const;
        };
    }
}
