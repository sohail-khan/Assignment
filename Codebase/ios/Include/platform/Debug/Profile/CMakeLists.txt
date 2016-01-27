set(headers ${headers} platform/Debug/Profile
)
set(currsources
  platform/Debug/Profile/CMakeLists.txt
  platform/Debug/Profile/FrameProfile.cpp
  platform/Debug/Profile/FrameProfile.h
  platform/Debug/Profile/FrameProfileFactory.cpp
  platform/Debug/Profile/FrameProfileFactory.h
  platform/Debug/Profile/PerformanceTestRunner.cpp
  platform/Debug/Profile/PerformanceTestRunner.h
  platform/Debug/Profile/Profile.h
  platform/Debug/Profile/Profiler.cpp
  platform/Debug/Profile/Profiler.h
  platform/Debug/Profile/ProfileRecord.cpp
  platform/Debug/Profile/ProfileRecord.h
  platform/Debug/Profile/ProfileRecordFactory.cpp
  platform/Debug/Profile/ProfileRecordFactory.h
  platform/Debug/Profile/ProfileVisualiser.cpp
  platform/Debug/Profile/ProfileVisualiser.h
)
set(sources ${sources} ${currsources})
source_group(\\Debug\\Profile FILES ${currsources})
