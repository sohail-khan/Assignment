// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "MortonKey.h"
#include "tr1.h"
#include "SolverConfig.h"
#include "NavGraphConnectionCache.h"
#include "SearchNodePriorityComparer.h"
#include <vector>
#include <queue>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class NavGraphConformerSolver : NonCopyable
                {
                public:
                    NavGraphConformerSolver(const SolverConfig& config, SolverNodeAllocator& allocator, const Streaming::MortonKey& key, const std::vector<const CandidateSet*>& candidateSets);
                    virtual ~NavGraphConformerSolver();
                    
                    virtual bool TrySolve(std::vector<const Candidate*>& solution);
                    

                    
                private:
                    typedef std::vector<Candidate*> TCandidatesInner;
                    typedef std::vector<const CandidateSet*> TCandidatesOuter;

                    SolverNode* CreateNeighbour(SolverNode* parent, const Candidate* nextCandidate);
                    
                    void BuildSolutionOutput(SolverNode* goalNode, std::vector<const Candidate*>& solutionSelectedCandidates);
                    
                    float GetH(const Candidate& candidate) const;
                    
                    void CreateDuplicatedCandidates(const std::vector<const CandidateSet*>& originalCandidates, std::vector<const CandidateSet*>& out_duplicatedCandidates, std::vector<int>& out_candidatesToOriginalCandidates) const;
                    
                    void DestroyDuplicatedCandidates(std::vector<const CandidateSet*>& duplicatedCandidates) const;
                    
                    bool PassesPreconditions() const;
                    
                    int CountUniqueRoads(const std::vector<Candidate*>& inner) const;
                    
                    bool TryPrecalcCandidatesH();
                    
                    void OpenNeighbours(SolverNode* node);
                    
                    bool IsGoal(const SolverNode& node) const;
                    
                    bool HasNonContiguousRoadSequence(const SolverNode& lastNode) const;
                    
                    bool IsValidConnection(const SolverNode& nodeA, const SolverNode& nodeB);
                    
                    bool CalculateIsValidConnection(const SolverNode& nodeA, const SolverNode& nodeB);
                    
                    bool IsValidCandidateExtension(const SolverNode& node);
                    
                    float CalcEdgeTraversalCost(const Candidate& candidateA, const Candidate& candidateB);
                    
                    void Reset();
                    
                    const TCandidatesOuter& m_originalCandidates;

                    const Streaming::MortonKey m_key;
                    
                    std::vector<int> m_candidatesToOriginalCandidates;
                    
                    std::vector<float> m_candidatesH;
                    TCandidatesOuter m_candidates;
 
                    typedef Eegeo::unordered_set<const Candidate*>::type TClosedSet;
                    TClosedSet m_closedSet;
                    
                    typedef Eegeo::unordered_map<const Candidate*, SolverNode*>::type TCandidateToOpen;
                    TCandidateToOpen m_candidateToOpenNodes;
                    
                    typedef std::priority_queue<SolverNode*, std::deque<SolverNode*>, SearchNodePriorityComparer> TOpenSet;
                    TOpenSet m_openSet;
                    
                    const SolverConfig m_config;
                    
                    SolverNodeAllocator& m_nodeAllocator;
                    
                    NavGraphConnectionCache m_connectionCache;
                    
                    int m_trivialCalls;
                    int m_cachedCalls;
                    int m_uncachedCalls;
                };
            }
        }
    }
}
