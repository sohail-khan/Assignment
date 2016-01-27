set(headers ${headers} platform/Data/StencilArea/Materials
)
set(currsources
  platform/Data/StencilArea/Materials/CMakeLists.txt
  platform/Data/StencilArea/Materials/StencilAreaFullScreenMaterial.cpp
  platform/Data/StencilArea/Materials/StencilAreaFullScreenMaterial.h
  platform/Data/StencilArea/Materials/StencilAreaMaterial.cpp
  platform/Data/StencilArea/Materials/StencilAreaMaterial.h
  platform/Data/StencilArea/Materials/StencilAreaShader.cpp
  platform/Data/StencilArea/Materials/StencilAreaShader.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\StencilArea\\Materials FILES ${currsources})
