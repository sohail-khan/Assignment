set(headers ${headers} platform/Camera/GlobeCamera
)
set(currsources
  platform/Camera/GlobeCamera/CMakeLists.txt
  platform/Camera/GlobeCamera/GlobeCamera.h
  platform/Camera/GlobeCamera/GlobeCameraController.cpp
  platform/Camera/GlobeCamera/GlobeCameraController.h
  platform/Camera/GlobeCamera/GlobeCameraControllerConfiguration.cpp
  platform/Camera/GlobeCamera/GlobeCameraControllerConfiguration.h
  platform/Camera/GlobeCamera/GlobeCameraControllerFactory.cpp
  platform/Camera/GlobeCamera/GlobeCameraControllerFactory.h
  platform/Camera/GlobeCamera/GlobeCameraInterestPointProvider.cpp
  platform/Camera/GlobeCamera/GlobeCameraInterestPointProvider.h
  platform/Camera/GlobeCamera/GlobeCameraJumpController.cpp
  platform/Camera/GlobeCamera/GlobeCameraJumpController.h
  platform/Camera/GlobeCamera/GlobeCameraModeTransition.cpp
  platform/Camera/GlobeCamera/GlobeCameraModeTransition.h
  platform/Camera/GlobeCamera/GlobeCameraTerrainFollower.cpp
  platform/Camera/GlobeCamera/GlobeCameraTerrainFollower.h
  platform/Camera/GlobeCamera/GlobeCameraTouchController.cpp
  platform/Camera/GlobeCamera/GlobeCameraTouchController.h
  platform/Camera/GlobeCamera/GlobeCameraTouchControllerConfiguration.cpp
  platform/Camera/GlobeCamera/GlobeCameraTouchControllerConfiguration.h
  platform/Camera/GlobeCamera/GlobeCameraTouchSettings.h
  platform/Camera/GlobeCamera/GpsGlobeCameraComponent.cpp
  platform/Camera/GlobeCamera/GpsGlobeCameraComponent.h
  platform/Camera/GlobeCamera/GpsGlobeCameraComponentConfiguration.cpp
  platform/Camera/GlobeCamera/GpsGlobeCameraComponentConfiguration.h
  platform/Camera/GlobeCamera/GpsGlobeCameraController.cpp
  platform/Camera/GlobeCamera/GpsGlobeCameraController.h
  platform/Camera/GlobeCamera/GpsGlobeCameraControllerFactory.cpp
  platform/Camera/GlobeCamera/GpsGlobeCameraControllerFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Camera\\GlobeCamera FILES ${currsources})
