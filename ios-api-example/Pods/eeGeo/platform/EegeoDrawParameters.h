// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "ScreenProperties.h"
#include "SpaceHelpers.h"
#include "RenderCamera.h"

namespace Eegeo
{
    class EegeoDrawParameters
    {
        dv3 m_ecefLocation;
        dv3 m_ecefInterestPoint;
        m44 m_viewMatrix;
        m44 m_projectionMatrix;
        m44 m_viewProjectionMatrix;
        Rendering::ScreenProperties m_screenProperties;
        
    public:
        EegeoDrawParameters(const dv3& ecefLocation,
                            const dv3& ecefInterestPoint,
                            const m44& viewMatrix,
                            const m44& projectionMatrix,
                            const Rendering::ScreenProperties& screenProperties)
        : m_ecefLocation(ecefLocation)
        , m_ecefInterestPoint(ecefInterestPoint)
        , m_viewMatrix(viewMatrix)
        , m_projectionMatrix(projectionMatrix)
        , m_screenProperties(screenProperties)
        {
            Eegeo::m44::Mul(m_viewProjectionMatrix, ProjectionMatrix(), ViewMatrix());
        }
        
        double Altitude() const { return Eegeo::Space::SpaceHelpers::GetAltitude(EcefLocation()); }
        
        const dv3& EcefLocation() const { return m_ecefLocation; }
        
        const dv3& EcefInterestPoint() const { return m_ecefInterestPoint; }
        
        const m44& ViewMatrix() const { return m_viewMatrix; }
        
        const m44& ProjectionMatrix() const { return m_projectionMatrix; }
        
        const Rendering::ScreenProperties& ScreenProperties() const { return m_screenProperties; }
        
        const m44& ViewProjectionMatrix() const { return m_viewProjectionMatrix; }
    };
    
    inline Camera::RenderCamera RenderCameraFromEegeoDrawParameters(const EegeoDrawParameters& eegeoDrawParameters)
    {
        Camera::RenderCamera renderCamera;
        
        renderCamera.SetViewport(0.f,
                                 0.f,
                                 eegeoDrawParameters.ScreenProperties().GetScreenWidth(),
                                 eegeoDrawParameters.ScreenProperties().GetScreenHeight());
        
        m33 viewOrientation(eegeoDrawParameters.ViewMatrix());
        m33 cameraModel;
        m33::Inverse(cameraModel, viewOrientation);
        m44 projection(eegeoDrawParameters.ProjectionMatrix());
        dv3 ecefLocation(eegeoDrawParameters.EcefLocation());
        
        renderCamera.SetOrientationMatrix(cameraModel);
        renderCamera.SetEcefLocation(ecefLocation);
        renderCamera.SetProjectionMatrix(projection);
        
        return renderCamera;
    }
}
