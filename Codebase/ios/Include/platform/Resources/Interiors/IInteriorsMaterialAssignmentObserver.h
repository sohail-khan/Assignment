// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Interiors.h"
#include "ICallback.h"
#include "Rendering.h"


namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class IInteriorsMaterialAssignmentObserver
            {
            public:
                typedef Helpers::ICallback1<Rendering::Renderables::InteriorRenderable> TCallback;
                
                virtual ~IInteriorsMaterialAssignmentObserver() {;}
                
                virtual void NotifyMaterialAssignedToRenderable(Rendering::Renderables::InteriorRenderable& interiorFloorRenderable) const = 0;
                
                virtual void RegisterCallback(const Rendering::Materials::IMaterial* pMaterial, const TCallback& callback) = 0;
                virtual void UnregisterCallback(const Rendering::Materials::IMaterial* pMaterial) = 0;
            };
        }
    }
}