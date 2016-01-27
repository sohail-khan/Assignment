// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "VectorMathDecl.h"
#include "Rendering.h"
#include "Space.h"
#include "ScratchGeometry.h"
#include "Bounds.h"
#include "FontCharacter.h"
#include "StringEntry.h"
#include "CharacterEntry.h"
#include <vector>
#include <deque>
#include <string>

namespace Eegeo
{
    namespace TextMeshes
    {
        struct TextMeshBuilderResult;
        
        namespace Internal
        {
            struct CharacterEntry;
            struct StringEntry;

            
            class TextMeshGenerator : public Eegeo::NonCopyable
            {
            public:
                TextMeshGenerator();
                
                virtual ~TextMeshGenerator() {}
                
                virtual void Begin(const Fonts::FontInstance* pFont, size_t initialCharacterCapacity);
                
                virtual void Reserve(size_t characterCount);
                
                virtual bool HasValidGeometry() const
                {
                    return !m_characterEntries.empty();
                }
                
                virtual void AddText(const std::vector<u32>& textUtf32, const Eegeo::m44& transform, float fontSize, float xOffset, float yOffset, float altitudeOffset, float& out_endX);
                
                
                virtual void AddCustomQuads(const std::vector<Rendering::VertexTypes::TextVertex>& vertices,
                                               int quadCount,
                                               int customGeometryPageIndex);
 
                virtual void GenerateMeshes(bool shadowed, bool doubleSided, float shadowOffsetMeters, const v3& up, Rendering::MeshFactories::TextMeshFactory& textMeshFactory, const std::string& debugName, const Space::CubeMap::CubeMapCellInfo& cellInfo, TextMeshBuilderResult& out_result);
                
            protected:
                virtual void AddTextGeometry(std::vector<Internal::CharacterEntry>::const_iterator characterRangeBegin,
                                     int characterCount,
                                     const v3& up,
                                     const m44& reverseSideTransform,
                                     float shadowParam,
                                     float z) = 0;
                
            private:
                void ValidateFont();
                
                void BuildGeometryForPage(
                                          std::vector<Internal::CharacterEntry>::const_iterator characterRangeBegin,
                                     int characterCount,
                                     bool shadowed, bool doubleSided, float shadowOffsetMeters,
                                     const v3& up);


                
                Rendering::Mesh* GenerateMesh(int quadCount,
                                              Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                              const std::string& debugName);
            protected:
                std::deque<Internal::StringEntry> m_stringEntries;
                std::vector<Internal::CharacterEntry> m_characterEntries;
                std::vector<int> m_pageCharacterCounts;
                
                Internal::ScratchGeometry m_scratchGeometry;
                std::vector<Geometry::Bounds2D> m_scratchBounds;
                
                std::vector<Rendering::VertexTypes::TextVertex> m_customVertices;
                int m_customGeometryPageIndex;
                
                const Fonts::FontInstance* m_pFont;

                float m_oneOverFontHeight;
                float m_oneOverScaleW;
                float m_oneOverScaleH;
            };
            
        }
    }
}
