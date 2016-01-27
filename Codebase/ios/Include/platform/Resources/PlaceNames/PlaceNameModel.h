// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Space.h"
#include "MortonKey.h"
#include "LatLongAltitude.h"
#include "PlaceNames.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNameModel : protected Eegeo::NonCopyable
            {
            public:
                
                PlaceNameModel(const Streaming::MortonKey& mortonKey,
                               const Space::LatLongAltitude& location,
                               const std::string& name,
                               const std::string& category,
                               float priority,
                               PlaceNameView* placeNameRenderable);
                ~PlaceNameModel();
                
                PlaceNameView& GetView() const;
                const std::string& GetCategory() const { return m_category; }

                const std::string& GetName() const { return m_name; }
                float GetPriority() const { return m_priority; }

                const bool IsEnabled() const { return m_enabled; }
                void SetEnabled(bool enabled) { m_enabled = enabled; }
                
                void UnscheduleForRemoval();
                void ScheduleForRemoval();
                bool IsScheduledForRemoval() const;
                
                const Streaming::MortonKey& GetKey() const { return m_mortonKey; }
                const Space::LatLongAltitude& GetLocation() const { return m_location; }

            private:
                Streaming::MortonKey m_mortonKey;
                Space::LatLongAltitude m_location;
                std::string m_name;
                const std::string m_category;
                float m_priority;

                PlaceNameView* m_pView;

                bool m_enabled;
                bool m_scheduledForDeletion;
            };
        }
    }
}