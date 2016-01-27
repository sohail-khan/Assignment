set(headers ${headers} platform/Concurrency/Tasks
)
set(currsources
  platform/Concurrency/Tasks/CMakeLists.txt
  platform/Concurrency/Tasks/DefaultWorkPool.cpp
  platform/Concurrency/Tasks/DefaultWorkPool.h
  platform/Concurrency/Tasks/GlTaskWorker.cpp
  platform/Concurrency/Tasks/GlTaskWorker.h
  platform/Concurrency/Tasks/IGlTaskContext.h
  platform/Concurrency/Tasks/IGlTaskContextFactory.h
  platform/Concurrency/Tasks/ITaskWorkerRunner.h
  platform/Concurrency/Tasks/IWorkPool.h
  platform/Concurrency/Tasks/Tasks.h
  platform/Concurrency/Tasks/TaskWorker.cpp
  platform/Concurrency/Tasks/TaskWorker.h
  platform/Concurrency/Tasks/TaskWorkerState.h
  platform/Concurrency/Tasks/TaskWorkPool.cpp
  platform/Concurrency/Tasks/TaskWorkPool.h
  platform/Concurrency/Tasks/TaskWorkPoolState.h
  platform/Concurrency/Tasks/ThreadedTaskWorkerRunner.cpp
  platform/Concurrency/Tasks/ThreadedTaskWorkerRunner.h
  platform/Concurrency/Tasks/WorkItem.cpp
  platform/Concurrency/Tasks/WorkItem.h
)
set(sources ${sources} ${currsources})
source_group(\\Concurrency\\Tasks FILES ${currsources})
include(platform/Concurrency/Tasks/Messages/CMakeLists.txt)
