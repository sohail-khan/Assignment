set(headers ${headers} platform/Data/PolyChart
)
set(currsources
  platform/Data/PolyChart/CMakeLists.txt
  platform/Data/PolyChart/PolyChart.h
  platform/Data/PolyChart/PolyChartController.h
  platform/Data/PolyChart/PolyChartModel.cpp
  platform/Data/PolyChart/PolyChartModel.h
  platform/Data/PolyChart/PolyChartRenderer.h
  platform/Data/PolyChart/PolyChartView.cpp
  platform/Data/PolyChart/PolyChartView.h
  platform/Data/PolyChart/PolyChartViewFactory.cpp
  platform/Data/PolyChart/PolyChartViewFactory.h
)
set(sources ${sources} ${currsources})
source_group(\\Data\\PolyChart FILES ${currsources})
