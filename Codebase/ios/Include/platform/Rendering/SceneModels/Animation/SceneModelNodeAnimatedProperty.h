// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ISceneModelNodeAnimatedProperty.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            template <class TProperty>
            class SceneModelNodeAnimatedProperty : public ISceneModelNodeAnimatedProperty<TProperty>
            {
            public:
                
                SceneModelNodeAnimatedProperty(std::vector<TProperty>& properties)
                : m_properties(properties)
                {
                }
                
                void GetPropertyForFrame(u32 frame, TProperty& out_property) const
                {
                    frame = frame % (u32)m_properties.size();//Clamp<u32>(frame, 0, (u32)m_properties.size()-1);
                    out_property = m_properties.at(frame);
                }
                
                ISceneModelNodeAnimatedProperty<TProperty>* Clone()
                {
                    return Eegeo_NEW(SceneModelNodeAnimatedProperty<TProperty>)(*this);
                }
                
            protected:
                
                SceneModelNodeAnimatedProperty(SceneModelNodeAnimatedProperty<TProperty>& source)
                : m_properties(source.m_properties)
                {
                }
                
                std::vector<TProperty> m_properties;
            };
        }
    }
}