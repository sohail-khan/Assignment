// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "LocalRouteVertex.h"
#include "MortonKey.h"

#include <vector>
#include <string>
#include <sstream>

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            struct FittedRouteSection
            {
                FittedRouteSection(const Eegeo::Streaming::MortonKey& key, const std::vector<LocalRouteVertex>& localVertices)
                : m_key(key)
                , m_localVertices(localVertices)
                {
                }
                
                const std::vector<LocalRouteVertex>& GetLocalVertices() const { return m_localVertices; }
                const Eegeo::Streaming::MortonKey& GetKey() const { return m_key; }
                bool IsEmpty() const { return m_localVertices.empty(); }
                
                std::string DebugString() const
                {
                    std::stringstream str;
                    str << m_key.ToString() << ": ";
                    if (!IsEmpty())
                    {
                        str << m_localVertices.front().GetRouteParam() << " -> " << m_localVertices.back().GetRouteParam();
                    }
                    
                    return str.str();
                }
            private:
                Eegeo::Streaming::MortonKey m_key;
                std::vector<LocalRouteVertex> m_localVertices;
                
            };
        }
    }
}
