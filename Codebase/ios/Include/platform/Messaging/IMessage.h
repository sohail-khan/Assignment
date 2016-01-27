// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Messaging
    {
        template<typename D>
        class IMessage
        {
        public:
            virtual ~IMessage() {};
            virtual bool Handle(D& dispatcher) const = 0;
        };
    }
}
