// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "Camera.h"
#include "Rendering.h"
#include "VectorMath.h"
#include "Random.h"
#include "Streaming.h"
#include "FireworksSequenceBurstConfiguration.h"
#include <vector>

namespace Eegeo
{
    namespace Fireworks
    {
        struct FireworksSequenceScheduledEmitter
        {
            FireworksSequenceBurstConfiguration config;
            FireworkEmitter* pEmitter;
            bool hasFired;
        };
        
        class FireworksSequence
        {
        public:

            FireworksSequence(const dv3& ecefOrigin,
                              std::vector<FireworksSequenceBurstConfiguration>& burstConfig,
                              Rendering::Renderables::BatchedSpriteRenderable& fireworksRenderable,
                              Streaming::CameraFrustumStreamingVolume& cameraFrustumStreamingVolume,
                              Random& random);
            ~FireworksSequence();
            
            bool IsPlaying() const;
            
            void PlaySequence();
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            void SetEcefOrigin(const dv3& ecefOrigin);
            
        private:
            
            void CreateEmitters(const dv3& ecefOrigin, std::vector<FireworksSequenceBurstConfiguration>& burstConfig);
            void DestroyEmitters();
            
            bool AllBurstsFired() const;
            bool AtLeastOneEmitterStillPlaying() const;
            void ResetSequence();
            
            Random& m_random;
            Rendering::Renderables::BatchedSpriteRenderable& m_fireworksRenderable;
            Streaming::CameraFrustumStreamingVolume& m_cameraFrustumStreamingVolume;
            std::vector<FireworksSequenceScheduledEmitter> m_sequenceEmitters;
            float m_sequenceTime;
            bool m_isPlaying;
        };
    }
}