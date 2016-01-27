// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Graphics.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A binding between a single field in a vertex format with a single vertex attribute consumed by a Shader.
         */
        class VertexBindingElement
        {
        public:
            VertexBindingElement(GLuint attribIndex, GLint numOfFields, GLenum dataType, GLsizei stride, GLint offset)
            : m_attribIndex(attribIndex)
            , m_numOfFields(numOfFields)
            , m_dataType(dataType)
            , m_stride(stride)
            , m_offset(offset)
            {
            }
            
            void Bind() const
            {
                Eegeo_GL(glEnableVertexAttribArray(m_attribIndex));
                Eegeo_GL(glVertexAttribPointer(m_attribIndex,
                                               m_numOfFields,
                                               m_dataType,
                                               GL_TRUE,
                                               m_stride,
                                               reinterpret_cast<GLvoid*>(m_offset)
                                               ));
            }
            
            inline bool operator== (const VertexBindingElement& other) const
            {
                return
                (
                 (m_attribIndex == other.m_attribIndex)
                 && (m_numOfFields == other.m_numOfFields)
                 && (m_dataType == other.m_dataType)
                 && (m_stride == other.m_stride)
                 && (m_offset == other.m_offset)
                );
            }
            
            inline bool operator!= (const VertexBindingElement& other) const
            {
                return
                (
                 (m_attribIndex != other.m_attribIndex)
                 || (m_numOfFields != other.m_numOfFields)
                 || (m_dataType != other.m_dataType)
                 || (m_stride != other.m_stride)
                 || (m_offset != other.m_offset)
                 );
            }

            inline bool operator< (const VertexBindingElement& other) const
            {
                if(m_attribIndex == other.m_attribIndex)
                {
                    if(m_numOfFields == other.m_numOfFields)
                    {
                        if(m_dataType == other.m_dataType)
                        {
                            if(m_stride == other.m_stride)
                            {
                                return m_offset < other.m_offset;
                            }
                            else
                            {
                                return m_stride < other.m_stride;
                            }
                        }
                        else
                        {
                            return m_dataType < other.m_dataType;
                        }
                    }
                    else
                    {
                        return m_numOfFields < other.m_numOfFields;
                    }
                }
                else
                {
                    return m_attribIndex < other.m_attribIndex;
                }
            }
            
        private:
            GLuint m_attribIndex;
            GLint m_numOfFields;
            GLenum m_dataType;
            GLsizei m_stride;
            GLint m_offset;
        };
    }
}
