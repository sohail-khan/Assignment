// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#ifndef COMPILE_CPP_11
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <tr1/functional>
#else
#include <unordered_set>
#include <unordered_map>
#include <functional>
#endif

namespace Eegeo
{
    template <class T>
    struct unordered_set {
#ifndef COMPILE_CPP_11
        typedef std::tr1::unordered_set<T> type;
#else
        typedef std::unordered_set<T> type;
#endif
    };
    
    template <class K, class V>
    struct unordered_multimap {
#ifndef COMPILE_CPP_11
        typedef std::tr1::unordered_multimap<K,V> type;
#else
        typedef std::unordered_multimap<K,V> type;
#endif
    };

#ifndef COMPILE_CPP_11
    template <class K, class V, class H=std::tr1::hash<K> >
#else
    template <class K, class V, class H=std::hash<K>>
#endif
    struct unordered_map {
#ifndef COMPILE_CPP_11
        typedef std::tr1::unordered_map<K,V,H> type;
#else
        typedef std::unordered_map<K,V,H> type;
#endif
    };
    
    template <class T>
    struct hash {
#ifndef COMPILE_CPP_11
        typedef std::tr1::hash<T> type;
#else
        typedef std::hash<T> type;
#endif
    };
}
