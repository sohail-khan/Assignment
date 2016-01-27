set(headers ${headers} platform/Resources/Interiors/Entities
)
set(currsources
  platform/Resources/Interiors/Entities/CMakeLists.txt
  platform/Resources/Interiors/Entities/IInteriorsLabelController.h
  platform/Resources/Interiors/Entities/InteriorsEntitiesRepository.cpp
  platform/Resources/Interiors/Entities/InteriorsEntitiesRepository.h
  platform/Resources/Interiors/Entities/InteriorsEntityGeometryView.cpp
  platform/Resources/Interiors/Entities/InteriorsEntityGeometryView.h
  platform/Resources/Interiors/Entities/InteriorsEntityJsonParser.cpp
  platform/Resources/Interiors/Entities/InteriorsEntityJsonParser.h
  platform/Resources/Interiors/Entities/InteriorsEntityMetadata.h
  platform/Resources/Interiors/Entities/InteriorsEntityModel.cpp
  platform/Resources/Interiors/Entities/InteriorsEntityModel.h
  platform/Resources/Interiors/Entities/InteriorsLabelController.cpp
  platform/Resources/Interiors/Entities/InteriorsLabelController.h
  platform/Resources/Interiors/Entities/InteriorsLabelParser.cpp
  platform/Resources/Interiors/Entities/InteriorsLabelParser.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Interiors\\Entities FILES ${currsources})
