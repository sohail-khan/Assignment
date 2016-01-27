// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Streaming
	{
        class ISceneGraphCellCallback
        {
        public:
            virtual void operator()(const MortonKey& key) = 0;
        };
        
        template <class T> class TSceneGraphCellCallback : public ISceneGraphCellCallback
        {
        private:
            void (T::*m_callback)(const MortonKey& key);
            T* m_context;
        public:
            TSceneGraphCellCallback(T* context, void (T::*callback)(const MortonKey& key))
            : m_context(context)
            , m_callback(callback)
            {
            }
            
            virtual void operator()(const MortonKey& key)
            {
                (*m_context.*m_callback)(key);
            }
        };
    }
}
