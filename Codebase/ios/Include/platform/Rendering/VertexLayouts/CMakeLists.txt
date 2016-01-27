set(headers ${headers} platform/Rendering/VertexLayouts
)
set(currsources
  platform/Rendering/VertexLayouts/CMakeLists.txt
  platform/Rendering/VertexLayouts/VertexAttribElement.h
  platform/Rendering/VertexLayouts/VertexAttribs.cpp
  platform/Rendering/VertexLayouts/VertexAttribs.h
  platform/Rendering/VertexLayouts/VertexBinding.cpp
  platform/Rendering/VertexLayouts/VertexBinding.h
  platform/Rendering/VertexLayouts/VertexBindingElement.h
  platform/Rendering/VertexLayouts/VertexBindingPool.cpp
  platform/Rendering/VertexLayouts/VertexBindingPool.h
  platform/Rendering/VertexLayouts/VertexLayout.cpp
  platform/Rendering/VertexLayouts/VertexLayout.h
  platform/Rendering/VertexLayouts/VertexLayoutElement.cpp
  platform/Rendering/VertexLayouts/VertexLayoutElement.h
  platform/Rendering/VertexLayouts/VertexLayoutPool.cpp
  platform/Rendering/VertexLayouts/VertexLayoutPool.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\VertexLayouts FILES ${currsources})
