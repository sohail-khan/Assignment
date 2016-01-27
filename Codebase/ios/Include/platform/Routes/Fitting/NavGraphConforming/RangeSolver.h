// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include "SolverConfig.h"
#include "SolverRange.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class RangeSolver : NonCopyable
                {
                public:
                    RangeSolver(const SolverConfig& config,
                                SolverNodeAllocator& nodeAllocator,
                                const Streaming::MortonKey& key,
                                const std::vector<const CandidateSet*>& candidatesSets);
                    virtual ~RangeSolver();
                    
                    virtual bool TrySolve(std::vector<ConformerSolution>& out_solutions);
                    
                    static void DestroySolutions(const std::vector<ConformerSolution>& solutions);
                    
                    
                private:
                    void BuildSolverRanges(std::vector<SolverRange>& solverRanges) const;
                    bool TrySolveRange(const SolverRange& range, std::vector<const Candidate*>& rangeSolution);
                    bool ContainsRailOrRoadWithoutCandidate(const std::vector<SolverRange>& solverRanges) const;
                    bool RangeContainsRoadOrRail(const SolverRange& solverRange) const;
                    void LogCandidateSets() const;
                    void AddUnfittedSolutionsForRange(const SolverRange& solverRange, std::vector<ConformerSolution>& out_solutions) const;
                    
                    typedef std::vector<Candidate*> TCandidatesInner;
                    typedef std::vector<const CandidateSet*> TCandidatesOuter;
                    
                    const SolverConfig m_config;
                    
                    const TCandidatesOuter& m_candidateSets;
                    const Streaming::MortonKey m_key;
                    SolverNodeAllocator& m_nodeAllocator;
                };
            }
        }
    }
}
