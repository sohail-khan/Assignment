// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IVehicle.h"
#include "Types.h"
#include "VectorMathDecl.h"
#include "Navigation.h"
#include "Traffic.h"
#include "Random.h"
#include "Location.h"
#include "Camera.h"
#include <string>
#include <vector>
#include <algorithm>

namespace Eegeo
{
    namespace Traffic
    {
        static const float DEATH_FADE_OUT_SECONDS = .5f;
        
        static const float CLOSE_ENOUGH_TO_TARGET_DISTANCE = 4.0;
        static const float CLOSE_ENOUGH_DISTANCE_SQR = CLOSE_ENOUGH_TO_TARGET_DISTANCE * CLOSE_ENOUGH_TO_TARGET_DISTANCE;
        static const float CENTER_OF_LANE_OFFSET = 0.45f;
        static const float TURNING_ANGLE = 1.0f;
        static const float CAR_BOUNDS_RADIUS = 10.f;
        static const float CAR_COLLISION_RADIUS = 8.f;
        static const float HeightCheckInterval = 1.5f;
        
        class PathedVehicle : public IVehicle, protected Eegeo::NonCopyable
        {
        public:
            PathedVehicle(const Resources::Roads::Navigation::NavigationGraph* navGraph,
                          const std::string& modelName,
                          const std::string& modelNamesuffix,
                          const int beginningRoadIndex,
                          const bool drivesOnRight,
                          const Config::TrafficSimulationRoadClassFilter& roadClassFilter,
                          const TrafficSimulationCellsModel* cellsModel,
                          Eegeo::Random* random,
                          float velocity,
                          float scale,
                          float closeEnoughDistSq=CLOSE_ENOUGH_DISTANCE_SQR,
                          float centerOfLaneOffset=CENTER_OF_LANE_OFFSET,
                          float turningAngle=TURNING_ANGLE);

            ~PathedVehicle() {};
            
            const Eegeo::dv3& GetWorldPosition() const { return m_worldPosition; }
            const Eegeo::v3& GetForwardsVector() const { return m_forwards; }
            const std::string& GetFullModelNodeName() const { return m_fullModelNodeName; }
            TrafficSimulationCell* GetNextCell() { return m_nextCellToTravelTo; }
            bool GetInitialised() { return m_initialised; }
            void ClearNextCell() { m_nextCellToTravelTo = NULL; }
            void Update(float elapsedSeconds, float speedMultiplier, const dv3& ecefInterestPoint);
            void Initialise(const dv3& ecefInterestPoint);
            
            void UpdateVelocity(float velocity) { m_velocity = velocity; }
            float GetDistanceToEndOfCurrentPath();
            bool IsOnFinalRoadInPath(float& out_distanceToEnd);
            bool GetVehicleOnDeadEnd();
            float Alpha() { return std::max(1.0f - m_deathCeremonyTimePassedSeconds/DEATH_FADE_OUT_SECONDS, 0.f); }
            bool VehicleMarkedToRemove() { return m_deathCeremonyTimePassedSeconds >= DEATH_FADE_OUT_SECONDS; }
            
            float GetBoundsRadius() const;
            float GetScale() const;

            void FadeOutThenDestroyVehicle();
            bool IsPlayingDeathCeremony() { return m_playingDeathCeremony; }
            
            float GetCollisionRadius() const;
            
            bool CanCollide() const;

            void SetModelNodeNameSuffix(const std::string &suffix);
            
            bool IsUnderground() const;
            void SetIsUnderground(bool isUnderground);
            bool NeedsUndergroundCheck();

        private:
            float m_velocity;
            float m_scale;
            const float m_closeEnoughDistSq;
            const float m_centerOfLaneOffset;
            const float m_turningAngle;
            bool m_expectPathToEndInDeadEnd;
            
            float m_deathCeremonyTimePassedSeconds;
            bool m_dieAtEndOfPath;
            bool m_playingDeathCeremony;
            
            Eegeo::v3 m_localPosition;
            Eegeo::dv3 m_worldPosition;
            Eegeo::v3 m_forwards;
            bool m_directionIsForwards;
            Eegeo::Random* const m_random;
            const Config::TrafficSimulationRoadClassFilter& m_roadClassFilter;
            
            const TrafficSimulationCellsModel* m_cellsModel;
            const Resources::Roads::Navigation::NavigationGraph* m_navGraph;
            TrafficSimulationCell* m_nextCellToTravelTo;
            std::vector<TrafficPathNode> m_pathNodes;
            const std::string& m_modelName;
            std::string m_fullModelNodeName;
            bool m_drivesOnRight;
            
            bool m_onFirstPath;
            bool m_initialised;
            
            int m_currentPathNodeIndex;
            int m_finalRoadIndex;
            int m_finalVertIndex;
            
            float m_heightCheckTimer;
            bool m_isUnderground;

            std::vector<int> m_debugUsedRoadIndices;
            
            std::vector<Resources::Roads::Navigation::NavigationGraphRoad*> m_recentMemory;
            size_t m_recentMemoryRingLatest;
            
            void CreateNewPath(const int initialRoadIndex, const dv3& ecefInterestPoint);
            void ResetToStartOfPath();
            
            void CheckLeavingCell(Resources::Roads::Navigation::NavigationGraphRoad*& currentRoad,
                                  int &currentPoint,
                                  bool &currentDirectionIsForwards);
           
            bool MovePathGenToNextRoad(Resources::Roads::Navigation::NavigationGraphRoad*& currentRoad,
                                       int &currentPoint,
                                       bool &currentDirectionIsForwards,
                                       bool atRoadEnd,
                                       std::vector<int> &usedRoadIndices,
                                       Eegeo::v3* pathFindCurrentForward,
                                       const dv3& ecefInterestPoint);
            
            bool IsInCamera(const Camera::RenderCamera& renderCamera);
        };
    }
}
