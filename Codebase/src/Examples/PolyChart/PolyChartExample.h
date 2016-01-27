// Copyright eeGeo Ltd 2015, All Rights Reserved

#pragma once

#include "PolyChart.h"
#include "PolyChartViewFactory.h"
#include "PolyChartModel.h"
#include "PolyChartController.h"
#include "LatLongAltitude.h"
#include "GlobeCameraExampleBase.h"
#include "VectorMath.h"

namespace Examples
{
    class PolyChartExample : public GlobeCameraExampleBase
    {
    private:
        Eegeo::Data::PolyChart::PolyChartModel* m_pDundeeEastWard;
        Eegeo::Data::PolyChart::PolyChartModel* m_pDundeeEastCylinder;

        Eegeo::Data::PolyChart::PolyChartModel* m_pDundeeWestWard;
        Eegeo::Data::PolyChart::PolyChartModel* m_pDundeeWestCylinder;
        Eegeo::Data::PolyChart::PolyChartController& m_polyChartController;
        
    public:
        PolyChartExample(
                                 Eegeo::Data::PolyChart::PolyChartController& polyChartController,
                                 Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController,
                                 Eegeo::Camera::GlobeCamera::GlobeCameraTouchController& cameraTouchController);
        
        static std::string GetName()
        {
            return "PolyChartExample";
        }
        std::string Name() const
        {
            return GetName();
        }
        
        void Start();
        void Update(float dt);
        void Draw();
        void Suspend();
        
        
        
        void Event_TouchPan				(const AppInterface::PanData& data);
        void Event_TouchDown            (const AppInterface::TouchData& data);
        void Event_TouchUp              (const AppInterface::TouchData& data);
        
    private:
        void CreateDundeeEastData();
        void CreateDundeeWestData();
    };
}