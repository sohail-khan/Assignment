set(headers ${headers} platform/Traffic/Config
)
set(currsources
  platform/Traffic/Config/CMakeLists.txt
  platform/Traffic/Config/PlaneSimulationConfig.h
  platform/Traffic/Config/TrafficSimulationAltitudeSpeedConfiguration.cpp
  platform/Traffic/Config/TrafficSimulationAltitudeSpeedConfiguration.h
  platform/Traffic/Config/TrafficSimulationConfiguration.cpp
  platform/Traffic/Config/TrafficSimulationConfiguration.h
  platform/Traffic/Config/TrafficVehicleRandomHelpers.cpp
  platform/Traffic/Config/TrafficVehicleRandomHelpers.h
)
set(sources ${sources} ${currsources})
source_group(\\Traffic\\Config FILES ${currsources})
