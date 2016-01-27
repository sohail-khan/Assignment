// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Fonts.h"
#include "Camera.h"
#include "Rendering.h"
#include "CityThemes.h"
#include "Modules.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class PlaceNamesPresentationModule : protected Eegeo::NonCopyable
                {
                public:
                    PlaceNamesPresentationModule(Resources::PlaceNames::PlaceNamesRepository& placeNamesRepository,
                                                 Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                 Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                 int screenDpi,
                                                 Fonts::FontInstance& environmentFont,
                                                 Rendering::Shaders::TextShader& textShader,
                                                 Resources::CityThemes::ICityThemesService& cityThemesService);
                                                
                    
                    ~PlaceNamesPresentationModule();
                    
                    static PlaceNamesPresentationModule* Create(Core::RenderingModule& renderingModule,
                                                                Map::Layers::PlaceNamesModelModule& placeNamesModelModule,
                                                                Core::FontsModule& fontsModule,
                                                                Map::CityThemesModule& cityThemesModule,
                                                                Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                                int screenDpi);
                    
                    Resources::PlaceNames::PlaceNamesController& GetPlaceNamesController() const;
                    Fonts::FontMaterialSet& GetPlaceNamesFontMaterialSet() const;
                    Resources::PlaceNames::PlaceNamesViewFilter& GetPlaceNamesViewFilter() const;
                    void Update(float dt, const Camera::RenderCamera& renderCamera);
                    
                private:
                    Resources::PlaceNames::PlaceNamesController* m_pPlaceNamesController;
                    Fonts::FontMaterialSet* m_pPlaceNamesFontMaterialSet;
                    Resources::PlaceNames::PlaceNamesViewFilter* m_pPlaceNamesViewFilter;
                };
            }
        }
    }
}