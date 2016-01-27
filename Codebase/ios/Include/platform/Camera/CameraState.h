// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Camera
    {
        class CameraState
        {
            dv3 m_locationEcef;
            dv3 m_interestPointEcef;
            m44 m_viewMatrix;
            m44 m_projectionMatrix;
            
        public:
            CameraState(const dv3& locationEcef,
                        const dv3& interestPointEcef,
                        const m44& viewMatrix,
                        const m44& projectionMatrix)
            : m_locationEcef(locationEcef)
            , m_interestPointEcef(interestPointEcef)
            , m_viewMatrix(viewMatrix)
            , m_projectionMatrix(projectionMatrix)
            {
                
            }
            
            const dv3& LocationEcef() const { return m_locationEcef; }
            
            const dv3& InterestPointEcef() const { return m_interestPointEcef; }
            
            const m44& ViewMatrix() const { return m_viewMatrix; }
            
            const m44& ProjectionMatrix() const { return m_projectionMatrix; }
        };
    }
}