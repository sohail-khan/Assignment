// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelResourceBase.h"
#include "Types.h"
#include "Mesh.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelMeshResource : public SceneModelResourceBase, private Eegeo::NonCopyable
            {
            public:
                
                SceneModelMeshResource(const std::string& name, Mesh* pMesh)
                : SceneModelResourceBase(name)
                , m_pMesh(pMesh)
                {
                    
                }
                
                ~SceneModelMeshResource()
                {
                    Eegeo_DELETE m_pMesh;
                    m_pMesh = NULL;
                }
                
                Mesh* GetMesh() const { return m_pMesh; }
                
            private:
                
                Mesh* m_pMesh;
            };
        }
    }
}