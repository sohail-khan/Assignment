// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITexturePageLayout.h"
#include "Geometry.h"

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A texture page divided into equally sized tiles along each axis.
         */
        class RegularTexturePageLayout : protected Eegeo::NonCopyable, public ITexturePageLayout
        {
        public:
            RegularTexturePageLayout(int numOfTilesInEachAxis);
            Eegeo::Geometry::Bounds2D GetTileUVBounds(int tileIndex) const;

        private:
            int m_numberOfTilesInEachAxis;
        };
    }
}
