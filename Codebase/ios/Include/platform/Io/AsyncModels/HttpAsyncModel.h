// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncModel.h"
#include "AsyncModels.h"
#include "Rendering.h"
#include "Web.h"
#include <string>

namespace Eegeo
{
    namespace Io
    {
        namespace AsyncModels
        {
            class HttpAsyncModel : protected Eegeo::NonCopyable, public IAsyncModel
            {
            public:
                HttpAsyncModel(
                           const std::string& modelUrl,
                           Rendering::SceneModels::SceneModel* pInitialModel,
                           IAsyncModelObserver* pObserver,
                           bool destroyObserverOnCompletion
                           );
                ~HttpAsyncModel();
                
                void Release();
                const std::string GetUrl() const;
                
                bool TryGetModel(Rendering::SceneModels::SceneModel*& out_pModel) const;
                bool IsLoaded() const;
               
                void SetWebLoadRequest(Eegeo::Web::IWebLoadRequest* pWebLoadRequest);
                void ClearWebLoadRequest();
                void SetLoadedModel(Rendering::SceneModels::SceneModel& model);
                void DispatchLoadCompleteNotication();
                void DispatchLoadFailNotification();
                
            private:
                std::string m_name;
                std::string m_url;
                Rendering::SceneModels::SceneModel* m_pModel;
                bool m_isLoaded;
                Eegeo::Web::IWebLoadRequest* m_pWebLoadRequest;
                IAsyncModelObserver* m_pObserver;
                bool m_destroyObserverOnCompletion;
            };
        }
    }
}