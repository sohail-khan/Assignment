if(${WINDOWS})
set(headers ${headers} platform/Windows/Input
)
set(currsources
  platform/Windows/Input/CMakeLists.txt
  platform/Windows/Input/IWindowsInputHandler.h
  platform/Windows/Input/PanGesture.cpp
  platform/Windows/Input/PanGesture.h
  platform/Windows/Input/PinchGesture.cpp
  platform/Windows/Input/PinchGesture.h
  platform/Windows/Input/RotateGesture.cpp
  platform/Windows/Input/RotateGesture.h
  platform/Windows/Input/TapGesture.cpp
  platform/Windows/Input/TapGesture.h
  platform/Windows/Input/TiltGesture.cpp
  platform/Windows/Input/TiltGesture.h
  platform/Windows/Input/TouchEventWrapper.h
  platform/Windows/Input/TouchGesture.cpp
  platform/Windows/Input/TouchGesture.h
  platform/Windows/Input/WindowsActionIdentifiers.h
  platform/Windows/Input/WindowsInput.h
  platform/Windows/Input/WindowsInputHandler.cpp
  platform/Windows/Input/WindowsInputHandler.h
  platform/Windows/Input/WindowsInputProcessor.cpp
  platform/Windows/Input/WindowsInputProcessor.h
  platform/Windows/Input/ZoomGesture.cpp
  platform/Windows/Input/ZoomGesture.h
)
set(sources ${sources} ${currsources})
source_group(\\Windows\\Input FILES ${currsources})
endif(${WINDOWS})
