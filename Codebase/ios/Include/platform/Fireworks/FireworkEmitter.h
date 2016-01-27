// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Rendering.h"
#include "Camera.h"
#include "Random.h"
#include "VectorMath.h"
#include "Streaming.h"
#include "EcefTangentBasis.h"
#include <vector>

namespace Eegeo
{
    namespace Fireworks
    {
        struct FireworkParticle
        {
            v3 startPosition;
            v3 endPosition;
            v4 color;
        };
        
        class FireworkEmitter
        {
        public:
            
            FireworkEmitter(int maxParticles, const dv3& ecefOrigin, Rendering::Renderables::BatchedSpriteRenderable& fireworksRenderable, Random& random);
            ~FireworkEmitter();
            
            const bool IsPlaying() const { return m_isPlayingBurstAnimation; }
            
            void Update(float dt, const Camera::RenderCamera& renderCamera, Streaming::CameraFrustumStreamingVolume& cameraFrustumStreamingVolume);
            void PlayBurstAnimation(const v3& offset, const v4& color, float burstSize);
            void SetEcefOrigin(const dv3& ecefOrigin);
            
        private:
            
            Random& m_random;
            Space::EcefTangentBasis m_tangentBasis;
            std::vector<FireworkParticle> m_particles;
            dv3 m_ecefOrigin;
            dv3 m_ecefBurstOrigin;
            v3 m_localUp;
            v3 m_gravityFalloffOffset;
            Rendering::Renderables::BatchedSpriteRenderable& m_fireworksRenderable;
            
            float m_emitterTime;
            float m_emitterDuration;
            float m_particleSize;
            
            float m_burstRadius;
            
            bool m_isPlayingBurstAnimation;
        };
    }
}