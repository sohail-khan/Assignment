// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Space.h"
#include "Fonts.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace TextMeshes
    {
        struct TextMeshBuilderResult;
        
        namespace Internal
        {
            class TextMeshGenerator;
        }
        
        class TextMeshBuilder : Eegeo::NonCopyable
        {
        public:
            TextMeshBuilder(Rendering::MeshFactories::TextMeshFactory& textMeshFactory, Internal::TextMeshGenerator* generator)
            : m_textMeshFactory(textMeshFactory)
            , m_generator(generator)
            , m_currentX(0.f)
            {
            }
            
            virtual ~TextMeshBuilder();
            
            virtual void Begin(const Fonts::FontInstance* pFont, size_t initialCharacterCapacity);
            
            virtual void GenerateMeshes(bool shadowed, bool doubleSided, float shadowOffsetMeters, const std::string& debugName, const Space::CubeMap::CubeMapCellInfo& cellInfo, TextMeshBuilderResult& out_result) = 0;
            
            virtual bool HasValidGeometry() const;
            
            virtual float GetCurrentX() const { return m_currentX; }
            
        protected:
            Rendering::MeshFactories::TextMeshFactory& m_textMeshFactory;
            Internal::TextMeshGenerator* const m_generator;
            float m_currentX;
            std::vector<u32> m_stringScratch;
        };
    }
}
