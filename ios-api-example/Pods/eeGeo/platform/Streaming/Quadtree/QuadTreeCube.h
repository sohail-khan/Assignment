// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class QuadTreeCube : protected Eegeo::NonCopyable
        {
        public:
            static const int MAX_DEPTH_TO_VISIT = 14;
            static const int NUM_OF_DEPTHS = MAX_DEPTH_TO_VISIT + 1;
            
        private:
            QuadTreeNodePool *m_pNodePool;
    		PayloadPool *m_pPayloadPool;
            
        public:
            std::vector<QuadTreeNode*> faceRootNodes;
            
            QuadTreeCube(PayloadPool *pPayloadPool, QuadTreeNodePool *pNodePool);

            ~QuadTreeCube();
        };
    }
}
