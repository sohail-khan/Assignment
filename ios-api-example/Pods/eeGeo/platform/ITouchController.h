// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AppInterface.h"

namespace Eegeo
{
    class ITouchController
    {
    public:
        virtual ~ITouchController() {;}
        
        virtual void Reset() = 0;
        
        virtual void Event_TouchRotate(const AppInterface::RotateData& data) = 0;
        virtual void Event_TouchRotate_Start(const AppInterface::RotateData& data) = 0;
        virtual void Event_TouchRotate_End(const AppInterface::RotateData& data) = 0;
        
        virtual void Event_TouchPinch(const AppInterface::PinchData& data) = 0;
        virtual void Event_TouchPinch_Start(const AppInterface::PinchData& data) = 0;
        virtual void Event_TouchPinch_End(const AppInterface::PinchData& data) = 0;
        
        virtual void Event_TouchPan(const AppInterface::PanData& data) = 0;
        virtual void Event_TouchPan_Start(const AppInterface::PanData& data) = 0;
        virtual void Event_TouchPan_End(const AppInterface::PanData& data) = 0;
        
        virtual void Event_TouchTap(const AppInterface::TapData& data) = 0;
        virtual void Event_TouchDoubleTap(const AppInterface::TapData& data) = 0;
        
        virtual void Event_TouchDown(const AppInterface::TouchData& data) = 0;
        virtual void Event_TouchMove(const AppInterface::TouchData& data) = 0;
        virtual void Event_TouchUp(const AppInterface::TouchData& data) = 0;

        virtual void Event_Zoom(const AppInterface::ZoomData& data) = 0;

        virtual void Event_TiltStart(const AppInterface::TiltData& data) {};
        virtual void Event_TiltEnd(const AppInterface::TiltData& data) {};
        virtual void Event_Tilt(const AppInterface::TiltData& data) {};
    };
}
