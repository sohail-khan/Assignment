// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SingleSphere.h"
#include "Types.h"
#include "EarthConstants.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Culling
    {
        struct CullingVolume
        {
        public:
            Eegeo::Geometry::SingleSphere sphere;
            u32 startIndex;
            u32 numOfIndices;
            int firstChildIndex;
            int childCount;
            
            inline v3 CalcScaleTarget(const dv3& ecefOrigin, float& sphereCentreAltitude) const
            {
                dv3 ecefCentre(ecefOrigin);
                ecefCentre += sphere.centre;
                double ecefCentreLength = ecefCentre.Length();
                sphereCentreAltitude = static_cast<float>(ecefCentreLength - Eegeo::Space::EarthConstants::Radius);
                double scale = (Eegeo::Space::EarthConstants::Radius / ecefCentreLength);
                ecefCentre *= scale;
                ecefCentre -= ecefOrigin;
                return ecefCentre.ToSingle();
            }
                        
            inline bool isLeafNode() const
            {
                return childCount == 0;
            }
        };
    }
}