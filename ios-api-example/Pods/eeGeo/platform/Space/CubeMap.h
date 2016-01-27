// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "MortonKey.h"
#include "Space.h"

namespace Eegeo
{
    namespace Space
    {
        namespace CubeMap
        {
            enum
            {
                FacePositiveX = 0,  // america
                FaceNegativeX = 1,  // india
                FacePositiveY = 2,  // north pole
                FaceNegativeY = 3,  // south pole
                FacePositiveZ = 4,  // africa
                FaceNegativeZ = 5,  // pacific
                
                FaceCount = 6,
                FaceInvalid = -1
            };

            Eegeo::dv3 FacePointToEcefNormal(int face, Eegeo::dv2 point, double faceSideLengthHalf);
            Eegeo::dv3 FacePointToWorld(int face, Eegeo::dv2 point, double faceSideLengthHalf);
            Eegeo::dv2 WorldPointToFace(int face, Eegeo::dv3 point, double faceSideLengthHalf);
            Eegeo::dv2 KeyToFaceCentre(Eegeo::Streaming::MortonKey key, double faceSideLengthHalf);
            Eegeo::dv3 KeyToECEF(Eegeo::Streaming::MortonKey key);
            Eegeo::Streaming::MortonKey FacePointToKey(Eegeo::dv2 point, int faceIndex, double faceSideLengthHalf, int keyDepth);
            int WorldPointToFaceIndex(const Eegeo::dv3& point);
            
            //! \deprecated use WorldPointToFaceIndex(const Eegeo::dv3& point) instead - faceSideLengthHalf param is unnecessary
            int WorldPointToFaceIndex(Eegeo::dv3 point, double faceSideLengthHalf);
            
            Eegeo::v2 FacePointToKeyNormalised(Eegeo::Streaming::MortonKey key, Eegeo::dv2 facePoint);
            Eegeo::Streaming::MortonKey EcefToKey(Eegeo::dv3 ecefPosition, int level);
        }
    }
}
