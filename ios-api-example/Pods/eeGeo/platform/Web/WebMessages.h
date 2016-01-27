// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Web.h"
#include "WebRequestDto.h"
#include "WebResponseDto.h"

namespace Eegeo
{
    namespace Web
    {
        class WebRequestLoadMessage
        {
        public:
            WebRequestLoadMessage(const WebRequestDto& webRequestDto)
            : m_webRequestDto(webRequestDto)
            {

            }
            
            const WebRequestDto& GetWebRequestDto() const
            {
                return m_webRequestDto;
            }
            
        private:
            const WebRequestDto m_webRequestDto;
        };

        class WebRequestCancelMessage
        {
        public:
            WebRequestCancelMessage(const TWebRequestId requestId)
            : m_requestId(requestId)
            {

            }

            TWebRequestId GetWebRequestId() const
            {
                return m_requestId;
            }

        private:
            TWebRequestId m_requestId;
        };
        
        class WebResponseFromWireMessage
        {
        public:
            WebResponseFromWireMessage(const WebResponseDto& webResponseDto)
            : m_webResponseDto(webResponseDto)
            {
            
            }
        
            const WebResponseDto& GetWebResponseDto() const
            {
                return m_webResponseDto;
            }
            
        private:
            const WebResponseDto m_webResponseDto;
        };
        
        class WebResponseFallBackToCacheMessage
        {
        public:
            WebResponseFallBackToCacheMessage(const TWebRequestId requestId)
            : m_requestId(requestId)
            {
                
            }
            
            TWebRequestId GetWebRequestId() const
            {
                return m_requestId;
            }
            
        private:
            TWebRequestId m_requestId;
        };

        class WebResponseFromCacheMessage
        {
        public:
            WebResponseFromCacheMessage(const WebResponseDto& webResponseDto)
                    : m_webResponseDto(webResponseDto)
            {

            }

            const WebResponseDto& GetWebResponseDto() const
            {
                return m_webResponseDto;
            }

        private:
            const WebResponseDto m_webResponseDto;
        };

        class WebPauseMessage
        {

        };

        class WebResumeMessage
        {

        };

        class WebStopWorkMessage
        {

        };
    }
}
