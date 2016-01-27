// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Bounds.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief Interface to the layout of a texture page.
         *
         * This interface allows clients to retrieve the UV bounds of numbered tiles within a texture page.
         */
        class ITexturePageLayout
        {
        public:
            virtual Eegeo::Geometry::Bounds2D GetTileUVBounds(int tileIndex) const = 0;
            virtual ~ITexturePageLayout() {};
        };
    }
}
