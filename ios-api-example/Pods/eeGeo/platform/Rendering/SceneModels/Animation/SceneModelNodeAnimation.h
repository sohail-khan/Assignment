// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ISceneModelNodeAnimation.h"
#include "ISceneModelNodeAnimatedProperty.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelNodeAnimation : public ISceneModelNodeAnimation
            {
            public:
                
                SceneModelNodeAnimation(ISceneModelNodeAnimatedProperty<v3>* pPositions,
                                        ISceneModelNodeAnimatedProperty<Quaternion>* pRotations,
                                        ISceneModelNodeAnimatedProperty<v3>* pScales);
                
                ~SceneModelNodeAnimation();
                
                void GetTransformForFrame(float frameTime, m44& out_transform) const;
                
                ISceneModelNodeAnimation* Clone();
                
            private:
                
                SceneModelNodeAnimation(SceneModelNodeAnimation& source);

                ISceneModelNodeAnimatedProperty<v3>* m_pPositions;
                ISceneModelNodeAnimatedProperty<Quaternion>* m_pRotations;
                ISceneModelNodeAnimatedProperty<v3>* m_pScales;
            };
        }
    }
}