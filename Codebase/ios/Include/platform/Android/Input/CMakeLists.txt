if(${ANDROID})
set(headers ${headers} platform/Android/Input
)
set(currsources
  platform/Android/Input/AndroidInput.h
  platform/Android/Input/AndroidInputHandler.cpp
  platform/Android/Input/AndroidInputHandler.h
  platform/Android/Input/AndroidInputProcessor.cpp
  platform/Android/Input/AndroidInputProcessor.h
  platform/Android/Input/CMakeLists.txt
  platform/Android/Input/IAndroidInputHandler.h
  platform/Android/Input/PanGesture.cpp
  platform/Android/Input/PanGesture.h
  platform/Android/Input/PinchGesture.cpp
  platform/Android/Input/PinchGesture.h
  platform/Android/Input/RotateGesture.cpp
  platform/Android/Input/RotateGesture.h
  platform/Android/Input/TapGesture.cpp
  platform/Android/Input/TapGesture.h
  platform/Android/Input/TouchEventWrapper.h
  platform/Android/Input/TouchGesture.cpp
  platform/Android/Input/TouchGesture.h
)
set(sources ${sources} ${currsources})
source_group(\\Android\\Input FILES ${currsources})
endif(${ANDROID})
