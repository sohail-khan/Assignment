// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            /*!
             * \brief A pool of reusable VertexLayouts for common vertex formats.
             */
            class VertexLayoutPool : protected Eegeo::NonCopyable
            {
            public:
                VertexLayoutPool();
                ~VertexLayoutPool();

                const VertexLayout& GetForPackedDiffuseVertex() const;
                const VertexLayout& GetForDiffuseVertex() const;
                const VertexLayout& GetFor2DTexturedVertex() const;
                const VertexLayout& GetForTextVertex() const;
                const VertexLayout& GetForPackedTwoTextureVertex() const;
                const VertexLayout& GetForPackedStencilShadowVertex() const;
                const VertexLayout& GetForPositionVertex() const;
                const VertexLayout& GetForColoredVertex() const;
                const VertexLayout& GetForTexturedVertex() const;
                const VertexLayout& GetForTexturedColoredVertex() const;
                const VertexLayout& GetForModelDiffuseVertex() const;
                const VertexLayout& GetForPackedPositionUvLightDotsColourVertex() const;
                const VertexLayout& GetForPackedPositionNormalUvColourVertex() const;
                const VertexLayout& GetForPackedPositionNormalUvVertex() const;
                
            private:
                VertexLayout* m_pPackedDiffuseLayout;
                VertexLayout* m_pDiffuseLayout;
                VertexLayout* m_p2dTexturedLayout;
                VertexLayout* m_pTextLayout;
                VertexLayout* m_pPackedTwoTextureLayout;
                VertexLayout* m_pPackedStencilShadowLayout;
                VertexLayout* m_pPositionLayout;
                VertexLayout* m_pTexturedLayout;
                VertexLayout* m_pColoredLayout;
                VertexLayout* m_pTexturedColoredLayout;
                VertexLayout* m_pModelDiffuseLayout;
                VertexLayout* m_pPackedPositionUvLightDotsColourVertex;
                VertexLayout* m_pPackedPositionNormalUvColourVertex;
                VertexLayout* m_pPackedPositionNormalUvVertex;
                            
                static VertexLayout* CreateForPackedDiffuseVertex();
                static VertexLayout* CreateForDiffuseVertex();
                static VertexLayout* CreateFor2DTexturedVertex();
                static VertexLayout* CreateForTextVertex();
                static VertexLayout* CreateForPackedTwoTextureVertex();
                static VertexLayout* CreateForPackedStencilShadowVertex();
                static VertexLayout* CreateForPositionVertex();
                static VertexLayout* CreateForTexturedVertex();
                static VertexLayout* CreateForColoredVertex();
                static VertexLayout* CreateForTexturedColoredVertex();
                static VertexLayout* CreateForModelDiffuseVertex();
                static VertexLayout* CreateForPackedPositionUvLightDotsColourVertex();
                static VertexLayout* CreateForPackedPositionNormalUvColourVertex();
                static VertexLayout* CreateForPackedPositionNormalUvVertex();
            };
        }
    }
}
