// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "RenderableBase.h"
#include "IMaterial.h"
#include "Shader.h"
#include "StencilLayersController.h"
#include <vector>
#include <functional>

#define LOG_SORT_KEYS               0
#define LOG_MATERIAL_CHANGES        0
#define LOG_MATERIAL_CHANGE_COUNT   0

namespace Eegeo
{
    namespace Rendering
    {
        namespace
        {
            class RenderableLess : public std::binary_function<const RenderableBase*, const RenderableBase*, bool>
            {
            public:
                inline bool operator()(const RenderableBase* pItemA, const RenderableBase* pItemB) const
                {
                    const SortKey& sortKeyA = pItemA->GetSortKey();
                    const SortKey& sortKeyB = pItemB->GetSortKey();
                    return sortKeyA < sortKeyB;
                }
            };
        }
        
        /*!
         * \brief A queue of renderable objects to be drawn.
         *
         * This class handles the sorting of renderable objects prior to their submission to Open GL. Renderables are sorted by layer, material and Z order so as to mimimize Open GL state changes while preserving necessary draw order.
         */
        class RenderQueue : protected Eegeo::NonCopyable
        {            
        public:
            RenderQueue(StencilLayersController& stencilLayersController);
            
            inline void BeginEnqueuing()
            {
                Eegeo_ASSERT(m_inEnqueuePhase == false);
                m_inEnqueuePhase = true;
                m_renderables.clear();
            }
            
            void EnqueueRenderable(const RenderableBase* pRenderable);
            
            void EnqueueRenderable(const RenderableBase& renderable);
            
            void EnqueueRenderables(const std::vector<RenderableBase*>& renderablesToAdd);
            
            void EndEnqueuing();
            
            void Render(Rendering::GLState& glState);
            
            int GetNumOfRenders() const
            {
                return m_numOfRenders;
            }

            int GetNumOfShaderChanges() const
            {
                return m_numOfShaderChanges;
            }
            
            int GetNumOfMaterialChanges() const
            {
                return m_numOfMaterialChanges;
            }
            
            int GetNumOfStateRestores() const
            {
                return m_numOfStateRestores;
            }
            
        private:
            bool m_inEnqueuePhase;
            typedef std::vector<const RenderableBase*> TRenderables;
            TRenderables m_renderables;
            StencilLayersController& m_stencilLayersController;
            int m_numOfRenders;
            int m_numOfShaderChanges;
            int m_numOfMaterialChanges;
            int m_numOfStateRestores;
            
            void ClearRenderStats()
            {
                m_numOfRenders = 0;
                m_numOfShaderChanges = 0;
                m_numOfMaterialChanges = 0;
                m_numOfStateRestores = 0;
            }
        };
    }
}
