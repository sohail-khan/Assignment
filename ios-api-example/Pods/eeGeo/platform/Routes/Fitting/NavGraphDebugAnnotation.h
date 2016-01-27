// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "PlaceNames.h"
#include "VectorMathDecl.h"
#include "Routes.h"
#include "Navigation.h"
#include <string>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            class NavGraphDebugAnnotation : Eegeo::NonCopyable
            {
            public:
                NavGraphDebugAnnotation(Streaming::MortonKey key,
                                        Eegeo::Resources::PlaceNames::PlaceNamesRepository& placeNamesRepo,
                                        Eegeo::Resources::PlaceNames::PlaceNameViewBuilder& placeNamesViewBuilder)
                : m_key(key)
                , m_placeNamesRepo(placeNamesRepo)
                , m_placeNamesViewBuilder(placeNamesViewBuilder)
                {
                    
                }
                
                void AnnotateNavGraph(const Eegeo::Resources::Roads::Navigation::NavigationGraph& navGraph);
                void ShowClippedSectionsAndVerts(const Fitting::FittedRoute* fittedRoute);
                
                const Streaming::MortonKey& GetKey() const { return m_key; }
            private:
                const Streaming::MortonKey m_key;
                Eegeo::Resources::PlaceNames::PlaceNamesRepository& m_placeNamesRepo;
                Eegeo::Resources::PlaceNames::PlaceNameViewBuilder& m_placeNamesViewBuilder;
                
                void AddLabel(const Eegeo::Streaming::MortonKey& key, const Eegeo::dv3 ecefPos, const std::string& name, const std::string& category, const v3& colour);
            };
        }
    }
}
