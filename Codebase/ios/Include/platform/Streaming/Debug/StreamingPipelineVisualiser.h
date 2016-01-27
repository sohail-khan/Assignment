//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "DebugRendering.h"
#include "VectorMathDecl.h"
#include "PayloadStateStats.h"
#include "Rendering.h"
#include <deque>

namespace Eegeo
{
    namespace Streaming
    {
        namespace Debug
        {
            class StreamingPipelineVisualiser : protected Eegeo::NonCopyable
            {
            public:
                StreamingPipelineVisualiser(DebugRendering::DebugRenderer& debugRenderer,
                                            const StreamingController& streamingController);
                
                const bool GetEnabled() const { return m_enabled; }
                void SetEnabled(bool enabled) { m_enabled = enabled; }
                
                void Draw(const Rendering::RenderContext& renderContext);
                
            private:
                void DrawPayloadStates(const PayloadStateStats& stats, int index);
                
                bool m_enabled;
                DebugRendering::DebugRenderer& m_debugRenderer;
                const StreamingController& m_streamingController;
                std::deque<PayloadStateStats> m_statsPerFrame;
            };
        }
    }
}