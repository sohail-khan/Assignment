// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Camera.h"
#include "RenderCamera.h"
#include "Geometry.h"
#include "Streaming.h"
#include "CameraState.h"
#include "Rendering.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace SplinePlayback
        {
            enum SplinePlaybackState
            {
                Started,
                Playing,
                Stopped
            };

            typedef Helpers::ICallback1<const SplinePlaybackState&> TPlaybackStateChangedCallback;

            class CameraSplinePlaybackController
            {
            public:
                CameraSplinePlaybackController(const Streaming::ResourceCeilingProvider& resourceCeilingProvider);
                
                RenderCamera GetRenderCamera() const { return m_camera; }
                bool IsPlaying() const { return m_playing; }
                
                double GetPlaybackSpeed() const { return m_playbackSpeed; }
                void SetPlaybackSpeed(double speed) { m_playbackSpeed = speed; }
                
                void TogglePlaybackDirection();
                
                bool IsLooped() const { return m_looped; }
                void SetLooped(bool looped) { m_looped = looped; }
                
                void SetSplines(Geometry::ISpline* pPositionSpline, Geometry::ISpline* pTargetSpline);
                void Play();
                void Stop();
                void Update(float dt);
                
                Camera::CameraState GetCameraState() const;
                
                void UpdateScreenProperties(const Eegeo::Rendering::ScreenProperties& screenProperties);
                
                void RegisterPlaybackStateCallback(TPlaybackStateChangedCallback& callback);
                void UnregisterPlaybackStateCallback(TPlaybackStateChangedCallback& callback);

            private:
                double m_time;
                double m_playbackSpeed;
                bool m_playing;
                bool m_looped;
                
                bool m_playReversed;

                Eegeo::Helpers::CallbackCollection1<const SplinePlaybackState&> m_playbackStateCallbacks;

                Geometry::ISpline* m_pPositionSpline;
                Geometry::ISpline* m_pTargetSpline;
                Camera::RenderCamera m_camera;
                const Streaming::ResourceCeilingProvider& m_resourceCeilingProvider;
                float m_fovDegrees;
                
                void UpdateCamera();
                void UpdateFovAndClippingPlanes();
            };
            
        }
    }
}