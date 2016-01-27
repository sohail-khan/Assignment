set(headers ${headers} platform/WorldStates
)
set(currsources
  platform/WorldStates/BaseState.cpp
  platform/WorldStates/BaseState.h
  platform/WorldStates/ConnectivityHealthCheckState.cpp
  platform/WorldStates/ConnectivityHealthCheckState.h
  platform/WorldStates/CityThemesLoadEmbeddedThemeState.cpp
  platform/WorldStates/CityThemesLoadEmbeddedThemeState.h
  platform/WorldStates/CityThemesLoadManifestState.cpp
  platform/WorldStates/CityThemesLoadManifestState.h
  platform/WorldStates/CMakeLists.txt
  platform/WorldStates/DownloadBootstrapResourcesState.cpp
  platform/WorldStates/DownloadBootstrapResourcesState.h
  platform/WorldStates/IChangeStateCallback.h
  platform/WorldStates/IWorldState.h
  platform/WorldStates/RunningState.cpp
  platform/WorldStates/RunningState.h
  platform/WorldStates/StreamingInitialSceneState.cpp
  platform/WorldStates/StreamingInitialSceneState.h
  platform/WorldStates/ValidateApiTokenState.cpp
  platform/WorldStates/ValidateApiTokenState.h
  platform/WorldStates/WorldStateManager.cpp
  platform/WorldStates/WorldStateManager.h
  platform/WorldStates/WorldStates.h
)
set(sources ${sources} ${currsources})
source_group(\\WorldStates FILES ${currsources})
