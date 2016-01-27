// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "Types.h"
#include "ICallback.h"
#include "CallbackCollection.h"


#include <map>
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Markers
            {
                class InteriorMarkerModelRepository : private Eegeo::NonCopyable
                {
                public:
                    typedef Helpers::ICallback1<const InteriorMarkerModel&> TCallback;
                    
                    InteriorMarkerModelRepository();
                    
                    virtual ~InteriorMarkerModelRepository();
                    
                    virtual void Add(const InteriorMarkerModel& interiorMarkerModel);
                    virtual void Remove(const InteriorMarkerModel& interiorMarkerModel);
                    virtual bool Contains(const InteriorId& interiorId) const;
                    virtual const InteriorMarkerModel& Get(const InteriorId& interiorId) const;
                    
                    virtual void RegisterNotifyAddedCallback(TCallback& callback);
                    virtual void RegisterNotifyRemovedCallback(TCallback& callback);
                    virtual void UnregisterNotifyAddedCallback(TCallback& callback);
                    virtual void UnregisterNotifyRemovedCallback(TCallback& callback);
                    
                private:
                
                    typedef std::map<std::string, const InteriorMarkerModel*> TInteriorIdToMarker;
                    
                    TInteriorIdToMarker m_markers;
                    
                    Helpers::CallbackCollection1<const InteriorMarkerModel&> m_notifyAddedCallbacks;
                    Helpers::CallbackCollection1<const InteriorMarkerModel&> m_notifyRemovedCallbacks;
                };
            }
        }
    }
}