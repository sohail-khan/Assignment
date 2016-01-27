// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include <string>

namespace Eegeo
{
    namespace Streaming
    {
        struct MortonKey
        {
        private:
            s64 value;
        public:
            explicit MortonKey(int rootFaceIndex);

            int Depth() const;
            MortonKey Push(int quadrant) const;
            MortonKey Pop(int timesToPop=1) const;

            int Element(int index) const;
            int At(int index) const;
            bool operator ==(const MortonKey& other) const;
            bool operator !=(const MortonKey& other) const;
            bool operator <(const MortonKey& other) const;
            bool IsParentOfKey(const MortonKey& potentialChildKey) const;
            double WidthInMetres() const;
            std::string ToString() const;
            int Face() const;
            bool CoversEcefPoint(const Eegeo::dv3& ecefPosition) const;
            s64 RawValue() const { return value; }

            static MortonKey CreateFromRawValue(s64 rawKey);
            static MortonKey CreateFromString(const char* keyString);
        };
        
        class MortonKeyCompare
        {
        public:
            inline bool operator()(const MortonKey& a, const MortonKey& b) const
            {
                return a.RawValue() < b.RawValue();
            }
        };
    }
}
