// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "Types.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct SolverNode
                {
                    SolverNode()
                    : m_candidate(NULL)
                    , m_prev(NULL)
                    , m_f(0.f)
                    , m_g(0.f)
                    {
                        
                    }
                    
                    SolverNode(const Candidate* candidate,
                               SolverNode* prev,
                               float f,
                               float g)
                    : m_candidate(candidate)
                    , m_prev(prev)
                    , m_f(f)
                    , m_g(g)
                    {
                    }
                    
                    const Candidate* candidate() const { return m_candidate; };
                    SolverNode* prev() const { return m_prev; }
                    float f() const { return m_f; }
                    float g() const { return m_g; }
                    
                    
                    void DebugPrint();
                private:
                    const Candidate* m_candidate;
                    SolverNode* m_prev;
                    float m_f;
                    float m_g;
                };
            }
        }
    }
}