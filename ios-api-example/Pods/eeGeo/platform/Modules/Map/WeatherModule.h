// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Weather.h"
#include "Location.h"
#include "Modules.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class WeatherModule : protected Eegeo::NonCopyable
            {
            public:
                WeatherModule(Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                              Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                              Rendering::GlBufferPool& glBufferPool,
                              Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                              Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                              Rendering::RenderableFilters& renderableFilters);
                
                ~WeatherModule();
                
                static WeatherModule* Create(Core::RenderingModule& renderingModule);
                
                void Update(float dt, const dv3& ecefInterestPoint, float cameraAltitude, float viewportAspectRatio);
                
                Rendering::Shaders::WeatherOverlayShader& GetWeatherOverlayShader() const;
                Rendering::Materials::WeatherOverlayMaterial2& GetWeatherOverlayMaterial() const;
                Rendering::Renderables::WorldMeshRenderable& GetWeatherOverlayRenderable() const;
                Weather::WeatherOverlayController& GetWeatherOverlayController() const;
                Weather::WeatherOverlayRenderer& GetWeatherOverlayRenderer() const;
            private:
                Rendering::Shaders::WeatherOverlayShader* m_pWeatherOverlayShader;
                Rendering::Materials::WeatherOverlayMaterial2* m_pWeatherOverlayMaterial;
                Rendering::Renderables::WorldMeshRenderable* m_pWeatherOverlayRenderable;
                Eegeo::Weather::WeatherOverlayController * m_pWeatherOverlayController;
                Eegeo::Weather::WeatherOverlayRenderer * m_pWeatherOverlayRenderer;
            };
        }
    }
}