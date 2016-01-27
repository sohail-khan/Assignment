// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "IInteriorsLabelController.h"
#include "Rendering.h"
#include <string>
#include "Interiors.h"
#include "CallbackCollection.h"
#include "TextMeshes.h"
#include "PlaceNames.h"
#include "Fonts.h"
#include "IRenderableFilter.h"
#include "Camera.h"
#include "InteriorsLabelParser.h"
#include "InteriorsEntitiesRepository.h"

#include <vector>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Entities
            {
                class InteriorsLabelsController : public IInteriorsLabelController
                {
                public:
                    InteriorsLabelsController(InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                              Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                              Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                              Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                              Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                              Fonts::FontInstance& font,
                                              PlaceNames::PlaceNamesController& placenamesController,
                                              InteriorController& interiorController,
                                              const bool interiorsAffectedByFlattening,
                                              const v3& glyphColor,
                                              const v3& outlineColor);
                    
                    ~InteriorsLabelsController();
                    
                    void AddLabelToOmit(const std::string& labelName);
                    void RemoveLabelToOmit(const std::string& labelName);
                    
                    const TFloorToModelMap& GetFloorsToModels() const { return m_floorsToModels; }
                    
                private:
                    Helpers::TCallback0<InteriorsLabelsController> m_interiorsStateChangedCallback;
                    Helpers::TCallback0<InteriorsLabelsController> m_interiorsVisibilityChangedCallback;
                    Helpers::TCallback0<InteriorsLabelsController> m_interiorsFloorChangeCallback;
                    
                    void OnInteriorsStateChanged();
                    void OnInteriorsVisibilityChanged();
                    void OnInteriorsFloorChanged();
                    
                    Helpers::TCallback2<InteriorsLabelsController, const std::string&, const TEntityModelVector&> m_entitiesAddedCallback;
                    Helpers::TCallback2<InteriorsLabelsController, const std::string&, const TEntityModelVector&> m_entitiesRemovedCallback;
                    
                    void OnEntitiesAdded(const std::string& interiorName, const TEntityModelVector& entities);
                    void OnEntitiesRemoved(const std::string& interiorName, const TEntityModelVector& entities);
                    
                    void RemoveAllLabels();
                    void StoreAndPresentCreatedLabels(TFloorToModelMap& newFloorsToModels);
                    
                    InteriorsEntitiesRepository& m_interiorsEntitiesRepository;
                    InteriorController& m_interiorController;

                    // Views
                    Rendering::Shaders::TextShader* m_pLabelTextShader;
                    Fonts::FontMaterialSet* m_pLabelsFontMaterialSet;
                    TextMeshes::InstancedTextMeshBuilder* m_pLabelsTextMeshBuilder;
                    Resources::PlaceNames::PlaceNameViewBuilder* m_pLabelsViewBuilder;
                    PlaceNames::PlaceNamesController& m_placenamesController;
                    const v3 m_glyphColor;
                    const v3 m_outlineColor;
                    
                    const InteriorsModel* m_pCurrentInteriorsModel;
                    
                    TFloorToModelMap m_floorsToModels;
                    
                    std::set<std::string> m_labelsToOmit;
                    
                    const bool m_interiorsAffectedByFlattening;
                };
            }
        }
    }
}