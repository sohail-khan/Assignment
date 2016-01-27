if(${ANDROID})
set(headers ${headers} platform/UI/NativeAlerts/Android
)
set(currsources
  platform/UI/NativeAlerts/Android/AndroidAlertBoxFactory.cpp
  platform/UI/NativeAlerts/Android/AndroidAlertBoxFactory.h
  platform/UI/NativeAlerts/Android/AndroidSingleOptionAlertBox.cpp
  platform/UI/NativeAlerts/Android/AndroidSingleOptionAlertBox.h
  platform/UI/NativeAlerts/Android/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeAlerts\\Android FILES ${currsources})
endif(${ANDROID})
