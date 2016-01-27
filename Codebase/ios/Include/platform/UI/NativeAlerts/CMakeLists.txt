set(headers ${headers} platform/UI/NativeAlerts
)
set(currsources
  platform/UI/NativeAlerts/AlertBox.h
  platform/UI/NativeAlerts/CMakeLists.txt
  platform/UI/NativeAlerts/IAlertBoxFactory.h
  platform/UI/NativeAlerts/ISingleOptionAlertBox.h
  platform/UI/NativeAlerts/ISingleOptionAlertBoxDismissedHandler.h
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeAlerts FILES ${currsources})
include(platform/UI/NativeAlerts/Android/CMakeLists.txt)
include(platform/UI/NativeAlerts/iOS/CMakeLists.txt)
include(platform/UI/NativeAlerts/Windows/CMakeLists.txt)
