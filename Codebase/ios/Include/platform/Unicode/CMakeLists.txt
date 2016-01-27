set(headers ${headers} platform/Unicode
)
set(currsources
  platform/Unicode/CMakeLists.txt
  platform/Unicode/Unicode.h
  platform/Unicode/UnicodeConverter.cpp
  platform/Unicode/UnicodeConverter.h
  platform/Unicode/Utf8.cpp
  platform/Unicode/Utf8.h
)
set(sources ${sources} ${currsources})
source_group(\\Unicode FILES ${currsources})
