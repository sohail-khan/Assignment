// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    
    namespace Traffic
    {
        namespace Config
        {
            class TrafficSimulationConfiguration;
            struct TrafficSimulationVehicleConfiguration;
            struct TrafficSimulationRoadClassFilter;
            struct TrafficSimulationAltitudeSpeedConfiguration;
            struct PlaneSimulationConfig;
        }

        namespace Themes
        {
            class ITrafficThemeModelObserver;
            class TrafficThemeController;
            class TrafficThemeModel;
        }

        class VehicleModelNodeRepository;
        
        class IVehicle;
        class TrainVehicle;
        class TrainCarriage;
        class IVehicleFactory;
        class CarVehicleFactory;
        class TrainVehicleFactory;

        class TrafficSimulationCell;
        class TrafficSimulationCellsModel;
        class TrafficSimulationPathedVehicle;
        class TrafficSimulationController;
        
        class VehicleRenderablesModel;
        struct VehicleRenderdata;
        class VehicleRenderer;
        class IVehicleModel;
        
        class PlaneSimulation;
        class PlaneVehicle;
        
        class VehiclesOnNavigationGraphSimulation;
        class TrafficSimulationFactory;
        
        class VehicleModelLoadHandler;
        
        typedef std::vector<IVehicle*> TVehicleVector;
        
        // TODO: Move this out of here. Doesn't belong in predecl file.
        struct TrafficPathNode
        {
        public:
            Eegeo::v3 position;
            Eegeo::v3 direction;
            Eegeo::v3 target;
            float length;
            float halfWidth;
            bool harshTurn;
            int roadIndex;
            int roadVertexIndex;
        };
        
    }
    
    struct IndexAndPriority
	{
		int index;
		float priority; //1.f high, 0.f low
		bool wasBestAngle;
		bool wasInRecentMemory;
		bool wasSingleVertex;
	};
}
