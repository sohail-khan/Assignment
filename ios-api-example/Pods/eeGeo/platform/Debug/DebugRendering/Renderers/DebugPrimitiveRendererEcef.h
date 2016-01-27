// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "AllVertexTypes.h"
#include "DynamicBuffer.h"
#include "Rendering.h"
#include "Streaming.h"
#include "VectorMath.h"
#include "Camera.h"
#include "IRenderableFilter.h"
#include "DebugPrimitiveRenderable.h"

#include <vector>

namespace Eegeo
{
    namespace DebugRendering
    {
        namespace Renderers
        {
            class DebugPrimitiveRendererEcef : public Rendering::IRenderableFilter
            {
                struct DebugPrimitiveSpec
                {
                    DebugPrimitiveSpec()
                    {}

                    std::vector<v3> LocalVerts;
                    std::vector<u16> LocalIndices;
                };

                struct DebugPrimitiveEcef
                {
                    m44 Orientation;
                    dv3 Origin;
                    v4 Color;
                    const DebugPrimitiveSpec* pPrimSpec;
                    float Lifetime;
                };

            public:
                DebugPrimitiveRendererEcef(Rendering::Materials::IMaterial* pMaterial,
                                           const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                           int vertexBufferSize,
                                           int indexBufferSize);

                ~DebugPrimitiveRendererEcef();

                void DrawCube(
                        const dv3& ecefOrigin,
                        const m44& transform,
                        const v4& colour,
                        const float lifetime);

                void DrawSphere(
                        const dv3& ecefOrigin,
                        const m44& transform,
                        const v4& colour,
                        const float lifetime);

                void DrawQuad(
                        const dv3& ecefOrigin,
                        const m44& transform,
                        const v4& colour,
                        const float lifetime);
                
                void Update(float dt, const Camera::RenderCamera& renderCamera);
                
                void GenerateGeometry(const Camera::RenderCamera& renderCamera);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
                
                void SetDepthEnabled(const bool depthEnabled);
                
            private:
                void DrawPrimitive(
                        const DebugPrimitiveSpec* pPrimSpec,
                        const dv3& ecefOrigin,
                        const m44& transform,
                        const v4& colour,
                        const float lifetime);

                void GenerateGeometryForSingleInstance(const DebugPrimitiveEcef& data,
                                                       const Camera::RenderCamera& renderCamera);
                
                DebugRendering::DebugPrimitiveRenderable* m_pDebugPrimitiveRenderable;

                DebugPrimitiveSpec m_primSpecCube;
                DebugPrimitiveSpec m_primSpecSphere;
                DebugPrimitiveSpec m_primSpecQuad;

                std::vector<DebugPrimitiveEcef> m_drawData;
            };
        }
    }
}

