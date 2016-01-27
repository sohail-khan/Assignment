// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "VertexBindingElement.h"
#include "VertexAttribs.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            /*!
             * \brief A binding between the layout of fields in a vertex format to the vertex attributes consumed by a Shader.
             */
            class VertexBinding
            {
            public:
                VertexBinding(const VertexLayout& vertexLayout, const VertexAttribs& vertexAttribs);
                
                void BindVertices() const;
                
                void AddElement(VertexBindingElement element);
                
                inline bool operator< (const VertexBinding& other) const
                {
                    if(m_elements.size() == other.m_elements.size())
                    {
                        for(int i = 0; i < m_elements.size(); ++i)
                        {
                            if(m_elements[i] == other.m_elements[i])
                            {
                                continue;
                            }
                            else
                            {
                                return m_elements[i] < other.m_elements[i];
                            }
                        }
                        
                        return false;
                    }
                    else
                    {
                        return m_elements.size() < other.m_elements.size();
                    }
                }
                
                inline bool operator== (const VertexBinding& other) const
                {
                    if(m_elements.size() == other.m_elements.size())
                    {
                        for(int i = 0; i < m_elements.size(); ++i)
                        {
                            if(m_elements[i] != other.m_elements[i])
                            {
                                return false;
                            }
                        }
                        
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                                
            private:
                typedef std::vector<VertexBindingElement> TBindingElements;
                TBindingElements m_elements;
            };
        }
    }
}
