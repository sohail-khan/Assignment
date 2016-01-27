// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "VectorMath.h"
#include "Geofencing.h"
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace Geofencing
        {
            class GeofenceViewFactory : private Eegeo::NonCopyable
            {
            public:
                static GeofenceViewFactory* Create(Eegeo::Modules::Core::RenderingModule& renderingModule);

                GeofenceViewFactory(
                        Rendering::Shaders::UniformColoredShader* pShader,
                        Rendering::Materials::UniformColoredMaterial* pMaterial,
                        const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                        Rendering::GlBufferPool& glBufferPool,
                        Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);

                ~GeofenceViewFactory();

                GeofenceView* CreateView(GeofenceModel& geofence);
                void FreeView(GeofenceView* pView);
            private:
                Rendering::Materials::UniformColoredMaterial* m_pMaterial;
                Rendering::Shaders::UniformColoredShader* m_pShader;
                const Rendering::VertexLayouts::VertexLayout& m_vertexLayout;
                Rendering::GlBufferPool& m_glBufferPool;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;

                Rendering::Mesh* CreateMesh(
                        const std::vector<dv3>& ecefVerts,
                        const dv3& ecefCellCenter);
            };
        }
    }
}

