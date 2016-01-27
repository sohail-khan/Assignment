// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "FrameTimer.h"
#include "DebugRenderer.h"

namespace Eegeo
{
    namespace Debug
    {
        class FrameTimerVisualiser : protected Eegeo::NonCopyable
        {
        public:
            FrameTimerVisualiser(const FrameTimer& frameTimer,
                                 DebugRendering::DebugRenderer& debugRenderer)
            : m_warningMs(33)
            , m_errorMs(40)
            , m_frameTimer(frameTimer)
            , m_debugRenderer(debugRenderer)
            , m_enabled(false)
            {
            }
            
            const bool GetEnabled() const { return m_enabled; }
            void SetEnabled(bool enabled) { m_enabled = enabled; }
            
            void SetWarningMs(int warningMs) { m_warningMs = warningMs; }
            void SetErrorMs(int errorMs) { m_errorMs = errorMs; }
            
            void Draw(const Rendering::RenderContext& renderContext);
            
        private:
            void DrawSample(const FrameTime& sample, const v2& screenDimensions, int position);
            
            v4 GetUpdateColor(float frameTimeMS);
            v4 GetFrameColor(float frameTimeMS);
            v4 GetDrawColor(float frameTimeMS);
            
            float m_warningMs;
            float m_errorMs;
            const FrameTimer& m_frameTimer;
            DebugRendering::DebugRenderer& m_debugRenderer;
            bool m_enabled;
        };
    }
}