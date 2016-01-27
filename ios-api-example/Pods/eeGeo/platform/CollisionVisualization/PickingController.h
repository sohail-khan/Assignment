// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Collision.h"
#include "Rendering.h"
#include "Modules.h"
#include "RenderCamera.h"
#include "IRayCaster.h"
#include "InteriorController.h"
#include "EnvironmentFlatteningService.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Picking
    {
        class PickingController : public Eegeo::NonCopyable
        {
        public:
            PickingController(Eegeo::Collision::IRayCaster& rayCaster,
                              Eegeo::Resources::Interiors::IInteriorController& interiorsController,
                              Eegeo::Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                              u32 collisionGroup);
            virtual ~PickingController();
            
            void CastRayFromScreenPosition(const Eegeo::v2& point, const Eegeo::Camera::RenderCamera& renderCamera);
            virtual void CastRay(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection);
            virtual void ProcessRayCastResult(const Eegeo::Collision::RayCasterResult& pickResult) = 0;
            
            u32 GetCollisionGroup() {return m_collisionGroup;}
            void SetCollisionGroup(u32 collisionGroup);
            
        private:
            float GetCurrentInteriorsTerrainHeight();
            
            u32 m_collisionGroup;
            
            Eegeo::Collision::IRayCaster& m_rayCaster;
            Eegeo::Resources::Interiors::IInteriorController& m_interiorController;
            Eegeo::Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
        };
    }
}