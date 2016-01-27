set(headers ${headers} platform/UI/NativeInput
)
set(currsources
  platform/UI/NativeInput/CMakeLists.txt
  platform/UI/NativeInput/IInputBox.h
  platform/UI/NativeInput/IInputBoxDismissedHandler.h
  platform/UI/NativeInput/IInputBoxFactory.h
  platform/UI/NativeInput/IKeyboardInput.h
  platform/UI/NativeInput/IKeyboardInputDismissedHandler.h
  platform/UI/NativeInput/IKeyboardInputFactory.h
  platform/UI/NativeInput/IKeyboardInputKeyPressedHandler.h
  platform/UI/NativeInput/InputBox.h
  platform/UI/NativeInput/KeyboardInput.h
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeInput FILES ${currsources})
include(platform/UI/NativeInput/Android/CMakeLists.txt)
include(platform/UI/NativeInput/iOS/CMakeLists.txt)
include(platform/UI/NativeInput/Windows/CMakeLists.txt)
