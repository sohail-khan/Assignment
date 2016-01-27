//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "StencilArea.h"

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            class StencilAreaView : private Eegeo::NonCopyable
            {
            public:
                StencilAreaView(const StencilAreaModel& model, StencilAreaRenderable* pRenderable);
                void Update();
                
                const StencilAreaModel& GetModel() const;
                StencilAreaRenderable* GetRenderable();
            private:
                const StencilAreaModel& m_model;
                StencilAreaRenderable* m_pRenderable;
            };
        }
    }
}