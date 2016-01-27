// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsCellResourceObserver : private Eegeo::NonCopyable
            {
            public:
                void RegisterAddedToSceneGraphCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);
                void UnregisterAddedToSceneGraphCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);
                
                void RegisterRemovedFromSceneGraphCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);
                void UnregisterRemovedFromSceneGraphCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);

                void RegisterResourceDeletedCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);
                void UnregisterResourceDeletedCallback(Helpers::ICallback1<const InteriorsCellResource>& callback);
            
                void NotifyAddedToSceneGraph(const InteriorsCellResource& interiorsCellResource);
                void NotifyRemovedFromSceneGraph(const InteriorsCellResource& interiorsCellResource);
                void NotifyResourceDeleted(const InteriorsCellResource& interiorsCellResource);
            private:
                Helpers::CallbackCollection1<const InteriorsCellResource> m_addedToSceneGraphCallbacks;
                Helpers::CallbackCollection1<const InteriorsCellResource> m_removedFromSceneGraphCallbacks;
                Helpers::CallbackCollection1<const InteriorsCellResource> m_resourceDeletedCallbacks;
            };
        }
    }
}