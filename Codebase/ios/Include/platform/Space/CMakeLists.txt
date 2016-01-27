set(headers ${headers} platform/Space
)
set(currsources
  platform/Space/CMakeLists.txt
  platform/Space/CoordinateConversion.cpp
  platform/Space/CoordinateConversion.h
  platform/Space/CubeMap.cpp
  platform/Space/CubeMap.h
  platform/Space/CubeMapCellHelpers.cpp
  platform/Space/CubeMapCellHelpers.h
  platform/Space/CubeMapCellInfo.h
  platform/Space/EarthConstants.cpp
  platform/Space/EarthConstants.h
  platform/Space/Ecef.cpp
  platform/Space/Ecef.h
  platform/Space/EcefTangentBasis.cpp
  platform/Space/EcefTangentBasis.h
  platform/Space/LatLongAltitude.cpp
  platform/Space/LatLongAltitude.h
  platform/Space/Space.h
  platform/Space/SpaceHelpers.cpp
  platform/Space/SpaceHelpers.h
)
set(sources ${sources} ${currsources})
source_group(\\Space FILES ${currsources})
