// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct SelectedRoad
                {
                    SelectedRoad(const NavGraphRoadFittingInfo* roadFittingInfo,
                                 bool directionFromTo)
                    : m_roadFittingInfo(roadFittingInfo)
                    , m_directionFromTo(directionFromTo)
                    {
                        
                    }
                    
                    
                    bool operator <(const SelectedRoad& other) const
                    {
                        if (m_directionFromTo == other.m_directionFromTo)
                        {
                            return m_roadFittingInfo < other.m_roadFittingInfo;
                        }
                        
                        return m_directionFromTo < other.m_directionFromTo;
                    }
                    
                private:
                    const NavGraphRoadFittingInfo* m_roadFittingInfo;
                    bool m_directionFromTo;
                };
            }
        }
    }
}
