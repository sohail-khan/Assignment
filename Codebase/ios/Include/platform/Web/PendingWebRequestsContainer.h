// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Web.h"
#include "Types.h"
#include <set>

namespace Eegeo
{
    namespace Web
    {
        class PendingWebRequestsContainer
        {
            typedef std::set<IWebLoadRequest*> TContainer;
            typedef TContainer::iterator TIterator;
            
            TContainer m_requests;
            
        public:
            ~PendingWebRequestsContainer();
            
            void InsertRequest(IWebLoadRequest& request);
            void RemoveRequest(IWebLoadRequest& request);
            void RemoveRequest(IWebResponse& response);

            void CancelAndRemoveAllRequests();
        };
    }
}
