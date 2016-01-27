// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct SolverRange
                {
                public:
                    SolverRange(int firstIndex, int lastIndex, bool conformToNavGraph)
                    : m_firstIndex(firstIndex)
                    , m_lastIndex(lastIndex)
                    , m_conformToNavGraph(conformToNavGraph)
                    {
                    }
                    
                    int GetFirstIndex() const { return m_firstIndex; }
                    int GetLastIndex() const { return m_lastIndex; }
                    bool GetConformToNavGraph() const { return m_conformToNavGraph; }
                    
                    int Size() const
                    {
                        return m_lastIndex - m_firstIndex + 1;
                    }
                    
                private:
                    int m_firstIndex;
                    int m_lastIndex;
                    bool m_conformToNavGraph;
                };
            }
        }
    }
}
