// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

namespace Eegeo
{
    namespace Helpers
    {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
        bool CaseInsensitiveStringEquals(const std::string& a, const std::string& b);

        std::string ToLower(const std::string& str);

        size_t Split(const std::string& s, char delim, std::vector<std::string>& out_elems);

        std::string TrimRight(const std::string& str, const std::string& charsToTrim);

        bool TryParseLatLong(const std::string& latString, const std::string& lonString, Eegeo::Space::LatLong& out_LatLon);
        
        bool TryParseDouble(const std::string& string, double& out_double);
        
        bool TryParseInt(const std::string& string, int& out_int);
        
        void SearchReplace(std::string& in_out_originalString, const std::string& searchTerm, const std::string& replaceTerm);
        
        bool Contains(std::string& originalString, const std::string& searchTerm);
        
        void PadRight(std::stringstream& stream, const std::string& string, int lineLengthToPadTo);
        
        void PadLeftRight(std::stringstream& stream, const std::string& string, int leftPadding, int lineLengthToPadTo);
        
        std::string FloatingPointToString(float v, int decimalPlaces);
        
        std::string FloatingPointToString(double v, int decimalPlaces);
#pragma clang diagnostic pop

        std::string Join(const std::vector<std::string>& tokens, const std::string separator);
        
        template <typename T>
        std::string Join(const std::vector<T>& values, const std::string& seperator)
        {
            std::stringstream ss;
            
            for (typename std::vector<T>::const_iterator iter = values.begin(); iter != values.end(); ++iter)
            {
                ss << *iter;
                if (iter != values.end() - 1)
                {
                    ss << seperator;
                }
            }
            
            return ss.str();
        }
    }
}
