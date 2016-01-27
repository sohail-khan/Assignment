// Copyright eeGeo Ltd (2012-2015), All Rights Reserved
#pragma once

#include "Types.h"
#include "Web.h"

#include <string>
#include <vector>
#include <queue>

namespace Eegeo
{
    namespace Web
    {
        class WebRequestHandlePool : private Eegeo::NonCopyable
        {
        public:
            WebRequestHandlePool(const int poolSize, const std::string& caCertFilePath);
            ~WebRequestHandlePool();

            bool HasCapacity() const;

            bool TryGetHandle(WebRequestHandle*& pOutHandle);
            void ReturnHandle(WebRequestHandle* pHandle);

            const std::vector<WebRequestHandle*>& GetHandlesInUse() const;
        private:
            std::vector<WebRequestHandle*> m_handlesInUse;
            std::queue<WebRequestHandle*> m_handlesFree;
            std::vector<WebRequestHandle*> m_handles; // debugging aid -- use to track handle in order of allocation (so we can say "slot 1 completed request, etc.")
        };
    }
}
