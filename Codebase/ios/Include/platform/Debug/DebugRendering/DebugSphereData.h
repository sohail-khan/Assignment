// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace DebugRendering
    {
        struct DebugSphereData
        {
        public:
            
            DebugSphereData(const dv3& ecefPosition, float radius, const v4& color)
            : ecefPosition(ecefPosition)
            , color(color)
            , radius(radius)
            {
            
            }
            
            void SetPosition(const dv3& newEcefPosition)
            {
                ecefPosition = newEcefPosition;
            }
            
            const dv3& GetEcefPosition() const { return ecefPosition; }
            const v4& GetColor() const { return color; }
            float GetRadius() const { return radius; }
        private:
            dv3 ecefPosition;
            v4 color;
            float radius;
        };
    }
}