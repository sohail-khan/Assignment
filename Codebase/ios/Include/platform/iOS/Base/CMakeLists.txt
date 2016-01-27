if(${IOS})
set(headers ${headers} platform/iOS/Base
)
set(currsources
  platform/iOS/Base/App.h
  platform/iOS/Base/App.mm
  platform/iOS/Base/AppDelegate.h
  platform/iOS/Base/AppDelegate.mm
  platform/iOS/Base/CMakeLists.txt
  platform/iOS/Base/Helper.h
  platform/iOS/Base/IOSHelper.h
  platform/iOS/Base/IOSHelper.mm
)
set(sources ${sources} ${currsources})
source_group(\\iOS\\Base FILES ${currsources})
endif(${IOS})
