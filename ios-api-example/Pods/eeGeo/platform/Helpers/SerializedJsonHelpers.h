// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{
    namespace Helpers
    {
        bool TryGetStringValueFromSerializedJson(const std::string& serialisedJson,
                                                 const std::string& field,
                                                 std::string& out_value);
        
        bool TryGetDoubleValueFromSerializedJson(const std::string& serializedJson,
                                                 const std::string& field,
                                                 double& out_value);
    }
}