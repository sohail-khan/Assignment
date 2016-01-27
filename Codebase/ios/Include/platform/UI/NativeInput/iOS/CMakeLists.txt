if(${IOS})
set(headers ${headers} platform/UI/NativeInput/iOS
)
set(currsources
  platform/UI/NativeInput/iOS/CMakeLists.txt
  platform/UI/NativeInput/iOS/iOSInputBox.h
  platform/UI/NativeInput/iOS/iOSInputBox.mm
  platform/UI/NativeInput/iOS/iOSInputBoxFactory.h
  platform/UI/NativeInput/iOS/iOSInputBoxFactory.mm
  platform/UI/NativeInput/iOS/iOSKeyboardInput.h
  platform/UI/NativeInput/iOS/iOSKeyboardInput.mm
  platform/UI/NativeInput/iOS/iOSKeyboardInputFactory.h
  platform/UI/NativeInput/iOS/iOSKeyboardInputFactory.mm
  platform/UI/NativeInput/iOS/iOSKeyboardLocationObserver.h
  platform/UI/NativeInput/iOS/iOSKeyboardLocationObserver.mm
)
set(sources ${sources} ${currsources})
source_group(\\UI\\NativeInput\\iOS FILES ${currsources})
endif(${IOS})
