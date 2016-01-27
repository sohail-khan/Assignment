// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace DataStructures 
    {  
        template <class T>
        class PoolItemFactory 
        {            
        public:
            virtual ~PoolItemFactory(){};
            virtual T CreateItem()=0;
        };
    }
}