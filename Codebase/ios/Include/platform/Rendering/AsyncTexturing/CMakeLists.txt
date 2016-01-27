set(headers ${headers} platform/Rendering/AsyncTexturing
)
set(currsources
  platform/Rendering/AsyncTexturing/AsyncTexturing.h
  platform/Rendering/AsyncTexturing/CMakeLists.txt
  platform/Rendering/AsyncTexturing/HttpAsyncTexture.cpp
  platform/Rendering/AsyncTexturing/HttpAsyncTexture.h
  platform/Rendering/AsyncTexturing/HttpAsyncTextureLoader.cpp
  platform/Rendering/AsyncTexturing/HttpAsyncTextureLoader.h
  platform/Rendering/AsyncTexturing/IAsyncTexture.h
  platform/Rendering/AsyncTexturing/IAsyncTextureObserver.h
  platform/Rendering/AsyncTexturing/IAsyncTextureRequestor.h
  platform/Rendering/AsyncTexturing/LocalAsyncTextureLoader.cpp
  platform/Rendering/AsyncTexturing/LocalAsyncTextureLoader.h
  platform/Rendering/AsyncTexturing/Texture.cpp
  platform/Rendering/AsyncTexturing/Texture.h
)
set(sources ${sources} ${currsources})
source_group(\\Rendering\\AsyncTexturing FILES ${currsources})
