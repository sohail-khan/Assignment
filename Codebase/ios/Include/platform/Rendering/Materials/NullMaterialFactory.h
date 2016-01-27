// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class NullMaterialFactory : protected Eegeo::NonCopyable
            {
            public:
                NullMaterialFactory(Rendering::Shaders::NullShader& nullShader,
                                    Rendering::Materials::MaterialIdGenerator& materialIdGenerator)
                : m_nullShader(nullShader)
                , m_materialIdGenerator(materialIdGenerator)
                {
                }
                
                NullMaterial* Create(const std::string& materialName) const;
                
            private:
                Rendering::Shaders::NullShader& m_nullShader;
                Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
            };
        }
    }
}