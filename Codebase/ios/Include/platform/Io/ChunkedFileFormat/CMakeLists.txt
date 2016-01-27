set(headers ${headers} platform/Io/ChunkedFileFormat
)
set(currsources
  platform/Io/ChunkedFileFormat/CellModelChunkReader.cpp
  platform/Io/ChunkedFileFormat/CellModelChunkReader.h
  platform/Io/ChunkedFileFormat/ChunkedFileFormat.h
  platform/Io/ChunkedFileFormat/ChunkStream.cpp
  platform/Io/ChunkedFileFormat/ChunkStream.h
  platform/Io/ChunkedFileFormat/CMakeLists.txt
  platform/Io/ChunkedFileFormat/GenericMeshData.h
  platform/Io/ChunkedFileFormat/IQuantizedMeshSetChunkReaderMeshFactory.h
  platform/Io/ChunkedFileFormat/LookUpTableInfo.h
  platform/Io/ChunkedFileFormat/MeshDataExtensions.h
  platform/Io/ChunkedFileFormat/NavGraphChunkReader.cpp
  platform/Io/ChunkedFileFormat/NavGraphChunkReader.h
  platform/Io/ChunkedFileFormat/QCMSMeshReader.cpp
  platform/Io/ChunkedFileFormat/QCMSMeshReader.h
  platform/Io/ChunkedFileFormat/QCMSReaderContext.cpp
  platform/Io/ChunkedFileFormat/QCMSReaderContext.h
  platform/Io/ChunkedFileFormat/QCMSReaderHelpers.cpp
  platform/Io/ChunkedFileFormat/QCMSReaderHelpers.h
  platform/Io/ChunkedFileFormat/QuantizedMeshInfo.h
  platform/Io/ChunkedFileFormat/QuantizedMeshSetChunkReader.cpp
  platform/Io/ChunkedFileFormat/QuantizedMeshSetChunkReader.h
  platform/Io/ChunkedFileFormat/RoadNamesChunkReader.cpp
  platform/Io/ChunkedFileFormat/RoadNamesChunkReader.h
  platform/Io/ChunkedFileFormat/VertexElementFlags.h
)
set(sources ${sources} ${currsources})
source_group(\\Io\\ChunkedFileFormat FILES ${currsources})
