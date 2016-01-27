// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphLink : protected Eegeo::NonCopyable
                {
                
                public:
                    NavigationGraphLink(NavigationGraph* navGraphInstance, int roadIndex, bool isAtEndOfRoad);
                    ~NavigationGraphLink() {};
                    
                    NavigationGraph* GetNavGraph() const { return m_navGraph; }
                    int GetRoadIndex() const { return m_roadIndex; }
                    bool GetIsLeavingCell() const { return m_isAtEndOfRoad; }

                    //! \return true if this link is connected at the end (last vertex of) GetLinkedRoad;
                    //! false if this link is connected at the start (first vertex of) GetLinkedRoad
                    bool IsAtEndOfRoad() const { return m_isAtEndOfRoad; }
                    
                    //! \return the road in GetNavGraph() at GetRoadIndex()
                    NavigationGraphRoad* GetLinkedRoad() const;
                    
                    const v3& GetLinkedRoadVertex() const;
                    
                    int GetLinkedRoadVertexIndex() const;
                    
                    bool IsEqual(const NavigationGraphLink& other) const
                    {
                        return m_navGraph == other.m_navGraph &&
                                m_roadIndex == other.m_roadIndex &&
                                m_isAtEndOfRoad == other.m_isAtEndOfRoad;
                    }
                    
                private:
                    NavigationGraph* m_navGraph;
                    int m_roadIndex;
                    bool m_isAtEndOfRoad;
            
                };
            }
        }
    }
}
