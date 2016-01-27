// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            class ISingleOptionAlertBox
            {
            public:
                virtual ~ISingleOptionAlertBox() {}
                
                virtual void Close()=0;
            };
        }
    }
}
