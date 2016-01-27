// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class ISceneModelNodeRenderVisitor
            {
            public:
                
                virtual ~ISceneModelNodeRenderVisitor() {}
                
                virtual void EnqueueForRendering(SceneModelNode& sceneModelNode, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue) = 0;
                virtual void EnqueueForRendering(SceneModelRenderableNode& sceneModelNode, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue) = 0;
                
            };
            
            class ISceneModelNodeRenderElement
            {
            public:
                virtual ~ISceneModelNodeRenderElement() {}
                
                virtual void VisitForRendering(ISceneModelNodeRenderVisitor& visitor, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue) = 0;
            };
        }
    }
}