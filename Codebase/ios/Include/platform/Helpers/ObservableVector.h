// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <algorithm>
#include <vector>
#include "CallbackCollection.h"
#include "ICallback.h"

namespace Eegeo
{
    namespace Helpers
    {
        template <typename T>
        class ObservableVector
        {
        private:
            std::vector<T> m_items;
            CallbackCollection1<T> m_itemAddedCallbacks;
            CallbackCollection1<T> m_itemRemovedCallbacks;
            
        public:
            size_t size() const { return m_items.size(); }
            
            void AddItem(T& item)
            {
                m_items.push_back(item);
                m_itemAddedCallbacks.ExecuteCallbacks(item);
            }
            
            void RemoveItem(T& item)
            {
                m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
                m_itemRemovedCallbacks.ExecuteCallbacks(item);
            }
           
            T& operator[] (size_t index)
            {
                return at(index);
            }
            
            T& at(size_t index)
            {
                Eegeo_ASSERT(index >= 0 && index < m_items.size());
                return m_items.at(index);
            }
            
            void AddItemAddedCallback(ICallback1<T>& callback)
            {
                m_itemAddedCallbacks.AddCallback(callback);
            }
            
            void RemoveItemAddedCallback(ICallback1<T>& callback)
            {
                m_itemAddedCallbacks.RemoveCallback(callback);
            }
            
            void AddItemRemovedCallback(ICallback1<T>& callback)
            {
                m_itemRemovedCallbacks.AddCallback(callback);
            }
            
            void RemoveItemRemovedCallback(ICallback1<T>& callback)
            {
                m_itemRemovedCallbacks.RemoveCallback(callback);
            }
        };
    }
}