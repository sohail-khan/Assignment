// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
	namespace Helpers
	{
        namespace UrlHelpers
		{
            class IUrlEncoder
            {
            public:
                virtual ~IUrlEncoder(){}
                virtual void UrlEncode(const std::string& input, std::string& output)const=0;
                virtual void UrlDecode(const std::string& input, std::string& output)const=0;
            };
        }
    }
}
