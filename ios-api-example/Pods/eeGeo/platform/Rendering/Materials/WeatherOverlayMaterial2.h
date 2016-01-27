// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IMaterial.h"
#include "Types.h"
#include "IdTypes.h"
#include "WeatherOverlayShader.h"
#include "Weather.h"
#include "Rendering.h"
#include <string>


namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
        class WeatherOverlayMaterial2 : protected Eegeo::NonCopyable, public IMaterial
        {
        public:
            WeatherOverlayMaterial2(
                                   const TMaterialId materialId,
                                   const std::string& name,
                                   Shaders::WeatherOverlayShader& shader,
                                   Eegeo::Weather::WeatherOverlayController & weatherOverlayController
                                    );
            
            const TMaterialId GetId() const{ return m_id;}
            
            const Shader& GetShader() const{return m_shader;}
            
            void SetState(Rendering::GLState& glState) const;
            
            void BindUniformShaderParams(Rendering::GLState& glState, const Weather::WeatherEffectLayer2& layerOne, const Weather::WeatherEffectLayer2& layerTwo, const float intensity) const;

            void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const { }
            const std::string& GetName() const {return m_name;}
            
            void SetTextureId(Eegeo::Rendering::TTextureId textureId) { m_textureId = textureId; }
            
        private:
            const TMaterialId m_id;
            const std::string m_name;
            
            TTextureId m_textureId;
            
            Shaders::WeatherOverlayShader& m_shader;
            Eegeo::Weather::WeatherOverlayController & m_weatherOverlayController;
        };
        }
    }
}
