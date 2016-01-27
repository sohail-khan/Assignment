// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "Location.h"
#include "Terrain.h"

namespace Eegeo
{
    namespace Location
    {
        class NavigationService
        {
        public:
            
            enum GpsMode
            {
                GpsModeOff,
                GpsModeFollow,
                GpsModeCompass
            };
        private:
            ILocationService* m_pLocationService;
            Eegeo::dv3 m_lastPosition;
            Eegeo::Resources::Terrain::Heights::TerrainHeightProvider* m_pTerrainHeightProvider;
            GpsMode m_gpsMode;

            float m_updatePeriodSeconds;
            float m_timeToNextUpdate;
            float m_absoluteHeadingDegrees;            
            
        public:
            
            const static float DefaultUpdatePeriod;
            
            NavigationService(Eegeo::Location::ILocationService* pLocationService,
                              Eegeo::Resources::Terrain::Heights::TerrainHeightProvider* pTerrainHeightProvider);
            
            ~NavigationService();
           
            float GetAbsoluteHeadingDegrees() const { return m_absoluteHeadingDegrees; }
            
            bool IsGPSActive() const { return m_gpsMode != GpsModeOff; }
            GpsMode GetGpsMode() const { return m_gpsMode; }
            
            void SetGpsMode(GpsMode mode);

            void SetUpdatePeriod(float updatePeriodSeconds) { m_updatePeriodSeconds = updatePeriodSeconds; }
            
            void Update(float deltaSeconds);
            
            void UpdateGPSPosition();
            void UpdateCompass();
            
            bool TryGetGpsLocationOnTerrain(dv3& out_pointEcef) const;
            
            void CycleGPSMode();
        };
    }
}

