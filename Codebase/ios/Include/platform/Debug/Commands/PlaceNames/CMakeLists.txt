set(headers ${headers} platform/Debug/Commands/PlaceNames
)
set(currsources
  platform/Debug/Commands/PlaceNames/CMakeLists.txt
  platform/Debug/Commands/PlaceNames/PlaceNamesEnableCommand.cpp
  platform/Debug/Commands/PlaceNames/PlaceNamesEnableCommand.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Commands\\PlaceNames FILES ${currsources})
