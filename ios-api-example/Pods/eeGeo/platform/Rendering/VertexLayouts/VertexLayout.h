// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VertexLayoutElement.h"
#include "VertexSemantics.h"
#include <vector>
#include <algorithm>

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            namespace
            {
                bool VertexLayoutElementComparator(VertexLayoutElement a, VertexLayoutElement b)
                {
                    return a.GetSemanticId() < b.GetSemanticId();
                }
            }
            
            /*!
             * \brief Describes the layout of fields within a particular vertex format.
             */
            class VertexLayout : protected Eegeo::NonCopyable
            {
            public:
                VertexLayout(int vertexSize)
                : m_vertexSize(vertexSize)
                , m_semanticFlags(VertexSemanticFlags::None)
                {
                }
                
                int GetVertexSize() const
                {
                    return m_vertexSize;
                }
                
                void AddElement(const VertexLayoutElement& element)
                {
                    Eegeo_ASSERT(!ContainsSemantic(element.GetSemanticId()), "Attempt to add the same semantic to VertexAttribs twice.");
                    
                    m_elements.push_back(element);
                    m_semanticFlags = VertexSemanticFlags::SetFlagForSemantic(m_semanticFlags, element.GetSemanticId());

                    std::sort(m_elements.begin(), m_elements.end(), VertexLayoutElementComparator);
                }
                
                int GetNumOfElements() const
                {
                    return static_cast<int>(m_elements.size());
                }
                
                VertexSemanticFlags::FlagValues GetSemanticFlags() const
                {
                    return m_semanticFlags;
                }
                
                const VertexLayoutElement& GetElement(size_t elementIndex)
                {
                    Eegeo_ASSERT(elementIndex < m_elements.size(), "Requested element index is out of range.");
                    return m_elements.at(elementIndex);
                }
                
                bool ContainsSemantic(const VertexSemanticId::IdValues semantic) const
                {
                    return VertexSemanticFlags::FlagsContainSemantic(m_semanticFlags, semantic);
                }
                
                const VertexLayoutElement& GetElementBySemantic(const VertexSemanticId::IdValues semantic) const
                {
                    for (std::vector<VertexLayoutElement>::const_iterator iter = m_elements.begin();
                         iter != m_elements.end();
                         iter++)
                    {
                        const VertexLayoutElement& element = (*iter);
                        if (element.GetSemanticId() == semantic)
                        {
                            return element;
                        }
                    }

                    Eegeo_ASSERT(false, "No element found for semantic");
                    return *m_elements.end();
                }
                
            private:
                int m_vertexSize;
                VertexSemanticFlags::FlagValues m_semanticFlags;
                
                // Probs need to keep a bitfield of used semantics here.
                std::vector<VertexLayoutElement> m_elements;
            };
        }
    }
}
