// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelResourceBase.h"
#include "Types.h"
#include "SceneModelMaterial.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelMaterialResource : public SceneModelResourceBase, private Eegeo::NonCopyable
            {
            public:
                
                SceneModelMaterialResource(const std::string& name, Materials::SceneModelMaterial* pMaterial)
                : SceneModelResourceBase(name)
                , m_pMaterial(pMaterial)
                {
                    
                }
                
                ~SceneModelMaterialResource()
                {
                    Eegeo_DELETE m_pMaterial;
                    m_pMaterial = NULL;
                }
                
                Materials::SceneModelMaterial* GetMaterial() const { return m_pMaterial; }
                
            private:
                
                Materials::SceneModelMaterial* m_pMaterial;
            };
        }
    }
}