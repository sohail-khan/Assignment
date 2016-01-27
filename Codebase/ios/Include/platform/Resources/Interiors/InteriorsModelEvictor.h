// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "ICallback.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsModelEvictor : private Eegeo::NonCopyable
            {
            public:
                
                InteriorsModelEvictor(InteriorsModelRepository& modelRepository);
                ~InteriorsModelEvictor();
                
                void Update();
                
            private:
                
                void OnModelAdded(InteriorsModel& model);
                void OnModelRemoved(InteriorsModel& model);
                void OnModelCellsInMemoryCountChanged(const InteriorsModel& model);
                
                InteriorsModelRepository& m_repository;
                
                std::vector<const InteriorsModel*> m_destructionList;
                
                Helpers::TCallback1<InteriorsModelEvictor, InteriorsModel&> m_modelAddedCallback;
                Helpers::TCallback1<InteriorsModelEvictor, InteriorsModel&> m_modelRemovedCallback;
                Helpers::TCallback1<InteriorsModelEvictor, const InteriorsModel&> m_modelCellsInMemoryCountChangedCallback;
            };
        }
    }
}