set(headers ${headers} platform/Streaming/BlockCoverageTrees
)
set(currsources
  platform/Streaming/BlockCoverageTrees/BlockCoverageTree.cpp
  platform/Streaming/BlockCoverageTrees/BlockCoverageTree.h
  platform/Streaming/BlockCoverageTrees/BlockCoverageTreeCube.cpp
  platform/Streaming/BlockCoverageTrees/BlockCoverageTreeCube.h
  platform/Streaming/BlockCoverageTrees/BlockCoverageTreeFactory.cpp
  platform/Streaming/BlockCoverageTrees/BlockCoverageTreeFactory.h
  platform/Streaming/BlockCoverageTrees/BlockCoverageTrees.h
  platform/Streaming/BlockCoverageTrees/CMakeLists.txt
  platform/Streaming/BlockCoverageTrees/CoverageTreeManifestBinaryLoader.cpp
  platform/Streaming/BlockCoverageTrees/CoverageTreeManifestBinaryLoader.h
  platform/Streaming/BlockCoverageTrees/CoverageTreeManifestChunkParser.cpp
  platform/Streaming/BlockCoverageTrees/CoverageTreeManifestChunkParser.h
  platform/Streaming/BlockCoverageTrees/PrioritisedBlockCoverageTreeList.cpp
  platform/Streaming/BlockCoverageTrees/PrioritisedBlockCoverageTreeList.h
)
set(sources ${sources} ${currsources})
source_group(\\Streaming\\BlockCoverageTrees FILES ${currsources})
