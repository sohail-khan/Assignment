// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Resources.h"
#include "Streaming.h"
#include <string>

namespace Eegeo
{
    namespace Streaming
    {
        class ResourceStreamComponent
        {
        public:
            ResourceStreamComponent(Resources::IResourceBuilder& resourceBuilder)
            : m_resourceBuilder(resourceBuilder)
            , m_priority(0)
            {
                
            }
            
            ResourceStreamComponent(std::string name,
                                    Resources::IResourceBuilder& resourceBuilder,
                                    std::string serverBaseUrl,
                                    std::string storeRelativePath,
                                    std::string featureRelativePath,
                                    std::string resourceName,
                                    std::string resourceExtension,
                                    int priority
                                    );
            
            std::string Name() const { return m_name; }
            Resources::IResourceBuilder& GetResourceBuilder() const { return m_resourceBuilder; }
            std::string UrlFor(const MortonKey& key, bool relativeUrl) const;
            std::string CoverageTreeUrl() const;
            std::string ResourceName() const;
            
            int GetPriority() const { return m_priority; }
            
        private:
            std::string m_name;
            Resources::IResourceBuilder& m_resourceBuilder;
            std::string m_serverBaseUrl;
            std::string m_storeRelativePath;
            std::string m_featureRelativePath;
            std::string m_resourceName;
            std::string m_resourceExtension;
            int m_priority;
        };
    }
}
