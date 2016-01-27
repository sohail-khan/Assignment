// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <queue>
#include <string>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class CommandBuffer : protected Eegeo::NonCopyable
            {
            public:
                bool IsEmpty() const;
                void Append(const std::string& text);
                std::string PopLine();
            private:
                std::queue<std::string> m_commandQueue;
            };            
        }
    }
}
