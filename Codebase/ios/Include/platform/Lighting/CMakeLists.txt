set(headers ${headers} platform/Lighting
)
set(currsources
  platform/Lighting/CMakeLists.txt
  platform/Lighting/GlobalFogging.cpp
  platform/Lighting/GlobalFogging.h
  platform/Lighting/GlobalLighting.cpp
  platform/Lighting/GlobalLighting.h
  platform/Lighting/GlobalShadowing.h
  platform/Lighting/Lighting.h
)
set(sources ${sources} ${currsources})
source_group(\\Lighting FILES ${currsources})
