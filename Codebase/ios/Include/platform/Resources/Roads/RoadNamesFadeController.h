// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Location.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            class RoadNamesFadeController : protected Eegeo::NonCopyable
            {
            public:
                RoadNamesFadeController()
                : m_masterOpacity(1.0f)
                , m_fadeParam(1.0f)
                {}
                
                void Update(float dt, const double& cameraAltitude, const dv3& interestPoint);

                float GetFadeParam() const { return m_fadeParam; }
                void SetMasterOpacity(float masterOpacity);
                float GetMasterOpacity() const;
                
            private:
                float m_masterOpacity;
                float m_fadeParam;
            };
        }
    }
}
