// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SolverNode.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class SearchNodePriorityComparer
                {
                public:
                    inline bool operator ()(const SolverNode* a, const SolverNode* b) const
                    {
                        return a->f() > b->f();
                    }
                    
                };
            }
        }
    }
}
