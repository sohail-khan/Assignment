// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "UrlHelpers.h"
#include "WindowsNativeState.h"
#include <string>

namespace Eegeo
{
	namespace Windows
	{
		class WindowsUrlEncoder : public Eegeo::NonCopyable, public Eegeo::Helpers::UrlHelpers::IUrlEncoder
		{
			WindowsNativeState* m_pState;
        	//jclass m_encoderClass;
        	//jmethodID m_encodeMethod;

        public:
        	WindowsUrlEncoder(WindowsNativeState* pState);

			virtual void UrlEncode(const std::string& input, std::string& output)const;

			virtual void UrlDecode(const std::string& input, std::string& output)const;
		};
	}
}
