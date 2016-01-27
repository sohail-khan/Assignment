set(headers ${headers} platform/Debug/Commands/TrafficCongestion
)
set(currsources
  platform/Debug/Commands/TrafficCongestion/CMakeLists.txt
  platform/Debug/Commands/TrafficCongestion/SetCongestionCommand.cpp
  platform/Debug/Commands/TrafficCongestion/SetCongestionCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\TrafficCongestion FILES ${currsources})
