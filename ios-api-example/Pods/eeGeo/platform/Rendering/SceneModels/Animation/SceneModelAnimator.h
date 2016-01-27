// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Types.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelAnimator : private Eegeo::NonCopyable
            {
            public:
                
                SceneModelAnimator(SceneModel& sceneModel, float fps);
                
                void Play();
                void Update(float dt);
                void Stop();
                
                void SetFps(float fps);
                const float GetFps() const;
                
                void SetLoopAnimation(bool loopAnimation);
                const bool GetAnimationIsLooped() const;
                
                const float GetAnimationLengthInSeconds() const;
                const float GetAnimationProgressInSeconds() const;
                
            private:
                
                SceneModel& m_sceneModel;
                
                float m_fps;
                float m_totalAnimationTime;
                float m_animationProgress;
                u32 m_frameCount;
                bool m_loop;
                bool m_playing;
                
                void CalculateAnimationTime();
                void RefreshSceneModel();
            };
        }
    }
}