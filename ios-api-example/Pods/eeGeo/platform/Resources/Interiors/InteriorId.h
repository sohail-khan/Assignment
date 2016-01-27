// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "CallbackCollection.h"
#include "ICallback.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            struct InteriorId
            {
                InteriorId()
                {}
                
                InteriorId(std::string interiorId)
                : m_interiorId(interiorId)
                {}
                
                std::string Value() const { return m_interiorId; }
                
                bool operator ==(const InteriorId& other) const { return Value() == other.Value(); }
                
                bool operator !=(const InteriorId& other) const { return Value() != other.Value(); }
                
                bool IsValid() const { return !m_interiorId.empty(); }
                
                inline static InteriorId NullId() { return InteriorId(""); }
            private:
                std::string m_interiorId;
            };
        }
    }
}