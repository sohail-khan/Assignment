// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "BuildingFootprints.h"
#include "Streaming.h"

#include <string>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprintResourceStore
        {
        public:
            BuildingFootprintResourceStore(const std::string& serverBaseUrl,
                                           const std::string& featureRelativePath,
                                           const std::string& resourceName,
                                           const std::string& resourceExtension,
                                           const std::string& authPolicy,
                                           const std::string& authSignature,
                                           const std::string& authKeyPairId
                                           )
            : m_serverBaseUrl(serverBaseUrl)
            , m_featureRelativePath(featureRelativePath)
            , m_resourceName(resourceName)
            , m_resourceExtension(resourceExtension)
            , m_authPolicy(authPolicy)
            , m_authSignature(authSignature)
            , m_authKeyPairId(authKeyPairId)
            {}
            
            std::string UrlFor(const Eegeo::Streaming::MortonKey& key, const std::string& storePrefix) const;
            
        private:
            std::string AuthQueryString() const;
            
            const std::string m_serverBaseUrl;
            const std::string m_featureRelativePath;
            const std::string m_resourceName;
            const std::string m_resourceExtension;
            
            const std::string m_authPolicy;
            const std::string m_authSignature;
            const std::string m_authKeyPairId;
        };
    }
}
