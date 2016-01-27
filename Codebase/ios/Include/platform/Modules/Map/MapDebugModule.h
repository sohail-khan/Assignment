// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "DebugDecl.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class MapDebugModule : protected Eegeo::NonCopyable
            {
            public:
                
                MapDebugModule(const Streaming::ResourceCeilingProvider& resourceCeilingProvider);
                ~MapDebugModule();
                
                Debug::SplinePlayback::DebugCameraSplinePlaybackService& GetDebugCameraSplinePlaybackService() const;
                
                void Update(float dt);
                
            private:
                
                Debug::SplinePlayback::DebugCameraSplinePlaybackService* m_pDebugCameraSplinePlaybackService;
            };
        }
    }
}