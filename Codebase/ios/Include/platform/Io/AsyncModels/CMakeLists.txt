set(headers ${headers} platform/Io/AsyncModels
)
set(currsources
  platform/Io/AsyncModels/AsyncModels.h
  platform/Io/AsyncModels/CMakeLists.txt
  platform/Io/AsyncModels/HttpAsyncModel.cpp
  platform/Io/AsyncModels/HttpAsyncModel.h
  platform/Io/AsyncModels/HttpAsyncModelLoader.cpp
  platform/Io/AsyncModels/HttpAsyncModelLoader.h
  platform/Io/AsyncModels/IAsyncModel.h
  platform/Io/AsyncModels/IAsyncModelObserver.h
)
set(sources ${sources} ${currsources})
source_group(\\Io\\AsyncModels FILES ${currsources})
