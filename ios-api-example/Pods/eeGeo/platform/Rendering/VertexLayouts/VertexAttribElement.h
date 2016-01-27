// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VertexSemantics.h"
#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            /*!
             * \brief A description of a single vertex attribute as consumed by a Shader.
             */
            class VertexAttribElement
            {
            public:
                VertexAttribElement(const VertexSemanticId::IdValues semantic, GLuint location, const std::string& name)
                : m_semantic(semantic)
                , m_location(location)
                , m_name(name)
                {
                }
                
                VertexSemanticId::IdValues GetSemantic() const
                {
                    return m_semantic;
                }
                
                GLuint GetLocation() const
                {
                    return m_location;
                }
                
                const std::string& GetName() const
                {
                    return m_name;
                }
                
            private:
                VertexSemanticId::IdValues m_semantic;
                GLuint m_location;
                std::string m_name;
            };
        }
    }
}
