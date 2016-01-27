if(${ANDROID})
set(headers ${headers} platform/UI/NativeInput/Android
)
set(currsources
  platform/UI/NativeInput/Android/AndroidInputBox.cpp
  platform/UI/NativeInput/Android/AndroidInputBox.h
  platform/UI/NativeInput/Android/AndroidInputBoxFactory.cpp
  platform/UI/NativeInput/Android/AndroidInputBoxFactory.h
  platform/UI/NativeInput/Android/AndroidKeyboardInput.cpp
  platform/UI/NativeInput/Android/AndroidKeyboardInput.h
  platform/UI/NativeInput/Android/AndroidKeyboardInputFactory.cpp
  platform/UI/NativeInput/Android/AndroidKeyboardInputFactory.h
  platform/UI/NativeInput/Android/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeInput\\Android FILES ${currsources})
endif(${ANDROID})
