// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "QuadTreeNodeVisitParams.h"
#include "PayloadSlotStream.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class QuadTreeVisibilityUpdater : protected Eegeo::NonCopyable
        {
        public:
                            
        private:            
            QuadTreeNodePool *m_pNodePool;            
            PayloadPool *m_pPayloadPool;
            PayloadSlotStreamMap *m_pPayloadSlotStreamMap;
            SceneGraphCellRepository& m_sceneGraphCellRepository;
            
            std::vector<QuadTreeNodeVisitParams> m_stack;
            std::vector<std::vector<int> > m_nodeCountListsByFace;
            
            
        public:
            QuadTreeVisibilityUpdater(QuadTreeNodePool *pNodePool,
                                      PayloadPool *pPayloadPool,
                                      PayloadSlotStreamMap* pPayloadSlotStreamMap,
                                      SceneGraphCellRepository& sceneGraphCellRepository);
     
            
            void updateVisibleNodes(QuadTreeCube * pQuadCube,
                                    IStreamingVolume& streamingVolume,
                                    int updateCount,
                                    std::vector<QuadTreeNode*>& nodesRequiringPlaceholders,
                                    int terrainPayloadIndex,
                                    std::vector<MortonKey>& keysThatAreNowVisible,
                                    std::vector<MortonKey>& keysThatAreNoLongerVisible,
                                    std::vector<MortonKey>& currentlyVisibleKeys);
            
            int numOfNodesOnFaceAtDepth(int faceIndex, int depth);
            
        private:
            void clearNodeCounts();
            
            void updateVisibleNodesOnFace(int faceIndex,
                                          IStreamingVolume& streamingVolume,
                                          QuadTreeNode* pRootNode,
                                          int updateCount,
                                          std::vector<QuadTreeNode*>& nodesRequiringPlaceholders,
                                          int terrainPayloadIndex,
                                          std::vector<MortonKey>& keys,
                                          std::vector<MortonKey>& keysThatAreNowVisible,
                                          std::vector<MortonKey>& keysThatAreNoLongerVisible,
                                          std::vector<MortonKey>& currentlyVisibleKeys);
            
            void updateNodePayloads(QuadTreeNode* pRootNode,
                                    const std::vector<PayloadSlotStream> &streamEntryList,
                                    uint updateCount,
                                    uint slotsAboveInSceneGraph,
                                    std::vector<QuadTreeNode*>& nodesRequiringPlaceholders,
                                    int terrainPayloadIndex);
            
            uint findSlotsInSceneGraph(QuadTreeNode* node);
        };
    }
}