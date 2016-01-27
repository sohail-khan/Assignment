// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace Helpers
    {
        typedef int TIdentity;

        class IIdentity
        {
        public:
            virtual ~IIdentity() {}
            
            virtual TIdentity GetIdentity() const = 0;
        };
        
        class IIdentityProvider
        {
        public:
            virtual ~IIdentityProvider() {}
            
            virtual TIdentity GetNextIdentity() = 0;
        };
        
        class IdentityProvider : public IIdentityProvider, private Eegeo::NonCopyable
        {
            TIdentity m_current;
        public:
            IdentityProvider() :m_current(0) { }
            
            TIdentity GetNextIdentity() { return m_current ++; }
        };
        
        inline bool operator==(const IIdentity& lhs, const IIdentity& rhs){ return lhs.GetIdentity() == rhs.GetIdentity(); }
        
        inline bool operator!=(const IIdentity& lhs, const IIdentity& rhs){return !operator==(lhs,rhs);}
    }
}
