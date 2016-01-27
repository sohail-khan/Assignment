//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "RenderableFilters.h"
#include "IRenderableFilter.h"
#include "WorldMeshRenderable.h"
#include "RenderQueue.h"

#include <algorithm>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Filters
        {
            template <typename TViewType>
            class SimpleRenderFilter : public IRenderableFilter, private Eegeo::NonCopyable
            {
            public:
                void EnqueueRenderables(const Rendering::RenderContext& renderContext, Rendering::RenderQueue& renderQueue)
                {
                    for(typename std::vector<TViewType*>::iterator iter = m_views.begin();
                        iter != m_views.end();
                        ++iter)
                    {
                        TViewType* pView = (*iter);
                        
                        pView->Update();
                        
                        pView->GetRenderable()->UpdateMVP(renderContext, 1.0f);
                        renderQueue.EnqueueRenderable(pView->GetRenderable());
                    }
                }
                
                void AddView(TViewType& view)
                {
                    Eegeo_ASSERT(
                                 std::find(m_views.begin(), m_views.end(), &view) == m_views.end(),
                                 "Cannot add view, as it has already been added");
                    
                    m_views.push_back(&view);
                }
                
                void RemoveView(TViewType& view)
                {
                    Eegeo_ASSERT(
                                 std::find(m_views.begin(), m_views.end(), &view) != m_views.end(),
                                 "Cannot remove view, as it has not been added");
                    
                    m_views.erase(std::remove(m_views.begin(), m_views.end(), &view));
                }
                
                void Clear()
                {
                    m_views.clear();
                }
                
            private:
                std::vector<TViewType*> m_views;
            };
        }
    }
}