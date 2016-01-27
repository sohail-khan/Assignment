//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMathDecl.h"
#include "Geometry.h"
#include "Camera.h"
#include "Streaming.h"
#include "CatmullRomSpline.h"
#include "Camera.h"
#include "VectorMath.h"
#include "CameraState.h"
#include "Rendering.h"
#include "CameraSplinePlaybackController.h"
#include "Space.h"
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace SplinePlayback
        {
            class DebugCameraSplinePlaybackService
            {
            public:
                
                DebugCameraSplinePlaybackService(const Streaming::ResourceCeilingProvider& resourceCeilingProvider);
                ~DebugCameraSplinePlaybackService();
                
                void AddPoint(const dv3& camPositionEcef, const dv3& focusPointEcef);
                void AddPoint(const Space::LatLongAltitude& camPosition, const Space::LatLongAltitude& focusPoint);
                void RemoveLastPoint();
                void Clear();
                void Play(float speed);
                void Stop();
                
                bool IsPlaying() const;
                
                void Update(float dt);
                
                void SetInterpolation(Geometry::TimeParameterizationMethod::Values interpolationMethodValue);
                void SetPlaybackSpeed(float speed);
                void TogglePlaybackDirection();
                
                Camera::RenderCamera GetPlaybackRenderCamera() const;
                
                void GetPointEcefPositions(std::vector<dv3>& out_cameraPositionsEcef, std::vector<dv3>& out_targetPositionsEcef) const;

                void RegisterPlaybackStateCallback(Eegeo::Camera::SplinePlayback::TPlaybackStateChangedCallback& callback);
                void UnregisterPlaybackStateCallback(Eegeo::Camera::SplinePlayback::TPlaybackStateChangedCallback& callback);
                
                Camera::CameraState GetCameraState() const;
                
                void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
                
            private:
                
                Geometry::CatmullRomSpline* m_pPositionSpline;
                Geometry::CatmullRomSpline* m_pTargetSpline;
                Camera::SplinePlayback::CameraSplinePlaybackController* m_pCameraController;
            };
        }
    }
}