// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "POD.h"

namespace Eegeo
{
    class Node;
    
    class SceneAnimator : Eegeo::NonCopyable
    {
    public:
        SceneAnimator(Eegeo::Node* rootNode,
                      int totalNumFramesInScene,
                      float frameRate=30.f);
        
        void Update(float dt);
        
    private:
        float m_time;
        const float m_frameRate;
        const int m_totalNumFramesInScene;
        Eegeo::Node* m_rootNode;
        
        void UpdateRecursive(Eegeo::Node* node);
        
        void UpdateTRS(Eegeo::Node* node);
        
        Eegeo::v3 EvaluatePosition(const Eegeo::IO::POD::PODNode& podNode, float frameTime);
        
        Eegeo::Quaternion EvaluateRotation(const Eegeo::IO::POD::PODNode& podNode, float frameTime);
        
        Eegeo::v3 EvaluateScale(const Eegeo::IO::POD::PODNode& podNode, float frameTime);
        
        Eegeo::v3 EvaluateAxisScale(const Eegeo::IO::POD::PODNode& podNode, float frameTime);
        
        float EvaluateStretchRotation(const Eegeo::IO::POD::PODNode& podNode, float frameTime);
        
        int GetFrameNumberToInterpolateFrom(float frameTime);
        
        int GetFrameNumberToInterpolateTo(float frameTime);
        
        float GetInterpolationParameters(float frameTime);
        
        void EvaluateInterpolatedMatrix(const Eegeo::IO::POD::PODNode& podNode, Eegeo::m44& target, float frameTim);
    };
}
