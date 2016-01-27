// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "IVehicle.h"
#include "Types.h"
#include "PathedVehicle.h"
#include <string>

#include <deque>

namespace Eegeo
{
    namespace Traffic
    {
        static const float TRAIN_CLOSE_ENOUGH_TO_TARGET_DISTANCE = 10.0;
        static const float TRAIN_CLOSE_ENOUGH_DISTANCE_SQR = TRAIN_CLOSE_ENOUGH_TO_TARGET_DISTANCE * TRAIN_CLOSE_ENOUGH_TO_TARGET_DISTANCE;
        static const float TRAIN_DISTANCE_FROM_DEAD_END_TO_STOP = 5.0f;
        static const float TRAIN_CENTER_OF_LANE_OFFSET = 0.55f;
        static const float TRAIN_TURNING_ANGLE = 1.5f;
        static const float TRAIN_CARRIAGE_SEPARATION = 3.65f;
        static const float TRAIN_BOUNDS_RADIUS = 15.f;

        struct TrainPreviousPosition
        {
            Eegeo::dv3 position;
            Eegeo::v3 dir;
            float distance;
            
            TrainPreviousPosition()
            : position(Eegeo::dv3::Zero())
            , dir(Eegeo::v3::Zero())
            , distance(0)
            {
            }
        };
        
        class TrainVehicle : public IVehicle, protected Eegeo::NonCopyable
        {
        private:
            static const float TRAIN_FADE_OUT_IN_SECONDS;

            float TrainLengthInM() const;
            float SecondsToFullySpawn();

            std::deque<TrainPreviousPosition> m_previousPostions;
            
            float m_secondsSinceDespawning;
            float m_secondsSinceSpawning;
            bool m_playingDeathCeremony;
            const float m_defaultVelocity;
            float m_trainLength;

            PathedVehicle* m_pathedVehicle;
            
        public:
            TrainVehicle(PathedVehicle* pathedVehicle, float velocity, float headVehicleLength);
            ~TrainVehicle();
            const Eegeo::dv3& GetWorldPosition() const { return m_pathedVehicle->GetWorldPosition(); }
            const Eegeo::v3& GetForwardsVector() const { return m_pathedVehicle->GetForwardsVector(); }
            
            const std::string& GetFullModelNodeName() const { return m_pathedVehicle->GetFullModelNodeName(); }
            TrafficSimulationCell* GetNextCell() { return m_pathedVehicle->GetNextCell(); }
            
            bool GetInitialised() { return m_pathedVehicle->GetInitialised(); }
            void ClearNextCell() { m_pathedVehicle->ClearNextCell(); }
            void Update(float elapsedSeconds, float speedMultiplier, const dv3& ecefInterestPoint);
            void Initialise(const dv3& ecefInterestPoint) { m_pathedVehicle->Initialise(ecefInterestPoint); }
            
            TrainPreviousPosition GetPreviousCarriagePosition(float carriageDistanceFromHead) const;

            void AddCarriage(TrainCarriage* carriage, float carriageLength);
            float Alpha();
            bool VehicleMarkedToRemove();
            void FadeOutThenDestroyVehicle();
            bool IsPlayingDeathCeremony();

            bool CanCollide() const;
            
            float GetCollisionRadius() const;
            float GetBoundsRadius() const;
            float GetScale() const;

            void SetModelNodeNameSuffix(const std::string &suffix) { m_pathedVehicle->SetModelNodeNameSuffix(suffix);}
            
            bool IsUnderground() const;
            bool NeedsUndergroundCheck();
            void SetIsUnderground(bool isUnderground);
        };
    }
}
