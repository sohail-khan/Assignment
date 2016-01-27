// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

//#ifdef EEGEO_IOS

#include "Types.h"
#include "Rendering.h"
#include "Graphics.h"
#include <vector>
#include <utility>

#define LOG_VAO_CACHE   0

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A cache of OpenGL vertex array objects (VAOs), keyed by VertexBinding.
         *
         * Typically each Mesh contains a single VAOCache. This cache contains a seperate vertex array object (VAO) for each vertex binding that the mesh has been used with.
         */
        class VAOCache : protected Eegeo::NonCopyable
        {
        public:
            ~VAOCache();
            
            bool TryGetVAOForVertexBinding(const VertexLayouts::VertexBinding* pVertexBinding, GLuint* out_foundVAO) const;
            
            GLuint CreateVAOForVertexBinding(const VertexLayouts::VertexBinding* pVertexBinding);
            
            int GetNumOfVAOs() const
            {
                return static_cast<int>(m_vaosByVertexBinding.size());
            }
            
        private:
            typedef std::pair<const VertexLayouts::VertexBinding*, GLuint> TVertexBindingVAOPair;
            typedef std::vector<TVertexBindingVAOPair> TVertexBindingToVAO;
            TVertexBindingToVAO m_vaosByVertexBinding;
        };
    }
}

//#endif
