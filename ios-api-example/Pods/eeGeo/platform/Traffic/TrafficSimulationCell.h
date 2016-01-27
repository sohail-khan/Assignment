// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Traffic.h"
#include "Camera.h"
#include "Terrain.h"
#include "Rendering.h"
#include <string>

namespace Eegeo
{    
    namespace Traffic
    {
        class TrafficSimulationCell : protected Eegeo::NonCopyable
        {
        public:
            TrafficSimulationCell(const Resources::Roads::Navigation::NavigationGraph* graph,
                                  IVehicleFactory& vehicleFactory,
                                  VehicleRenderablesModel* vehicleRenderables,
                                  Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                  const Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            ~TrafficSimulationCell();
            
            const TVehicleVector& GetVehicles() const { return m_vehicles; }
            const Resources::Roads::Navigation::NavigationGraph* GetGraph() const { return m_graph; }
            
            
            void ManagePopulation(bool isOutsideView);
            void Update(float deltaSeconds, float speedMultiplier, const dv3& ecefInterestPoint);
            void AddVehicles(const TVehicleVector vehicles);
            void AddVehicle(IVehicle* vehicle);
            void RemoveVehicle(IVehicle* vehicle);
            void PopulateInitialVehicles();
            
            void PopulateRenderableList(const float maxDistanceForLandVehiclesSq, const dv3& cameraEcefLocation);

            void SetModelNameSuffixOnVehicles(const std::string suffix);

            void ReleaseVehicles();
        private:
            void SpawnVehicles();
            void DespawnVehicles();
            
            void InitialiseVehicles(const dv3& ecefInterestPoint);
            void UpdateVehicles(float deltaSeconds, float speedMultiplier, const dv3& ecefInterestPoint);
            void PerformVehicleCollision();
            void TransferVehiclesToOtherCells();
            void RemoveVehicles();
            
            void UpdateVehicleIsUnderground(IVehicle& vehicle);
            
            static int CollideVehicles(TVehicleVector& vehicles, float maxRadius);
            
            const Resources::Roads::Navigation::NavigationGraph* m_graph;
            IVehicleFactory& m_vehicleFactory;
            TVehicleVector m_vehicles;
            TVehicleVector m_vehiclesToTransferBetweenCells;
            TVehicleVector m_vehiclesToDelete;
            TVehicleVector m_vehiclesToCollide;
            VehicleRenderablesModel* m_renderableList;
            int m_targetVehicleCount;
            
            int m_collisionDebugCount;
            
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
	}

}
