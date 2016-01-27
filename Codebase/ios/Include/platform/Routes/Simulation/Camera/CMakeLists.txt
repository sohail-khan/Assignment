set(headers ${headers} platform/Routes/Simulation/Camera
)
set(currsources
  platform/Routes/Simulation/Camera/CMakeLists.txt
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraController.cpp
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraController.h
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraControllerConfig.cpp
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraControllerConfig.h
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraControllerFactory.cpp
  platform/Routes/Simulation/Camera/RouteSimulationGlobeCameraControllerFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Simulation\\Camera FILES ${currsources})
