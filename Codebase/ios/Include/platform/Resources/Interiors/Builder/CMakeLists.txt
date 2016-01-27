set(headers ${headers} platform/Resources/Interiors/Builder
)
set(currsources
  platform/Resources/Interiors/Builder/ChunkedInteriorsBuilder.cpp
  platform/Resources/Interiors/Builder/ChunkedInteriorsBuilder.h
  platform/Resources/Interiors/Builder/ChunkedInteriorsBuilderOutput.cpp
  platform/Resources/Interiors/Builder/ChunkedInteriorsBuilderOutput.h
  platform/Resources/Interiors/Builder/CMakeLists.txt
  platform/Resources/Interiors/Builder/InteriorData.cpp
  platform/Resources/Interiors/Builder/InteriorData.h
  platform/Resources/Interiors/Builder/InteriorDto.h
  platform/Resources/Interiors/Builder/InteriorEntitiesChunkDto.h
  platform/Resources/Interiors/Builder/InteriorFloorChunkDto.h
  platform/Resources/Interiors/Builder/InteriorFloorData.cpp
  platform/Resources/Interiors/Builder/InteriorFloorData.h
  platform/Resources/Interiors/Builder/InteriorMetadataChunkDto.h
  platform/Resources/Interiors/Builder/InteriorRenderableCreationData.cpp
  platform/Resources/Interiors/Builder/InteriorRenderableCreationData.h
  platform/Resources/Interiors/Builder/InteriorsJsonParser.cpp
  platform/Resources/Interiors/Builder/InteriorsJsonParser.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Interiors\\Builder FILES ${currsources})
