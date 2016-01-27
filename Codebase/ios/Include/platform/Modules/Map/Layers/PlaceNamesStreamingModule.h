// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Modules.h"
#include "Rendering.h"
#include "Fonts.h"
#include "CoverageTrees.h"
#include "TextMeshes.h"
#include "Interiors.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class PlaceNamesStreamingModule : protected Eegeo::NonCopyable
                {
                public:
                    PlaceNamesStreamingModule(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                              Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                              Fonts::FontInstance& environmentFont,
                                              Fonts::FontMaterialSet& placeNamesFontMaterialSet,
                                              Resources::PlaceNames::PlaceNamesController& placeNamesController,
                                              Eegeo::Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder& interiorMarkersCellResourceBuilder,
                                              const bool enableInteriors);
                    
                    ~PlaceNamesStreamingModule();
                    
                    static PlaceNamesStreamingModule* Create(Core::RenderingModule& renderingModule,
                                                             Core::FontsModule& fontsModule,
                                                             Map::Layers::PlaceNamesPresentationModule& placeNamesPresentationModule,
                                                             Map::Layers::InteriorsStreamingModule& interiorsStreamingModule,
                                                             const bool enableInteriors);
                    
                    Resources::PlaceNames::PlaceNamesStreaming& GetPlaceNamesStream() const;
                    Resources::PlaceNames::PlaceNamesBuilder& GetPlaceNamesBuilder() const;
                    Resources::PlaceNames::PlaceNameViewBuilder& GetPlaceNameViewBuilder() const;
                    TextMeshes::InstancedTextMeshBuilder& GetPlaceNamesTextMeshBuilder() const;
                    
                private:
                   Resources::PlaceNames::PlaceNamesStreaming* m_pPlaceNamesStream;
                   TextMeshes::InstancedTextMeshBuilder* m_pPlaceNamesTextMeshBuilder;
                   Resources::PlaceNames::PlaceNameViewBuilder* m_pPlaceNameViewBuilder;
                   Resources::PlaceNames::PlaceNamesBuilder* m_pPlaceNamesBuilder;
                };
            }
        }
    }
}