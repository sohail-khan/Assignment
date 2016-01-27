// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Graphics.h"
#include "VertexSemantics.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            /*!
             * \brief Description of a single field within a vertex format.
             */
            class VertexLayoutElement
            {
            public:
                // Arguments in same order as SetVertexAttribPointer().
                VertexLayoutElement(const VertexSemanticId::IdValues semantic, GLint numOfFields, GLenum dataType, GLint offset)
                : m_semantic(semantic)
                , m_numOfFields(numOfFields)
                , m_dataType(dataType)
                , m_offset(offset)
                {
                }
                
                VertexSemanticId::IdValues GetSemanticId() const
                {
                    return m_semantic;
                }
                
                GLenum GetDataType() const
                {
                    return m_dataType;
                }
                
                GLint GetNumOfFields() const
                {
                    return m_numOfFields;
                }
                
                GLint GetOffset() const
                {
                    return m_offset;
                }
                
            private:
                VertexSemanticId::IdValues m_semantic;
                GLenum m_dataType;
                GLint m_numOfFields;
                GLint m_offset;
            };
        }
    }
}
