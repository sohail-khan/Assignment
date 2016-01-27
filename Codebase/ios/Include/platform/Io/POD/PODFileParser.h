// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "POD.h"
#include <vector>
#include <iostream>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODFileParser
            {
            public:
                static const PODFile* ParseFileFromByteBuffer(const std::vector<Byte>& buffer);
                static const PODFile* ParseFileFromPODStream(std::istream& stream, u32 fileSize);
            };
        }
    }
}
