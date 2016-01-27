set(headers ${headers} platform/Rendering/VertexTypes
)
set(currsources
  platform/Rendering/VertexTypes/AllVertexTypes.h
  platform/Rendering/VertexTypes/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\VertexTypes FILES ${currsources})
