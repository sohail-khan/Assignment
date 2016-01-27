// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "WebMessages.h"
#include "CatalogBinding.h"

namespace Eegeo
{
    namespace Web
    {
        class MainToWebIOMessageCatalog
                : public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebRequestLoadMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebRequestCancelMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebPauseMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebResumeMessage>
                , public Eegeo::Messaging::CatalogBinding<Eegeo::Web::WebStopWorkMessage>
                , private Eegeo::NonCopyable
        {

        };
    }
}