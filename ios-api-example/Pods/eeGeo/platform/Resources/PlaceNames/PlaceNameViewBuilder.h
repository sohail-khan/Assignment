// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Fonts.h"
#include "TextMeshes.h"
#include "Space.h"
#include "LayerIds.h"
#include "PlaceNames.h"
#include "VectorMathDecl.h"
#include <vector>
#include <string>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            // Unicode codepoints for icon glyphs - in Dingbats range U+2701 onwards
            enum IconCodepoint
            {
                NONE = 0,
                TRAFFIC_LIGHTS = 9985,
                PARK = 9986,
                AIRPORT = 9987,
                STATION = 9988,
                STAR = 9989,
                GOLF = 9990,
                COFFEE = 9991,
                FOOD = 9992,
                GAS_STATION = 9993,
                NIGHTLIFE = 9994,
                FERRY = 9995,
            };
            
            class PlaceNameViewBuilder : public Eegeo::NonCopyable
            {
            public:
                PlaceNameViewBuilder(
                                     Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                     TextMeshes::InstancedTextMeshBuilder& textBuilder,
                                     Fonts::FontInstance& font,
                                     Fonts::FontMaterialSet& materialSet,
                                     Rendering::LayerIds::Values layerId
                                     );
                virtual ~PlaceNameViewBuilder();
                
                PlaceNameView* CreatePlaceNameView(const std::vector<u32>& textUtf32,
                                                   const std::string& iconKey,
                                                   float fontSize,
                                                   const dv3& positionEcef,
                                                   const std::string& debugName,
                                                   const Space::CubeMap::CubeMapCellInfo& cellInfo,
                                                   bool hasUnderline = false,
                                                   float unflattenableHeightOffset = 0.0f);
                
                static const float UNDERLINE_POINTER_HEIGHT;
                static const float UNDERLINE_POINTER_HEIGHT_LOW_LEVEL;
                
            private:
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
                Fonts::FontInstance& m_font;
                TextMeshes::InstancedTextMeshBuilder& m_textBuilder;
                Fonts::FontMaterialSet& m_materialSet;
                Rendering::LayerIds::Values m_layerId;
                
                std::vector<Rendering::VertexTypes::TextVertex> m_underlineVertices;
                const float m_underlineHorizontalOffset;
                const float m_underlineThickness;
                const float m_shadowOffset;
                int m_underlineCharacterTexturePage;
                std::map<const std::string, IconCodepoint> m_iconCodepointMap;
                
                void BuildTextMeshes(const std::vector<u32>& textUtf32, const std::string& iconKey, float fontSize, float altitude, const std::string& debugName, const Space::CubeMap::CubeMapCellInfo& cellInfo, bool hasUnderline, TextMeshes::TextMeshBuilderResult& out_builderResult);
                
                void AddIconGeometry(u32 iconCodepointUft32, float iconSize, float xOffset, float yOffset, float altitude, bool hasUnderline);
                void AddUnderlineGeometry(float textWidth, float underlineHeight, float altitude);
                void InitUnderlineGeometry();
                void BuildIconCodepointMap();
            };
        }
    }
}
