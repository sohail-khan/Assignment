// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextMeshBuilder.h"
#include "Rendering.h"
#include "Types.h"
#include "Space.h"
#include <vector>

namespace Eegeo
{
    namespace TextMeshes
    {
        struct TextMeshBuilderResult;
        
        class InstancedTextMeshBuilder : public TextMeshBuilder
        {
        public:
            InstancedTextMeshBuilder(Rendering::MeshFactories::TextMeshFactory& textMeshFactory);
            
            virtual void AddText(const std::vector<u32>& textUtf32, float fontSize, float xOffset, float yOffset, float altitudeOffset);
            virtual void AddText(const std::string& text, float fontSize, float xOffset, float yOffset, float altitudeOffset);
            virtual void AddText(const char* textStr, int textLength, float fontSize, float xOffset, float yOffset, float altitudeOffset);
            
            virtual void GenerateMeshes(bool shadowed, bool doubleSided, float shadowOffsetMeters, const std::string& debugName, const Space::CubeMap::CubeMapCellInfo& cellInfo, TextMeshBuilderResult& out_result);
            
            virtual void AddCustomQuads(const std::vector<Rendering::VertexTypes::TextVertex>& vertices, int quadCount, int customGeometryPageIndex);
        };
    }
}