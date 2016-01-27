set(headers ${headers} platform/Streaming/Prioritisers
)
set(currsources
  platform/Streaming/Prioritisers/BuildPrioritiser.cpp
  platform/Streaming/Prioritisers/BuildPrioritiser.h
  platform/Streaming/Prioritisers/CMakeLists.txt
  platform/Streaming/Prioritisers/LoadPrioritiser.cpp
  platform/Streaming/Prioritisers/LoadPrioritiser.h
  platform/Streaming/Prioritisers/PayloadPriorityComparator.cpp
  platform/Streaming/Prioritisers/PayloadPriorityComparator.h
  platform/Streaming/Prioritisers/ResourceStreamPriorities.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\Prioritisers FILES ${currsources})
