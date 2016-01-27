set(headers ${headers} platform/TrafficCongestion
)
set(currsources
  platform/TrafficCongestion/CMakeLists.txt
  platform/TrafficCongestion/ITrafficCongestionService.h
  platform/TrafficCongestion/TrafficCongestion.h
  platform/TrafficCongestion/TrafficCongestionConfig.cpp
  platform/TrafficCongestion/TrafficCongestionConfig.h
  platform/TrafficCongestion/TrafficCongestionLevel.cpp
  platform/TrafficCongestion/TrafficCongestionLevel.h
  platform/TrafficCongestion/TrafficCongestionModel.cpp
  platform/TrafficCongestion/TrafficCongestionModel.h
  platform/TrafficCongestion/TrafficCongestionModelCell.cpp
  platform/TrafficCongestion/TrafficCongestionModelCell.h
  platform/TrafficCongestion/TrafficCongestionService.cpp
  platform/TrafficCongestion/TrafficCongestionService.h
  platform/TrafficCongestion/TrafficCongestionSimulationCell.cpp
  platform/TrafficCongestion/TrafficCongestionSimulationCell.h
  platform/TrafficCongestion/TrafficCongestionSimulationController.cpp
  platform/TrafficCongestion/TrafficCongestionSimulationController.h
  platform/TrafficCongestion/TrafficCongestionStateChangedCallback.h
  platform/TrafficCongestion/TrafficCongestionStateData.h
  platform/TrafficCongestion/TrafficCongestionThemeData.h
  platform/TrafficCongestion/TrafficCongestionVehicleFactory.cpp
  platform/TrafficCongestion/TrafficCongestionVehicleFactory.h
  platform/TrafficCongestion/TrafficCongestionVehicleModel.cpp
  platform/TrafficCongestion/TrafficCongestionVehicleModel.h
  platform/TrafficCongestion/TrafficCongestionVehicles.cpp
  platform/TrafficCongestion/TrafficCongestionVehicles.h
)
set(sources ${sources} ${currsources})
source_group(\\TrafficCongestion FILES ${currsources})
