// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Navigation.h"
#include "PlaceNames.h"
#include "Roads.h"
#include "Streaming.h"
#include "VectorMathDecl.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        class ResourceSpatialQueryService : public Eegeo::NonCopyable
        {
        private:
            typedef Rendering::Scene::SceneElement<Rendering::Renderables::PackedRenderable> TPackedRenderableSceneElement;
            typedef std::vector<const TPackedRenderableSceneElement*> TPackedRenderableSceneElementSet;
            typedef Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable> TPackedRenderableSceneElementRepository;
            
            typedef Rendering::Scene::SceneElement<Resources::Roads::RoadNamesRenderable> TRoadNamesSceneElement;
            typedef std::vector<const TRoadNamesSceneElement*> TRoadNamesSceneElementSet;
            typedef Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable> TRoadNamesSceneElementRepository;
            
            typedef std::vector<const PlaceNames::PlaceNameModel*> TPlaceNameModels;
            
            const TPackedRenderableSceneElementRepository& m_buildingRepository;
            const TPackedRenderableSceneElementRepository& m_roadRepository;
            const TRoadNamesSceneElementRepository& m_roadNamesRepository;
            const TPackedRenderableSceneElementRepository& m_terrainRepository;
            const TPackedRenderableSceneElementRepository& m_shadowRepository;
            const Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& m_navGraphRepository;
            const Eegeo::Resources::PlaceNames::PlaceNamesRepository& m_placeNamesRepository;
            
            static bool IsBetterDelta(
                                      int currentBestDelta,
                                      const Streaming::MortonKey& referenceKey,
                                      const Streaming::MortonKey& testKey,
                                      int& newDelta
                                      );
            
            static bool IsSameAsBestDelta(
                                          int currentBestDelta,
                                          const Streaming::MortonKey& referenceKey,
                                          const Streaming::MortonKey& testKey,
                                          int& newDelta
                                          );
            
            template<typename T>
            static std::vector<const Eegeo::Rendering::Scene::SceneElement<T>*> GetItemForKey(
                                                                                              const Eegeo::Rendering::Scene::SceneElementRepository<T>& repository,
                                                                                              const Streaming::MortonKey& key,
                                                                                              int lowestLevel,
                                                                                              Eegeo::Streaming::MortonKey& matched);
            
        public:
            ResourceSpatialQueryService(
                                        const TPackedRenderableSceneElementRepository& buildingRepository,
                                        const TPackedRenderableSceneElementRepository& roadRepository,
                                        const Rendering::Scene::SceneElementRepository<Resources::Roads::RoadNamesRenderable>&roadNamesRepository,
                                        const TPackedRenderableSceneElementRepository& terrainRepository,
                                        const TPackedRenderableSceneElementRepository& shadowRepository,
                                        const Eegeo::Resources::Roads::Navigation::NavigationGraphRepository& navGraphRepository,
                                        const Eegeo::Resources::PlaceNames::PlaceNamesRepository& placeNamesRepository);
            
            TPackedRenderableSceneElementSet GetBuildingByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                                    int ecefLevel,
                                                                    int lowestLevel,
                                                                    Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetBuildingByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                                    int lowestLevel,
                                                                    Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetRoadByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                                int ecefLevel,
                                                                int lowestLevel,
                                                                Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetRoadByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                                int lowestLevel,
                                                                Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetTerrainByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                                   int ecefLevel,
                                                                   int lowestLevel,
                                                                   Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetTerrainByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                                   int lowestLevel,
                                                                   Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetShadowByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                                  int ecefLevel,
                                                                  int lowestLevel,
                                                                  Streaming::MortonKey& matched) const;
            
            TPackedRenderableSceneElementSet GetShadowByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                                  int lowestLevel,
                                                                  Streaming::MortonKey& matched) const;
            
            TRoadNamesSceneElementSet GetRoadNamesByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                              int ecefLevel,
                                                              int lowestLevel,
                                                              Streaming::MortonKey& matched) const;
            
            TRoadNamesSceneElementSet GetRoadNamesByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                              int lowestLevel,
                                                              Streaming::MortonKey& matched) const;
            
            TPlaceNameModels GetPlaceNamesByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                      int ecefLevel,
                                                      int lowestLevel,
                                                      Streaming::MortonKey& matched) const;
            
            TPlaceNameModels GetPlaceNamesByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                      int lowestLevel,
                                                      Streaming::MortonKey& matched) const;
            
            Eegeo::Resources::Roads::Navigation::NavigationGraph* GetNavGraphByEcefPoint(const Eegeo::dv3& ecefPoint,
                                                                                         int ecefLevel,
                                                                                         int lowestLevel,
                                                                                         Streaming::MortonKey& matched) const;
            
            Eegeo::Resources::Roads::Navigation::NavigationGraph* GetNavGraphByMortonKey(const Eegeo::Streaming::MortonKey& key,
                                                                                         int lowestLevel,
                                                                                         Streaming::MortonKey& matched) const;
        };
    }
}
