// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Routes.h"
#include "RouteSample.h"
#include "Streaming.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Routes
    {
        namespace Simulation
        {
            class RouteSimulationSession : public Eegeo::NonCopyable
            {
            public:
                enum RouteSimulationSessionState
                {
                    InactiveState,
                    PausedState,
                    ActiveState
                };
                
                enum RouteSimulationPlaybackDirection
                {
                    PlaybackDirectionForward,
                    PlaybackDirectionReverse
                };
                
                enum RouteSimulationPlaybackSpeed
                {
                    PlaybackSpeedUseLinkSpeedValue,
                    PlaybackSpeedUseLinkSpeedMultiplier,
                    PlaybackSpeedUseCustomSpeed
                };
                
            private:
                
                const Route& m_route;

                
                RouteSimulationSessionState m_state;
                RouteSimulationPlaybackDirection m_playbackDirection;
                RouteSimulationPlaybackSpeed m_playbackSpeed;
                float m_linkSpeedMultiplier;
                float m_customSpeed;
                bool m_routeCompleted;
                bool m_drivesOnRight;

                
                typedef std::vector<IRouteSimulationSessionObserver*> TSessionObservers;
                TSessionObservers m_observers;

                double m_currentRouteParam;

                
                
                RouteSampler* m_routeSampler;

                RouteSample* m_currentRouteSample;
                RouteSample m_routeSampleAllocation;
                
                
                int m_currentRouteIndex;
                
                
                void InvalidateRouteSample()
                {
                    m_currentRouteSample = NULL;
                }
                
                void SetRouteSample(const RouteSample& v)
                {
                    m_currentRouteSample = &m_routeSampleAllocation;
                    *m_currentRouteSample = v;
                }
                
            public:
                RouteSimulationSession(const Route& route,
                                       RouteSamplerFactory& routeSamplerFactory);
                
                ~RouteSimulationSession();
                
                void InvalidateCachedFittedRouteForKey(const Eegeo::Streaming::MortonKey& key);
                
                
                RouteVertexClassification GetCurrentLinkClassification() const;
                v3 GetCurrentDirection() const;
                
                dv3 GetCurrentPositionEcef() const;

                const Route& GetRoute() const;
                
                double GetDistanceFromStartInMetres() const;
                
                RouteSimulationSessionState GetSessionState() const;
                
                RouteSimulationPlaybackDirection GetPlaybackDirection() const;
                
                double GetCurrentParam() const;
                
                RouteSimulationPlaybackSpeed GetPlaybackSpeedType() const;
                
                bool IsRouteCompleted() const;
                
                void SetCurrentPositionSnappedToRoute(const Eegeo::dv3& targetEcef);
                
                void StartPlaybackFromBeginning();
                
                void EndPlayback();
                
                void Pause();
                
                void Unpause();
                
                void SetReversePlaybackDirection();
                
                void SetForwardPlaybackDirection();
                
                void TogglePlaybackDirection();
                
                void Update(float dt);
                
                void UseCustomSpeedValue(float customSpeedValue);
                
                void UseLinkSpeedValueWithMultiplier(float linkSpeedMultiplier);
                
                void UseLinkSpeedValue();
                
                bool GetDrivesOnRight() const;
                
                void SetDrivesOnRight(bool drivesOnRight);
                
                void AddSessionObserver(IRouteSimulationSessionObserver& observer);
                
                void RemoveSessionObserver(IRouteSimulationSessionObserver& observer);
                
                bool IsForRoute(const Route* pRoute) const
                {
                    return &m_route == pRoute;
                }
                
                void UpdatePositionStateFromRouteParam(const double routeParam);
                
            private:
                float GetSpeed() const;
            };
        }
    }
}
