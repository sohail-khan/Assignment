// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Lighting
    {
        class GlobalShadowing
        {
        private:
            
            Eegeo::v3 m_shadowColor;
            float m_shadowAlpha;
            Eegeo::v3 m_trueShadowColor;
            
            void Refresh()
            {
                m_trueShadowColor = v3::Lerp(v3::One(), m_shadowColor, m_shadowAlpha);
            }
            
        public:
            GlobalShadowing()
            : m_shadowColor(1.f, 1.f, 1.f)
            , m_trueShadowColor(1.f, 1.f, 1.f)
            , m_shadowAlpha(1.0f)
            {
            }

            void SetShadowColor(const Eegeo::v3& shadowColor)
            {
                m_shadowColor = shadowColor;
                Refresh();
            }
            
            void SetShadowAlpha(float alpha)
            {
                m_shadowAlpha = alpha;
                Refresh();
            }
            
            const Eegeo::v3& GetShadowColor() const { return m_trueShadowColor; }
            const float GetShadowAlpha() const { return m_shadowAlpha; }
            
        };
    }
}
