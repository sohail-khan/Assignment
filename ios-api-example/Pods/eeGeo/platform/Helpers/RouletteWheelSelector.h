// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Random.h"

#include <vector>

namespace Eegeo
{
    namespace Helpers
    {
        /*!
        * \brief A roulette wheel selector for making weighted random choices.
        *        http://en.wikipedia.org/wiki/Fitness_proportionate_selection
        *        http://stackoverflow.com/a/3995038 <- this is a clear explanation of how it works
        */
        class RouletteWheelSelector : private Eegeo::NonCopyable
        {
        public:
            static RouletteWheelSelector* CreateWithFitnessValues(const std::vector<float>& fitness);
            void UpdateFitnessValues(const std::vector<float>& fitness);
            size_t SelectItemIndex(Random& rand) const;
        private:
            RouletteWheelSelector() {}
            std::vector<float> m_cumulativeFitness;
        };
    }
}