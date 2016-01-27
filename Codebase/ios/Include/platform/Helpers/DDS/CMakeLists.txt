set(headers ${headers} platform/Helpers/DDS
)
set(currsources
  platform/Helpers/DDS/CMakeLists.txt
  platform/Helpers/DDS/DDSTypes.h
)
set(sources ${sources} ${currsources})
source_group(\\Helpers\\DDS FILES ${currsources})
