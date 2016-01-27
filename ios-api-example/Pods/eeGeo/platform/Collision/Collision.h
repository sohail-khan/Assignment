// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

namespace Eegeo
{
    namespace Collision
    {
        struct CollisionBvhNode;
        struct CollisionMaterialIndexLookupPair;
        struct CollisionMaterialTable;
        class CollisionBvh;
        class ICollisionBvhFactory;
        class CollisionBvhFactory;

        class IRayPicker;
        class ICollisionMeshResource;
        class CollisionMeshResourceRepository;
        class CollisionMeshRayPicker;
        class ICollisionBvhProvider;
        class CollisionMeshResourceRepository;
        class CollisionMeshBuiltResource;
        class AggregateCollisionBvhProvider;
        
        struct SkewedRay;
        struct RayNodeIntersectionResult;
        struct RayMeshIntersectionResult;
        struct RayCasterResult;
        class EnvironmentRayCaster;
        
        struct CollisionSubMesh;
        class CollisionSubMeshBuilder;
        struct ContiguousRangeBuilder;
        

    }
}