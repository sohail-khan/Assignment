//  Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "FrameProfileFactory.h"
#include "ProfileRecordFactory.h"

#include "Pool.h"

#include <deque>
#include <stack>
#include <string>

#define PROFILER_ENABLED 1

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            struct ProfileResults
            {
                std::string name;
                double min;
                double max;
                double avg;
                double last;
            };
            
#if PROFILER_ENABLED
            class Profiler : protected Eegeo::NonCopyable
            {
            public:
                Profiler();
                
                void BeginFrame();
                void Begin(const std::string& name);
                void End(const std::string& end);
                void EndFrame();
                
                const int GetNumberOfSamples() const { return static_cast<int>(m_profilesPerFrame.size()); }
                const FrameProfile& GetFrameProfile(int index) const;
                
                ProfileResults GetProfileResults(const std::string& name) const;
                
                void SetEnabled(bool enabled) { m_enabled = enabled; }
                bool IsEnabled() const { return m_enabled; }
                
            private:
                bool m_enabled;
                std::deque<FrameProfile*> m_profilesPerFrame;
                std::stack<ProfileRecord*> m_currentProfileRecord;
                
                FrameProfile* m_pCurrentFrameProfile;

                FrameProfileFactory m_frameProfileFactory;
                ProfileRecordFactory m_profileRecordFactory;
                
                DataStructures::Pool<FrameProfile*> m_frameProfilePool;
                DataStructures::Pool<ProfileRecord*> m_profileRecordPool;
            };
            
#else
            class Profiler : protected Eegeo::NonCopyable
            {
            public:
                void BeginFrame() {;}
                void Begin(const std::string& name) {;}
                void End(const std::string& end) {;}
                void EndFrame() {;}
                
                const size_t GetNumberOfSamples() const { return 0; }
                const FrameProfile& GetFrameProfile(int index) const { Eegeo_ASSERT(false); return m_emptyFrameProfile; }
               
                ProfileResults GetProfileResults(const std::string& name) const { return m_emptyProfileResults; }
                
                void SetEnabled(bool enabled) { ; }
                bool IsEnabled() const { return false; }

            private:
                FrameProfile m_emptyFrameProfile;
                ProfileResults m_emptyProfileResults;
            };
#endif
        }
    }
}