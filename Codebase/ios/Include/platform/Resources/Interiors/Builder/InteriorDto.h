// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Streaming.h"
#include "InteriorsEntityMetadata.h"
#include "Bounds.h"
#include "MortonKey.h"
#include "LatLongAltitude.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct BoundsDto
                {
                    BoundsDto()
                    : ModelBoundsLocalEcef(Eegeo::Geometry::Bounds3D::Empty())
                    , ModelBoundsTangentSpace(Eegeo::Geometry::Bounds3D::Empty())
                    {}
                    Eegeo::Geometry::Bounds3D ModelBoundsLocalEcef;
                    Eegeo::Geometry::Bounds3D ModelBoundsTangentSpace;
                    std::vector<Eegeo::Geometry::Bounds3D> FloorModelBoundsTangentSpace;
                };
                
                struct LevelDataDto
                {
                    LevelDataDto()
                    : ZLevel(0)
                    {}
                    
                    LevelDataDto(int z_level, const std::string& name, const std::string& readableName)
                    : ZLevel(z_level)
                    , Name(name)
                    , ReadableName(readableName)
                    {}
                    
                    int ZLevel;
                    std::string Name;
                    std::string ReadableName;
                };
                
                struct EntitiesDto
                {
                    Eegeo::Resources::Interiors::Entities::TCategoryToEntitiesMetadata CategoryToEntities;
                };
                
                struct InteriorDto
                {
                    std::string InteriorId;
                    std::string LandmarkName;
                    std::string SourceVendor;
                    
                    BoundsDto Bounds;
                    float TerrainHeight;
                    
                    std::vector<Eegeo::Streaming::MortonKey> IntersectingCellKeys;
                    
                    std::vector<LevelDataDto> LevelDatas;
                    
                    EntitiesDto Entities;
                    
                    Space::LatLong MarkerLatLong;
                    
                    dv3 TangentSpaceOriginEcef;
                    bool HasTangentSpaceOriginEcef;
                    
                    InteriorDto()
                    : TerrainHeight(0.f)
                    , MarkerLatLong(0,0)
                    , TangentSpaceOriginEcef(0,0,0)
                    , HasTangentSpaceOriginEcef(false)
                    {}
                };
            }
        }
    }
}