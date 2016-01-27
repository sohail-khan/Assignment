set(headers ${headers} platform/Routes/Style/Thickness
)
set(currsources
  platform/Routes/Style/Thickness/CMakeLists.txt
  platform/Routes/Style/Thickness/IdentityRouteThicknessPolicy.cpp
  platform/Routes/Style/Thickness/IdentityRouteThicknessPolicy.h
  platform/Routes/Style/Thickness/IRouteThicknessPolicy.h
  platform/Routes/Style/Thickness/LinearAltitudeBasedRouteThicknessPolicy.cpp
  platform/Routes/Style/Thickness/LinearAltitudeBasedRouteThicknessPolicy.h
)
set(sources ${sources} ${currsources})
source_group(\\Routes\\Style\\Thickness FILES ${currsources})
