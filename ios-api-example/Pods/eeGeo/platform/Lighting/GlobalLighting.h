// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Lighting
    {
        enum LightDirectionType
        {
            LightDirectionType_Key = 0,
            LightDirectionType_Back,
            LightDirectionType_Fill,
            LightDirectionType_Ambient,
            LightDirectionType_MAX
        };
        
        class GlobalLighting
        {
        private:
        
            Eegeo::m44 m_lightColorMat;
            Eegeo::m44 m_alternativeAmbientLightColorMat;
            Eegeo::m44 m_cameraPositionLightDirectionMatrix;
            Eegeo::v3 m_nightLightmapColour;
            Eegeo::v3 m_alternativeAmbientColour;
            float m_dayToNightParam;
            float m_nightGlowLightmapIntensity;
            
            Eegeo::v3 GetKeyLightVectorByAzimuthZenithForEcefPosition(float _azimuthDegrees, float _zenithDegrees, Eegeo::dv3 _ecefVertexPosition) const;
        public:
            const static float KeyLightAzimuth;
            const static float KeyLightZenith;
            
            GlobalLighting();

            void SetRenderState(const Eegeo::dv3& cameraLocationEcef);
            void SetWithScale(GlobalLighting* pSource, float scale);

            void GetLightDirectionMatrix(const Eegeo::dv3& _ecefVertexPosition, Eegeo::m44 &out_inverseLightDirectionMat) const;
            const Eegeo::m44& GetLightDirectionMatrixForCameraPosition() const;
            void SetLightColourMatrix(const Eegeo::m44& lightColourMatrix);
            
            const Eegeo::m44 &GetColors(bool useAlternativeAmbient = false) const
            {
                return useAlternativeAmbient ? m_alternativeAmbientLightColorMat : m_lightColorMat;
            }
            
            //void FillInRGB(Rendering::VertexTypes::DiffuseTexturedPreLitVertex &v,float packedLightDots);

            const Eegeo::v3& GetAlternativeAmbientLight() const { return m_alternativeAmbientColour;}

            void SetNightLightmapColour(const Eegeo::v3& colour) { m_nightLightmapColour = colour; }
            void SetAlternativeAmbientColour(const Eegeo::v3& colour) { m_alternativeAmbientColour = colour; }
            const Eegeo::v3& GetNightLightmapColour() const { return m_nightLightmapColour; }
            //const Eegeo::v3& GetNightForcedAmbientColour() const { return m_nightAmbientColour; }

            //! \deprecated
            //! Sets day to night parameter value
            void SetDayToNightParam(float dayToNightParam) { m_dayToNightParam = dayToNightParam; }

            //! \deprecated
            //! Gets day to night parameter value
            float GetDayToNightParam() const { return m_dayToNightParam; }
            
            void SetNightGlowLightmapIntensity(float nightGlowLightmapIntensity) { m_nightGlowLightmapIntensity = nightGlowLightmapIntensity; }
            float GetNightGlowLightmapIntensity() const { return m_nightGlowLightmapIntensity; }
        };
    }
}
