set(headers ${headers} platform/Streaming/CoverageTrees
)
set(currsources
  platform/Streaming/CoverageTrees/CMakeLists.txt
  platform/Streaming/CoverageTrees/CoverageTreeDownloadFailedHandler.cpp
  platform/Streaming/CoverageTrees/CoverageTreeDownloadFailedHandler.h
  platform/Streaming/CoverageTrees/CoverageTreeManifest.h
  platform/Streaming/CoverageTrees/CoverageTreeManifestLoaderResult.h
  platform/Streaming/CoverageTrees/CoverageTreeManifestNotifier.cpp
  platform/Streaming/CoverageTrees/CoverageTreeManifestNotifier.h
  platform/Streaming/CoverageTrees/CoverageTreeMinMaxLevel.h
  platform/Streaming/CoverageTrees/CoverageTrees.h
  platform/Streaming/CoverageTrees/ICoverageTreeManifestLoader.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\CoverageTrees FILES ${currsources})
