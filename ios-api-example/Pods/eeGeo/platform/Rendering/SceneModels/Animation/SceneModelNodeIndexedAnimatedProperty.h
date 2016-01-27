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
            class SceneModelNodeIndexedAnimatedProperty : public ISceneModelNodeAnimatedProperty<TProperty>
            {
            public:
                
                SceneModelNodeIndexedAnimatedProperty(std::vector<TProperty>& properties, std::vector<u32>& indices)
                : m_properties(properties)
                , m_indices(indices)
                {
                }
                
                void GetPropertyForFrame(u32 frame, TProperty& out_property) const
                {
                    frame = frame % (u32)m_indices.size(); //Clamp<u32>(frame, 0, (u32)m_indices.size()-1);
                    const u32& index = m_indices.at(frame);
                    out_property = m_properties.at(index);
                }
                
                ISceneModelNodeAnimatedProperty<TProperty>* Clone()
                {
                    return Eegeo_NEW(SceneModelNodeIndexedAnimatedProperty<TProperty>)(*this);
                }
                
            protected:
                
                SceneModelNodeIndexedAnimatedProperty(SceneModelNodeIndexedAnimatedProperty<TProperty>& source)
                : m_properties(source.m_properties)
                , m_indices(source.m_indices)
                {
                }
                
                std::vector<TProperty> m_properties;
                std::vector<u32> m_indices;
            };
        }
    }
}