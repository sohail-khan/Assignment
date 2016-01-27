// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Culling.h"
#include "Geometry.h"
#include "VectorMathDecl.h"
#include "IndexBufferRangeMerger.h"

#include <vector>

namespace Eegeo
{
    namespace Culling
    {
        class CullingVolumeVisibilityUpdater
        {
        private:
            struct StackEntry
            {
                int cullingVolumeIndex;
                uint inactivePlaneFlags;
            };

            std::vector<StackEntry> m_stack;
            
            const static int maxRanges = 128;
            IndexBufferRangeMerger<maxRanges> m_rangeMerger;
            
            void ComputeVisibleRangesInTreeScaled(const CullingVolumeTree& cullingVolumeTree, const Geometry::Frustum& frustum, v3 cameraRelativeOrigin, float scale);
            
            void ComputeVisibleRangesInTree(const CullingVolumeTree& cullingVolumeTree, const Geometry::Frustum& frustum, v3 cameraRelativeOrigin);
            
        protected:
            virtual void ComputeVisibleRangesScaled(const CullingVolumeTree& cullingVolumeTree, const dv3& cameraEcefOrigin, const Geometry::Frustum& frustum, std::vector<IndexBufferRange>& visibleRanges, float scale);
            
        public:
            CullingVolumeVisibilityUpdater();
            
            virtual ~CullingVolumeVisibilityUpdater() {;}
            
            virtual void ComputeVisibleRanges(const CullingVolumeTree& cullingVolumeTree, const dv3& cameraEcefOrigin, const Geometry::Frustum& frustum, std::vector<IndexBufferRange>& visibleRanges, float environmentScale);
        };
    }
}