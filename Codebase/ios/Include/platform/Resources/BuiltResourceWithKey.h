// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IBuiltResource.h"
#include "MortonKey.h"

namespace Eegeo
{
    namespace Resources
    {
        class BuiltResourceWithKey : public IBuiltResource
        {
        public:
            BuiltResourceWithKey(const Streaming::MortonKey& mortonKey)
            : m_key(mortonKey)
            {
                
            }

            const Eegeo::Streaming::MortonKey& GetKey() const
            {
                return m_key;
            }
            
        private:
            Eegeo::Streaming::MortonKey m_key;
        };
    }
}