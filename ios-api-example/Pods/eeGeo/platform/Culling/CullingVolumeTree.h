// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Culling.h"
#include "VectorMath.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace Culling
    {
        class CullingVolumeTree : private Eegeo::NonCopyable
        {
        public:
            static CullingVolumeTree* Create(const Eegeo::dv3& ecefCellOrigin, const std::vector<CullingVolume>* pCullingVolumes);
            
            CullingVolumeTree(const Eegeo::dv3& ecefCellOrigin, const std::vector<CullingVolume>* pCullingVolumes);
            
            ~CullingVolumeTree();
            
            bool containsNodes() const
            {
                return (m_pCullingVolumes != NULL) && (m_pCullingVolumes->empty() == false);
            }
            
            const dv3& GetEcefCellOrigin() const { return m_ecefCellOrigin; }
            const std::vector<CullingVolume>& GetCullingVolumes() const { return *m_pCullingVolumes; }
            const std::vector<Eegeo::v3>& GetCullingVolumeScaleTargets() const { return m_cullingVolumeScaleTargets; }

        private:
            Eegeo::dv3 m_ecefCellOrigin;
            const std::vector<CullingVolume>* m_pCullingVolumes;
            std::vector<Eegeo::v3> m_cullingVolumeScaleTargets;
        };
    }
}