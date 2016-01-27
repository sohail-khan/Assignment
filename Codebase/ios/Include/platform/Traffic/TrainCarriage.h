// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IVehicle.h"
#include "Types.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Traffic
    {
        class TrainVehicle;
        
        class TrainCarriage : public IVehicle, protected Eegeo::NonCopyable
        {
        private:
            Eegeo::dv3 m_followPosition;
            Eegeo::v3 m_followDirection;
            
            TrainVehicle* m_parent;
            float m_carriageOffset;
            const std::string &m_modelName;
            std::string m_fullModelNodeName;
            
        public:
            TrainCarriage(TrainVehicle* parentVehicle, const std::string& modelName, const std::string& modelNameSuffix, float carriageOffset);
            ~TrainCarriage() { }
            const Eegeo::dv3& GetWorldPosition() const { return m_followPosition; }
            const Eegeo::v3& GetForwardsVector() const { return m_followDirection; }
            
            const std::string& GetFullModelNodeName() const { return m_fullModelNodeName; }
            TrafficSimulationCell* GetNextCell() { return NULL; } // this never moves cell itself, the parent moves cell.
            
            bool GetInitialised() { return true; }
            void ClearNextCell() { };
            void Update(float elapsedSeconds, float speedMultiplier, const dv3& ecefInterestPoint);
            void Initialise(const dv3& ecefInterestPoint) { };
            float Alpha();
            bool VehicleMarkedToRemove();
            void FadeOutThenDestroyVehicle() { }
            bool IsPlayingDeathCeremony() { return false; }
            float GetBoundsRadius() const;
            float GetCollisionRadius() const;
            float GetScale() const;
            bool CanCollide() const;
            void SetModelNodeNameSuffix(const std::string &suffix);
            
            bool IsUnderground() const;
            bool NeedsUndergroundCheck();
            void SetIsUnderground(bool isUnderground);
        };
    }
}