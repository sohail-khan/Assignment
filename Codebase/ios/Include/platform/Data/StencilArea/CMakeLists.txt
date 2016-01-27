set(headers ${headers} platform/Data/StencilArea
)
set(currsources
  platform/Data/StencilArea/CMakeLists.txt
  platform/Data/StencilArea/StencilArea.h
  platform/Data/StencilArea/StencilAreaController.cpp
  platform/Data/StencilArea/StencilAreaController.h
  platform/Data/StencilArea/StencilAreaModel.cpp
  platform/Data/StencilArea/StencilAreaModel.h
  platform/Data/StencilArea/StencilAreaPaletteModel.cpp
  platform/Data/StencilArea/StencilAreaPaletteModel.h
  platform/Data/StencilArea/StencilAreaRenderable.cpp
  platform/Data/StencilArea/StencilAreaRenderable.h
  platform/Data/StencilArea/StencilAreaRenderer.cpp
  platform/Data/StencilArea/StencilAreaRenderer.h
  platform/Data/StencilArea/StencilAreaView.cpp
  platform/Data/StencilArea/StencilAreaView.h
  platform/Data/StencilArea/StencilAreaViewFactory.cpp
  platform/Data/StencilArea/StencilAreaViewFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\StencilArea FILES ${currsources})
include(platform/Data/StencilArea/Materials/CMakeLists.txt)
