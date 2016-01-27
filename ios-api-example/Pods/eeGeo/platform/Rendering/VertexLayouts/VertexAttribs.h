// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "VertexSemantics.h"
#include "VertexAttribElement.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexLayouts
        {
            
            /*!
             * \brief A collection of vertex attributes as consumed by a Shader.
             */
            class VertexAttribs : protected Eegeo::NonCopyable
            {
            public:
                VertexAttribs();
                
                void AddElement(const VertexAttribElement& element);
                
                bool UsesSemantic(const VertexSemanticId::IdValues semantic) const;
                
                VertexSemanticFlags::FlagValues GetSemanticFlags() const;
                
                int GetNumOfElements() const;
                
                const VertexAttribElement& GetElement(int elementIndex) const;
                
                void DetectShaderAttributes(GLuint programHandle);
                
            private:
                VertexSemanticId::IdValues NameToSemantic(const std::string& name) const;

                VertexSemanticFlags::FlagValues m_semanticFlags;
                std::vector<VertexAttribElement> m_elements;
            };
        }
    }
}
