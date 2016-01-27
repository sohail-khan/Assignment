// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "LayerIds.h"
#include "StencilMapLayerMask.h"

namespace Eegeo
{
    namespace Rendering
    {
        class StencilLayersController : protected Eegeo::NonCopyable
        {
        public:
            StencilLayersController();
            ~StencilLayersController();
            static StencilLayersController* Create();
            
            u32 GetStencilBitplaneMask(Eegeo::Rendering::LayerIds::Values layerId) const;
            
            void SetEnabledBitplanes(uint bitplanes) { m_enabledBitplanes = bitplanes & StencilMapLayerMask::AllMapLayers; }
            u32 GetEnabledBitplanes() const { return m_enabledBitplanes; }
            
            // todo - temp, move to MAterials
            void SetDefaultStencilState(Rendering::GLState& glState, const Rendering::RenderableBase& renderable) const;
            
        private:
            u32 m_enabledBitplanes;
        };
    }
}