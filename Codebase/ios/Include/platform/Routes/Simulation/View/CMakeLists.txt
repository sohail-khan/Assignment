set(headers ${headers} platform/Routes/Simulation/View
)
set(currsources
  platform/Routes/Simulation/View/CMakeLists.txt
  platform/Routes/Simulation/View/RouteSimulationModelBinding.cpp
  platform/Routes/Simulation/View/RouteSimulationModelBinding.h
  platform/Routes/Simulation/View/RouteSimulationViewFactory.cpp
  platform/Routes/Simulation/View/RouteSimulationViewFactory.h
  platform/Routes/Simulation/View/RouteSimulationViewRepository.cpp
  platform/Routes/Simulation/View/RouteSimulationViewRepository.h
  platform/Routes/Simulation/View/RouteSimulationViewService.cpp
  platform/Routes/Simulation/View/RouteSimulationViewService.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Simulation\\View FILES ${currsources})
