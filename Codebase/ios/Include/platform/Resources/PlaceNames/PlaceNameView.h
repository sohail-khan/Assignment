// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "PlaceNames.h"
#include "Geometry.h"
#include "Camera.h"
#include "VectorMathDecl.h"
#include "Bounds.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNameView : public Eegeo::NonCopyable
            {
            public:
                PlaceNameView(const std::vector<PlaceNameRenderable*>& renderables,
                              const Geometry::Bounds2D& localBounds,
                              const dv3& positionEcef,
                              const v3& color,
                              const v3& outlineColor,
                              float scale,
                              float unflattenableHeightOffset);
                ~PlaceNameView();
                
                const std::vector<PlaceNameRenderable*>& GetRenderables() const { return m_renderables; }
                
                void UpdateTransformsAndVisibility(const Camera::RenderCamera& renderCamera, const v3& cameraSurfaceNormal, float baseScale, float environmentScale);
                
                const Geometry::Bounds3D& GetScreenBounds() const { return m_screenBounds; }
                
                bool IsOccluded() const { return m_isOccluded; }
                
                bool IsOcclusionPending() const { return m_occlusionPending; }

                float GetAlpha() const { return m_alpha; }
                
                bool IsCompletelyTransparent() const { return m_alpha < (1.0f / 255.0f); }
             
                bool IsInFrustum() const { return m_isInFrustum; }

                bool IsInFrontOfCamera() const { return m_isInFrontOfCamera; }
                
                void CopyStateFrom(const PlaceNameView& placeNameView);
                void SetOccluded(bool isOccluded) { m_isOccluded = isOccluded; }
                void SetOcclusionPending(bool isPending) { m_occlusionPending = isPending; }
                void SetAlpha(float alpha) {  m_alpha = alpha; }
                void SetIsInFrustum(bool isInFrustum) { m_isInFrustum = isInFrustum; }
                void SetIsInFrontOfCamera(bool isInFrontOfCamera) { m_isInFrontOfCamera = isInFrontOfCamera; }
                
                float GetTransitionParam() const { return m_transitionParam; }
                void SetTransitionParam(float t) { m_transitionParam = t; }
                
                void SetColor(const v3& color) { m_color = color; }
                void SetOutlineColor(const v3& outlineColor) { m_outlineColor = outlineColor; }
                void SetScale(float scale) { m_scale = scale; }
                
            private:
                const std::vector<PlaceNameRenderable*> m_renderables;
                const Geometry::Bounds2D m_localBounds;
                const dv3 m_positionEcef;
                v3 m_color;
                v3 m_outlineColor;
                float m_scale;
                const float m_unflattenableHeightOffset;
                
                Geometry::Bounds3D m_screenBounds;
                bool m_isOccluded;
                bool m_occlusionPending;
                bool m_isInFrustum;
                bool m_isInFrontOfCamera;
                float m_alpha;
                float m_transitionParam;
                
                void UpdatePerInstanceData(const m44& mvp);
                void CalculateCullState(const Geometry::Bounds2D& localBounds, const m44& mvp, Geometry::Bounds3D& out_screenBounds, bool& out_isInFrustum, bool& out_isInFrontOfCamera) const;
            };
        }
    }
}
