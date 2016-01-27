// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "MortonKey.h"
#include "Streaming.h"
#include <vector>

namespace Eegeo
{
    namespace Streaming
	{
        class SceneGraphCellRepository : protected Eegeo::NonCopyable
        {
            static const int MAX_REFINE_DEPTH = 14;
            
            std::vector<MortonKey> m_cellKeysPresentInScene;
            std::vector<ISceneGraphCellCallback*> m_addedCallbacks;
            std::vector<ISceneGraphCellCallback*> m_removalCallbacks;
            
            void CallAddedCallbacks(const MortonKey& key) const;
            void CallRemovalCallbacks(const MortonKey& key) const;
            
            std::vector<MortonKey> m_cellsAdded;
            std::vector<MortonKey> m_cellsRemoved;
            std::vector<MortonKey> m_clampedCells;
            
        public:
            
            void GetCellsInSceneGraph(std::vector<MortonKey>& output) const; // Not used. Should go.
            bool IsCellInSceneGraph(const MortonKey& key) const; // Should go but used.
            
            void RegisterAddedCallback(ISceneGraphCellCallback* callback);
            void UnregisterAddedCallback(ISceneGraphCellCallback* callback);
            
            void RegisterRemovalCallback(ISceneGraphCellCallback* callback);
            void UnregisterRemovalCallback(ISceneGraphCellCallback* callback);
            
            void UpdateCells(std::vector<MortonKey>& cellKeysInSceneGraph);
        };
    }
}
