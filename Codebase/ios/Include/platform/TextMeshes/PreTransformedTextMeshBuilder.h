// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextMeshBuilder.h"
#include "Types.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Space.h"
#include <vector>

namespace Eegeo
{
    namespace TextMeshes
    {
        struct TextMeshBuilderResult;
        
        class PreTransformedTextMeshBuilder : public TextMeshBuilder
        {
        public:
            PreTransformedTextMeshBuilder(Rendering::MeshFactories::TextMeshFactory& textMeshFactory);
            
            void AddText(const std::vector<u32>& textUtf32, const Eegeo::m44& transform, float fontSize, float xOffset, float yOffset);
            void AddText(const std::string& text, const Eegeo::m44& transform, float fontSize, float xOffset, float yOffset);
            void AddText(const char* textStr, int textLength, const Eegeo::m44& transform, float fontSize, float xOffset, float yOffset);
            
            void GenerateMeshes(bool shadowed, bool doubleSided, float shadowOffsetMeters, const std::string& debugName, const Space::CubeMap::CubeMapCellInfo& cellInfo, TextMeshBuilderResult& out_result);
        };
    }
}
