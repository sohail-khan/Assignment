// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "VertexBinding.h"
#include <set>

#define LOG_VERTEX_BINDING_POOL 0

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            /*!
             * \brief A pool of VertexBinding objects.
             *
             * This pool keeps a persistent set of vertex bindings for pairings of VertexLayout and VertexAttribs.
             */
            class VertexBindingPool : protected Eegeo::NonCopyable
            {
            public:
                const VertexBinding& GetVertexBinding(const VertexLayout& layout, const VertexAttribs& attribs);
            private:
                typedef std::set<VertexBinding> TVertexBindings;
                TVertexBindings m_bindings;
            };
        }
    }
}
