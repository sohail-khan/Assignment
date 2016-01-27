set(headers ${headers} platform/Rendering/Shaders
)
set(currsources
  platform/Rendering/Shaders/BatchedSpriteShader.h
  platform/Rendering/Shaders/CMakeLists.txt
  platform/Rendering/Shaders/ColoredVertShader.h
  platform/Rendering/Shaders/ColorShader.h
  platform/Rendering/Shaders/DiffuseShader.h
  platform/Rendering/Shaders/FireworksShader.h
  platform/Rendering/Shaders/FogShaderIncludes.h
  platform/Rendering/Shaders/FogShaderUniforms.cpp
  platform/Rendering/Shaders/FogShaderUniforms.h
  platform/Rendering/Shaders/LightmappedPackedDiffuseShader.h
  platform/Rendering/Shaders/LightmappedPackedDiffuseTransitionShader.h
  platform/Rendering/Shaders/ModelShader.h
  platform/Rendering/Shaders/NullShader.h
  platform/Rendering/Shaders/PackedDiffuseAlphaShader.h
  platform/Rendering/Shaders/PackedDiffuseFoggedShader.h
  platform/Rendering/Shaders/PackedDiffuseShader.h
  platform/Rendering/Shaders/PackedDiffuseTransitionShader.h
  platform/Rendering/Shaders/PackedStencilShadowShader.h
  platform/Rendering/Shaders/ShaderIdGenerator.h
  platform/Rendering/Shaders/ShaderMacros.h
  platform/Rendering/Shaders/TextShader.cpp
  platform/Rendering/Shaders/TextShader.h
  platform/Rendering/Shaders/TexturedUniformColoredShader.h
  platform/Rendering/Shaders/UniformColoredShader.cpp
  platform/Rendering/Shaders/UniformColoredShader.h
  platform/Rendering/Shaders/VertexColoredShader.cpp
  platform/Rendering/Shaders/VertexColoredShader.h
  platform/Rendering/Shaders/WaterShader.h
  platform/Rendering/Shaders/WaterTransitionShader.h
  platform/Rendering/Shaders/WeatherOverlayShader.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\Shaders FILES ${currsources})
