if(${OSX})
set(headers ${headers} platform/OSX
)
set(currsources
  platform/OSX/CMakeLists.txt
  platform/OSX/OSXAppInfoFactory.h
  platform/OSX/OSXAppInfoFactory.mm
  platform/OSX/OSXConnectivityService.cpp
  platform/OSX/OSXConnectivityService.h
  platform/OSX/OSXFileIO.cpp
  platform/OSX/OSXFileIO.h
  platform/OSX/OSXFileIOHelpers.cpp
  platform/OSX/OSXFileIOHelpers.h
  platform/OSX/OSXGlTaskContext.h
  platform/OSX/OSXGlTaskContext.mm
  platform/OSX/OSXGlTaskContextFactory.h
  platform/OSX/OSXGlTaskContextFactory.mm
  platform/OSX/OSXLocationService.cpp
  platform/OSX/OSXLocationService.h
  platform/OSX/OSXLoggingHelper.h
  platform/OSX/OSXLoggingHelper.mm
  platform/OSX/OSXNetworkBandwithStats.cpp
  platform/OSX/OSXPlatformAbstractionModule.h
  platform/OSX/OSXPlatformAbstractionModule.mm
  platform/OSX/OSXPlatformConfigBuilder.cpp
  platform/OSX/OSXPlatformConfigBuilder.h
  platform/OSX/OSXStubUI.h
  platform/OSX/OSXTextRenderer.cpp
  platform/OSX/OSXTextRenderer.h
  platform/OSX/OSXTextureFileLoader.cpp
  platform/OSX/OSXTextureFileLoader.h
  platform/OSX/OSXThreadHelper.mm
  platform/OSX/OSXUrlEncoder.h
  platform/OSX/OSXUrlEncoder.mm
)
set(sources ${sources} ${currsources})
source_group(\\OSX FILES ${currsources})
endif(${OSX})
