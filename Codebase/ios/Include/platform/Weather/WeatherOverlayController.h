// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Location.h"

namespace Eegeo
{
    namespace Weather
    {
        struct WeatherEffectLayer2
        {
            WeatherEffectLayer2()
            : uvOffset(v2::Zero())
            , uvVelocity(v2::Zero())
            , uvScale(v2::Zero())
            , inverseScale(0.f)
            , alpha(0.f)
            {
            }
            WeatherEffectLayer2(v2 uvOffset, v2 uvVelocity, float alpha, float inverseScale)
            : uvOffset(uvOffset)
            , uvVelocity(uvVelocity)
            , uvScale(v2::Zero())
            , inverseScale(inverseScale)
            , alpha(alpha)
            {
                Eegeo_ASSERT(inverseScale > 0.0f);
            }
            
            float GetAlpha() const { return alpha; }
            v2 GetUVOffset() const { return uvOffset; }
            v2 GetUVScale() const { return uvScale; }
            
            void Update(float dt, float viewportAspectRatio)
            {
                uvOffset += uvVelocity * (inverseScale * dt);
                uvOffset.x -= (int)uvOffset.x;
                uvOffset.y -= (int)uvOffset.y;
               
                uvScale = inverseScale * ((viewportAspectRatio >= 1.f) ? v2(viewportAspectRatio, 1.f) : v2(1.f, 1.f/viewportAspectRatio));
            }
        private:
            v2 uvOffset;
            v2 uvVelocity;
            v2 uvScale;
            float inverseScale;
            float alpha;

        };
        
        class WeatherOverlayController
        {
        public:
            WeatherOverlayController();
            
            ~WeatherOverlayController();

            void Update(float dt, const dv3& ecefInterestPoint, float cameraAltitude, float viewportAspectRatio);
            
            void SetIntensity(float value) { m_globalIntensity = Clamp(value, 0.0f, 1.0f); }
            
            WeatherEffectLayer2& GetWeatherEffectLayerOne(){ return m_effectLayerOne;}
            WeatherEffectLayer2& GetWeatherEffectLayerTwo(){ return m_effectLayerTwo;}
            float GetCurrentIntensity(){return m_currentIntensity;}
            
            void SetWeatherLayersParameters(v2 uvOffsetOne, v2 uvVelocityOne, float alphaOne, float scaleOne,
                                            v2 uvOffsetTwo, v2 uvVelocityTwo, float alphaTwo, float scaleTwo);

        private:
            float CalculateIntensityAtCameraAltitude(float cameraAltitude) const;
            
            WeatherEffectLayer2 m_effectLayerOne;
            WeatherEffectLayer2 m_effectLayerTwo;
            
            float m_globalIntensity;
            float m_currentIntensity;
        };
    }
}
