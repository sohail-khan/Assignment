// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IPinViewFactory.h"
#include "LayerIds.h"
#include "Pin.h"
#include "Bounds.h"
#include "PinView.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Factory for creating PinViews.
         *
         *  The views created by this class have their origin in centre of their base edge.
         *  This class performs a 1-to-1 mapping of the Pin's category id to a tile in the texture used by the
         *  PinViewRenderer. That is, category 0 maps to tile 0, category 1 maps to tile 1 and so on.
         *
         */
        class PinViewFactory : protected Eegeo::NonCopyable, public IPinViewFactory
        {
        public:
            PinViewFactory(float spriteWidth, float spriteHeight)
            : m_spriteDimensions(Geometry::Bounds2D(
                            v2(-(spriteWidth / 2), 0),
                            v2((spriteWidth / 2), spriteHeight)))
            {

            }
                        
            PinView* CreateViewForPin(Pin& pinModel)
            {
                // since we're constructing a local bounds from the dimensions, we don't need to add all four points
                v3 vertices[3];

                vertices[0].x = m_spriteDimensions.min.GetX();
                vertices[0].y = m_spriteDimensions.min.GetY();
                vertices[0].z = 0;

                vertices[1].x = m_spriteDimensions.min.GetX();
                vertices[1].y = m_spriteDimensions.max.GetY();
                vertices[1].z = 0;

                vertices[2].x = m_spriteDimensions.max.GetX();
                vertices[2].y = m_spriteDimensions.max.GetY();
                vertices[2].z = 0;

                Geometry::Bounds3D modelBounds = Geometry::Bounds3D::Degenerate();
                modelBounds.Encapsulate(vertices[0]);
                modelBounds.Encapsulate(vertices[1]);
                modelBounds.Encapsulate(vertices[2]);

                return Eegeo_NEW(PinView)(pinModel, modelBounds);
            }
            
        private:
            Eegeo::Geometry::Bounds2D m_spriteDimensions;
        };
    }
}
