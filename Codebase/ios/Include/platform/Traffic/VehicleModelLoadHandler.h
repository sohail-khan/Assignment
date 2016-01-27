// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "AsyncModels.h"
#include "IAsyncModelObserver.h"
#include "IAsyncModel.h"
#include "VehicleModelNodeRepository.h"
#include "SceneModel.h"
#include <string>
#include <vector>
#include <set>

namespace Eegeo
{
    namespace Traffic
    {
        class VehicleModelLoadHandler : protected Eegeo::NonCopyable, public Io::AsyncModels::IAsyncModelObserver
        {
        public:
            VehicleModelLoadHandler(
                    Traffic::VehicleModelNodeRepository& vehicleModelNodeRepository,
                    const std::vector<Config::TrafficSimulationVehicleConfiguration>& vehiclesConfigList,
                    std::set<std::string> &nodeSuffixes)
            : m_vehicleModelNodeRepository(vehicleModelNodeRepository)
            , m_vehiclesConfigList(vehiclesConfigList)
            , m_nodeSuffixes(nodeSuffixes)
            {
            }
            
            void OnModelLoadSuccess(const Io::AsyncModels::IAsyncModel& loadedModel)
            {
                Rendering::SceneModels::SceneModel* pModel = NULL;

                Eegeo_TTY("Succeeded load of model at %s\n", loadedModel.GetUrl().c_str());
                
                if(loadedModel.TryGetModel(pModel))
                {
                    Eegeo_TTY("Adding to repo.\n");

                    m_vehicleModelNodeRepository.AddVehicleNodesFromModel(pModel, m_vehiclesConfigList, m_nodeSuffixes);
                }
            }
            
            void OnModelLoadFail(const Io::AsyncModels::IAsyncModel& loadedModel)
            {
                Eegeo_TTY("Failed load of model at %s\n", loadedModel.GetUrl().c_str());
            }
            
        private:
            Traffic::VehicleModelNodeRepository& m_vehicleModelNodeRepository;
            const std::vector<Config::TrafficSimulationVehicleConfiguration>& m_vehiclesConfigList;
            std::set<std::string> m_nodeSuffixes;
        };
    }
}
