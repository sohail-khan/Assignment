set(headers ${headers} platform/Config
)
set(currsources
  platform/Config/CMakeLists.txt
  platform/Config/Config.h
  platform/Config/ConfigSections.h
  platform/Config/IPlatformConfigBuilder.h
  platform/Config/LodRefinementConfig.cpp
  platform/Config/LodRefinementConfig.h
  platform/Config/PlatformConfig.h
)
set(sources ${sources} ${currsources})
source_group(\\Config FILES ${currsources})
