set(headers ${headers} platform/UI
)
set(currsources
  platform/UI/CMakeLists.txt
  platform/UI/EegeoUI.h
  platform/UI/KeyboardLocationObserver.h
  platform/UI/NativeUIFactories.h
)
set(sources ${sources} ${currsources})
source_group(\\UI FILES ${currsources})
include(platform/UI/NativeAlerts/CMakeLists.txt)
include(platform/UI/NativeInput/CMakeLists.txt)
