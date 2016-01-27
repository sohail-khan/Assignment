// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelResourceBase
            {
            public:
                
                SceneModelResourceBase(const std::string& name)
                : m_name(name)
                , m_refCount(0)
                {
                }
                
                virtual ~SceneModelResourceBase() {}
                
                const std::string& GetName() const
                {
                    return m_name;
                };
                
                void IncrementReferenceCount()
                {
                    Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                    ++m_refCount;
                }
                
                void DecrementReferenceCount()
                {
                    --m_refCount;
                    Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                }
                
                bool IsReferenced() const
                {
                    Eegeo_ASSERT(m_refCount >= 0, "invalid ref count -- mismatched Increment/Decrement");
                    return m_refCount > 0;
                }
                
            protected:
                
                std::string m_name;
                int m_refCount;
            };
        }
    }
}