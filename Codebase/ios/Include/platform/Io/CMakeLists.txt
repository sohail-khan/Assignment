set(headers ${headers} platform/Io
)
set(currsources
  platform/Io/BinarySerialization.cpp
  platform/Io/BinarySerialization.h
  platform/Io/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Io FILES ${currsources})
include(platform/Io/AsyncModels/CMakeLists.txt)
include(platform/Io/ChunkedFileFormat/CMakeLists.txt)
include(platform/Io/POD/CMakeLists.txt)
