set(headers ${headers} platform/Fonts
)
set(currsources
  platform/Fonts/CMakeLists.txt
  platform/Fonts/FontAlignment.h
  platform/Fonts/FontCharacter.cpp
  platform/Fonts/FontCharacter.h
  platform/Fonts/FontCharacterTable.cpp
  platform/Fonts/FontCharacterTable.h
  platform/Fonts/FontInstance.cpp
  platform/Fonts/FontInstance.h
  platform/Fonts/FontKerningTable.cpp
  platform/Fonts/FontKerningTable.h
  platform/Fonts/FontLayout.cpp
  platform/Fonts/FontLayout.h
  platform/Fonts/FontLegacyHelpers.cpp
  platform/Fonts/FontLegacyHelpers.h
  platform/Fonts/FontLoader.cpp
  platform/Fonts/FontLoader.h
  platform/Fonts/FontRenderer.cpp
  platform/Fonts/FontRenderer.h
  platform/Fonts/Fonts.h
)
set(sources ${sources} ${currsources})
source_group(\\Fonts FILES ${currsources})
include(platform/Fonts/BMFont/CMakeLists.txt)
