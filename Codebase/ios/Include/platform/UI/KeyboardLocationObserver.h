// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace UI
    {
        namespace NativeInput
        {
            struct KeyboardLocationData
            {
                Eegeo::v2 location;
                Eegeo::v2 size;
            };
            
            class IKeyboardLocationObserver
            {
            public:
                virtual ~IKeyboardLocationObserver() { ; }
                virtual void operator()(const KeyboardLocationData& locationData) = 0;
            };
            
            template <class T> class TKeyboardLocationObserver : public IKeyboardLocationObserver
            {
            private:
                void (T::*m_callback)(const KeyboardLocationData& animationData);
                T* m_context;
            public:
                TKeyboardLocationObserver(T* context, void (T::*callback)(const KeyboardLocationData& locationData))
                : m_context(context)
                , m_callback(callback)
                {
                }
                
                virtual void operator()(const KeyboardLocationData& locationData)
                {
                    (*m_context.*m_callback)(locationData);
                }
            };
        }
    }
}
