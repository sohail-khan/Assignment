// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IInteriorController.h"
#include "Interiors.h"
#include "Buildings.h"
#include "Rendering.h"
#include "Lighting.h"
#include "ICallback.h"
#include "VectorMath.h"
#include "CallbackCollection.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace InteriorViewState
            {
                enum Values
                {
                    NoInteriorSelected = 0,     // No Interior selected, should render normally
                    AwaitingInteriorResources,  // Interior selected but resources not present. Waiting for resources to load
                    InteriorOutOfScene,         // Selected Interior resource present but no cells in scene graph.
                    InteriorInScene,            // Selected Interior resource present and at least one cell in scene graph. Interior can be displayed correctly at this point.
                    MAX
                };
            }
            
            class InteriorController : public IInteriorController
            {
            public:
                
                InteriorController(InteriorSelectionModel& selectionModel,
                                   InteriorsModelRepository& modelRepository,
                                   InteriorsCellResourceObserver& cellResourceObserver,
                                   Resources::Buildings::LandmarkToRenderableRepository& landmarkToRenderableRepository,
                                   Lighting::GlobalShadowing& globalShadowing,
                                   Rendering::Materials::DepthlessColorMaterial& quadMaterial);
                
                ~InteriorController();
                
                void SetSelectedInterior(InteriorId& interiorId);
                void ClearSelectedInterior();
                
                InteriorViewState::Values GetCurrentState() const { return m_currentViewState; }
                
                void SetExteriorToInteriorParam(float param);
                
                void SetCurrentFloor(int floor, bool snap=false);
                int GetCurrentFloorIndex() const;
                
                bool InteriorInScene() const { return m_currentViewState == InteriorViewState::InteriorInScene; }
                bool InteriorIsVisible() const;
                
                bool TryGetCurrentModel(const Resources::Interiors::InteriorsModel*& out_pModel);
                bool TryGetCurrentFloorModel(const Resources::Interiors::InteriorsFloorModel*& out_pModel);
                bool TryGetCurrentViewModel(const Resources::Interiors::CurrentInteriorViewModel*& out_pViewModel);
                
                void Update(float dt);
                
                void RegisterStateChangedCallback(Helpers::ICallback0& callback);
                void RegisterVisibilityChangedCallback(Helpers::ICallback0& callback);
                void RegisterFloorChangedCallback(Helpers::ICallback0& callback);
                
                void UnregisterStateChangedCallback(Helpers::ICallback0& callback);
                void UnregisterVisibilityChangedCallback(Helpers::ICallback0& callback);
                void UnregisterFloorChangedCallback(Helpers::ICallback0& callback);
                
            private:
                
                void HandleSelectionChanged(const InteriorId& previousSelection);
                void HandleInteriorAdded(InteriorsModel& model);
                void HandleInteriorRemoved(InteriorsModel& model);
                void HandleInteriorVisible(const InteriorsCellResource& interiorCellResource);
                void HandleInteriorInvisible(const InteriorsCellResource& interiorCellResource);
                void HandleLandmarkRenderableAdded(const std::string& landmarkName, Rendering::Renderables::CustomLandmarkRenderable& landmarkRenderable);
                void HandleLandmarkRenderableRemoved(const std::string& landmarkName, Rendering::Renderables::CustomLandmarkRenderable& landmarkRenderable);
                
                void SetState(InteriorViewState::Values nextState);
                
                void SetTransitionState(float t);
                const float GetTransitionState() const;
                void RefreshTransitionState();
                
                // Move this to Viewmodel if possible?
                void SetRenderablesLayer(bool landmarkShouldDrawAboveWorld);
                
                void InitialiseViewModel();
                void TearDownViewModel();
                
                Helpers::TCallback1<InteriorController, const InteriorId> m_selectionChangedCallback;
                Helpers::TCallback1<InteriorController, const InteriorsCellResource> m_interiorVisibleCallback;
                Helpers::TCallback1<InteriorController, const InteriorsCellResource> m_interiorInvisibleCallback;
                Helpers::TCallback1<InteriorController, InteriorsModel&> m_modelAddedCallback;
                Helpers::TCallback1<InteriorController, InteriorsModel&> m_modelRemovedCallback;
                Helpers::TCallback2<InteriorController, const std::string&, Rendering::Renderables::CustomLandmarkRenderable&> m_landmarkRenderableAddedCallback;
                Helpers::TCallback2<InteriorController, const std::string&, Rendering::Renderables::CustomLandmarkRenderable&> m_landmarkRenderableRemovedCallback;
                
                Helpers::CallbackCollection0 m_interiorStateChangedCallbacks;
                Helpers::CallbackCollection0 m_interiorVisibilityChangedCallbacks;
                Helpers::CallbackCollection0 m_interiorFloorChangedCallbacks;
                
                // Camera helper -> Expose ideal transition points.
                
                InteriorsModelRepository& m_modelRepository;
                InteriorsCellResourceObserver& m_cellResourceObserver;
                Resources::Buildings::LandmarkToRenderableRepository& m_landmarkToRenderableRepository;
                InteriorSelectionModel& m_selectionModel;
                Lighting::GlobalShadowing& m_globalShadowing;
                Rendering::Materials::DepthlessColorMaterial& m_quadMaterial;
                
                CurrentInteriorViewModel* m_pCurrentInteriorViewModel;
                InteriorViewState::Values m_currentViewState;
                float m_transitionState;
                bool m_landmarkShouldDrawAboveWorld;
            };
        }
    }
}