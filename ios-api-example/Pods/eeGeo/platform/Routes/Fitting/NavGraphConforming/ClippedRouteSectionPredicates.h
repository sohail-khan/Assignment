// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include <functional>
#include "Streaming.h"
#include "ClippedRouteSection.h"
#include "SceneGraphCellRepository.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class ClippedRouteSectionPredicates : public std::unary_function<Clipping::ClippedRouteSection, bool>
                {
                public:
                    class ContainsKey
                    {
                    public:
                        ContainsKey(const Streaming::MortonKey& key)
                        : m_key(key)
                        {
                        }
                        
                        bool operator() (const Clipping::ClippedRouteSection& clippedRouteSection) const
                        {
                            return clippedRouteSection.Key == m_key;
                        }
                    private:
                        Streaming::MortonKey m_key;
                    };
                    
                    class CellInScene : public std::unary_function<Clipping::ClippedRouteSection, bool>
                    {
                    public:
                        CellInScene(const Streaming::SceneGraphCellRepository& sceneGraphCellRepository)
                        : m_sceneGraphCellRepository(sceneGraphCellRepository)
                        {
                            
                        }
                        
                        bool operator() (const Clipping::ClippedRouteSection& clippedRouteSection) const
                        {
                            return m_sceneGraphCellRepository.IsCellInSceneGraph(clippedRouteSection.Key);
                        }
                    private:
                        const Streaming::SceneGraphCellRepository& m_sceneGraphCellRepository;
                    };
                };
            }
        }
    }
}
