set(headers ${headers} platform/Base/Model
)
set(currsources
  platform/Base/Model/BaseModelMaterial.cpp
  platform/Base/Model/BaseModelMaterial.h
  platform/Base/Model/CMakeLists.txt
  platform/Base/Model/CRC32.cpp
  platform/Base/Model/CRC32.h
  platform/Base/Model/Model.cpp
  platform/Base/Model/Model.h
  platform/Base/Model/ModelHelpers.cpp
  platform/Base/Model/ModelHelpers.h
  platform/Base/Model/ModelMesh.cpp
  platform/Base/Model/ModelMesh.h
  platform/Base/Model/Models.h
  platform/Base/Model/Node.cpp
  platform/Base/Model/Node.h
  platform/Base/Model/SceneAnimator.cpp
  platform/Base/Model/SceneAnimator.h
)
set(sources ${sources} ${currsources})
source_group(\\Base\\Model FILES ${currsources})
