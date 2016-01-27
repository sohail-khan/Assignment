// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct FittedRangeForRoad
                {
                public:
                    FittedRangeForRoad(std::vector<const Candidate*> solution,
                                       const NavGraphRoadFittingInfo* roadFittingInfo,
                                       bool clipAtStart,
                                       bool clipAtEnd,
                                       bool isConformed)
                    : m_solution(solution)
                    , m_roadFittingInfo(roadFittingInfo)
                    , m_clipAtStart(clipAtStart)
                    , m_clipAtEnd(clipAtEnd)
                    , m_isConformed(isConformed)
                    {
                        
                    }

                    const std::vector<const Candidate*>& GetSolution() const { return m_solution; }
                    const NavGraphRoadFittingInfo* GetRoadFittingInfo() const { return m_roadFittingInfo; }
                    bool GetClipAtStart() const { return m_clipAtStart; }
                    bool GetClipAtEnd() const { return m_clipAtEnd; }
                    bool IsConformed() const { return m_isConformed; }
                   
                    bool IsSolutionEmpty() const { return m_solution.empty(); }
                private:
                    std::vector<const Candidate*> m_solution;
                    const NavGraphRoadFittingInfo* m_roadFittingInfo;
                    bool m_clipAtStart;
                    bool m_clipAtEnd;
                    bool m_isConformed;
                };
            }
        }
    }
}
