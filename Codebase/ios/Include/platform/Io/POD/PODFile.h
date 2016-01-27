// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "POD.h"
#include <vector>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODFile
            {
            private:
                std::vector<PODScene*> m_podScenes;
                
            public:
                ~PODFile();
                
                void AddScene(PODScene* podScene);
                
                size_t GetNumOfScenes() const;
                const PODScene* GetScene(u32 sceneIndex) const;
            };
        }
    }
}
