if(${IOS})
set(headers ${headers} platform/UI/NativeAlerts/iOS
)
set(currsources
  platform/UI/NativeAlerts/iOS/CMakeLists.txt
  platform/UI/NativeAlerts/iOS/iOSAlertBoxFactory.h
  platform/UI/NativeAlerts/iOS/iOSAlertBoxFactory.mm
  platform/UI/NativeAlerts/iOS/iOSSingleOptionAlertBox.h
  platform/UI/NativeAlerts/iOS/iOSSingleOptionAlertBox.mm
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeAlerts\\iOS FILES ${currsources})
endif(${IOS})
