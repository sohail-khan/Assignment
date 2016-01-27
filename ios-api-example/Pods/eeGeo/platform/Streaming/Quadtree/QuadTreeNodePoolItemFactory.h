// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "PoolItemFactory.h"

namespace Eegeo
{
    namespace Streaming 
    {
        class QuadTreeNodePoolItemFactory : public Eegeo::DataStructures::PoolItemFactory<Eegeo::Streaming::QuadTreeNode*>
        {
        public:
            virtual Eegeo::Streaming::QuadTreeNode* CreateItem();
        };
    }
}
