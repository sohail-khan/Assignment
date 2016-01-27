// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Rendering.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                class InteriorsEntityGeometryView
                {
                public:
                    InteriorsEntityGeometryView(InteriorsEntityModel& interiorsEntityModel, Rendering::Renderables::InteriorFloorRenderable* pEntityRenderable,
                        const dv3 &ecefEntityPosition, const m44& modelToWorld);
                    ~InteriorsEntityGeometryView();
                    
                    const InteriorsEntityModel& GetInteriorsEntityModel() const;
                    Rendering::Renderables::InteriorFloorRenderable& GetRenderable() const;
                    
                    const dv3& GetEntityPosition() const
                    {
                        return m_ecefEntityPosition;
                    }
                    
                    m44 GetModelToWorld() const
                    {
                        return m_modelToWorld;
                    }
                    
                private:
                    m44 m_modelToWorld;
                    dv3 m_ecefEntityPosition;
                    InteriorsEntityModel& m_interiorsEntityModel;
                    Rendering::Renderables::InteriorFloorRenderable* m_pEntityRenderable;
                };
            }
        }
    }
}