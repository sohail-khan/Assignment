set(headers ${headers} platform/Rendering/MeshFactories
)
set(currsources
  platform/Rendering/MeshFactories/CMakeLists.txt
  platform/Rendering/MeshFactories/DiffuseMeshFactory.h
  platform/Rendering/MeshFactories/LcmReadMeshFactory.cpp
  platform/Rendering/MeshFactories/LcmReadMeshFactory.h
  platform/Rendering/MeshFactories/MeshFactory.cpp
  platform/Rendering/MeshFactories/MeshFactory.h
  platform/Rendering/MeshFactories/PackedDiffuseReadMeshFactory.cpp
  platform/Rendering/MeshFactories/PackedDiffuseReadMeshFactory.h
  platform/Rendering/MeshFactories/ReadMeshFactory.cpp
  platform/Rendering/MeshFactories/ReadMeshFactory.h
  platform/Rendering/MeshFactories/SceneModelMeshFactory.cpp
  platform/Rendering/MeshFactories/SceneModelMeshFactory.h
  platform/Rendering/MeshFactories/TextMeshFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\MeshFactories FILES ${currsources})
