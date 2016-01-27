// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "AndroidNativeState.h"
#include "AlertBox.h"
#include "ISingleOptionAlertbox.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeAlerts
        {
            namespace Android
            {
                class AndroidSingleOptionAlertBox : public ISingleOptionAlertBox
                {
                	AndroidNativeState* m_pState;
                	ISingleOptionAlertBoxDismissedHandler& m_handler;
                    bool m_closed;
                    bool m_nativesRequireUnregistering;

                    //sjm - we could store a jobject here if there is more than one inputbox, and implement via instance rather than
                    //static methods - would be easy, change should be made here if need to do that arises
                	jclass m_msgBoxClass;

                public:
                	AndroidSingleOptionAlertBox(
                			AndroidNativeState* pState,
                    		const std::string& title,
							const std::string& message,
							ISingleOptionAlertBoxDismissedHandler& handler);

                    virtual ~AndroidSingleOptionAlertBox();

                    void DismissFromJavaCallback();

                    virtual void Close();
                };
            }
        }
    }
}

