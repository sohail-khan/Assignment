//
//  ConformerRouteSection.h
//  apps-on-maps
//

#ifndef __apps_on_maps__ConformerRouteSection__
#define __apps_on_maps__ConformerRouteSection__

#include "Routes.h"
#include "ClippedRouteSection.h"

#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct ConformerRouteSection
                {
                    ConformerRouteSection(const std::vector<Clipping::ClippedRouteSection>& orderedClippedRouteSections)
                    : m_orderedClippedRouteSections(orderedClippedRouteSections)
                    {
                        Eegeo_ASSERT(!orderedClippedRouteSections.empty());
                    }
                
                    const Clipping::ClippedRouteVertex& Start() const
                    {
                        return m_orderedClippedRouteSections.front().Start;
                    }
                    
                    const Clipping::ClippedRouteVertex& End() const
                    {
                        return m_orderedClippedRouteSections.back().End;
                    }
                    
                    const std::vector<Clipping::ClippedRouteSection>& OrderedClippedRouteSections() const
                    {
                        return m_orderedClippedRouteSections;
                    }
                    
                private:
                    std::vector<Clipping::ClippedRouteSection> m_orderedClippedRouteSections;
                };
            }
        }
    }
}

#endif /* defined(__apps_on_maps__ConformerRouteSection__) */
