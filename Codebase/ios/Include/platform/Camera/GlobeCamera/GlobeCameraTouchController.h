// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"
#include "ITouchController.h"
#include "GlobeCameraTouchControllerConfiguration.h"
#include "VectorMath.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GlobeCameraTouchController : public ITouchController
            {
            public:
                GlobeCameraTouchController(const GlobeCameraTouchControllerConfiguration& config,
                                           const Rendering::ScreenProperties& screenProperties);
                
                virtual ~GlobeCameraTouchController();
                
                void SetDebugLogging(bool enableDebugLogging) { m_enableDebugLogging = enableDebugLogging; }
                
                virtual void Reset();

                virtual void Update(float deltaSeconds);
                
                virtual float GetZoomDelta() const { return m_zoomDelta; }
                virtual float GetRotationDelta() const { return m_rotationDelta; }
                virtual const v2& GetPanPixelDelta() const { return m_panPixelDelta; }
                virtual float GetTiltDelta() const { return m_tiltDelta; }

                virtual void SetPanIsHeavilyDamped(bool panIsHeavilyDamped) { m_panIsHeavilyDamped = panIsHeavilyDamped; }
                
                virtual const v2& GetPanAbsolutePixelCoord() const { return m_panAbsolutePixelCoord; }
                
                virtual float GetScreenScale() const { return m_screenScale; }
                
                virtual void Event_TouchRotate(const AppInterface::RotateData& data);
                virtual void Event_TouchRotate_Start(const AppInterface::RotateData& data);
                virtual void Event_TouchRotate_End(const AppInterface::RotateData& data);
                
                virtual void Event_TouchPinch(const AppInterface::PinchData& data);
                virtual void Event_TouchPinch_Start(const AppInterface::PinchData& data);
                virtual void Event_TouchPinch_End(const AppInterface::PinchData& data);
                
                virtual void Event_TouchPan(const AppInterface::PanData& data);
                virtual void Event_TouchPan_Start(const AppInterface::PanData& data);
                virtual void Event_TouchPan_End(const AppInterface::PanData& data);
                
                virtual void Event_TouchTap(const AppInterface::TapData& data) {}
                virtual void Event_TouchDoubleTap(const AppInterface::TapData& data) {}
                
                virtual void Event_TouchDown(const AppInterface::TouchData& data);
                virtual void Event_TouchMove(const AppInterface::TouchData& data) {}
                virtual void Event_TouchUp(const AppInterface::TouchData& data) {}

                virtual void Event_Zoom(const AppInterface::ZoomData& data);

                virtual void Event_TiltStart(const AppInterface::TiltData& data);
                virtual void Event_TiltEnd(const AppInterface::TiltData& data);
                virtual void Event_Tilt(const AppInterface::TiltData& data);
            private:
                void UpdateRotationInertia(float deltaSeconds);
                void UpdateZoomInertia(float deltaSeconds);
                void UpdatePanInertia(float deltaSeconds);
                void AccumulateTouchRotate(const AppInterface::RotateData& data);
                void AccumulateTouchPanTilt(const AppInterface::PanData& data);
                bool ShouldTilt(const AppInterface::PanData& data) const;
            
                const GlobeCameraTouchControllerConfiguration m_configuration;

                bool m_enableDebugLogging;
                
                bool m_rotating;
                bool m_pinching;
                bool m_panning;
                bool m_tilting;
                bool m_tiltStartBlocked;
                bool m_panIsHeavilyDamped;
                bool m_panAccumulatorWasUpdated;

                float m_zoomDelta;
                float m_zoomAccumulator;
                float m_zoomVelocity;
                int m_zoomSign;
                float m_rotationDelta;
                float m_rotationAccumulator;
                float m_rotationVelocity;
                float m_previousEventRotation;
                float m_screenScale;
                
                int m_singleTouchRotateEvents;
                int m_panEventsSinceGestureStart;
                
                Eegeo::v2 m_panPixelDelta;
                Eegeo::v2 m_panPixelAccumulator;
                Eegeo::v2 m_panPixelVelocity;
                Eegeo::v2 m_previousEventPanPointRelative;
                Eegeo::v2 m_panAbsolutePixelCoord;
                
                float m_tiltAccumulator;
                float m_tiltDelta;
                
                const Rendering::ScreenProperties& m_screenProperties;
            };
        }
    }
}
