// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class SolverRangeBuilder : Eegeo::NonCopyable
                {
                public:
                    SolverRangeBuilder();
                    
                    int GetFirstIndex() const { return m_firstIndex; }
                    
                    int GetLastIndex() const { return m_lastIndex; }
                    
                    bool GetConformToNavGraph() const { return m_conformToNavGraph; }
                    
                    bool IsOpen() const { return m_firstIndex >= 0; }
                    
                    void Open(int firstIndex, bool conformToNavGraph);
                    
                    void Open(const SolverRange& solverRange);
                    
                    SolverRange Close();
                    
                    void Extend(bool conformToNavGraph, int lastIndex);
                    
                    bool NeedsClose() const { return IsOpen() && !m_canExtend; }
                    
                    bool TryExtend(const SolverRange& suffix);
                    
                private:
                    int m_firstIndex;
                    int m_lastIndex;
                    bool m_conformToNavGraph;
                    bool m_canExtend;
                };
            }
        }
    }
}
