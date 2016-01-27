//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include <map>
#include <algorithm>

namespace Eegeo
{
    namespace Data
    {
        template <typename TArgs>
        class DataEntityController : private Eegeo::NonCopyable
        {
        private:
            typedef typename TArgs::TId TId;
            typedef typename TArgs::TModel TModel;
            typedef typename TArgs::TView TView;
            typedef typename TArgs::TViewFactory TViewFactory;
            typedef typename TArgs::TRenderableFilter TRenderableFilter;
            
        public:
            DataEntityController(TViewFactory& viewFactory, TRenderableFilter& renderableFilter)
            : m_viewFactory(viewFactory)
            , m_viewRenderer(renderableFilter)
            {
            }
            
            virtual ~DataEntityController()
            {
                for(typename TModelToView::iterator iter = m_modelToView.begin(); iter != m_modelToView.end(); ++iter)
                {
                    TView* pView = iter->second;
                    m_viewRenderer.RemoveView(*pView);
                    m_viewFactory.FreeView(pView);
                }
                m_modelToView.clear();
            }
            
            void Add(TModel& model)
            {
                TView* pView = m_viewFactory.CreateView(model);
                m_viewRenderer.AddView(*pView);
                m_modelToView[&model] = pView;
            }
            
            void Remove(TModel& model)
            {
                Eegeo_ASSERT(
                             m_modelToView.find(&model) != m_modelToView.end(),
                             "Cannot remove, as it has not been added");
                
                TView* pView = m_modelToView[&model];
                
                m_modelToView.erase(&model);
                m_viewRenderer.RemoveView(*pView);
                m_viewFactory.FreeView(pView);
            }
            
            struct HasId
            {
                HasId(const TId& id) : m_id(id) { }
                bool operator() (const std::pair<TModel*, TView*>& pair) { return pair.first->GetId() == m_id; }
                TId m_id;
            };
            
            bool TryRemoveById(const TId& id, TModel*& out_removedItem)
            {
                typename std::map<TModel*, TView*>::iterator iter = std::find_if(
                                                                                      m_modelToView.begin(), m_modelToView.end(), HasId(id));
                
                if(iter == m_modelToView.end())
                {
                    out_removedItem = NULL;
                    return false;
                }
                
                const std::pair<TModel*, TView*>& pair = *iter;
                TModel* pModel = pair.first;
                Remove(*pModel);
                out_removedItem = pModel;
                return true;
            }
            
            TViewFactory& GetViewFactory() const { return m_viewFactory; }
            TRenderableFilter& GetRenderer() const { return m_viewRenderer; }
            
        private:
            typedef std::map<TModel*, TView*> TModelToView;
            
            std::map<TModel*, TView*> m_modelToView;
            TViewFactory& m_viewFactory;
            TRenderableFilter& m_viewRenderer;
        };
    }
}