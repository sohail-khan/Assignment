// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "LayerIds.h"
#include "SortKey.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief The simplest renderable unit consumed by the renderer.
         *
         * Renderables provide a sort key that allows them to be sorted by draw order and material. They are also capable of submitting themselves to Open GL for rendering.
         */
        class RenderableBase : protected Eegeo::NonCopyable
        {
        public:
            RenderableBase(
                           LayerIds::Values layerId,
                           const dv3& ecefPosition,
                           const Rendering::Materials::IMaterial* material,
                           const VertexLayouts::VertexBinding& vertexBinding
                           );
            
            RenderableBase(
                           LayerIds::Values layerId,
                           const dv3& ecefPosition,
                           const Rendering::Materials::IMaterial* material
                           );
            
            virtual ~RenderableBase() { };
            
            inline const SortKey GetSortKey() const { return m_sortKey; }
            
            void SetLayer(LayerIds::Values layerId);
            
            inline LayerIds::Values GetLayer() const
            {
                return (LayerIds::Values) m_sortKey.GetLayer();
            }
            
            void SetUserDefined(u64 userDefined);
            
            inline u64 GetUserDefined() const
            {
                return m_sortKey.GetUserDefined();
            }
            
            void SetDepth(u32 depth);
            
            inline u32 GetDepth() const
            {
                return m_sortKey.GetDepth();
            }
            
            virtual void SetMaterial(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
            
            inline const Materials::IMaterial* GetMaterial() const
            {
                return m_material;
            }
            
            virtual bool ShouldRender() const { return true; }
            
            virtual void Render(Rendering::GLState& glState) const = 0;

            inline void SetEcefPosition(const dv3& ecefPosition) { m_ecefPosition = ecefPosition; }
            inline const dv3& GetEcefPosition() const { return m_ecefPosition; }
            
            inline void SetModelViewProjection(const m44& modelViewProjection)
            {
                m_modelViewProjection = modelViewProjection;
            }
            
            inline const m44& GetModelViewProjection() const
            {
                return m_modelViewProjection;
            }
            
        protected:
            virtual void UpdateSortKeyForMaterial(const Materials::IMaterial* material);
            
            virtual void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool)
            {
            }

            void SetVertexBinding(const VertexLayouts::VertexBinding& binding);
            
            inline const VertexLayouts::VertexBinding* GetVertexBinding() const
            {
                return m_pVertexBinding;
            }

            m44 m_modelViewProjection;
            dv3 m_ecefPosition;
            const VertexLayouts::VertexBinding* m_pVertexBinding;
            const Rendering::Materials::IMaterial* m_material;
            SortKey m_sortKey;
        };
    }
}
