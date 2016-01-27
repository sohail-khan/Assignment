// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "POD.h"
#include <vector>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODScene
            {
            private:
                std::vector<PODMesh*> m_podMeshes;
                std::vector<PODNode*> m_podNodes;
                std::vector<PODMaterial*> m_podMaterials;
                std::vector<PODTexture*> m_podTextures;
                u32 m_flags;
                u32 m_numOfFrames;
                u32 m_numMeshNodes;
                
            public:
                PODScene();
                ~PODScene();
                
                void AddMesh(PODMesh* podMesh);
                void AddNode(PODNode* podNode);
                void AddMaterial(PODMaterial* podMaterial);
                void AddTexture(PODTexture* podTexture);
                void SetFlags(u32 flags);
                void SetNumOfFrames(u32 numOfFrames);
                void SetNumMeshNodes(u32 numMeshNodes);
                
                int GetNumOfMeshes() const;
                int GetNumOfNodes() const;
                int GetNumOfMaterials() const;
                int GetNumOfTextures() const;
                const u32 GetNumMeshNodes() const;

                const PODMesh* GetMesh(u32 meshIndex) const;
                const PODNode* GetNode(u32 nodeIndex) const;
                const PODMaterial* GetMaterial(u32 materialIndex) const;
                const PODTexture* GetTexture(u32 textureIndex) const;
                u32 GetFlags() const;
                u32 GetNumOfFrames() const;
            };
        }
    }
}
