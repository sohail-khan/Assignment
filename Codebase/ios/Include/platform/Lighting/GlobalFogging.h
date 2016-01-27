// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Lighting
    {
        struct GlobalFoggingUniformValues
        {
            Eegeo::v4 FogColour;
            Eegeo::v3 WorldUp;
            float FogDensityGlobal;
            float HeightFogIntensity;
            float DistanceFogIntensity;
            float CameraAltitude;
            float HeightFogMinAltitude;
            float HeightFogMaxAltitude;
            float DistanceFogNear;
            float DistanceFogFar;
            float DistanceFogLow;
            float DistanceFogHigh;
            
        };
        
        class GlobalFogging : protected Eegeo::NonCopyable
        {
        public:
            GlobalFogging();
            
            void SetDefault();

            void SetFogColour(const Eegeo::v4& fogColour) { m_fogColour = fogColour; }
            void SetHeightFogAltitudes(float minAltitude, float maxAltitude) { m_heightFogMinAltitude = minAltitude; m_heightFogMaxAltitude = maxAltitude; }
            void SetDistanceFogDistances(float nearFog, float farFog) { m_distanceFogNear = nearFog; m_distanceFogFar = farFog; }
            void SetDistanceFogAltitudes(float low, float high) { m_distanceFogLow = low; m_distanceFogHigh = high; }
            void SetCameraPositionEcef(const Eegeo::dv3& cameraPositionEcef) { m_cameraPositionEcef = cameraPositionEcef; }
            void SetFogDensity(float fogDensity) { m_fogDensity = fogDensity; }
            void SetHeightFogIntensity(float heightFogIntensity) { m_heightFogIntensity = heightFogIntensity; }
            void SetDistanceFogIntensity(float distanceFogIntensity) { m_distanceFogInstensity = distanceFogIntensity; }
            void SetBaseAltitude(float baseAltitude) { m_baseAltitude = baseAltitude; }
            
            void GetUniformValues(GlobalFoggingUniformValues& values) const;
            
            bool IsEnabled() const { return m_fogDensity > 0.f;}
        private:
            
            Eegeo::v4 m_fogColour;
            Eegeo::dv3 m_cameraPositionEcef;
            float m_heightFogMinAltitude;
            float m_heightFogMaxAltitude;
            float m_distanceFogNear;
            float m_distanceFogFar;
            float m_distanceFogLow;
            float m_distanceFogHigh;
            float m_fogDensity;
            float m_heightFogIntensity;
            float m_distanceFogInstensity;
            float m_baseAltitude;

        };
    }
}
