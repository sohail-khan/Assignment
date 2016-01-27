//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "RenderingModule.h"
#include "VertexColoredShader.h"
#include "VertexColoredMaterial.h"
#include "Rendering.h"
#include "PolyChart.h"

namespace Eegeo
{
    namespace Data
    {
        namespace PolyChart
        {
            class PolyChartViewFactory : private Eegeo::NonCopyable
            {
            public:
                static PolyChartViewFactory* Create(Eegeo::Modules::Core::RenderingModule& renderingModule);
                
                PolyChartViewFactory(
                                    Rendering::Shaders::VertexColoredShader* pShader,
                                    Rendering::Materials::VertexColoredMaterial* pMaterial,
                                    const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                                    Rendering::GlBufferPool& glBufferPool,
                                    Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                ~PolyChartViewFactory();
                
                PolyChartView* CreateView(PolyChartModel& model);
                void FreeView(PolyChartView* pView);
                
            private:
                Rendering::Materials::VertexColoredMaterial* m_pMaterial;
                Rendering::Shaders::VertexColoredShader* m_pShader;
                const Rendering::VertexLayouts::VertexLayout& m_vertexLayout;
                Rendering::GlBufferPool& m_glBufferPool;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                
                Rendering::Mesh* CreateMesh(PolyChartModel& model);
            };
        }
    }
}