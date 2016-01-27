//  Copyright (c) 2015 eeGeo. All rights reserved.
#pragma once

#include "Types.h"
#include "BlockCoverageTrees.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        namespace BlockCoverageTrees
        {
            class BlockCoverageTreeCube: protected Eegeo::NonCopyable
            {
            public:
                BlockCoverageTreeCube();
                ~BlockCoverageTreeCube();
                
                bool HasCoverageFor(const MortonKey& mortonKey) const;
                
                void SetBlockCoverageTreeForFace(int face, const std::vector<u64>& blocks);

            private:
                static const int CubeFaceCount = 6;
                
                bool FaceEmpty(int faceIndex) const
                {
                    return ((1 << faceIndex) & m_hasFaceMask) == 0;
                }
                
                Byte m_hasFaceMask;
                
                std::vector<u64> m_cubeFaces[6];
            };
        }
    }
}