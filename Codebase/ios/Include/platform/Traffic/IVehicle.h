// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Traffic.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        class IVehicle
        {
        public:
        	IVehicle() : isDebugVehicle(false) { }
            virtual ~IVehicle() {};
            
            virtual const Eegeo::dv3& GetWorldPosition() const = 0;
            virtual const Eegeo::v3& GetForwardsVector() const = 0;
            virtual const std::string& GetFullModelNodeName() const  = 0;
            virtual float Alpha() = 0;
            virtual TrafficSimulationCell* GetNextCell() = 0;
            virtual bool GetInitialised() = 0;
            virtual void ClearNextCell() = 0;
            virtual void Update(float elapsedSeconds, float speedMultiplier, const dv3& ecefInterestPoint) = 0;
            virtual void Initialise(const dv3& ecefInterestPoint) = 0;
            virtual bool VehicleMarkedToRemove() = 0;
            virtual void FadeOutThenDestroyVehicle() = 0;
            virtual bool IsPlayingDeathCeremony() = 0;
            
            virtual bool IsUnderground() const = 0;
            virtual bool NeedsUndergroundCheck() = 0;
            virtual void SetIsUnderground(bool isUnderground) = 0;

            virtual bool CanCollide() const = 0;
            
            virtual float GetBoundsRadius() const = 0;
            virtual float GetScale() const = 0;

            virtual float GetCollisionRadius() const = 0;
            virtual void SetModelNodeNameSuffix(const std::string &suffix) = 0;
            
            virtual const std::vector<IVehicle*>& GetChildVehicles() const { return m_childVehicles; }
            bool isDebugVehicle;
        protected:
            std::vector<IVehicle*> m_childVehicles;
        };
    }
}