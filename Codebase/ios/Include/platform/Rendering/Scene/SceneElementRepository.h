// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "SceneElement.h"
#include "ISceneElementRemover.h"
#include "ISceneElementSource.h"
#include "ISceneElementFilterCriteria.h"
#include "ISceneElementObservable.h"
#include "PackedRenderable.h"
#include "ISceneElementObserver.h"
#include <vector>
#include <algorithm>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Scene
        {
            /*!
             * \brief A repository of SceneElement<T> objects.
             */
            template<class T>
            class SceneElementRepository : public ISceneElementSource<T>, ISceneElementRemover<T>, ISceneElementObservable<T>, protected Eegeo::NonCopyable
            {
                typedef SceneElement<T> TSceneElement;
                typedef TSceneElement* TSceneElementPtr;
                typedef std::vector<TSceneElementPtr> TSceneElementPtrVector;
                
            private:
                TSceneElementPtrVector m_sceneElements;
                typedef ISceneElementObserver<T> TObserver;
                typedef TObserver* TObserverPtr;
                typedef std::vector<TObserverPtr> TObserverPtrVec;
                TObserverPtrVec m_observers;
                
                void NotifyObserversOfAdd(TSceneElement& sceneElementAdded) const
                {
                    for(typename TObserverPtrVec::const_iterator it = m_observers.begin(); it != m_observers.end(); ++it)
                    {
                        (*it)->OnSceneElementAdded(sceneElementAdded);
                    }
                }
                
                void NotifyObserversOfRemove(TSceneElement& sceneElementRemoved) const
                {
                    for(typename TObserverPtrVec::const_iterator it = m_observers.begin(); it != m_observers.end(); ++it)
                    {
                        (*it)->OnSceneElementRemoved(sceneElementRemoved);
                    }
                }

            public:
                SceneElementRepository()
                {
                }
                
                ~SceneElementRepository()
                {
                    m_observers.clear();
                }
                
                void AddObserver(ISceneElementObserver<T>& observerToAdd)
                {
                    m_observers.push_back(&observerToAdd);
                }

                void RemoveObserver(ISceneElementObserver<T>& observerToRemove)
                {
                    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), &observerToRemove));
                }
                
                int GetNumOfSceneElements() const
                {
                    return m_sceneElements.size();
                }
                
                int GetCapacity() const
                {
                    return m_sceneElements.capacity();
                }
                
                void GetSceneElements(std::vector<SceneElement<T>*>& out_sceneElements) const
                {
                    out_sceneElements.insert(out_sceneElements.end(), m_sceneElements.begin(), m_sceneElements.end());
                }
                
                void Add(SceneElement<T>& sceneElement)
                {
                    sceneElement.SetRemover(this);
                    m_sceneElements.push_back(&sceneElement);
                    NotifyObserversOfAdd(sceneElement);
                }
                
                void Remove(SceneElement<T>* pSceneElement)
                {
                    Eegeo_ASSERT(std::find(m_sceneElements.begin(), m_sceneElements.end(), pSceneElement) != m_sceneElements.end());
                    size_t size = m_sceneElements.size();
                    m_sceneElements.erase(std::remove(m_sceneElements.begin(), m_sceneElements.end(), pSceneElement));
                    Eegeo_ASSERT(m_sceneElements.size() == size - 1);
                    NotifyObserversOfRemove(*pSceneElement);
                }
            };
        }
    }
}
