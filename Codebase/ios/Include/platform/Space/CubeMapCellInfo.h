// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "VectorMath.h"
#include "EarthConstants.h"
#include "CubeMap.h"
#include <string>

#define CubeMapCellInfo_DebugString 0

namespace Eegeo
{
    namespace Space
    {
        namespace CubeMap
        {
            struct CubeMapCellInfo
            {
            public:
                CubeMapCellInfo(const Eegeo::Streaming::MortonKey& key)
                : m_key(key)
#if CubeMapCellInfo_DebugString
                , m_debugKeyString(key.ToString())
#endif
                {
                    m_normalisedFaceCentre = CubeMap::KeyToFaceCentre(key, 1.0);
                    m_faceCentre = m_normalisedFaceCentre *  EarthConstants::CubeSideLengthHalf;
                    m_quadTreeLevel = key.Depth() - 1;
                    
                    m_faceIndex = key.Face();
                    m_faceCentreECEF = CubeMap::FacePointToWorld(m_faceIndex, m_faceCentre, EarthConstants::CubeSideLengthHalf);
                    m_normalisedWidth = 1.0 / (1 << (m_quadTreeLevel));
                }
                
                
                const Eegeo::Streaming::MortonKey& GetKey() const { return m_key; }
                int GetFaceIndex() const { return m_faceIndex; }
                const Eegeo::dv2& GetFaceCentre() const { return m_faceCentre; }
                const Eegeo::dv2& GetNormalisedFaceCentre() const { return m_normalisedFaceCentre; }
                const Eegeo::dv3& GetFaceCentreECEF() const { return m_faceCentreECEF;}
                int GetQuadTreeLevel() const { return m_quadTreeLevel; }
                double GetNormalisedWidth() const { return m_normalisedWidth; }
                
            private:
                Eegeo::Streaming::MortonKey m_key;
                Eegeo::dv3 m_faceCentreECEF;
                Eegeo::dv2 m_faceCentre;
                Eegeo::dv2 m_normalisedFaceCentre;
                double m_normalisedWidth;
                int m_faceIndex;
                int m_quadTreeLevel;
#if CubeMapCellInfo_DebugString
                std::string m_debugKeyString;
#endif
            };
            
        }
    }
}
#undef CubeMapCellInfo_DebugString