// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "AsyncTexturing.h"
#include "AsyncModels.h"
#include "Helpers.h"
#include "Rendering.h"
#include "Web.h"
#include "WebLoadRequestCompletionCallback.h"
#include <string>
#include <deque>
#include <vector>
#include <map>
#include "PendingWebRequestsContainer.h"

namespace Eegeo
{
    namespace Io
    {
        namespace AsyncModels
        {
            typedef std::vector<IAsyncModel*> TIAsyncModels;
            
            class HttpAsyncModelLoader : protected Eegeo::NonCopyable
            {
            public:
                HttpAsyncModelLoader(
                                Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                Eegeo::Helpers::IHttpCache& httpCache,
                                Rendering::SceneModels::SceneModel* pPlaceholderModel,
                                Rendering::SceneModels::SceneModelFactory& sceneModelFactory
                                );
                
                IAsyncModel& CreateLoadRequest(const std::string& modelUrl, IAsyncModelObserver* pObserver, bool destroyObserverOnCompletion);
                void Cancel(IAsyncModel& modelToRelease);
                
                void IssueNextLoadRequest();
                bool HasPendingLoadRequests() const;
                
            private:
                Web::IWebLoadRequestFactory& m_webLoadRequestFactory;
                Eegeo::Helpers::IHttpCache& m_httpCache;
            
                Rendering::SceneModels::SceneModel* m_pPlaceholderModel;
                Rendering::SceneModels::SceneModelFactory& m_sceneModelFactory;
                
                typedef std::deque<HttpAsyncModel*> TModelDeque;
                TModelDeque m_pendingLoads;
                int m_inFlightLoadCount;
                
                Web::TWebLoadRequestCompletionCallback<HttpAsyncModelLoader> m_webRequestCompletionCallback;
                Web::PendingWebRequestsContainer m_pendingWebRequestsContainer;
                
                HttpAsyncModel* CreateModel(const std::string& modelUrl, IAsyncModelObserver* pObserver, bool destroyObserverOnCompletion);
                void StartLoadingModel(HttpAsyncModel* pModel);
                void OnWebLoadComplete(Web::IWebResponse& webResponse);
                void Evict(IAsyncModel* pModel);
                void FinaliseModelLoad(HttpAsyncModel* pAsyncModel, const std::vector<Byte>& buffer);
                
                typedef std::map<IAsyncModel*, Web::IWebLoadRequest*> TModelToRequest;
                TModelToRequest m_requestByModel;
            };
        }
    }
}
