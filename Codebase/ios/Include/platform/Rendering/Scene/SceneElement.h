// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IBuiltResource.h"
#include "Streaming.h"
#include "Types.h"
#include "ISceneElementRemover.h"
#include "ISceneElementInGraphObserver.h"
#include "MortonKey.h"
#include "PackedRenderable.h" // Has to be included to support the m_pRenderable delete below. Remove as soon as possible
#include "RoadNamesRenderable.h" // Has to be included to support the m_pRenderable delete below. Remove as soon as possible

namespace Eegeo
{
    namespace Rendering
    {
        namespace Scene
        {
            /*!
             * \brief An element of the scene graph.
             *
             * This class handles the lifetime management of individual elements in the scene graph.
             */
            template <class TRenderableType>
            class SceneElement : public Resources::IBuiltResource
            {
            public:
                SceneElement(TRenderableType* pRenderable, const Streaming::MortonKey& key)
                    : m_pRenderable(pRenderable)
                    , m_isInScene(false)
                    , m_pRemover(NULL)
                    , m_pObserver(NULL)
                    , m_key(key)
                {
                }
                
                ~SceneElement()
                {
                    Eegeo_ASSERT(m_pRemover != NULL);
                    m_pRemover->Remove(this);

                    Eegeo_ASSERT(m_pRenderable != NULL);
                    Eegeo_DELETE(m_pRenderable); // Calling ~TRenderableType() without knowing its implementation? Smells a bit.
                    m_pRenderable = NULL;
                }

                // Do nothing - legacy, should never be called for this type.
                // IBuiltResource needs this removing.
                void Unload()
                {
                    Eegeo_DELETE(this); //lol.
                }
                
                bool IsInSceneGraph() const
                {
                    return m_isInScene;
                }
                
                void RemovedFromSceneGraph()
                {
                    m_isInScene = false;
                    if(m_pObserver != NULL)
                    {
                        m_pObserver->OnRemovedFromSceneGraph(this);
                    }
                }
                
                void AddedToSceneGraph()
                {
                    m_isInScene = true;
                    if(m_pObserver != NULL)
                    {
                        m_pObserver->OnAddedToSceneGraph(this);
                    }
                }
                
                const Eegeo::Streaming::MortonKey& GetKey() const
                {
                    return m_key;
                }
                
                void SetKey(const Eegeo::Streaming::MortonKey& key)
                {
                    m_key = key;
                }
                
                void SetRemover(Rendering::Scene::ISceneElementRemover<TRenderableType>* remover)
                {
                    Eegeo_ASSERT(m_pRemover == NULL);
                    m_pRemover = remover;
                }
                
                void SetObserver(Scene::ISceneElementInGraphObserver<TRenderableType>* pObserver)
                {
                    m_pObserver = pObserver;
                }
                
                TRenderableType& GetResource() const { return *m_pRenderable; }
            private:
                Scene::ISceneElementRemover<TRenderableType>* m_pRemover;
                Scene::ISceneElementInGraphObserver<TRenderableType>* m_pObserver;
                TRenderableType* m_pRenderable;
                bool m_isInScene;
                Eegeo::Streaming::MortonKey m_key;
            };
        }
    }
}
