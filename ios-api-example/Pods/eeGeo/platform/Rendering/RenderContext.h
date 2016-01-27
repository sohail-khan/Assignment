// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Camera.h"

namespace Eegeo
{
    namespace Rendering
    {    
        class RenderContext : Eegeo::NonCopyable
        {
        public:
            RenderContext(const Camera::RenderCamera& renderCamera, const ScreenProperties& screenProperties);
            
            const Camera::RenderCamera& GetRenderCamera() const;
            const ScreenProperties& GetScreenProperties() const;
            
        private:
        
            const Camera::RenderCamera& m_renderCamera;
            const ScreenProperties& m_screenProperties;
        };
    }
}
