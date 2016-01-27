//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "Pool.h"
#include "Profile.h"
#include "PoolHandle.h"
#include <map>
#include <string>

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            class FrameProfile : protected Eegeo::NonCopyable
            {
            public:
                FrameProfile();
                
                double GetProfileDuration(const std::string& profile);
                void SetProfileDuration(const std::string& profile, double duration);
                
                ProfileRecord* GetRootRecord() const;
                void SetRootRecord(ProfileRecord* profileRecord);
                void SetHandle(DataStructures::PoolHandle& handle);
                void ReleaseToPool(Eegeo::DataStructures::Pool<FrameProfile*>& frameProfilePool,
                                  Eegeo::DataStructures::Pool<ProfileRecord*>& profileRecordPool);
            private:
                ProfileRecord* m_pRootRecord;
                std::map<std::string, double> m_profileDurations;
                DataStructures::PoolHandle m_handle;
            };
        }
    }
}