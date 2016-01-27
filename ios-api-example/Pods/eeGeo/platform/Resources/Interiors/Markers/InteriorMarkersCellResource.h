// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "BuiltResourceWithKey.h"
#include "Streaming.h"

#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Markers
            {
                class InteriorMarkersCellResource : public BuiltResourceWithKey, private Eegeo::NonCopyable
                {
                public:
                    InteriorMarkersCellResource(const Streaming::MortonKey& cellKey,
                                                std::vector<const InteriorMarkerModel*> interiorMarkerModels,
                                                InteriorMarkerModelRepository& interiorMarkerModelRespository);
                    
                    virtual ~InteriorMarkersCellResource();
                    
                    virtual void Unload();
                    
                    virtual void AddedToSceneGraph();
                    
                    virtual void RemovedFromSceneGraph();
                    
                    virtual std::vector<const InteriorMarkerModel*> GetInteriorMarkerModels() const { return m_interiorMarkerModels; }
                    
                private:
                    std::vector<const InteriorMarkerModel*> m_interiorMarkerModels;
                    InteriorMarkerModelRepository& m_interiorMarkerModelRespository;
                };
            }
        }
    }
}
