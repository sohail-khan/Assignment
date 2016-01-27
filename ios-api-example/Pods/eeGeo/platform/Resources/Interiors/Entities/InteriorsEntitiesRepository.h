// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "CallbackCollection.h"

#include <vector>
#include <map>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                typedef std::vector<InteriorsEntityModel*> TEntityModelVector;
                typedef std::map<std::string, TEntityModelVector> TInteriorToEntitiesMap;
                
                class InteriorsEntitiesRepository
                {
                public:
                    const TEntityModelVector& GetAllStreamedEntitiesForInterior(const std::string& interiorName);
                    void AddEntitiesForInterior(const std::string& interiorName, const TEntityModelVector& entities);
                    void RemoveEntitiesForInterior(const std::string& interiorName, const TEntityModelVector& entities);
                    
                    void RegisterEntitiesAddedCallback(Helpers::ICallback2<const std::string&, const TEntityModelVector&>& callback);
                    void UnregisterEntitiesAddedCallback(Helpers::ICallback2<const std::string&, const TEntityModelVector&>& callback);
                    void RegisterEntitiesRemovedCallback(Helpers::ICallback2<const std::string&, const TEntityModelVector&>& callback);
                    void UnregisterEntitiesRemovedCallback(Helpers::ICallback2<const std::string&, const TEntityModelVector&>& callback);
                    
                private:
                    
                    TInteriorToEntitiesMap m_interiorToEntities;
                    
                    Helpers::CallbackCollection2<const std::string&, const TEntityModelVector&> m_entitiesAddedCallbacks;
                    Helpers::CallbackCollection2<const std::string&, const TEntityModelVector&> m_entitiesRemovedCallbacks;
                };
            }
        }
    }
}