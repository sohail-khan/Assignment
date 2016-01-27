// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            class IInputBox
            {
            public:
                virtual ~IInputBox() {}
                
                virtual void Close()=0;
            };
        }
    }
}
