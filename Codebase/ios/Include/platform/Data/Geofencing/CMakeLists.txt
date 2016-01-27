set(headers ${headers} platform/Data/Geofencing
)
set(currsources
  platform/Data/Geofencing/CMakeLists.txt
  platform/Data/Geofencing/GeofenceController.h
  platform/Data/Geofencing/GeofenceModel.cpp
  platform/Data/Geofencing/GeofenceModel.h
  platform/Data/Geofencing/GeofenceRenderer.h
  platform/Data/Geofencing/GeofenceTriangulator.cpp
  platform/Data/Geofencing/GeofenceTriangulator.h
  platform/Data/Geofencing/GeofenceView.cpp
  platform/Data/Geofencing/GeofenceView.h
  platform/Data/Geofencing/GeofenceViewFactory.cpp
  platform/Data/Geofencing/GeofenceViewFactory.h
  platform/Data/Geofencing/Geofencing.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\Geofencing FILES ${currsources})
