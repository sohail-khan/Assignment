set(headers ${headers} platform/Concurrency/Tasks/Messages
)
set(currsources
  platform/Concurrency/Tasks/Messages/CMakeLists.txt
  platform/Concurrency/Tasks/Messages/ITaskMessage.h
  platform/Concurrency/Tasks/Messages/ITaskMessageDispatcher.h
  platform/Concurrency/Tasks/Messages/ITaskPoolMessage.h
  platform/Concurrency/Tasks/Messages/ITaskPoolMessageDispatcher.h
  platform/Concurrency/Tasks/Messages/PerformWorkMessage.cpp
  platform/Concurrency/Tasks/Messages/PerformWorkMessage.h
  platform/Concurrency/Tasks/Messages/StopWorkerMessage.cpp
  platform/Concurrency/Tasks/Messages/StopWorkerMessage.h
  platform/Concurrency/Tasks/Messages/WorkCompleteMessage.cpp
  platform/Concurrency/Tasks/Messages/WorkCompleteMessage.h
  platform/Concurrency/Tasks/Messages/WorkerStoppedMessage.cpp
  platform/Concurrency/Tasks/Messages/WorkerStoppedMessage.h
)
set(sources ${sources} ${currsources})
source_group(\\Concurrency\\Tasks\\Messages FILES ${currsources})
