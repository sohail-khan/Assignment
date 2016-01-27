//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "RenderingModule.h"
#include "StencilAreaShader.h"
#include "StencilAreaMaterial.h"
#include "StencilAreaFullScreenMaterial.h"
#include "StencilAreaPaletteModel.h"
#include "Rendering.h"
#include "StencilArea.h"
#include "ColorShader.h"
#include "Types.h"
#include <map>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            class StencilAreaViewFactory : private Eegeo::NonCopyable
            {
            public:
                static StencilAreaViewFactory* Create(Eegeo::Modules::Core::RenderingModule& renderingModule);
                
                StencilAreaViewFactory(
                                    Materials::StencilAreaShader* pShader,
                                    Eegeo::Rendering::Shaders::ColorShader* pFullScreenShader,
                                    Eegeo::Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                    const Rendering::VertexLayouts::VertexLayout& vertexLayout,
                                    Rendering::GlBufferPool& glBufferPool,
                                       Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                    Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                ~StencilAreaViewFactory();
                
                StencilAreaView* CreateView(StencilAreaModel& model);
                Rendering::Renderables::WorldMeshRenderable* CreatePalette(const StencilAreaPaletteModel& palette);

                void FreeView(StencilAreaView* pView);
                void FreePalette(const StencilAreaPaletteModel& palette);
                void Clear();
            private:
                typedef std::map<TStencilPaletteId, Materials::StencilAreaFullScreenMaterial*> TStencilPaletteToFullScreenMaterial;
                typedef std::map<TStencilPaletteId, Materials::StencilAreaMaterial*> TStencilPaletteToAreaMaterial;
                typedef std::map<TStencilPaletteId, u64> TStencilPaletteToSortKeyComponents;
                
                TStencilPaletteToFullScreenMaterial m_stencilPaletteFullScreenMaterials;
                TStencilPaletteToAreaMaterial m_stencilPaletteAreaMaterials;
                TStencilPaletteToSortKeyComponents m_stencilPaletteAreaSortKeyValues;
                
                Materials::StencilAreaShader* m_pShader;
                Eegeo::Rendering::Shaders::ColorShader* m_pFullScreenShader;
                
                const Rendering::VertexLayouts::VertexLayout& m_vertexLayout;
                Rendering::GlBufferPool& m_glBufferPool;
                Rendering::VertexLayouts::VertexLayoutPool& m_vertexLayoutPool;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                Eegeo::Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
                u64 m_currentSortKeyComponent;

                u64 GetUserDefinedValue(const TStencilPaletteId& paletteId);
                Rendering::Mesh* CreateMesh(StencilAreaModel& model);
                void RegisterNewPalette(const StencilAreaPaletteModel& palette);
            };
        }
    }
}