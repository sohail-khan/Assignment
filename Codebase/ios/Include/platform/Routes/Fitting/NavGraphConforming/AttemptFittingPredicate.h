//
//  AttemptFittingPredicate.h
//  apps-on-maps
//

#ifndef apps_on_maps_AttemptFittingPredicate_h
#define apps_on_maps_AttemptFittingPredicate_h

#include "Routes.h"
#include "ClippedRouteSection.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                class AttemptFittingPredicate : public std::unary_function<Clipping::ClippedRouteSection, bool>
                {
                public:
                    
                    AttemptFittingPredicate(const Route& route,
                                            const NavGraphFittingInfoRepository& roadNavGraphFittingInfoRepository,
                                            const NavGraphFittingInfoRepository& railNavGraphFittingInfoRepository)
                    : m_route(route)
                    , m_roadNavGraphFittingInfoRepository(roadNavGraphFittingInfoRepository)
                    , m_railNavGraphFittingInfoRepository(railNavGraphFittingInfoRepository)
                    {
                        
                    }
                    
                    bool operator() (const Clipping::ClippedRouteSection& clippedRouteSection) const
                    {
                        return ShouldAttemptFitting(clippedRouteSection);
                    }

                    
                private:
                    bool ShouldAttemptFitting(const Clipping::ClippedRouteSection& clippedRouteSection) const;

                    
                    const Route& m_route;
                    const NavGraphFittingInfoRepository& m_roadNavGraphFittingInfoRepository;
                    const NavGraphFittingInfoRepository& m_railNavGraphFittingInfoRepository;
                };
            }
        }
    }
}

#endif
