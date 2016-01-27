// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "QuantizedMeshSetChunkReader.h"
#include "Collision.h"
#include "CollisionGroup.h"
#include "ChunkedFileFormat.h"
#include "VectorMathDecl.h"

#include <vector>


namespace Eegeo
{
    namespace Collision
    {
        class ICollisionBvhFactory
        {
        public:
            typedef Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderCollisionResult ReaderCollisionResult;
            typedef std::vector<Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::ReaderMeshResult> ReaderMeshResults;
            
            virtual ~ICollisionBvhFactory() {;}
            virtual CollisionBvh* Create(const dv3& ecefOrigin,
                                         const ReaderCollisionResult& readerCollisionResult,
                                         const ReaderMeshResults& readerMeshResults) = 0;
        };
    }
}