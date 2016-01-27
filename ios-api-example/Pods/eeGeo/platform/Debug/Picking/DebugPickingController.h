// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Collision.h"
#include "Rendering.h"
#include "DebugRendering.h"
#include "Modules.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Debug
    {
        namespace Picking
        {
            class DebugPickingController : public Eegeo::NonCopyable
            {
                enum Mode
                {
                    Disabled,
                    Pick,
                    PickMesh,
                    MaxModes
                };
            public:
                DebugPickingController(Eegeo::Collision::ICollisionBvhProvider& collisionBvhProvider,
                                       Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                       Eegeo::DebugRendering::DebugRenderer& debugRenderer);
                
                ~DebugPickingController();

                void Draw();
            
                bool IsEnabled() const { return m_mode != Disabled; }
                void CycleMode();
                std::string GetModeDescription() const;
                
                void CastRay(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection);
                
                
            private:
                void DebugDrawSubMeshes(std::vector<const Collision::CollisionBvh*>& collisionBvhs, const std::string& collisionMaterialId);
            
                Eegeo::Collision::EnvironmentRayCaster* m_pRayCaster;
                Eegeo::dv3 m_spherePosition;
                Eegeo::v4 m_sphereColour;
                Eegeo::v3 m_pickSurfaceNormal;
                Mode m_mode;
                Eegeo::DebugRendering::DebugRenderer& m_debugRenderer;
            };
        }
    }
}