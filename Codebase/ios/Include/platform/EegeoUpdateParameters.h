// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "ScreenProperties.h"
#include "SpaceHelpers.h"
#include "RenderCamera.h"
#include "IStreamingVolume.h"

namespace Eegeo
{
    class EegeoUpdateParameters
    {
        float m_frameDeltaSeconds;
        dv3 m_ecefLocation;
        dv3 m_ecefInterestPoint;
        m44 m_viewMatrix;
        m44 m_projectionMatrix;
        m44 m_viewProjectionMatrix;
        Streaming::IStreamingVolume& m_streamingVolume;
        Rendering::ScreenProperties m_screenProperties;
        
    public:
        EegeoUpdateParameters(float frameDeltaSeconds,
                              const dv3& ecefLocation,
                              const dv3& ecefInterestPoint,
                              const m44& viewMatrix,
                              const m44& projectionMatrix,
                              Streaming::IStreamingVolume& streamingVolume,
                              const Rendering::ScreenProperties& screenProperties)
        : m_frameDeltaSeconds(frameDeltaSeconds)
        , m_ecefLocation(ecefLocation)
        , m_ecefInterestPoint(ecefInterestPoint)
        , m_viewMatrix(viewMatrix)
        , m_projectionMatrix(projectionMatrix)
        , m_streamingVolume(streamingVolume)
        , m_screenProperties(screenProperties)
        {
            Eegeo::m44::Mul(m_viewProjectionMatrix, ProjectionMatrix(), ViewMatrix());
        }
        
        float FrameDeltaSeconds() const { return m_frameDeltaSeconds; }
        
        double Altitude() const { return Eegeo::Space::SpaceHelpers::GetAltitude(EcefLocation()); }
        
        const dv3& EcefLocation() const { return m_ecefLocation; }
        
        const dv3& EcefInterestPoint() const { return m_ecefInterestPoint; }
        
        const m44& ViewMatrix() const { return m_viewMatrix; }
        
        const m44& ProjectionMatrix() const { return m_projectionMatrix; }
        
        Streaming::IStreamingVolume& StreamingVolume() const { return m_streamingVolume; }
        
        const Rendering::ScreenProperties& ScreenProperties() const { return m_screenProperties; }
        
        const m44& ViewProjectionMatrix() const { return m_viewProjectionMatrix; }
    };
    
    inline Camera::RenderCamera RenderCameraFromEegeoUpdateParameters(const EegeoUpdateParameters& eegeoUpdateParameters)
    {
        Camera::RenderCamera renderCamera;
        
        renderCamera.SetViewport(0.f,
                                 0.f,
                                 eegeoUpdateParameters.ScreenProperties().GetScreenWidth(),
                                 eegeoUpdateParameters.ScreenProperties().GetScreenHeight());
        
        m33 viewOrientation(eegeoUpdateParameters.ViewMatrix());
        m33 cameraModel;
        m33::Inverse(cameraModel, viewOrientation);
        m44 projection(eegeoUpdateParameters.ProjectionMatrix());
        dv3 ecefLocation(eegeoUpdateParameters.EcefLocation());
        
        renderCamera.SetOrientationMatrix(cameraModel);
        renderCamera.SetEcefLocation(ecefLocation);
        renderCamera.SetProjectionMatrix(projection);
        
        return renderCamera;
    }
}
