// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Routes.h"
#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class NavGraphConformerCandidateGenerator : NonCopyable
                {
                public:
                    NavGraphConformerCandidateGenerator(const Streaming::MortonKey& key,
                                                        const NavGraphFittingInfoRepository& roadNavGraphFittingInfoRepository,
                                                        const NavGraphFittingInfoRepository& railNavGraphFittingInfoRepository,
                                                        const float maxRadius,
                                                        const int subDivisions,
                                                        const bool debugLog);
                    
                    bool GenerateCandidates(const std::vector<LocalRouteVertex>& inputLocalRouteVertices,
                                            std::vector<const CandidateSet*>& out_candidates) const;
                    

                    
                    static void DestroyCandidates(const std::vector<const CandidateSet*>& candidateSets);
                private:
    
                    bool CreateCandidates(const std::vector<LocalRouteVertex>& inputLocalRouteVertices,
                                          std::vector<const CandidateSet*>& out_candidates) const;
                    
                    void SubdivideInput(const std::vector<LocalRouteVertex>& inputLocalRouteVertices, std::vector<LocalRouteVertex>& out_subdividedLocalRouteVertices) const;

          
                    const Streaming::MortonKey m_key;
                    const float m_maxRadius;
                    const int m_subDivisions;
                    const bool m_debugLog;
 
                    const NavGraphFittingInfoRepository& m_roadNavGraphFittingInfoRepository;
                    const NavGraphFittingInfoRepository& m_railNavGraphFittingInfoRepository;
                };
            }
        }
    }
}
