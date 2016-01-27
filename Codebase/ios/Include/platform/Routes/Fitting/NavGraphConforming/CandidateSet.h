// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "LocalRouteVertex.h"
#include "Candidate.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                
                class CandidateSet : Eegeo::NonCopyable
                {
                public:
                    CandidateSet(const LocalRouteVertex& localRouteVertex,
                                 const std::vector<Candidate*>& candidates,
                                 int index);
                    
                    const LocalRouteVertex& SrcVertex() const { return m_localRouteVertex; }
                    
                    std::vector<Candidate*>& candidates() { return m_candidates; }
                    const std::vector<Candidate*>& GetCandidates() const { return m_candidates; }
                    
                    bool HasConformCandidates() const;
                    
                    
                    const Candidate* GetUnfittedCandidate() const { return &m_unfittedCandidate; }
                    
                    int GetIndex() const { return m_index; }
                    
                    bool IsInputInCentralCell() const { return m_localRouteVertex.IsInCentralCell(); }
                    
                    const CandidateSet* GetNextCandidateSet(const std::vector<const CandidateSet*>& candidateSets) const
                    {
                        int nextIndex = m_index + 1;
                        if (nextIndex >= candidateSets.size())
                        {
                            return NULL;
                        }
                        return candidateSets.at(nextIndex);
                    }
                    
                    static CandidateSet* CreateDeepCopy(const CandidateSet& src, int newIndex);
                    
                private:
                    void FixUpCandidatesPointers();
                
                    LocalRouteVertex m_localRouteVertex;
                    std::vector<Candidate*> m_candidates;
                    Candidate m_unfittedCandidate;

                    int m_index;
                };
            }
        }
    }
}
