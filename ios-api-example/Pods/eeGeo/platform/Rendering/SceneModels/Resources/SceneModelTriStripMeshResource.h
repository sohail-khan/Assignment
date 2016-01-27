// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelResourceBase.h"
#include "Types.h"
#include "TriStripMesh.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelTriStripMeshResource : public SceneModelResourceBase, private Eegeo::NonCopyable
            {
            public:
                
                SceneModelTriStripMeshResource(const std::string& name, TriStripMesh* pMesh)
                : SceneModelResourceBase(name)
                , m_pMesh(pMesh)
                {
                    
                }
                
                ~SceneModelTriStripMeshResource()
                {
                    Eegeo_DELETE m_pMesh;
                    m_pMesh = NULL;
                }
                
                TriStripMesh* GetMesh() const { return m_pMesh; }
                
            private:
                
                TriStripMesh* m_pMesh;
            };
        }
    }
}

