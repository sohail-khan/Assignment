set(headers ${headers} platform/Resources
)
set(currsources
  platform/Resources/BinaryParsing.cpp
  platform/Resources/BinaryParsing.h
  platform/Resources/BuiltResourceWithKey.h
  platform/Resources/CMakeLists.txt
  platform/Resources/IBuiltResource.h
  platform/Resources/IPlaceholderBuilder.h
  platform/Resources/IResourceBuilder.cpp
  platform/Resources/IResourceBuilder.h
  platform/Resources/ResourceNodeCache.cpp
  platform/Resources/ResourceNodeCache.h
  platform/Resources/Resources.h
  platform/Resources/ResourceSpatialQueryService.cpp
  platform/Resources/ResourceSpatialQueryService.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources FILES ${currsources})
include(platform/Resources/Buildings/CMakeLists.txt)
include(platform/Resources/CityThemes/CMakeLists.txt)
include(platform/Resources/Interiors/CMakeLists.txt)
include(platform/Resources/PlaceNames/CMakeLists.txt)
include(platform/Resources/Roads/CMakeLists.txt)
include(platform/Resources/Terrain/CMakeLists.txt)
