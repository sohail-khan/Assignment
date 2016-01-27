// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include <map>
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            typedef std::map<std::string, InteriorsModel*> TInteriorsContainer;
            
            class InteriorsModelRepository
            {
            public:
                
                InteriorsModelRepository();
                ~InteriorsModelRepository();
                
                void AddInterior(InteriorsModel& pModelToAdd);
                void RemoveInterior(const std::string& interiorName);
                
                bool HasInterior(const std::string& interiorName) const;
                InteriorsModel& GetInterior(const std::string& interiorName) const;
                
                TInteriorsContainer& GetAllInteriors();
                
                void RegisterAddedCallback(Helpers::ICallback1<InteriorsModel&>& callback);
                void RegisterRemovedCallback(Helpers::ICallback1<InteriorsModel&>& callback);
                void UnregisterAddedCallback(Helpers::ICallback1<InteriorsModel&>& callback);
                void UnregisterRemovedCallback(Helpers::ICallback1<InteriorsModel&>& callback);
            private:
                
                TInteriorsContainer m_interiors;
                
                Helpers::CallbackCollection1<InteriorsModel&> m_addedCallbacks;
                Helpers::CallbackCollection1<InteriorsModel&> m_removedCallbacks;
            };
        }
    }
}
