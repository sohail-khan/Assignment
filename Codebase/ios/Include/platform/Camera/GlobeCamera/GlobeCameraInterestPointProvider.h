// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IInterestPointProvider.h"
#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            //! implementation of IInterestPointProvider using a GlobeCameraController to define the
            //! current interest point
            class GlobeCameraInterestPointProvider : public Location::IInterestPointProvider
            {
                GlobeCameraController* m_globeCamera;
                
            public:
                GlobeCameraInterestPointProvider();
                
                void SetGlobeCamera(GlobeCameraController* globeCamera);

                virtual Eegeo::dv3 GetEcefInterestPoint() const;
            };
        }
    }
}
