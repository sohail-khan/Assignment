// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"
#include "Rendering.h"
#include "Streaming.h"
#include "Terrain.h"
#include "GlobeCameraControllerConfiguration.h"
#include "EcefTangentBasis.h"
#include "GlobeCameraModeTransition.h"
#include "GlobeCameraTerrainFollower.h"
#include "GlobeCameraTouchSettings.h"
#include "IInterestPointProvider.h"
#include "CameraState.h"
#include "RenderCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            /*! \brief Controls a RenderCamera to be constrained to look at an interest point, with touch-surface user input.
             *
             *  GlobeCameraController aggregates a RenderCamera object, and sets its transform to always look at an
             *  interest point. User interaction is consumed via a GlobeCameraTouchController. This allowing the interest point
             *  to be moved around the Earth's surface, the camera to be rotated around this point, and zoomed in and out.
             *  The controller is modal. 
             *  Below a threshold altitude, in "city mode", touch pan gestures allow the user to drag the interest point 
             *  around, and rotate about a local Earth surface-normal up axis.
             *  Above the threshold altitude, in "globe mode", orientation is constrained so that the globe appears with 
             *  the Earth's axis vertical in screenspace, with North pole at top of screen. Touch pan gestures rotate the globe.
             *  The controller smoothly transitions between the two modes when moving across the threshold altitude
             *  The pitch angle of the camera is altered based on altitude - looking vertically down towards the earth surface
             *  at high altitudes, and tilting up towards the horizon at lower altitudes
             *  Camera field of view is altered based on altitude, narrowing at lower altitudes.
             *  Configuration of constants used by the controller can be made in the GlobeCameraControllerConfiguration constructor parameter.
             */
            class GlobeCameraController : public Eegeo::NonCopyable, public Location::IInterestPointProvider
            {
            public:
                GlobeCameraController(const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                               const Eegeo::Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                               const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                               const GlobeCameraTouchController& touchController,
                               const GlobeCameraControllerConfiguration& configuration,
                               const Eegeo::Rendering::ScreenProperties& screenProperties);
                virtual ~GlobeCameraController();
                
                virtual Camera::RenderCamera GetRenderCamera() const { return m_camera; }
                
                virtual void Update(float deltaSeconds);
                
                virtual void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                virtual const Space::EcefTangentBasis& GetInterestBasis() const { return m_interestBasis; }
                virtual float GetDistanceToInterest() const { return m_distanceToInterest; }
                
                dv3 GetEcefInterestPoint() const;
                
                virtual void SetInterestBasis(const Space::EcefTangentBasis& interestBasis);
                virtual void SetView(const Space::EcefTangentBasis& interestBasis, float distanceToInterest);
                
                virtual void SetProjection(float fovRadians,
                                           float nearClipDistance,
                                           float farClipDistance);
                
                virtual bool IsZoomDistanceAboveGlobeModeThreshold() const;

                virtual const GlobeCameraTouchSettings& GetTouchSettings() const { return m_touchSettings; }
                virtual void SetTouchSettings(const GlobeCameraTouchSettings& settings) { m_touchSettings = settings; }

                virtual const GlobeCameraControllerConfiguration& GetConfig() { return m_configuration; }
                
                virtual dv3 ComputeNonFlattenedCameraPosition() const;
            
                void ApplyTilt(float tiltDegrees) { m_tiltDegrees = tiltDegrees; };
                virtual float CalculatePitchDegrees() const;
            
                CameraState GetCameraState() const;
                
            protected:
                virtual float CalculateFovDegrees() const;
                virtual float CalculateMaximumAltitude() const;
                
            private:
                enum Mode
                {
                    CityMode,
                    TransitioningToGlobeMode,
                    GlobeMode,
                };
                
                Mode DetermineMode() const;
                
                void UpdateCityMode(float deltaSeconds, const v2& touchPanPixelDelta, float touchRotateAngleDelta, float touchTiltAngleDelta);
                void UpdateGlobeMode(float deltaSeconds, const v2& touchPanPixelDelta);
                void UpdateTransitionMode(float deltaSeconds, const v2& touchPanPixelDelta);
                
                void ApplyZoom(float deltaSeconds, float touchZoomDelta, float& out_distanceToInterest) const;
                void ApplyRotation(float deltaSeconds, float touchRotateAngleDelta, v3& out_heading) const;
                void ApplyTilt(float touchTiltAngleDelta, float& out_tilt) const;
                void ApplyPanCityMode(float deltaSeconds, const v2& touchPanPixelDelta, dv3& out_interestPointEcef) const;
                void ApplyPanGlobeMode(float deltaSeconds, const v2& touchPanPixelDelta, dv3& out_interestPointEcef) const;
                float ClampedDistanceToInterest(float distanceToInterest) const;

                void SetRenderCameraTransforms();
                void SetRenderCameraViewTransform(float pitchRadians);
                void SetRenderCameraProjectionTransform(float verticalFovRadians);
                
                const Eegeo::Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
                const GlobeCameraTouchController& m_touchController;
                
                GlobeCameraControllerConfiguration m_configuration;
                Camera::RenderCamera m_camera;
                GlobeCameraModeTransition m_globeModeTransition;
                GlobeCameraTerrainFollower m_terrainFollower;
                
                Mode m_mode;
                Space::EcefTangentBasis m_interestBasis;
                float m_distanceToInterest;
                
                float m_tiltDegrees;
                
                GlobeCameraTouchSettings m_touchSettings;
            };
        }
    }
}
