// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IRenderableFilter.h"
#include <vector>
#include "SceneModel.h"
#include "SceneModelNode.h"
#include "SceneModelRenderable.h"
#include "RenderContext.h"
#include "RenderQueue.h"
#include "SceneModelNodeVisitors.h"
#include "DebugRendering.h"
#include <algorithm>
#include <stack>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            class SceneModelRenderableFilter : public IRenderableFilter, SceneModels::ISceneModelNodeRenderVisitor
            {
            public:
                
                SceneModelRenderableFilter(DebugRendering::DebugRenderer& debugRenderer);
                
                void AddSceneModel(SceneModels::SceneModel& sceneModel);
                void RemoveSceneModel(SceneModels::SceneModel& sceneModel);
                
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                void EnqueueForRendering(SceneModels::SceneModelNode& node, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                void EnqueueForRendering(SceneModels::SceneModelRenderableNode& node, const Rendering::RenderContext& renderContext, RenderQueue& renderQueue);
                
            private:
                std::vector<SceneModels::SceneModel*> m_sceneModels;
                
                DebugRendering::DebugRenderer& m_debugRenderer;
                bool m_drawNodeSpheres;
            };
        }
    }
}
