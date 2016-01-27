// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "PoolHandle.h"
#include "MortonKey.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming 
    {
        class QuadTreeNode : protected Eegeo::NonCopyable
        {
        public:
            static const int NUM_OF_PAYLOAD_SLOTS = 6;
            
            DataStructures::PoolHandle handle;
            QuadTreeNode *parent;
            std::vector<QuadTreeNode*> children;
            std::vector<Payload*> payloads;
            s64 rawMortonKeyValue;
            int depth;
            double cellHalfWidth;
            float cellAngleOfView;
            float distanceFromCamera;
            float depthSortSignedDistance;
            QuadTreeNode();
            void onAllocatedFromPool(DataStructures::PoolHandle poolHandle);
            int numOfPayloads();
            void freeAllPayloads(PayloadPool *pPayloadPool);
            bool hasChildren();
            bool isLeaf();
            void removeChild(QuadTreeNode *pChildNode);
            bool hasNoPayloads();
            bool hasPayloads();
            bool isRoot();
            bool isRedundant();
            void deleteSubtreeBelow(PayloadPool *pPayloadPool, QuadTreeNodePool *pNodePool);
            int numOfNodesInSubtree();
            
            void addSubtreeKeysToList(std::vector<MortonKey>& nodeKeys);
        };
    }
}