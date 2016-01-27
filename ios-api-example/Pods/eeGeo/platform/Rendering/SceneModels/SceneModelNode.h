// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "SceneModelRenderable.h"
#include "SingleSphere.h"
#include "SceneModelNodeAnimation.h"
#include "SceneModelNodeVisitors.h"
#include "LayerIds.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelNode : public ISceneModelNodeRenderElement
            {
            public:
                
                SceneModelNode(std::string name);
                ~SceneModelNode();
                
                void AddNode(SceneModelNode* pNode);
                void RemoveNode(SceneModelNode* pNode);
                
                const std::string& GetName() const { return m_name; }
                void SetName(const std::string& name);
                
                const size_t GetChildCount() const { return m_childNodes.size(); }
                
                SceneModelNode* GetChild(uint index) const;
                SceneModelNode* GetNodeWithName(const std::string& name) const;
                
                void SetTransform(const m44& transform);
                const m44& GetLocalTransform() const { return m_localTransform; }
                const m44& GetWorldTransform() const { return m_worldTransform; }
                virtual void UpdateTransforms(const dv3& ecefOrigin, const m44& parentTransform, bool dirtyParent);
                
                virtual void SetLayer(Rendering::LayerIds::Values layer);
                virtual void SetDepthTestingRecursive(bool enabled);
                virtual void SetDepthRangeRecursive(float near, float far);
                
                void SetAnimationData(ISceneModelNodeAnimation* pAnimationData);
                ISceneModelNodeAnimation* GetAnimationData() const { return m_pAnimationData; }
                
                virtual void VisitForRendering(ISceneModelNodeRenderVisitor &visitor, const Rendering::RenderContext &renderContext, Eegeo::Rendering::RenderQueue &renderQueue);
                
                void SetBounds(const v3& center, const float radius);
                void UpdateSphereRecursive();
                const Geometry::SingleSphere& GetBoundingSphere() const { return m_worldBoundingSphere; }
                const Geometry::SingleSphere& GetSubtreeBoundingSphere() const { return m_subtreeBoundingSphere; }
                
                virtual SceneModelNode* Clone(SceneModelNode* pNewParent);
                
            protected:
                
                void SetParent(SceneModelNode* pParent);
                
                std::string m_name;
                SceneModelNode* m_pParentNode;
                std::vector<SceneModelNode*> m_childNodes;
                
                m44 m_localTransform;
                m44 m_worldTransform;
                
                bool m_transformDirty;
                
                dv3 m_ecefPosition;
                
                Geometry::SingleSphere m_localBoundingSphere;
                Geometry::SingleSphere m_worldBoundingSphere;
                Geometry::SingleSphere m_subtreeBoundingSphere;
                
                ISceneModelNodeAnimation* m_pAnimationData;
            };
        }
    }
}