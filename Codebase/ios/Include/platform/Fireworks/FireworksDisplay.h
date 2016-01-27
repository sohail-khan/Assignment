// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "VectorMath.h"
#include "Camera.h"
#include <vector>

namespace Eegeo
{
    namespace Fireworks
    {
        class FireworksDisplay
        {
        public:
            
            FireworksDisplay(const FireworksLocationConfiguration& config, FireworksSequenceFactory& sequenceFactory);
            ~FireworksDisplay();
            
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            
            void Play();
            void Stop();
            
            bool IsPlaying() const;
            
            const FireworksLocationConfiguration& GetLocationConfiguration() const { return m_locationConfig; }
            const dv3& GetEcefPosition() const { return m_ecefOrigin; }
            
            bool HasTerrainHeight() const { return m_assignedTerrainHeight; }
            void SetTerrainHeight(float terrainHeight);
            
        private:
            
            void InitialiseSequences(const dv3& ecefOrigin);
            void DestroySequences();
            
            FireworksSequenceFactory& m_sequenceFactory;
            const FireworksLocationConfiguration& m_locationConfig;
            std::vector<Fireworks::FireworksSequence*> m_pSequences;
            dv3 m_ecefOrigin;
            float m_currentSequenceTimer;
            float m_timeBetweenSequences;
            int m_currentSequence;
            bool m_isPlaying;
            bool m_assignedTerrainHeight;
        };
    }
}