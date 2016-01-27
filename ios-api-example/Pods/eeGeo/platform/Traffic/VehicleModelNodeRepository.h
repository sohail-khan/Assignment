// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Traffic.h"
#include <vector>
#include <string>
#include <set>
#include <map>

namespace Eegeo
{
    namespace Traffic
    {
        class VehicleModelNodeRepository : protected Eegeo::NonCopyable
        {
        public:            
            VehicleModelNodeRepository();
            ~VehicleModelNodeRepository();
            
            void AddVehicleNodesFromModel(Rendering::SceneModels::SceneModel* model, const std::vector<Config::TrafficSimulationVehicleConfiguration>& vehiclesConfigList, std::set<std::string> &nodeSuffixes);
            IVehicleModel* GetVehicleModel(const std::string& name);
            
            int GetCount() const { return static_cast<int>(m_modelNameToModelMap.size()); }
            bool HasModelForName(const std::string& name) const { return m_modelNameToModelMap.find(name) != m_modelNameToModelMap.end(); }
            
            void Clear();
            
        private:
            std::map<const std::string, IVehicleModel*> m_modelNameToModelMap;
            
            void AddVehicleToMapIfValid(Rendering::SceneModels::SceneModel *model, const std::string& modelName);
        };
    }
}