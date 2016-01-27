set(headers ${headers} platform/Resources/Roads/Navigation
)
set(currsources
  platform/Resources/Roads/Navigation/CMakeLists.txt
  platform/Resources/Roads/Navigation/DebugNavigationGraphMesh.cpp
  platform/Resources/Roads/Navigation/DebugNavigationGraphMesh.h
  platform/Resources/Roads/Navigation/NavGraphHelpers.cpp
  platform/Resources/Roads/Navigation/NavGraphHelpers.h
  platform/Resources/Roads/Navigation/Navigation.h
  platform/Resources/Roads/Navigation/NavigationGraph.cpp
  platform/Resources/Roads/Navigation/NavigationGraph.h
  platform/Resources/Roads/Navigation/NavigationGraphAddedCallback.h
  platform/Resources/Roads/Navigation/NavigationGraphBuilder.cpp
  platform/Resources/Roads/Navigation/NavigationGraphBuilder.h
  platform/Resources/Roads/Navigation/NavigationGraphDebuggingService.cpp
  platform/Resources/Roads/Navigation/NavigationGraphDebuggingService.h
  platform/Resources/Roads/Navigation/NavigationGraphLink.cpp
  platform/Resources/Roads/Navigation/NavigationGraphLink.h
  platform/Resources/Roads/Navigation/NavigationGraphLinkManager.cpp
  platform/Resources/Roads/Navigation/NavigationGraphLinkManager.h
  platform/Resources/Roads/Navigation/NavigationGraphRemovalCallback.h
  platform/Resources/Roads/Navigation/NavigationGraphRepository.cpp
  platform/Resources/Roads/Navigation/NavigationGraphRepository.h
  platform/Resources/Roads/Navigation/NavigationGraphRoad.cpp
  platform/Resources/Roads/Navigation/NavigationGraphRoad.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\Roads\\Navigation FILES ${currsources})
