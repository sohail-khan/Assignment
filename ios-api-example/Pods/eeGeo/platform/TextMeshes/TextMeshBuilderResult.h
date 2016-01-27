// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Bounds.h"
#include "Rendering.h"
#include <vector>

namespace Eegeo
{
    namespace TextMeshes
    {
        struct TextMeshBuilderResult
        {
            TextMeshBuilderResult() : totalBounds(Geometry::Bounds2D::Degenerate()) {}
            
            Geometry::Bounds2D totalBounds;
            std::vector<Rendering::Mesh*> meshes;
        };
    }
}