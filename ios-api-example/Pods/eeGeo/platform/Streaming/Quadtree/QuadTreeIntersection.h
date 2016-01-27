// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class QuadTreeIntersection
        {
        private:
            static void CellsIntersectingVolumeRecursive(MortonKey& currentCell, IStreamingVolume& streamingVolume, std::vector<MortonKey>& cellsIntersecting);
            static void CellsIntersectingVolumeUnrolled(int faceIndex, IStreamingVolume& streamingVolume, std::vector<MortonKey>& cellsIntersecting);
        public:
            static void CellsIntersectingVolume(IStreamingVolume& streamingVolume, std::vector<MortonKey>& cellsIntersecting);
        };
    }
}