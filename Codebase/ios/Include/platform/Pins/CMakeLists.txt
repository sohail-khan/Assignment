set(headers ${headers} platform/Pins
)
set(currsources
  platform/Pins/CMakeLists.txt
  platform/Pins/IPinObservable.h
  platform/Pins/IPinObserver.h
  platform/Pins/IPinViewFactory.h
  platform/Pins/Pin.cpp
  platform/Pins/Pin.h
  platform/Pins/PinController.h
  platform/Pins/PinRepository.cpp
  platform/Pins/PinRepository.h
  platform/Pins/Pins.h
  platform/Pins/PinsModule.cpp
  platform/Pins/PinsModule.h
  platform/Pins/PinView.cpp
  platform/Pins/PinView.h
  platform/Pins/PinViewFactory.h
  platform/Pins/PinViewRenderer.cpp
  platform/Pins/PinViewRenderer.h
)
set(sources ${sources} ${currsources})
source_group(\\Pins FILES ${currsources})
