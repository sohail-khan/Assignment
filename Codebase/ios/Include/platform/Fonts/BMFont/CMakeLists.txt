set(headers ${headers} platform/Fonts/BMFont
)
set(currsources
  platform/Fonts/BMFont/BMFont.h
  platform/Fonts/BMFont/BMFontCommon.h
  platform/Fonts/BMFont/BMFontInfo.h
  platform/Fonts/BMFont/BMFontKerning.h
  platform/Fonts/BMFont/BMFontReaderResult.h
  platform/Fonts/BMFont/BMFontTextReader.cpp
  platform/Fonts/BMFont/BMFontTextReader.h
  platform/Fonts/BMFont/CMakeLists.txt
)
set(sources ${sources} ${currsources})
source_group(\\Fonts\\BMFont FILES ${currsources})
