// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Rendering
    {
        class EnvironmentFlatteningService : Eegeo::NonCopyable
        {
        public:
            
            enum EasingType
            {
                PennerInOutBack,
                Linear,
                SmoothStep,
            };
            
            static const float DefaultEaseDurationSeconds;
            static const float DefaultNormalScale;
            static const float DefaultFlatScale;
            
            EnvironmentFlatteningService();
            
            void ToggleFlattened();
            void Update(float dt);
            
            void SetIsFlattened(bool isFlattened);
            void SetEasingType(EasingType easingType) { m_easingType = easingType; }
            void SetEaseDuration(float easeDurationSeconds) { m_easeDurationSeconds = easeDurationSeconds; }
            
            bool IsFlattened() const;
            
            void SetCurrentScale(float scale);
            float GetCurrentScale() const;
            
            void SetFlattenedScale(float scale);
            float GetFlattenedScale() const;
            
            static dv3 GetScaledPointEcef(const dv3& pointEcef, float environmentScale);
            static dv3 GetScaledPointAboveGroundEcef(const dv3& pointEcef, float heightAboveGround, float environmentScale);
            
            void InsertChangedCallback(Eegeo::Helpers::ICallback0& callback);
            
            void RemoveChangedCallback(Eegeo::Helpers::ICallback0& callback);
            
        private:
            float m_flatScale;

            float m_scale;
            float m_interpParam;
            bool m_isFlat;
            bool m_manualScale;
            float m_easeDurationSeconds;
            EasingType m_easingType;
            Eegeo::Helpers::CallbackCollection0 m_changedCallbacks;
        };
    }
}