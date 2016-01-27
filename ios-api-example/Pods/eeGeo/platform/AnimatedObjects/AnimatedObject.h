// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Space.h"
#include "VectorMath.h"

namespace Eegeo
{
    class Model;
    
    namespace AnimatedObjects
    {
        class AnimatedObject : protected Eegeo::NonCopyable
        {
        public:
            AnimatedObject(Eegeo::Model* pModel, const Eegeo::dv3& ecefOrigin, const Eegeo::m33& basis, float frameRateScale);
            ~AnimatedObject();
                        
            Eegeo::Model& GetModel() const { return *m_pModel; }
            const Eegeo::dv3& GetEcefOrigin() const { return m_ecefOrigin; }
            const Eegeo::m33& GetBasis() const { return m_basis; }
            float GetFrameRateScale() const { return m_frameRateScale; }
            
            static AnimatedObject* CreateAtLatLongAltitude(Eegeo::Model* pModel, const Space::LatLongAltitude& latLongAltitude, float framerateScale);
            static AnimatedObject* CreateAtEcef(Eegeo::Model* pModel, const dv3& ecefOrigin, float framerateScale);
            
        private:
            Eegeo::Model* m_pModel;
            Eegeo::dv3 m_ecefOrigin;
            Eegeo::m33 m_basis;
            float m_frameRateScale;
        };
    }
}
