// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace MathsHelpers
        {
            void ComputeScaleAndOffset(Eegeo::m44& result,
                                       float scale,
                                       const Eegeo::v3& scaleVector,
                                       const Eegeo::v3& offset);
            
            Eegeo::m33 ComputeScale(float scale, const Eegeo::v3& scaleAxis);
            
            
            float PennerElasticEaseInOut(float from, float to, float interpParam);
            float PennerEaseInOut_Deprecated(float t, float b, float c, float d, float a, float p);
            
            float PennerQuadraticEaseIn(float t, float b, float c, float d);
            float PennerQuadraticEaseOut(float t, float b, float c, float d);
            float PennerQuadraticEaseInOut(float t, float b, float c, float d);
            float PennerExpoEaseOut(float t, float b, float c, float d);
            float PennerExpoEaseIn(float t, float b, float c, float d);
            
            float expDecayFactor(float halfLife, float deltaTime);
            
            float ExpMoveTowards( float from, float to, float halfLife, float deltaTime, float epsilon);
            
            void AlphaBetaFilter(float input, float& output, float& outputVel, float previous, float previousVel, float dt);
            
            void AlphaBetaFilter(float input, float& output, float& outputVel, float previous, float previousVel, float dt, float alpha, float beta);
            
            bool AreAlphaBetaParamsStable(float alpha, float beta);
        }
    }
}
