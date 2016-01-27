if(${WINDOWS})
set(headers ${headers} platform/UI/NativeAlerts/Windows
)
set(currsources
  platform/UI/NativeAlerts/Windows/CMakeLists.txt
  platform/UI/NativeAlerts/Windows/WindowsAlertBoxFactory.cpp
  platform/UI/NativeAlerts/Windows/WindowsAlertBoxFactory.h
  platform/UI/NativeAlerts/Windows/WindowsSingleOptionAlertBox.cpp
  platform/UI/NativeAlerts/Windows/WindowsSingleOptionAlertBox.h
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeAlerts\\Windows FILES ${currsources})
endif(${WINDOWS})
