//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Pool.h"
#include "PoolHandle.h"

#include <string>

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            class ProfileRecord : protected Eegeo::NonCopyable
            {
            public:
                ProfileRecord();

                void Start();
                void Stop();
                void AddChild(ProfileRecord* child);
                
                std::vector<ProfileRecord*>& GetChildren();
                
                void ReleaseToPool(Eegeo::DataStructures::Pool<ProfileRecord*>& pool);
                void SetHandle(DataStructures::PoolHandle& poolHandle);
                
                void SetName(const std::string& name);
                double GetDuration() const;
                const std::string& GetName() const;
                
            private:
                std::string m_name;
                double m_start;
                double m_duration;
                std::vector<ProfileRecord*> m_children;
                DataStructures::PoolHandle m_handle;
            };
        }
    }
}