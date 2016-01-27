set(headers ${headers} platform/Io/POD
)
set(currsources
  platform/Io/POD/CMakeLists.txt
  platform/Io/POD/POD.h
  platform/Io/POD/PODFile.cpp
  platform/Io/POD/PODFile.h
  platform/Io/POD/PODFileHelpers.cpp
  platform/Io/POD/PODFileHelpers.h
  platform/Io/POD/PODFileParser.cpp
  platform/Io/POD/PODFileParser.h
  platform/Io/POD/PODMaterial.cpp
  platform/Io/POD/PODMaterial.h
  platform/Io/POD/PODMaterialParser.cpp
  platform/Io/POD/PODMaterialParser.h
  platform/Io/POD/PODMesh.cpp
  platform/Io/POD/PODMesh.h
  platform/Io/POD/PODMeshParser.cpp
  platform/Io/POD/PODMeshParser.h
  platform/Io/POD/PODNode.cpp
  platform/Io/POD/PODNode.h
  platform/Io/POD/PODNodeParser.cpp
  platform/Io/POD/PODNodeParser.h
  platform/Io/POD/PODScene.cpp
  platform/Io/POD/PODScene.h
  platform/Io/POD/PODSceneParser.cpp
  platform/Io/POD/PODSceneParser.h
  platform/Io/POD/PODTexture.cpp
  platform/Io/POD/PODTexture.h
  platform/Io/POD/PODTextureParser.cpp
  platform/Io/POD/PODTextureParser.h
)
set(sources ${sources} ${currsources})
source_group(\\Io\\POD FILES ${currsources})
