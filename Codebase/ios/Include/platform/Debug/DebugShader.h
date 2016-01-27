// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{
    namespace DebugRendering
    {
        struct Shader {
            int m_positionSlot;
            int m_colorSlot;
            int m_uvSlot;
            int m_projectionUniform;
            int m_viewUniform;
            int m_modelUniform;
            int m_textureUniform;
            u32 m_programHandle;
        };
        
        class DebugShader : protected Eegeo::NonCopyable
        {
        public:
            // IH: Dependency on GLState in construction. These objects should only be constructed
            // during the app's Draw() phase
            DebugShader(Eegeo::Rendering::GLState& glState);
            ~DebugShader();
            
            Shader* GetDiffuseTexturedShader() { return m_pDiffuseTexturedShader; }
            Shader* GetDiffuseColourShader() { return m_pDiffuseColourShader; }
            
        private:
            
            Shader* m_pDiffuseTexturedShader;
            Shader* m_pDiffuseColourShader;
            
            void CompileShaders(Eegeo::Rendering::GLState& glState);
            Shader* CompileSingleShader(std::string &vertexProgram, std::string &fragmentProgram, Eegeo::Rendering::GLState& glState);
            void DestroyShaders();
            std::string VertexShader();
            std::string TexturedFragmentShader();
            std::string ColourFragmentShader();
        };
    }
}