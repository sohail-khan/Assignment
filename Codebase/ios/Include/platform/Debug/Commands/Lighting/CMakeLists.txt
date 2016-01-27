set(headers ${headers} platform/Debug/Commands/Lighting
)
set(currsources
  platform/Debug/Commands/Lighting/CMakeLists.txt
  platform/Debug/Commands/Lighting/DumpLightingCommand.cpp
  platform/Debug/Commands/Lighting/DumpLightingCommand.h
  platform/Debug/Commands/Lighting/LightingCommand.cpp
  platform/Debug/Commands/Lighting/LightingCommand.h
  platform/Debug/Commands/Lighting/SetLightColorCommand.cpp
  platform/Debug/Commands/Lighting/SetLightColorCommand.h
  platform/Debug/Commands/Lighting/SetShadowColorCommand.cpp
  platform/Debug/Commands/Lighting/SetShadowColorCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Lighting FILES ${currsources})
