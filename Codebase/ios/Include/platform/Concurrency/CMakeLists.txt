set(headers ${headers} platform/Concurrency
)
set(currsources
  platform/Concurrency/AtomicOps.h
  platform/Concurrency/CMakeLists.txt
  platform/Concurrency/Concurrency.h
  platform/Concurrency/IRunnable.h
  platform/Concurrency/MPMCQueue.h
  platform/Concurrency/MPMCQueueImpl.h
  platform/Concurrency/SemaphoreEegeo.cpp
  platform/Concurrency/SemaphoreEegeo.h
  platform/Concurrency/Thread.cpp
  platform/Concurrency/Thread.h
)
set(sources ${sources} ${currsources})
source_group(\\Concurrency FILES ${currsources})
include(platform/Concurrency/Tasks/CMakeLists.txt)
