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
                struct ConformerSolution
                {
                public:
                    ConformerSolution(const std::vector<const Candidate*>& solution,
                                      bool isFitted)
                    : m_solution(solution)
                    , m_isFitted(isFitted)
                    {
                        
                    }
                    
                    const std::vector<const Candidate*>& GetSolution() const { return m_solution; }
                    bool IsFitted() const { return m_isFitted; }
                private:
                    std::vector<const Candidate*> m_solution;
                    bool m_isFitted;
                    
                };
            }
        }
    }
}
