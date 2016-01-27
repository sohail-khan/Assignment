// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "UrlHelpers.h"
#include <string>

namespace Eegeo
{
	namespace OSX
	{
		class OSXUrlEncoder : public Eegeo::NonCopyable, public Eegeo::Helpers::UrlHelpers::IUrlEncoder
		{
        public:
			virtual void UrlEncode(const std::string& input, std::string& output)const;
			virtual void UrlDecode(const std::string& input, std::string& output)const;
		};
	}
}
