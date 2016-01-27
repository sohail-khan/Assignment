// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct InteriorEntitiesChunkDto
                {
                    InteriorEntitiesChunkDto(const std::vector<std::string>& entityIdentifiers)
                    : m_entityIdentifiers(entityIdentifiers)
                    {}
                    
                    std::vector<std::string> EntityIdentifiers() const { return m_entityIdentifiers; }
                private:
                    std::vector<std::string> m_entityIdentifiers;
                };
            }
        }
    }
}