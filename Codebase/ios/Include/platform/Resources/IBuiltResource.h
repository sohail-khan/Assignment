// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"

namespace Eegeo
{
    namespace Resources
    {
        class IBuiltResource
        {
        public:
        	virtual ~IBuiltResource(){}
            virtual void Unload() = 0;
            virtual void RemovedFromSceneGraph() = 0;
            virtual void AddedToSceneGraph() = 0;
            virtual const Eegeo::Streaming::MortonKey& GetKey() const = 0;
        };
    }
}
