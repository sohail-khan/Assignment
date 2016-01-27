// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GlobeCamera.h"
#include "Location.h"
#include "VectorMathDecl.h"
#include "Space.h"
#include "GpsGlobeCameraComponentConfiguration.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GpsGlobeCameraComponent : public Eegeo::NonCopyable
            {
            public:
                GpsGlobeCameraComponent(const GlobeCameraController& globeCamera,
                                         Location::NavigationService& navigationService,
                                         const GlobeCameraTouchController& touchController,
                                         const GpsGlobeCameraComponentConfiguration& configuration
                                         );
                virtual ~GpsGlobeCameraComponent() { };
                
                virtual bool TryGetViewSettings(
                        float deltaSeconds,
                        Space::EcefTangentBasis& out_interestBasis,
                        float& out_distanceToInterest,
                        const GlobeCameraTouchSettings& existingTouchSettings,
                        GlobeCameraTouchSettings& out_touchSettings);

                virtual bool IsGpsActive() const;
                virtual bool IsCompassActive() const;
                virtual bool TryGetDefaultGpsView(Space::EcefTangentBasis& out_interestBasis, float& out_distanceToInterest);
                
            private:
                void HandleGpsCancelGestures(const v2& touchPanPixelDelta, float touchRotateAngleDelta);
                void UpdateGpsControl(float deltaSeconds, bool& out_allowTouchRotate, bool& out_allowTouchPan);
                void UpdateCompassCamera(float deltaSeconds, const Space::EcefTangentBasis& cameraInterest, v3& out_heading, float& out_compassHeadingVelocity) const;
            
                const GlobeCameraController& m_globeCamera;
                Location::NavigationService& m_navigationService;
                const GlobeCameraTouchController& m_touchController;
                const GpsGlobeCameraComponentConfiguration m_configuration;
                
                float m_compassHeadingVelocity;
                bool m_gpsActiveLastFrame;
            };
        }
    }
}
