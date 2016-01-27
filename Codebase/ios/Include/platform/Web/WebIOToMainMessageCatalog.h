// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "WebMessages.h"
#include "CatalogBinding.h"

namespace Eegeo
{
    namespace Web
    {
        class WebIOToMainMessageCatalog
                : public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebResponseFromWireMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebResponseFallBackToCacheMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebResponseFromCacheMessage>
                , private Eegeo::NonCopyable
        {

        };
    }
}