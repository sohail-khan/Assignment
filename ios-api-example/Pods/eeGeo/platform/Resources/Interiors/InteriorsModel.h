// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IdTypes.h"
#include "Space.h"
#include "VectorMath.h"
#include "EcefTangentBasis.h"
#include <string>
#include <vector>
#include "Bounds.h"
#include "InteriorsEntityMetadata.h"
#include "MortonKey.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            typedef std::vector<InteriorsFloorModel*> TFloorModelVector;
            
            class InteriorsModel
            {
            public:
                InteriorsModel(const std::string& name,
                               const std::string& associatedLandmarkMaterialName,
                               const std::string& sourceVendor,
                               const Space::EcefTangentBasis& tangentSpace,
                               const Geometry::Bounds3D& localEcefBounds,
                               const Geometry::Bounds3D& tangentSpaceBounds,
                               const Entities::TCategoryToEntitiesMetadata& entitiesMetadata,
                               const std::vector<InteriorsFloorModel*>& floorModels,
                               const std::vector<InteriorsFloorCells*>& interiorsFloorCells,
                               const int defaultFloorIndex);
                
                ~InteriorsModel();
                
                const InteriorId GetId() const;
                
                const std::string& GetName() const;
                const std::string& GetAssociatedLandmarkMaterialName() const;
                const std::string& GetSourceVendor() const;

                int GetMiddleFloorIndex() const;
                
                const TFloorModelVector& GetFloors() const;
                const InteriorsFloorModel& GetFloorAtIndex(int floorIndex) const;
                int GetFloorCount() const { return static_cast<int>(m_floorModels.size()); }
                
                const InteriorsFloorModel* GetBottomFloor() const;
                const int GetDefaultFloorIndex() const;
                
                const Eegeo::Space::EcefTangentBasis& GetTangentBasis() const { return m_tangentBasis; }
                
                const Geometry::Bounds3D& GetLocalEcefBounds() const { return m_localEcefBounds; }
                const Geometry::Bounds3D& GetTangentSpaceBounds() const { return m_tangentSpaceBounds; }
                
                const Entities::InteriorsEntityMetadata* GetMetadataForEntity(const std::string& entityId) const;
                const Entities::InteriorsEntityMetadata* GetMetadataForEntityFromCategory(const std::string& category, const std::string& entityId) const;
                
                // Cell/View methods
                InteriorsFloorCells* GetFloorCells(int floor) const;
                
                void IncrementCellInMemoryReferenceCount();
                void DecrementCellInMemoryReferenceCount();
                void IncrementCellVisibleReferenceCount();
                void DecrementCellVisibleReferenceCount();
                
                const bool AnyCellsInMemory() const { return m_cellsInMemoryRefCount > 0; }
                const bool AnyCellsVisible() const { return m_cellsVisibilityRefCount > 0; }
                
                void RegisterCellsInMemoryChangedCallback(Helpers::ICallback1<const InteriorsModel&>& callback);
                void UnregisterCellsInMemoryChangedCallback(Helpers::ICallback1<const InteriorsModel&>& callback);
                void RegisterCellsVisibilityChangedCallback(Helpers::ICallback1<const InteriorsModel&>& callback);
                void UnregisterCellsVisibilityChangedCallback(Helpers::ICallback1<const InteriorsModel&>& callback);
 
                
            private:
                void RefreshFloorTransforms();
                
                std::string m_name;
                std::string m_associatedLandmarkMaterialName;
                std::string m_sourceVendor;

                Eegeo::Space::EcefTangentBasis m_tangentBasis;
                
                Entities::TCategoryToEntitiesMetadata* m_pEntitiesMetadata;
                
                Geometry::Bounds3D m_localEcefBounds;
                Geometry::Bounds3D m_tangentSpaceBounds;

                TFloorModelVector m_floorModels;
                int m_defaultFloorIndex;
                
                // Cell/View methods
                std::vector<InteriorsFloorCells*> m_floorCellsPerFloor;
                int m_cellsInMemoryRefCount;
                int m_cellsVisibilityRefCount;
                
                Helpers::CallbackCollection1<const InteriorsModel&> m_cellsInMemoryChangedCallbacks;
                Helpers::CallbackCollection1<const InteriorsModel&> m_cellsVisibilityChangedCallbacks;
            };
        }
    }
}