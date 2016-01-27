// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Helpers.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelLoader
            {
            public:
                
                SceneModelLoader(SceneModelFactory& localSceneModelFactory, Helpers::IFileIO& fileIO);
                
                SceneModel* LoadPOD(const std::string& filename);
                
            private:
                
                SceneModelFactory& m_localSceneModelFactory;
                Helpers::IFileIO& m_fileIO;
            };
        }
    }
}