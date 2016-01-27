// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Streaming.h"
#include "Camera.h"
#include "VectorMathDecl.h"
#include "Geometry.h"
#include "DebugRendering.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class StreamingVolumeController : public Eegeo::NonCopyable
        {
        private:
            
            CameraFrustumStreamingVolume& m_streamingVolume;

            DebugRendering::DebugRenderer& m_debugRenderer;
            
        public:
            static const double CAMERA_ALTITUDE_TO_FAR_PLANE_DISTANCE_MULTIPLIER;
            static const double MIN_STREAMING_FAR_PLANE_DISTANCE;
            
            StreamingVolumeController(CameraFrustumStreamingVolume& streamingVolume,
                                      DebugRendering::DebugRenderer& debugRenderer)
            : m_streamingVolume(streamingVolume)
            , m_debugRenderer(debugRenderer)
            {
            }
            
            void Update(const Camera::RenderCamera& renderCamera);
            
            void RenderStreamingFrustum();

            void updateStreamingFrustum(
					Geometry::Frustum &frustum,
					const Eegeo::m44& viewProjection,
					const dv3& cameraEcefLocation) const;
        private:
            
            void updateStreamingFrustumPlanes(
            		std::vector<Geometry::Plane> &frustumPlanes,
            		const Eegeo::m44& viewProjection,
            		const dv3& cameraEcefLocation) const;
        };
    }
}
