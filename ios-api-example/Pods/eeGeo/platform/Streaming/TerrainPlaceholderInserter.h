// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
    {
        class TerrainPlaceholderInserter : protected Eegeo::NonCopyable
        {
            public:
                TerrainPlaceholderInserter(
                                           PayloadPool* pPayloadPool,
                                           QuadTreeNodePool* pQuadTreeNodePool,
                                           IResourceStream* pTerrainStream,
                                           PayloadSlotStreamMap* pStreamMap,
                                           int minTerrainDepth,
                                           int maxTerrainDepth) :
                m_pPayloadPool(pPayloadPool),
                m_pQuadTreeNodePool(pQuadTreeNodePool),
                m_pTerrainStream(pTerrainStream),
                m_pStreamMap(pStreamMap),
                m_terrainPayloadSlot(-1),
                m_terrainMinDepth(minTerrainDepth),
                m_terrainMaxDepth(maxTerrainDepth)
                {
                }
            
                int terrainPayloadSlot() const { return m_terrainPayloadSlot; }
                void InsertPlaceholders(std::vector<QuadTreeNode*>& nodeList, int updateCount);
                void OnStreamsChanged();

            private:
                PayloadPool* m_pPayloadPool;
                QuadTreeNodePool* m_pQuadTreeNodePool;
                IResourceStream* m_pTerrainStream;
                PayloadSlotStreamMap* m_pStreamMap;
                int m_terrainPayloadSlot;
                const int m_terrainMinDepth;
                const int m_terrainMaxDepth;
            
                bool InsertAdditionalQuadTreeNodesBelow(QuadTreeNode* node, int updateCount);
                QuadTreeNode* CreateChildAtIndex(QuadTreeNode* parentNode, int childIndex);
                void CreatePlaceholder(QuadTreeNode* quadTreeNode, bool dontLoadOnTopOf, int updateCount);
                bool IsTerrainLeaf(QuadTreeNode* quadTreeNode);
                bool HasNoTerrainChildrenInSceneGraph(QuadTreeNode* quadTreeNode);
        };
    }
}
