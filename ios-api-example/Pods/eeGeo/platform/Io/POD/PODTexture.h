// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODTexture
            {
            private:
                std::string m_name;
                
            public:
                void SetName(std::string &name);
                
                std::string GetName() const;
            };
        }
    }
}
