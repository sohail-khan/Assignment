// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include "EcefTangentBasis.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class CurrentInteriorViewModel : private Eegeo::NonCopyable
            {
            public:
                
                CurrentInteriorViewModel(InteriorsModel& selectedInteriorModel);
                ~CurrentInteriorViewModel();
                
                const InteriorsModel& GetModel() const { return m_model; }
                
                void SetAlpha(float alpha);
                float GetAlpha() const { return m_alpha; }
                
                void SetHeightOffset(float heightOffset);
                const float GetHeightOffset() const { return m_heightOffset; }
                
                const int GetSelectedFloorIndex() const { return m_selectedFloorIndex; };
                void SelectFloorAtIndex(int floorIndex, bool snap=false);
                const InteriorsFloorModel& GetSelectedFloorModel() const;
                
                float GetFloorParameter() const { return m_floorParameter; }
                
                void Update(float dt);
                
                void SetExteriorMeshHasFaded(bool exteriorMeshHasFaded);
                bool GetExteriorMeshHasFaded() const;

            private:
                
                void RefreshFloorViews();
                
                float m_floorParameter;
                float m_alpha;
                bool m_exteriorMeshHasFaded;
                float m_heightOffset;
                int m_selectedFloorIndex;
                int m_previouslySelectedFloorIndex;
                bool m_viewDirty;

                bool m_isCurrentFloorTransitionComplete;
                
                InteriorsModel& m_model;
                
            };
        }
    }
}
