set(headers ${headers} platform/DataStructures
)
set(currsources
  platform/DataStructures/CMakeLists.txt
  platform/DataStructures/Pool.h
  platform/DataStructures/PoolEntry.h
  platform/DataStructures/PoolHandle.h
  platform/DataStructures/PoolImpl.h
  platform/DataStructures/PoolItemFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\DataStructures FILES ${currsources})
