//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "StencilArea.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            typedef std::string TStencilPaletteId;
            
            class StencilAreaPaletteModel : private Eegeo::NonCopyable
            {
            public:
                class StencilAreaPaletteBuilder : private Eegeo::NonCopyable
                {
                public:
                    StencilAreaPaletteBuilder(const TStencilPaletteId id, const Eegeo::v4& color)
                    : m_id(id)
                    , m_color(color)
                    , m_finished(false)
                    {
                    }
                    
                    StencilAreaPaletteModel* Build();
                private:
                    const TStencilPaletteId m_id;
                    const Eegeo::v4 m_color;
                    bool m_finished;
                };
                
                
                const TStencilPaletteId& GetID() const { return m_id; }
                const Eegeo::v4& GetColor() const { return m_color; }
            private:
                StencilAreaPaletteModel() { };
                TStencilPaletteId m_id;
                Eegeo::v4 m_color;
            };
        }
    }
}