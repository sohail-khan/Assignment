// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "TrafficCongestionModelCell.h"

namespace Eegeo
{
    namespace TrafficCongestion
    {
        class ITrafficCongestionStateChangedCallback
        {
        public:
            virtual void operator()(const TrafficCongestionModelCell& changed) = 0;
        };

        template<typename T>
        class TTrafficCongestionStateChangedCallback : public ITrafficCongestionStateChangedCallback
        {
        private:
            void (T::*m_callback)(const TrafficCongestionModelCell& changed);

            T* m_context;
        public:
            TTrafficCongestionStateChangedCallback(
                    T* context,
                    void (T::*callback)(const TrafficCongestionModelCell& changed))
                    : m_context(context), m_callback(callback)
            {
            }

            virtual void operator()(const TrafficCongestionModelCell& changed)
            {
                (*m_context.*m_callback)(changed);
            }
        };
    }
}