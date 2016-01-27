set(headers ${headers} platform/Resources/Interiors/Markers
)
set(currsources
  platform/Resources/Interiors/Markers/CMakeLists.txt
  platform/Resources/Interiors/Markers/InteriorMarkerModel.cpp
  platform/Resources/Interiors/Markers/InteriorMarkerModel.h
  platform/Resources/Interiors/Markers/InteriorMarkerModelRepository.cpp
  platform/Resources/Interiors/Markers/InteriorMarkerModelRepository.h
  platform/Resources/Interiors/Markers/InteriorMarkersCellResource.cpp
  platform/Resources/Interiors/Markers/InteriorMarkersCellResource.h
  platform/Resources/Interiors/Markers/InteriorMarkersCellResourceBuilder.cpp
  platform/Resources/Interiors/Markers/InteriorMarkersCellResourceBuilder.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Interiors\\Markers FILES ${currsources})
