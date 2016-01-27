// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IMaterial.h"
#include "PackedDiffuseMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "Lighting.h"
#include "ICallback.h"
#include "InteriorsStencilMirrorType.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsMaterialBase : public Rendering::Materials::IMaterial, private Eegeo::NonCopyable
            {
            public:
                
                const static u32 MirrorStencilRef = 0x10;
                
                InteriorsMaterialBase(
                                  const Rendering::TMaterialId materialId,
                                  const std::string& name,
                                  const Lighting::GlobalLighting& lighting,
                                  IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                  bool useAlternativeAmbient,
                                  bool isTranslucent,
                                  const v4& diffuseColor
                                  );
                
                virtual ~InteriorsMaterialBase();
                
                virtual const Rendering::TMaterialId GetId() const { return m_id; }
                
                virtual const std::string& GetName() const { return m_name; }
                
                virtual const Lighting::GlobalLighting& GetLighting() const { return m_lighting; }
                
                virtual bool IsUsingAlternativeAmbient() const { return m_useAlternativeAmbient; }
                
                virtual bool IsTranslucent() const { return m_isTranslucent; }
                
                virtual v4 GetDiffuseColor() const { return m_diffuseColor; }
                
                virtual void OnAssignedToRenderable(Rendering::Renderables::InteriorRenderable& renderable);
                
                virtual void SetState(Rendering::GLState& glState) const;
                
                virtual v4 GetModulatedDiffuseColor(const v4& renderableColor) const;
                
            protected:
                
                virtual void SetTranslucencyState(const Rendering::Renderables::InteriorRenderable& interiorFloorRenderable, Rendering::GLState& glState) const;
                virtual void SetTranslucencyState(const Rendering::Renderables::InteriorHighlightRenderable& interiorFloorRenderable, Rendering::GLState& glState) const;
                
            private:
                const Rendering::TMaterialId m_id;
                const std::string m_name;
                const Lighting::GlobalLighting& m_lighting;
                Helpers::TCallback1<InteriorsMaterialBase, Rendering::Renderables::InteriorRenderable> m_assignedToRenderableCallback;
                IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
                
                const bool m_useAlternativeAmbient;
                const bool m_isTranslucent;
                const v4 m_diffuseColor;
            };
        }
    }
}