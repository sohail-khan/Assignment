// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <sstream>
#include <string>

namespace Eegeo
{
    namespace Search
    {
        namespace Service
        {
            class SearchServiceCredentials : public Eegeo::NonCopyable
            {
                std::string m_appKey;
                std::string m_appCode;
                
            public:
                SearchServiceCredentials(const std::string& appKey, const std::string& appCode)
                :m_appKey(appKey)
                ,m_appCode(appCode)
                {
                }
                
                const std::string& key() const { return m_appKey; } 
                const std::string& code() const { return m_appCode; } 
            };
            
            inline void AppendQueryStringCredentialsToStringStream(const SearchServiceCredentials& credentials,
                                                            std::stringstream& ss)
            {
                ss << "app_id=" << credentials.key() << "&app_code=" << credentials.code();
            }
        }
    }
}
