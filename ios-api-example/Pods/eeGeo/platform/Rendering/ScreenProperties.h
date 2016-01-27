// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"


namespace Eegeo
{
    namespace Rendering
    {
        struct ScreenProperties
        {
            static ScreenProperties Make(float screenWidth, float screenHeight, float pixelScale, float screenDpi);
            
            ScreenProperties()
            : m_screenWidth(0.f)
            , m_screenHeight(0.f)
            , m_screenPixelScale(0.f)
            , m_screenDpi(0.f)
            {
            }
            
            ScreenProperties(float screenWidth, float screenHeight, float pixelScale, float screenDpi)
            : m_screenWidth(screenWidth)
            , m_screenHeight(screenHeight)
            , m_screenPixelScale(pixelScale)
            , m_screenDpi(screenDpi)
            {
            }
            
            float GetScreenWidth() const { return m_screenWidth; }
            float GetScreenHeight() const { return m_screenHeight; }
            float GetPixelScale() const { return m_screenPixelScale; }
            float GetScreenDpi() const { return m_screenDpi; }
        private:
            float m_screenWidth;
            float m_screenHeight;
            float m_screenPixelScale;
            float m_screenDpi;
        };
    }
}