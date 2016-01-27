// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Interiors.h"
#include "MortonKey.h"
#include "VectorMath.h"
#include "InteriorRenderableSet.h"

#include <vector>
#include <string>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsFloorCell : private Eegeo::NonCopyable
            {
            public:
                static const std::string DefaultTag;
                static const std::string DefaultDetailTag;

                InteriorsFloorCell(const Streaming::MortonKey& cellKey,
                                   const std::map<std::string, InteriorRenderableSet>& renderables,
                                   const std::vector<Rendering::Renderables::InteriorHighlightRenderable*>& interiorHighlightRenderables,
                                   const std::vector<Entities::InteriorsEntityModel*>& entityModels,
                                   const std::vector<Entities::InteriorsEntityGeometryView*>& entityGeometryViews,
                                   const int floorNumber);

                ~InteriorsFloorCell();
                
                const Streaming::MortonKey& GetCellKey() const { return m_cellKey; }

                bool TryActivateTag(const std::string& _tag);

                bool TryDeactivateTag(const std::string& _tag);

                bool TryGetTagIsActive(const std::string& _tag, bool &isActive);
                
                std::vector<Rendering::Renderables::InteriorFloorRenderable*> GetFloorFeatureRenderables() const;
                
                std::vector<InteriorsStencilMirrorClearRenderable*> GetStencilMirrorClearRenderables() const;
                
                const std::vector<Rendering::Renderables::InteriorHighlightRenderable*>& GetHighlightRenderables() const;

                std::vector<Rendering::Renderables::InstancedInteriorFloorRenderable*> GetInstancedRenderables() const;
                
                const std::vector<Entities::InteriorsEntityModel*>& GetEntityModels() const { return m_entityModels; }
                
                std::vector<Entities::InteriorsEntityGeometryView*> GetGeometryViews() const { return m_entityGeometryViews; }
                
                int GetFloorNumber() const { return m_floorNumber; }
                
                void UpdateRenderables(const v3& floorOffsetEcef, const float brightness, const float alpha);
                
            private:

                InteriorRenderableSet* GetSetFromTag(const std::string& _tag);

                const Streaming::MortonKey m_cellKey;
                const dv3 m_cellCentreEcef;
                const std::vector<Entities::InteriorsEntityModel*> m_entityModels;
                const std::vector<Entities::InteriorsEntityGeometryView*> m_entityGeometryViews;
                std::map<std::string, InteriorRenderableSet> m_renderables;
                std::vector<Rendering::Renderables::InteriorHighlightRenderable*> m_interiorHighlightRenderables;
                const int m_floorNumber;
            };
        }
    }
}