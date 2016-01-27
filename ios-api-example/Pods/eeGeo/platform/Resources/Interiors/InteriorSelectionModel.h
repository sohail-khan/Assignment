// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "CallbackCollection.h"
#include "ICallback.h"
#include "InteriorId.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorSelectionModel : private Eegeo::NonCopyable
            {
            public:
                
                InteriorSelectionModel();
                
                virtual ~InteriorSelectionModel();
                
                virtual bool IsInteriorSelected() const;
                
                virtual InteriorId GetSelectedInteriorId() const;
                
                virtual void SelectInteriorId(const InteriorId& interiorId);
                
                virtual void ClearSelection();
                
                virtual void RegisterSelectionChangedCallback(Helpers::ICallback1<const InteriorId>& callback);
                
                virtual void UnregisterSelectionChangedCallback(Helpers::ICallback1<const InteriorId>& callback);
                
            private:
                InteriorId m_selectedInteriorId;
                
                Helpers::CallbackCollection1<const InteriorId> m_selectionChangedObservers;
            };
        }
    }
}