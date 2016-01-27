// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "IInteriorsMaterialAssignmentObserver.h"
#include "Types.h"
#include "ICallback.h"
#include "Rendering.h"

#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsMaterialAssignmentObserver : public IInteriorsMaterialAssignmentObserver, private Eegeo::NonCopyable
            {
            public:
                void NotifyMaterialAssignedToRenderable(Rendering::Renderables::InteriorRenderable& interiorFloorRenderable) const;
                
                void RegisterCallback(const Rendering::Materials::IMaterial* pMaterial, const TCallback& callback);
                void UnregisterCallback(const Rendering::Materials::IMaterial* pMaterial);
            private:
                
                typedef std::map<const Rendering::Materials::IMaterial*, const TCallback*> TRenderableToCallback;
                
                TRenderableToCallback m_callbacks;
            };
        }
    }
}