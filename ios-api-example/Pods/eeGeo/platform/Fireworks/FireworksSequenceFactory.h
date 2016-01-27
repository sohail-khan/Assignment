// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fireworks.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Streaming.h"
#include "Random.h"
#include <vector>
#include <functional>

namespace Eegeo
{
    namespace Fireworks
    {
        class FireworksSequenceFactory
        {
        public:
            
            FireworksSequenceFactory(Rendering::Renderables::BatchedSpriteRenderable& batchedSpriteRenderable,
                                     Streaming::CameraFrustumStreamingVolume& cameraFrustumStreamingVolume,
                                     Random& random);
            ~FireworksSequenceFactory();
            
            FireworksSequence* CreateRandomSequence(const dv3& ecefOrigin);
            
        private:

            Rendering::Renderables::BatchedSpriteRenderable& m_batchedSpriteRenderable;
            Streaming::CameraFrustumStreamingVolume& m_cameraFrustumStreamingVolume;
            Random& m_random;
            std::vector<v4> m_colorTable;
            
            void CreateRandomPattern(std::vector<FireworksSequenceBurstConfiguration>& sequenceBursts);
            void CreateLinePattern(std::vector<FireworksSequenceBurstConfiguration>& sequenceBursts);
            void CreateStarPattern(std::vector<FireworksSequenceBurstConfiguration>& sequenceBursts);
            void CreateRisingPattern(std::vector<FireworksSequenceBurstConfiguration>& sequenceBursts);
            void CreateLayeredPatterm(std::vector<FireworksSequenceBurstConfiguration>& sequenceBursts);
            
            void PopulateColorTable(std::vector<v4>& colors);
            v4 GetRandomColor();
            
        };
    }
}