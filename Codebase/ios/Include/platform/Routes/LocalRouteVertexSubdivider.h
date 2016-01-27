// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "Types.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        class LocalRouteVertexSubdivider : public Eegeo::NonCopyable
        {
        public:
            LocalRouteVertexSubdivider(const Fitting::FittingTerrainProjector& fittingTerrainProjector)
            : m_fittingTerrainProjector(fittingTerrainProjector)
            {
                
            }
            
            void Subdivide(float maxDistBetweenVerts, std::vector<LocalRouteVertex>::const_iterator first, std::vector<LocalRouteVertex>::const_iterator last, std::vector<LocalRouteVertex>& subdividedOutput) const;
        private:
            const Fitting::FittingTerrainProjector& m_fittingTerrainProjector;
        };
    }
}