// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "Streaming.h"
#include "FittedRangeForRoad.h"
#include "ConformerSolution.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class FittedRangeBuilder : Eegeo::NonCopyable
                {
                public:
                    FittedRangeBuilder(const Streaming::MortonKey& key,
                                       const std::vector<ConformerSolution>& conformerSolutions);
                    
                    void Create(SelectedRoadRepository& selectedRoadRepository, std::vector<FittedRangeForRoad>& out_fittedRanges);
                    
                private:
                    struct MutableFittedRange
                    {
                        std::vector<const Candidate*> solution;
                        const NavGraphRoadFittingInfo* roadFittingInfo;
                        bool clipAtStart;
                        bool clipAtEnd;
                        bool isConformed;
                        bool isClosed;
                        
                        MutableFittedRange()
                        : roadFittingInfo(NULL)
                        , clipAtStart(false)
                        , clipAtEnd(false)
                        , isConformed(false)
                        , isClosed(false)
                        {
                            
                        }
                    };
                    
                    void Start(const Candidate& firstCandidate, bool clipAtStart);
                    
                    bool CanExtend(const Candidate& candidate) const;
                    
                    void Extend(const Candidate& candidate);
                    
                    void Reset();
                    
                    void BuildMutableFittedRanges(const std::vector<const Candidate*>& inputSolution, SelectedRoadRepository& selectedRoadRepository, std::vector<MutableFittedRange>& out_fittedRanges);

                    
                    const Streaming::MortonKey& m_key;
                    const std::vector<ConformerSolution>& m_conformerSolutions;
                    
                    MutableFittedRange m_current;
                };
            }
        }
    }
}
