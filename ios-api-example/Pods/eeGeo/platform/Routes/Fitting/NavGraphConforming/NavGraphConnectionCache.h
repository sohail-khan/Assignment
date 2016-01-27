// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Routes.h"
#include "tr1.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                using namespace Resources::Roads::Navigation;
                
                class NavGraphConnectionCache
                {
                public:

                    struct Key
                    {
                    private:
                        const NavigationGraphRoad* roadA;
                        const NavigationGraphRoad* roadB;
                        bool directionFromToA;
                        bool directionFromToB;
                        
                        
                    public:
                        Key(const NavigationGraphRoad* roadA,
                            const NavigationGraphRoad* roadB,
                            bool directionFromToA,
                            bool directionFromToB)
                        : roadA(roadA)
                        , roadB(roadB)
                        , directionFromToA(directionFromToA)
                        , directionFromToB(directionFromToB)
                        {
                            
                        }
                        
                        const NavigationGraphRoad* GetRoadA() const { return roadA; }
                        const NavigationGraphRoad* GetRoadB() const { return roadB; }
                        bool GetDirectionFromToA() const { return directionFromToA; }
                        bool GetDirectionFromToB() const { return directionFromToB; }
                    
                        bool operator ==(const Key& other) const
                        {
                            return roadA == other.roadA &&
                            roadB == other.roadB &&
                            directionFromToA == other.directionFromToA &&
                            directionFromToB == other.directionFromToB;
                        }
                    };
                    
                    
                    static Key MakeKey(const SolverNode& nodeA, const SolverNode& nodeB);
                    
                   
                    bool TryGetValue(const Key& key, bool& out_isConnectionValue) const
                    {
                        TCache::const_iterator iter = m_cache.find(key);
                        if (iter != m_cache.end())
                        {
                            out_isConnectionValue = iter->second;
                            return true;
                        }
                        
                        return false;
                    }
                    
                    void Add(const Key& key, bool value)
                    {
                        m_cache.insert(std::make_pair(key, value));
                    }
                    
                    struct Hash
                    {
                        size_t operator()(const Key& key) const;
                    };
                    
                    typedef Eegeo::unordered_map<Key, bool, Hash>::type TCache;
                    TCache m_cache;
                };
            }
            
        }
    }
}
