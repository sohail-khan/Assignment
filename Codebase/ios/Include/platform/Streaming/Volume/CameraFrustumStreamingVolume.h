// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>

#include "Types.h"
#include "IStreamingVolume.h"
#include "Frustum.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Location.h"

namespace Eegeo
{
    namespace Streaming
    {            
        class CameraFrustumStreamingVolume : public IStreamingVolume
        {
        private:
            
            struct CameraFrustumStreamingVolumeQuadtreeNodeVisitParams
            {
                s64 nodeKeyRawValue;
                double nodeCentreX;
                double nodeCentreY;
                double halfToPowerOfDepth;
                int nodeDepth;
                double nodeHalfWidth;
                uint planeState;
                uint faceCentralNodeFlags;
            };
            
            const Eegeo::Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
            
            Eegeo::dv3 m_origin;
            Geometry::Frustum m_frustum;
            float m_fovRadians;
            Eegeo::v3 m_viewDirection;
            uint m_inactivePlaneFlags;
            int m_sphereTestsPerformed;
            int m_cylinderTestsPerformed;
            double m_sagittaAtCylinderTestMinNodeDepth;
            float m_ceilingHeight;
            double m_cellRefineDistance;
            double m_depthSortBias;
            int m_deepestLevelForAltitudeLodRefinement;
            
            
            Eegeo::dv3 m_cameraWorldPosition;
            Eegeo::dv3 m_cameraWorldPositionNormal;
            double m_viewDependentScale;
            float m_halfCeilingHeight;
            float m_earthRadiusPlusHalfCeiling;
            float m_earthRadiusPlusCeilingSq;
            float m_halfCeilingHeightSq;
            float m_cylinderHeight;
            float m_earthCentreToCylinderBase;
            double m_cameraAltitude;
            double m_cameraSpaceErrorDenominatorMult;
        
            
			int m_stackItemIndex;
            int m_currentMostDetailedLodLevel;
            std::vector<double> m_lodRefinementAltitudes;
            std::vector<CameraFrustumStreamingVolumeQuadtreeNodeVisitParams> m_stack;
            std::vector<double> m_visibilityThresholdsByDepth;
            
            bool m_forceMaximumRefinement;
            
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            
        public:
            static const int PLANE_FLAGS_ALL = 0x3F;
            const Geometry::Frustum& frustum() const { return m_frustum; }
            const Eegeo::dv3& origin() const { return m_origin; }
            const Eegeo::v3& viewDirection() const { return m_viewDirection; }
            float fovRadians() const { return m_fovRadians; }
            uint inactivePlaneFlags() const { return m_inactivePlaneFlags; }
            
            CameraFrustumStreamingVolume(const Eegeo::Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                                         const std::vector<double>& lodRefinementAltitudes,
                                         int deepestLevelForAltitudeLodRefinement,
                                         const Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            void ResetVolume(const dv3& ecefInterestPoint);
            
            bool IntersectsKey(const MortonKey& key,
                               bool& canRefineIntersectedKey,
                               double& intersectedNodeDepthSortSignedDistance);
            
            void updateStreamingVolume(Eegeo::dv3 ecefCentre,
                                       const std::vector<Geometry::Plane>& frustumPlanes,
                                       float fovRadians);
            
            void setInactivePlaneFlags(uint inactivePlaneFlags) { m_inactivePlaneFlags = inactivePlaneFlags; }
            
            bool intersectsOriginRelativeSphere(float sphereRadius, const v3& sphereCentreRelativePos);
            
            bool intersectsSphere(double sphereRadius, double sphereCentreX, double sphereCentreY, double sphereCentreZ);
            
            void setDeepestLevelForAltitudeLodRefinement(int level);
            
            void SetForceMaximumRefinement(bool forceMaximumRefinement);
            
        private:
            
            bool intersectsUprightCylinder(double cylinderRadius,
                                           double cylinderHeight,
                                           double cylinderBaseCentreX,
                                           double cylinderBaseCentreY,
                                           double cylinderBaseCentreZ);
            
            
            bool shouldDivideAtDepth(int nodeDepth, double cellCameraSpaceError);
            
            int calculateMostDetailedLodLevel(double cameraAltitude);
            
            int calculateLodLevelForAltitude(double altitude);
            
            void calculateVisibilityThresholds();
        };
    }
}
