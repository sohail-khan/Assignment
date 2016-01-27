// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "AndroidNativeState.h"
#include "InputBox.h"
#include "IInputBox.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            namespace Android
            {
                class AndroidInputBox : public IInputBox
                {
                	AndroidNativeState* m_pState;
                    IInputBoxDismissedHandler& m_handler;
                    bool m_closed;
                    bool m_nativesRequireUnregistering;

                    //sjm - we could store a jobject here if there is more than one inputbox, and implement via instance rather than
                    //static methods - would be easy, change should be made here if need to do that arises
                	jclass m_msgBoxClass;

                public:
                    AndroidInputBox(
                    		AndroidNativeState* pState,
                    		const std::string& title,
							const std::string& message,
							const std::string& button,
							const std::string& initialContent,
							bool initialContentIsPlaceholder,
							IInputBoxDismissedHandler& handler);

                    virtual ~AndroidInputBox();

                    void DismissFromJavaCallback();

                    virtual void Close();
                };
            }
        }
    }
}

