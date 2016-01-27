// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "VectorMath.h"
#include "Colors.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            class RoadNamesRenderable : public Eegeo::Rendering::Renderables::TextRenderable
            {
            public:
                RoadNamesRenderable  (
                                     Rendering::LayerIds::Values layerId,
                                     Rendering::Materials::IMaterial* material,
                                     const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                     Rendering::Mesh* pMesh,
                                     const Eegeo::dv3& ecefPosition
                                     )
                : TextRenderable(layerId, material, vertexBinding, pMesh, ecefPosition)
                {
                    SetForegroundColour(v4(1,1,1,1));
                    SetShadowColour(v4(0,0,0,1));
                    SetOutlineColour(Rendering::Colors::BLACK);
                    SetScale(v3::One());
                }
                
                virtual void UpdateMVP(const dv3& ecefCameraPosition, const m44& viewProjection, const v3& up, const float environmentFlatteningScale, const float fadeOffsetMagnitude)
                {
                    const v3 fadeOffset = up * fadeOffsetMagnitude;
                    
                    v3 cameraLocalPos = (GetEcefPosition() - ecefCameraPosition).ToSingle();
                    cameraLocalPos += fadeOffset;
                    Eegeo::m44 model, mvp;
                    model.Identity();
                    model.SetRow(3, Eegeo::v4(cameraLocalPos, 1));
                    Eegeo::m44::Mul(mvp, viewProjection, model);
                    SetModelViewProjection(mvp);
                }
                
            private:
                Eegeo::v3 m_cameraRelativeModelOrigin;
            };
        }
    }
}
