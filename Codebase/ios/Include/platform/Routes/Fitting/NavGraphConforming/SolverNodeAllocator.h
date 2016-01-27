// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include <deque>


namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class SolverNodeAllocator : Eegeo::NonCopyable
                {
                public:
                    virtual ~SolverNodeAllocator();
                    virtual SolverNode* CreateNode(const Candidate* candidate, SolverNode* prev, float f, float g);
                    virtual void ReleaseNode(SolverNode* pNode);
                    virtual void ReleaseAllNodes();
                    virtual void DestroyNodes();
                private:
                    std::deque<SolverNode*> m_allocatedNodes;
                    std::deque<SolverNode*> m_freeNodes;
                    
                };
            }
        }
    }
}