// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "VectorMath.h"
#include "Types.h"
#include "LayerIds.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModel : private Eegeo::NonCopyable
            {
            public:
                
                SceneModel(u32 animationFrames);
                ~SceneModel();
                
                SceneModelNode& GetRootNode() const { return *m_pRootNode; }
                SceneModelNode* GetNodeWithName(const std::string& name) const;
                
                void AddNode(SceneModelNode* pNode);
                void RemoveNode(SceneModelNode* pNode);
                
                const dv3& GetEcefPosition() const { return m_ecefOrigin; }
                void SetEcefPosition(const dv3& ecefPosition);
                
                void SetLayer(Rendering::LayerIds::Values layer);
                void SetDepthTesting(bool enabled);
                void SetDepthRange(float near, float far);
                
                void PreRender();
                
                const u32 GetAnimationFrameCount() const { return m_animationFrames; }
                
                SceneModel* Clone();
                
            private:

                SceneModel(SceneModel& source);
                
                SceneModelNode* m_pRootNode;
                
                dv3 m_ecefOrigin;
                
                const u32 m_animationFrames;
            };
        }
    }
}
