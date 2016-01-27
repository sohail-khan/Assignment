// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Graphics.h"
#include <string>

namespace Eegeo
{
    namespace Helpers
    {
        namespace ShaderCompiler
        {    
            GLuint CompileShader(std::string code, GLenum shaderType);
            
            bool InitProgram(GLuint programHandle, const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
        }
    }
}
