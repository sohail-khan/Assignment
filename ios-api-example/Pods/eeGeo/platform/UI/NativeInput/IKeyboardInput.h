// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            enum KeyboardType
            {
                KeyboardTypeDefault
            };
            
            enum ReturnKeyType
            {
                ReturnKeyDone,
                ReturnKeyGo,
                ReturnKeySearch
            };
            
            class IKeyboardInput
            {
            public:
                virtual ~IKeyboardInput() {}
                
                virtual void Dismiss() = 0;
            };
        }
    }
}
