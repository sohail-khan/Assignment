// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "Rendering.h"
#include "DynamicBuffer.h"
#include "AllVertexTypes.h"
#include "Types.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        class DebugRenderableBase : public Rendering::RenderableBase
        {
        public:
            DebugRenderableBase(Rendering::Materials::IMaterial* material);
            
            virtual ~DebugRenderableBase();
            
            virtual bool ContainsMeshData() const = 0;
            
            void SetDepthTest(bool depthTest);
            bool GetDepthTest() const;
            
        protected:
            void UnbindBuffers(Rendering::GLState& glState) const;
            
            bool m_depthTest;
        };
    }
}