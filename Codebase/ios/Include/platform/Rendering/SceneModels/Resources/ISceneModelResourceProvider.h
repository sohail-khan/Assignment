// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            template <typename TResourceType>
            class ISceneModelResourceProvider
            {
            public:
                
                virtual ~ISceneModelResourceProvider() {};
                
                virtual TResourceType& UseResource(const std::string& name) = 0;
                virtual bool HasResource(const std::string& name) const = 0;
                virtual void ReleaseUnusedResources() = 0;
            };
        }
    }
}