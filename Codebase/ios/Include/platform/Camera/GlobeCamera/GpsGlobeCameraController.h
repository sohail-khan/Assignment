// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GlobeCamera.h"
#include "VectorMathDecl.h"
#include "Space.h"
#include "IInterestPointProvider.h"
#include "CameraState.h"
#include "Rendering.h"
#include "RenderCamera.h"

namespace Eegeo
{
    class ITouchController;
    
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GpsGlobeCameraController : public Eegeo::NonCopyable, public Location::IInterestPointProvider
            {
            public:
                GpsGlobeCameraController(GpsGlobeCameraComponent* gpsGlobeCameraComponent,
                                        GlobeCameraController* globeCameraController,
                                        GlobeCameraTouchController* globeCameraTouchController);
                virtual ~GpsGlobeCameraController();
                
                virtual void Update(float deltaSeconds);
                
                virtual void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                virtual RenderCamera GetRenderCamera() const;
                
                dv3 GetEcefInterestPoint() const;
                
                virtual float GetDistanceToInterest() const;
                
                virtual const Space::EcefTangentBasis& GetInterestBasis() const;
                
                virtual void SetInterestBasis(const Space::EcefTangentBasis& interestBasis);
                
                virtual void SetView(const Space::EcefTangentBasis& interestBasis, float distanceToInterest);
                
                virtual void SetInterestLocation(const dv3& interestPointEcef);
                
                virtual void SetView(double interestLatitudeDegrees, double interestLongitudeDegrees, float headingDegrees, float distanceToInterest);
                
                virtual bool IsGpsActive() const;
                
                virtual bool IsCompassActive() const;
                
                virtual bool TryGetDefaultGpsView(Space::EcefTangentBasis& out_interestBasis, float& out_distanceToInterest);
                
                virtual ITouchController& GetTouchController();
                
                virtual void SetDebugLogging(bool enabled);

                virtual Eegeo::Camera::GlobeCamera::GlobeCameraController& GetGlobeCameraController();
                
                CameraState GetCameraState() const;
                
            private:
            
                GpsGlobeCameraComponent* m_gpsGlobeCameraComponent;
                GlobeCameraController* m_globeCameraController;
                GlobeCameraTouchController* m_globeCameraTouchController;
                
                bool m_debugLoggingEnabled;
            };
        }
    }
}