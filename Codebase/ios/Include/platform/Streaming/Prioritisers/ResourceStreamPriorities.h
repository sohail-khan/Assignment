// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Streaming
    {
        namespace ResourceStreamPriorities
        {
            enum ResourceStreamPrioritiesValues
            {
                Terrain = 1,
                Buildings,
                MaxPriorityForImmediateLoad = Buildings,
                Roads,
                PlaceNames,
                Interiors
            };
        }
        
    }
}
