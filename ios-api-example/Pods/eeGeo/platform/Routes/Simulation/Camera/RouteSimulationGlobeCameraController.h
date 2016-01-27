// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "Terrain.h"
#include "Collision.h"
#include "Rendering.h"
#include "RouteSimulationGlobeCameraControllerConfig.h"
#include "TerrainRayPicker.h"
#include "VectorMathDecl.h"
#include "GlobeCamera.h"
#include "Space.h"
#include "IInterestPointProvider.h"
#include "CameraState.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            namespace Camera
            {
                class RouteSimulationGlobeCameraController : public Location::IInterestPointProvider
                {
                public:
                    enum RouteSimulationGlobeCameraControllerOrientationMode
                    {
                        UnlockedOrientation,
                        LockedToAbsoluteHeading,
                        LockedToCurrentLinkDirection
                    };
                    
                private:
                    const RouteSimulationSession* m_pRouteSimulationSession;
                    Eegeo::Camera::GlobeCamera::GlobeCameraController* m_pCameraController;
                    Eegeo::Camera::GlobeCamera::GlobeCameraTouchController* m_pCameraTouchController;

                    const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                    Eegeo::Resources::Terrain::Collision::TerrainRayPicker m_rayPicker;
                    const RouteSimulationGlobeCameraControllerConfig m_config;
                    
                    float m_followDistanceMeters;
                    bool m_touchZoomEnabled;
                    bool m_tiltEnabled;
                    float m_followHeadingDegrees;
                    RouteSimulationGlobeCameraControllerOrientationMode m_orientationMode;
                    float m_headingVelocity;
                    
                    float m_deltaSecondsAccumulator;
                    float m_collisionDistance;
                    float m_collisionTimer;

                    
                public:
                    RouteSimulationGlobeCameraController(Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController,
                                                         Eegeo::Camera::GlobeCamera::GlobeCameraTouchController* pCameraTouchController,
                                                         const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                                         const Collision::ICollisionBvhProvider& collisionMeshResourceProvider,
                                                         const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                         const RouteSimulationGlobeCameraControllerConfig& config);
                    
                    ~RouteSimulationGlobeCameraController();
                    
                    Eegeo::Camera::GlobeCamera::GlobeCameraTouchController& GetTouchController() const;
                    
                    Eegeo::Camera::RenderCamera GetRenderCamera() const;
                    
                    bool IsActive() const { return m_pRouteSimulationSession != NULL; }
                    
                    RouteSimulationGlobeCameraControllerOrientationMode GetOrientationMode() const;
                    
                    void SetTouchZoomEnabled(bool enabled);

                    void SetTiltEnabled(bool enabled);
                    
                    void SetFollowDistance(float followDistanceMetres);
                    
                    void LockFollowHeadingDegrees(float followHeadingDegrees);
                    
                    void LockFollowHeadingToCurrentLinkDirection();
                    
                    void SetOrientationMode(RouteSimulationGlobeCameraControllerOrientationMode mode);
                    
                    void UnlockFollowHeading();
                    
                    void Update(float dt);
                    
                    void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
                    
                    void StartFollowingSession(const RouteSimulationSession* routeSimulationSession);
                    
                    void StopFollowingSession();
                    
                    void SetView(double interestLatitudeDegrees,
                                 double interestLongitudeDegrees,
                                 float headingDegrees,
                                 float distanceToInterest);

                    void SetProjection(float fovRadians,
                                       float nearClipDistance,
                                       float farClipDistance);
                    
                    bool IsTouchZoomEnabled() const { return m_touchZoomEnabled; }

                    bool IsTiltEnabled() const { return m_tiltEnabled; }
                    
                    float GetFollowDistanceMetres() const { return m_followDistanceMeters; }
                    
                    float GetDistanceToInterest() const;
                    
                    dv3 GetEcefInterestPoint() const;
                    
                    Eegeo::Camera::CameraState GetCameraState() const;
                    
                private:
                    
                    void UpdateCameraInteractionSettings();
                    
                    void ComputeBasisFromHeading(const dv3& ecefPos, Space::EcefTangentBasis& interestBasis);
                    
                    void UpdateBasisFromLinkDirection(float deltaSeconds, const dv3& desiredInterestPos, Space::EcefTangentBasis& out_interestBasis);

                    bool TryIntersectCameraRayWithTerrain(double& out_intersectionDist);
                                        
                    float ClampedFollowDistance(float in) const;
                    
                    void ForceUnlockedOrientationIfGlobeMode();
                    
                    void UpdateInterestBasis(float deltaTime);
                };
            }
        }
    }
}
