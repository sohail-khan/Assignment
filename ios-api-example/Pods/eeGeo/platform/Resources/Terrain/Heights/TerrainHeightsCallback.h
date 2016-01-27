// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TerrainHeightLookup.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Heights
            {
                class ITerrainHeightsCallback
                {
                public:
                    virtual void operator()(const ITerrainHeightLookup& terrainHeightLookup) = 0;
                };
                
                template <class T> class TTerrainHeightsCallback : public ITerrainHeightsCallback
                {
                private:
                    void (T::*m_callback)(const ITerrainHeightLookup& terrainHeightLookup);
                    T* m_context;
                public:
                    TTerrainHeightsCallback(T* context, void (T::*callback)(const ITerrainHeightLookup& terrainHeightLookup))
                    : m_context(context)
                    , m_callback(callback)
                    {
                    }
                    
                    virtual void operator()(const ITerrainHeightLookup& terrainHeightLookup)
                    {
                        (*m_context.*m_callback)(terrainHeightLookup);
                    }
                };
            }
        }
    }
}
