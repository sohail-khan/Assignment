// Copyright eeGeo Ltd 2015, All Rights Reserved

#pragma once

#include "Types.h"
#include "GeofenceModule.h"
#include "PolyChartModule.h"
#include "StencilAreaModule.h"
#include "HeatmapModule.h"
#include "RenderingModule.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Data
        {
            class DataModule : private Eegeo::NonCopyable

            {
            public:
                DataModule(Modules::Core::RenderingModule& renderingModule);
                
                ~DataModule();
                
                PolyChartModule& GetPolyChartModule() { return *m_pPolyChartModule; }
                GeofenceModule& GetGeofenceModule() { return *m_pGeofenceModule; }
                StencilAreaModule& GetStencilAreaModule() { return *m_pStencilAreaModule; }
                HeatmapModule& GetHeatmapModule() { return *m_pHeatmapModule; }
                
            private:
                PolyChartModule* m_pPolyChartModule;
                GeofenceModule* m_pGeofenceModule;
                StencilAreaModule* m_pStencilAreaModule;
                HeatmapModule* m_pHeatmapModule;
            };
        }
    }
}