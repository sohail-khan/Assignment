set(headers ${headers} platform/Helpers/Jpeg
)
set(currsources
  platform/Helpers/Jpeg/CMakeLists.txt
  platform/Helpers/Jpeg/IJpegLoader.h
  platform/Helpers/Jpeg/JpegImage.h
  platform/Helpers/Jpeg/JpegLoader.cpp
  platform/Helpers/Jpeg/JpegLoader.h
  platform/Helpers/Jpeg/JpegType.h
)
set(sources ${sources} ${currsources})
source_group(\\Helpers\\Jpeg FILES ${currsources})
