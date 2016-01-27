set(headers ${headers} platform/Debug/Commands/Web
)
set(currsources
  platform/Debug/Commands/Web/CMakeLists.txt
  platform/Debug/Commands/Web/WebCacheClearCommand.cpp
  platform/Debug/Commands/Web/WebCacheClearCommand.h
  platform/Debug/Commands/Web/SetWebProxyCommand.cpp
  platform/Debug/Commands/Web/SetWebProxyCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\Web FILES ${currsources})
