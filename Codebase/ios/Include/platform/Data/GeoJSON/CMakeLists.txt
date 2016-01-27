set(headers ${headers} platform/Data/GeoJSON
)
set(currsources
  platform/Data/GeoJSON/CMakeLists.txt
  platform/Data/GeoJSON/Feature.cpp
  platform/Data/GeoJSON/Feature.h
  platform/Data/GeoJSON/FeatureCollection.cpp
  platform/Data/GeoJSON/FeatureCollection.h
  platform/Data/GeoJSON/GeoJSON.h
  platform/Data/GeoJSON/GeoJSONDocument.cpp
  platform/Data/GeoJSON/GeoJSONDocument.h
  platform/Data/GeoJSON/GeoJSONObject.cpp
  platform/Data/GeoJSON/GeoJSONObject.h
  platform/Data/GeoJSON/GeoJSONTypes.h
  platform/Data/GeoJSON/LinearRing.cpp
  platform/Data/GeoJSON/LinearRing.h
  platform/Data/GeoJSON/MultiPolygon.cpp
  platform/Data/GeoJSON/MultiPolygon.h
  platform/Data/GeoJSON/Polygon.cpp
  platform/Data/GeoJSON/Polygon.h
  platform/Data/GeoJSON/PolygonData.cpp
  platform/Data/GeoJSON/PolygonData.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\GeoJSON FILES ${currsources})
