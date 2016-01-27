// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "EegeoSearch.h"
#include "Location.h"
#include "Rendering.h"
#include "Camera.h"
#include "Terrain.h"
#include "PlaceNames.h"
#include "LatLongAltitude.h"
#include "IRenderableFilter.h"

#include <string>
#include <map>

namespace Eegeo
{
    namespace Search
    {
        class SearchComponent : public Eegeo::NonCopyable, public Rendering::IRenderableFilter
        {
            struct Quality
            {
                int terrainHeight;
                Space::LatLong location;
                std::string label;
                int counter;
                
                Quality():terrainHeight(0),location(0,0), label(""), counter(0) {}
                
                Quality(int terrainHeight, Space::LatLong location, const std::string& label)
                :terrainHeight(terrainHeight)
                ,location(location)
                ,label(label)
                ,counter(0)
                {}
                
                Quality(const Quality& other)
                :terrainHeight(other.terrainHeight)
                ,location(other.location)
                ,label(other.label)
                ,counter(other.counter)
                {
                }
            };
            
            Service::SearchService& m_searchService;
            const Location::IInterestPointProvider& m_interestPointProvider;
            Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeights;
            Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            
            typedef std::map<Resources::PlaceNames::PlaceNameView*, Quality> TViewToQualityMap;
            TViewToQualityMap m_viewToQuality;
            
            Eegeo::Resources::PlaceNames::PlaceNameViewBuilder& m_placeNamesViewBuilder;
            
            bool GetBestHeight(const Space::LatLong& location, int& lod, float& height);
            void Insert3DVisualisationForLodHeight(const std::string& label, Space::LatLong& location, int lod, float height);
            
            void UpdateVisualisationHeights();
            void UpdateViews(const Camera::RenderCamera& renderCamera);
            
        public:
            SearchComponent(Service::SearchService& searchService,
                            const Location::IInterestPointProvider& interestPointProvider,
                            Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeights,
                            Eegeo::Resources::PlaceNames::PlaceNameViewBuilder& placeNamesViewBuilder,
                            Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            virtual ~SearchComponent();
            
            void PerformQueryAddressSearch(const std::string& query, Service::IGeocodeAddressCallback& callback);
            void PerformNearbyAddressSearch(Service::IAddressSearchCallback& callback);
            void PerformPoiAddressSearch(const std::string& query, bool isCategory, Service::IPoiSearchCallback& callback);
            void PerformPoiInfoSearch(const std::string& placeId, Service::IPoiInfoCallback& callback);
            
            void Clear3DVisualisations();
            void Insert3DVisualisation(const std::string& label, Space::LatLong& location);
            void Update(const Camera::RenderCamera& renderCamera);
            
            void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue);
        private:
            void SubmitToRenderer(const Camera::RenderCamera& renderCamera);
        };
    }
}
