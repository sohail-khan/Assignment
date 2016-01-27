// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IdTypes.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            /*!
             * \brief A generator of unique material id numbers.
             */
            class MaterialIdGenerator : protected Eegeo::NonCopyable
            {
            public:
                MaterialIdGenerator()
                : m_nextId(0)
                {
                }
                
                TMaterialId GetNextId()
                {
                    return m_nextId++;
                }
                
                // TODO: Add functionality for freeing reusing TMaterialIds.
                
            private:
                TMaterialId m_nextId;
            };
        }
    }
}