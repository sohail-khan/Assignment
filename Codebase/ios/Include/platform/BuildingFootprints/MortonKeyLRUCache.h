// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"

#include <list>
#include <vector>
#include <map>

namespace Eegeo
{
    namespace BuildingFootprints
    {
        class MortonKeyLRUCache : public Eegeo::NonCopyable
        {
        public:
            void Put(const Streaming::MortonKey& key);
            void Shrink(int newSize);
            int Size() const;
            std::vector<Streaming::MortonKey> OrderedKeys() const;
        private:
            typedef std::list<Streaming::MortonKey> KeyList;
            typedef std::map<Streaming::MortonKey, KeyList::iterator> KeysToListNodes;
            KeyList m_keysMostRecentlyUsedFirst;
            KeysToListNodes m_keysToListNodes;
        };
    }
}