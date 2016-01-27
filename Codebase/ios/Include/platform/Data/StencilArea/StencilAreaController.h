//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "StencilAreaModel.h"
#include "StencilAreaView.h"
#include "StencilAreaRenderer.h"
#include "StencilAreaViewFactory.h"
#include "DataEntityController.h"
#include "StencilAreaPaletteModel.h"

#include <map>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            struct StencilAreaArgs
            {
                typedef TStencilAreaId TId;
                typedef StencilAreaModel TModel;
                typedef StencilAreaView TView;
                typedef StencilAreaViewFactory TViewFactory;
                typedef StencilAreaRenderer TRenderableFilter;
            };
            
            class StencilAreaController : private Eegeo::NonCopyable
            {
            public:
                StencilAreaController(StencilAreaViewFactory& viewFactory, StencilAreaRenderer& renderableFilter);
                
                ~StencilAreaController();
                
                void Add(StencilAreaModel& model);
                
                void Remove(StencilAreaModel& model);
                
                bool TryRemoveById(const TStencilAreaId& id, StencilAreaModel*& out_removedItem);
                
            private:
                void RemovePalette(const StencilAreaPaletteModel& model);
                
                void AddPalette(const StencilAreaPaletteModel& model);
                
                void Clear();
                
                bool HasPalette(const StencilAreaPaletteModel& model) const;
                
                bool ShouldRemovePalette(const StencilAreaPaletteModel& model) const;
                
                typedef std::map<const TStencilPaletteId, Rendering::Renderables::WorldMeshRenderable*> TStencilPalettesToQuads;
                typedef std::map<const TStencilPaletteId, int> TStencilPaletteModelCounts;
                
                DataEntityController<StencilAreaArgs> m_controller;
                
                TStencilPalettesToQuads m_paletteQuads;
                TStencilPaletteModelCounts m_paletteMemberCounts;
            };
        }
    }
}