// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "InteriorDto.h"
#include "InteriorMetadataChunkDto.h"

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
                struct InteriorData
                {
                    InteriorData(const std::string& interiorName,
                                 const std::vector<const InteriorFloorData*>& interiorFloors,
                                 const InteriorDto& interiorDto,
                                 const InteriorMetadataChunkDto& interiorMetadata,
                                 const InteriorInstanceChunkDto& instanceDto);
                    
                    ~InteriorData();
                    
                    void TransferResourceOwnership();
                    
                    std::string GetInteriorName() const { return m_interiorName; }
                    std::vector<const InteriorFloorData*> GetInteriorFloorData() const { return m_interiorFloors; }
                    InteriorDto GetInteriorDto() const { return m_interiorDto; }
                    InteriorMetadataChunkDto GetInteriorMetadata() const { return m_interiorMetadata; }
                    const InteriorInstanceChunkDto& GetInstanceDto() const { return m_instanceDto; }
                private:
                    const std::string m_interiorName;
                    std::vector<const InteriorFloorData*> m_interiorFloors;
                    const InteriorDto m_interiorDto;
                    const InteriorMetadataChunkDto m_interiorMetadata;
                    const InteriorInstanceChunkDto m_instanceDto;
                };
            }
        }
    }
}