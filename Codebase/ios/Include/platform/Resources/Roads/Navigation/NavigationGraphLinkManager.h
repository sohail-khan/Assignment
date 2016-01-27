// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Streaming.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphLinkManager : Eegeo::NonCopyable
                {
                public:
                    NavigationGraphLinkManager(bool debugLog, float maxLinkDist = 2.0f)
                    : m_debugLog(debugLog)
                    , m_maxLinkDistSqr(maxLinkDist*maxLinkDist)
                    {
                        
                    }
                    typedef std::vector<NavigationGraphLink*> TLinksVector;
                    
                    void FormConnections(NavigationGraph& newNavGraph);
                    void Disconnect(NavigationGraph& oldNavGraph);
                    
                private:
                    TLinksVector m_pendingLinks;
                    TLinksVector m_newLinksScratch;
                    TLinksVector m_newPendingLinksScratch;
                    
                    const float m_maxLinkDistSqr;
                    const bool m_debugLog;
                    
                    void FormConnectionsWithLinks(const NavigationGraph& navGraphA, const TLinksVector& newLinksToA);
                    
                    void ConnectRoads(NavigationGraphLink* linkAtoB, NavigationGraphLink* linkBtoA);
                    void RemovePendingLinksWithThisGraph(NavigationGraph* navGraph);
                    void DisconnectRoad(NavigationGraphRoad& road, const NavigationGraph& navGraph);
                    void DisconnectLink(NavigationGraphRoad& roadA, const NavigationGraph& navGraphA, NavigationGraphLink& linkAToB);
                    
                    TLinksVector::iterator FindBestAdmissableLink(const NavigationGraphLink& link, TLinksVector::iterator pendingLinksBegin, TLinksVector::iterator pendingLinksEnd);

                };
            }
        }
    }
}
