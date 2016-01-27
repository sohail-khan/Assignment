set(headers ${headers} platform/Routes/Fitting
)
set(currsources
  platform/Routes/Fitting/Candidate.h
  platform/Routes/Fitting/CMakeLists.txt
  platform/Routes/Fitting/FittedRoute.h
  platform/Routes/Fitting/FittedRouteCallback.h
  platform/Routes/Fitting/FittedRouteFactory.cpp
  platform/Routes/Fitting/FittedRouteFactory.h
  platform/Routes/Fitting/FittedRouteRepository.cpp
  platform/Routes/Fitting/FittedRouteRepository.h
  platform/Routes/Fitting/FittedRouteSection.h
  platform/Routes/Fitting/FittingTerrainProjector.cpp
  platform/Routes/Fitting/FittingTerrainProjector.h
  platform/Routes/Fitting/NavGraphDebugAnnotation.cpp
  platform/Routes/Fitting/NavGraphDebugAnnotation.h
  platform/Routes/Fitting/NavGraphFittingInfoForKey.cpp
  platform/Routes/Fitting/NavGraphFittingInfoForKey.h
  platform/Routes/Fitting/NavGraphFittingInfoRepository.cpp
  platform/Routes/Fitting/NavGraphFittingInfoRepository.h
  platform/Routes/Fitting/NavGraphFittingInfoService.cpp
  platform/Routes/Fitting/NavGraphFittingInfoService.h
  platform/Routes/Fitting/NavGraphRoadFittingInfo.cpp
  platform/Routes/Fitting/NavGraphRoadFittingInfo.h
  platform/Routes/Fitting/RouteFittingService.cpp
  platform/Routes/Fitting/RouteFittingService.h
  platform/Routes/Fitting/RouteObserver.cpp
  platform/Routes/Fitting/RouteObserver.h
  platform/Routes/Fitting/UnfittedRouteBuilder.cpp
  platform/Routes/Fitting/UnfittedRouteBuilder.h
  platform/Routes/Fitting/UniqueKeyFifo.cpp
  platform/Routes/Fitting/UniqueKeyFifo.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Fitting FILES ${currsources})
include(platform/Routes/Fitting/NavGraphConforming/CMakeLists.txt)
