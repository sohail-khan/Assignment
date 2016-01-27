//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Heatmaps.h"
#include "RenderingModule.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            class HeatmapViewFactory : private Eegeo::NonCopyable
            {
            public:
                static HeatmapViewFactory* Create(Eegeo::Modules::Core::RenderingModule& renderingModule);

                HeatmapViewFactory(
                                   Materials::HeatmapShader* pShader,
                                   Materials::HeatmapMaterial* pMaterial,
                                    const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                                    Rendering::GlBufferPool& glBufferPool,
                                    Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                ~HeatmapViewFactory();
                
                HeatmapView* CreateView(HeatmapModel& geofence);
                void FreeView(HeatmapView* pView);
            private:
                Materials::HeatmapShader* m_pShader;
                Materials::HeatmapMaterial* m_pMaterial;
                const Rendering::VertexLayouts::VertexLayout& m_vertexLayout;
                Rendering::GlBufferPool& m_glBufferPool;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                
                Rendering::Mesh* CreateMesh(const dv3& topLeft,
                                            const dv3& topRight,
                                            const dv3& bottomRight,
                                            const dv3& bottomLeft,
                                            const dv3& ecefCellCenter);
            };
        }
    }
}