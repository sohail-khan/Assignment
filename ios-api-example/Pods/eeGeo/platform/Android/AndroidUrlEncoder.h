// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "UrlHelpers.h"
#include "AndroidNativeState.h"
#include <string>

namespace Eegeo
{
	namespace Android
	{
		class AndroidUrlEncoder : public Eegeo::NonCopyable, public Eegeo::Helpers::UrlHelpers::IUrlEncoder
		{
			AndroidNativeState* m_pState;
        	jclass m_encoderClass;
        	jmethodID m_encodeMethod;
        	jmethodID m_decodeMethod;

        public:
        	AndroidUrlEncoder(AndroidNativeState* pState);

			virtual void UrlEncode(const std::string& input, std::string& output)const;
			virtual void UrlDecode(const std::string& input, std::string& output)const;
		};
	}
}
