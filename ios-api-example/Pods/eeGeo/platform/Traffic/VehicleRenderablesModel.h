// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "Rendering.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Traffic
    {
        struct VehicleRenderdata
        {
            Eegeo::v3 right;
            Eegeo::v3 up;
            Eegeo::v3 forward;
            Eegeo::dv3 ecefPosition;
            std::string vehicleMeshId;
            float alpha;
            float boundsRadius;
            float distToCameraSq;
            float scale;
        };
        
        class VehicleRenderablesModel
        {
        public:
            
            typedef std::vector<VehicleRenderdata> TVehicleRenderables;
            typedef TVehicleRenderables::const_iterator TRenderableIter;
            
            VehicleRenderablesModel(Rendering::EnvironmentFlatteningService& environmentFlatteningService);
            
            ~VehicleRenderablesModel();
            
            TRenderableIter Begin() { return m_renderables.begin(); }
            TRenderableIter End() { return m_renderables.end(); }
            
            void Preallocate(int numVehicles);
            void CalculateFlattenedPositionInPlace(const dv3& initialPosition, dv3& out_flattenedPosition);
            void Submit(const Eegeo::dv3& position,
                        const Eegeo::v3& forward,
                        const Eegeo::v3& localY,
                        const std::string& meshId,
                        float alpha,
                        float maxDrawDistanceSq,
                        float boundsRadius,
                        float scale,
                        const dv3& cameraEcefLocation);
            
            TVehicleRenderables GetRenderables() const { return m_renderables; }
            void Clear();
            
        private:
        
            TVehicleRenderables m_renderables;
            
            Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
    }
}
