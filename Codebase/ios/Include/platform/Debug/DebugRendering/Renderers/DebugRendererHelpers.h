#pragma once

#include <vector>
#include <algorithm>

#include "Streaming.h"
#include "RenderCamera.h"
#include "VectorMath.h"
#include "Plane.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        template <typename T>
        static inline bool IsExpired(const T& drawData)
        {
            return drawData.Lifetime <= 0.0f;
        }

        template <typename T>
        static void UpdateCommandLifetimes(std::vector<T>& drawDatas, float dt)
        {
            for(int i = 0; i < drawDatas.size(); ++i)
            {
                // TODO: Common base class for render data? Currently using duck-typing
                drawDatas[i].Lifetime -= dt;
            }
        }

        template <typename T>
        static void RemoveExpiredCommands(std::vector<T>& drawData)
        {
            drawData.erase(std::remove_if(drawData.begin(), drawData.end(), IsExpired<T>), drawData.end());
        }
        

        inline bool IsInCamera(const dv3& position, const float sphereRadius, const Camera::RenderCamera& renderCamera)
        {
            const Geometry::Frustum& frustum = renderCamera.GetFrustum();
            Eegeo::dv3 cameraRelativePosition = position - renderCamera.GetEcefLocation();

            bool inCamera = true;
            
            for (size_t i = 0; i < Eegeo::Geometry::Frustum::PLANES_COUNT; ++i)
            {
                const Eegeo::Geometry::Plane& p = frustum.planes[i];
                double signedDist = p.a * cameraRelativePosition.GetX() + p.b * cameraRelativePosition.GetY() + p.c * cameraRelativePosition.GetZ() + p.d;

                if (signedDist + sphereRadius < 0.0f)
                {
                    inCamera = false;
                    break;
                }
            }

            return inCamera;
        }
    }
}

