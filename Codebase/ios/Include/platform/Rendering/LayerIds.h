// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Rendering
    {
        namespace LayerIds
        {
            /*!
             * \brief Unique identifiers for the layers that renderables are grouped into for rendering.
             *
             * Layers are are rendered in strictly ascending order. That is, all renderables in the first layer are rendered before all objects in the second layer.
             */
            enum Values
            {
                // Rendered first.
                
                BeforeAll,
                    BeforeWorld,
                        BeforeWorldOpaque,
                            Buildings,
                            Roads,
                            Terrain,

                        AfterWorldOpaque,
                        
                        BeforeWorldShadow,
                            ShadowGeometry,
                        AfterWorldShadow,
                        
                        ShadowOverlay,
                
                        BeforeWorldTranslucency,
                            RoadNames,
                            PlaceNames,                
                        AfterWorldTranslucency,
                
                        Interiors,
                            InteriorEntities,
                    AfterWorld,
                AfterAll
                
                // Rendered last.
            };
        };
    }
}
