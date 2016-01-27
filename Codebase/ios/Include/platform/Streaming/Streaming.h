// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Streaming
    {
        class BuildPrioritiser;
        class PayloadSortFunctor;
        class IResourceStream;
        class IStreamingVolume;
        class CameraFrustumStreamingVolume;
        class LoadPrioritiser;
        class LodStreamMap;
        struct MortonKey;
        class MortonKeyCompare;
        class NullResourceStream;
        class Payload;
        class PayloadCache;
        class PayloadCacheLoader;
        class PayloadBuildManager;
        class PayloadEvicter;
        class PayloadLoadRequestItemFactory;
        class PayloadPlaceholderBuilder;
        class PayloadPool;
        class PayloadPriorityComparator;
        class PayloadSlotStreamMap;
        class PayloadStateStats;
        class PayloadWebLoader;
        class PayloadWebLoadRequest;
        class QuadTreeCube;
        class QuadTreeNode;
        class QuadTreeNodePool;
        class QuadTreeVisibilityUpdater;
        class QuadTreeNodePoolItemFactory;
        class RedundantNodeEvicter;
        class RegionSelectedResourceStream;
        class ResourceCeilingProvider;
        class ResourceNodeCache;
        class ResourceStream;
        class ResourceStreamBase;
        class ResourceStreamComponent;
        class SceneGraphUpdater;
        class SceneGraphCellRepository;
        class ISceneGraphCellCallback;
        class StreamingController;
        class StreamingVolume;
        class StreamingVolumeController;
        class TerrainPlaceholderInserter;
        class IStreamingObserver;
        class FrustumStreamingVolume;
        class LoggingResourceStream;
        class ResourceNode;
    }
}