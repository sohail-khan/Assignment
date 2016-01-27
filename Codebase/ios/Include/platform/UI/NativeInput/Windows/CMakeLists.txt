if(${WINDOWS})
set(headers ${headers} platform/UI/NativeInput/Windows
)
set(currsources
  platform/UI/NativeInput/Windows/CMakeLists.txt
  platform/UI/NativeInput/Windows/WindowsDialogBox.cpp
  platform/UI/NativeInput/Windows/WindowsDialogBox.h
  platform/UI/NativeInput/Windows/WindowsDialogBoxBuilder.cpp
  platform/UI/NativeInput/Windows/WindowsDialogBoxBuilder.h
  platform/UI/NativeInput/Windows/WindowsDialogBoxParams.h
  platform/UI/NativeInput/Windows/WindowsDialogBoxTemplate.h
  platform/UI/NativeInput/Windows/WindowsInputBox.cpp
  platform/UI/NativeInput/Windows/WindowsInputBox.h
  platform/UI/NativeInput/Windows/WindowsInputBoxFactory.cpp
  platform/UI/NativeInput/Windows/WindowsInputBoxFactory.h
  platform/UI/NativeInput/Windows/WindowsKeyboardInput.cpp
  platform/UI/NativeInput/Windows/WindowsKeyboardInput.h
  platform/UI/NativeInput/Windows/WindowsKeyboardInputFactory.cpp
  platform/UI/NativeInput/Windows/WindowsKeyboardInputFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeInput\\Windows FILES ${currsources})
endif(${WINDOWS})
