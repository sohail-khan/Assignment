// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IdTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Shaders
        {
            class ShaderIdGenerator : protected Eegeo::NonCopyable
            {
            public:
                ShaderIdGenerator()
                : m_nextId(0)
                {
                }
                
                TShaderId GetNextId()
                {
                    return m_nextId++;
                }
                
            private:
                TShaderId m_nextId;
            };
        }
    }
}