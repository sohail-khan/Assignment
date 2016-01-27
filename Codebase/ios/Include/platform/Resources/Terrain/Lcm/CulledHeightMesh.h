// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "CullingVolume.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace lcm
            {
                class CulledHeightMesh
                {
                public:
                    const std::vector<Eegeo::v3>& vertices() const { return *m_pVertices; }
                    const std::vector<u16>& indices() const { return *m_pIndices; }
                    const std::vector<Culling::CullingVolume>& cullingVolumes() const { return *m_pCullingVolumes; }
                    const Eegeo::dv3& originEcef() const { return m_originEcef; }
                    
                    
                    CulledHeightMesh();
                    
                    CulledHeightMesh(std::vector<Eegeo::v3>* pVertices,
                                     std::vector<u16>* pIndices,
                                     std::vector<Culling::CullingVolume>* pCullingVolumes,
                                     const Eegeo::dv3& originEcef
                                     );
                    
                    ~CulledHeightMesh();
                    
                    
                private:
                    std::vector<Eegeo::v3>* m_pVertices;
                    std::vector<u16>* m_pIndices;
                    std::vector<Culling::CullingVolume>* m_pCullingVolumes;
                    Eegeo::dv3 m_originEcef;
                    
                };
            }
        }
    }
}
