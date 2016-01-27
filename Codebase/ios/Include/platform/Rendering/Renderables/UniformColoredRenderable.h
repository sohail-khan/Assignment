// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "WorldMeshRenderable.h"
#include "LayerIds.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Graphics.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class UniformColoredRenderable : public WorldMeshRenderable
            {
            public:
                UniformColoredRenderable(
                        const LayerIds::Values layerId,
                        Materials::IMaterial* material,
                        const VertexLayouts::VertexBinding& vertexBinding,
                        Rendering::Mesh* pMesh,
                        const Eegeo::dv3 ecefPosition,
                        const Eegeo::v4 initialColor)
                : WorldMeshRenderable(layerId, material, vertexBinding, pMesh, ecefPosition)
                , m_color(initialColor)
                {

                }

                void SetColor(const v4& color) { m_color = color; }
                v4 GetColor() const { return m_color; }

            protected:
                v4 m_color;
            };
        }
    }
}
