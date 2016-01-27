set(headers ${headers} platform/Routes/Simulation
)
set(currsources
  platform/Routes/Simulation/CMakeLists.txt
  platform/Routes/Simulation/IRouteSimulationSessionObserver.h
  platform/Routes/Simulation/RouteSample.cpp
  platform/Routes/Simulation/RouteSample.h
  platform/Routes/Simulation/RouteSampler.cpp
  platform/Routes/Simulation/RouteSampler.h
  platform/Routes/Simulation/RouteSamplerFactory.cpp
  platform/Routes/Simulation/RouteSamplerFactory.h
  platform/Routes/Simulation/RouteSimulationRouteObserver.cpp
  platform/Routes/Simulation/RouteSimulationRouteObserver.h
  platform/Routes/Simulation/RouteSimulationService.cpp
  platform/Routes/Simulation/RouteSimulationService.h
  platform/Routes/Simulation/RouteSimulationSession.cpp
  platform/Routes/Simulation/RouteSimulationSession.h
  platform/Routes/Simulation/RouteSimulationSessionCallback.h
  platform/Routes/Simulation/RouteSimulationSessionFactory.cpp
  platform/Routes/Simulation/RouteSimulationSessionFactory.h
  platform/Routes/Simulation/RouteSimulationSessionFittedRouteObserver.cpp
  platform/Routes/Simulation/RouteSimulationSessionFittedRouteObserver.h
  platform/Routes/Simulation/RouteSimulationSessionRepository.cpp
  platform/Routes/Simulation/RouteSimulationSessionRepository.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Simulation FILES ${currsources})
include(platform/Routes/Simulation/Camera/CMakeLists.txt)
include(platform/Routes/Simulation/View/CMakeLists.txt)
