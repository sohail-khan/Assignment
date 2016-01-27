// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IStreamingVolume.h"
#include "Frustum.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Streaming
    {
		class FrustumStreamingVolume : public Eegeo::Streaming::IStreamingVolume
		{
			Eegeo::Geometry::Frustum m_frustum;
			Eegeo::dv3 m_cameraEcefPos;

		public:

			FrustumStreamingVolume(
					const Eegeo::Geometry::Frustum& frustum,
					const Eegeo::dv3& cameraEcefPos);

			bool IntersectsKey(
					const Eegeo::Streaming::MortonKey& key,
					bool& canRefineIntersectedKey,
					double& intersectedNodeDepthSortSignedDistance);
		};
    }
}
