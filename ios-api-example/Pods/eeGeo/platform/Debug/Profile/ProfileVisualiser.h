// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "DebugRendering.h"
#include "Profile.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            class ProfileVisualiser : private Eegeo::NonCopyable
            {
            public:
                ProfileVisualiser(const Profiler& profiler, DebugRendering::DebugRenderer& debugRenderer)
                : m_profiler(profiler)
                , m_debugRenderer(debugRenderer)
                , m_enabled(false)
                {
                }
                
                void Draw(const Rendering::RenderContext& renderContext);
                
                const bool GetEnabled() const { return m_enabled; }
                void SetEnabled(bool enabled) { m_enabled = enabled; }

            private:
                const Profiler& m_profiler;
                DebugRendering::DebugRenderer& m_debugRenderer;
                bool m_enabled;
            };
        }
    }
}