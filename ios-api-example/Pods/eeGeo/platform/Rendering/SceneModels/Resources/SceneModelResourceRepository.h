// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ISceneModelResourceProvider.h"
#include <string>
#include <map>
#include <vector>

#define LOG_SCENEMODEL_RESOURCE_REPO_DEBUG_MESSAGES

#if defined (LOG_SCENEMODEL_RESOURCE_REPO_DEBUG_MESSAGES)
#define DEBUG_LOG Eegeo_TTY
#else
#define DEBUG_LOG if (1) {} else Eegeo_TTY
#endif

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            template <typename TResourceType, typename TResourceInternalType>
            class SceneModelResourceRepository : public ISceneModelResourceProvider<TResourceType>
            {
            public:
                ~SceneModelResourceRepository()
                {
                    ReleaseUnusedResources();
                }
                
                void Insert(const std::string& name, TResourceInternalType* pMesh)
                {
                    typename std::map<std::string, TResourceType*>::iterator value = m_resourceMap.find(name);
                    Eegeo_ASSERT(value == m_resourceMap.end(), "Already have a mesh resource: %s", name.c_str());
                    if (value == m_resourceMap.end())
                    {
                        TResourceType* sceneMeshResoure = Eegeo_NEW(TResourceType)(name, pMesh);
                        m_resourceMap[name] = sceneMeshResoure;
                    }
                }
                
                TResourceType& UseResource(const std::string& name)
                {
                    typename std::map<std::string, TResourceType*>::iterator value = m_resourceMap.find(name);
                    Eegeo_ASSERT(value != m_resourceMap.end(), "Cannot find resource: %s", name.c_str());
                    value->second->IncrementReferenceCount();
                    return *value->second;
                }
                
                bool HasResource(const std::string& name) const
                {
                    typename std::map<std::string, TResourceType*>::const_iterator value = m_resourceMap.find(name);
                    return value != m_resourceMap.end();
                }
                
                void ReleaseUnusedResources()
                {
                    std::vector<std::string> resourcesToErase;
                    for(typename std::map<std::string, TResourceType*>::iterator it = m_resourceMap.begin(); it != m_resourceMap.end(); it++)
                    {
                        if (!it->second->IsReferenced())
                        {
                            Eegeo_DELETE it->second;
                            resourcesToErase.push_back(it->first);
                        }
                    }
                    
                    for(std::vector<std::string>::iterator it = resourcesToErase.begin(); it != resourcesToErase.end(); ++it)
                    {
                        DEBUG_LOG("Deleting scene model resource: %s\n", (*it).c_str());
                        m_resourceMap.erase(*it);
                    }
                }

                
            protected:
                
                std::map<std::string, TResourceType*> m_resourceMap;
            };
        }
    }
}