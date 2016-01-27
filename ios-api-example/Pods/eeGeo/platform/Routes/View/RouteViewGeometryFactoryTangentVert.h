// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RouteVertexClassification.h"
#include "VectorMath.h"

//#define CURVE_COLOURING
//#define CURVE_FLOW_COLOURING
//#define CURVE_ADJUSTMENT_COLOURING
//#define ROUTE_VIEW_RESERVE_CHECKS

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            // TODO: Move this elsewhere. It's causing pain with definition of isnan though...
            inline bool hasNan(const Eegeo::v2 v)
            {
                return (std::isnan(v.x) || std::isnan(v.y));
            }

            // cut-down struct for processing data
            struct RouteVert
            {
                RouteVert()
                : tangentVert(v2::Zero())
                , offset(v2::Zero())
                , colour(v4::Zero())
                {}
                
                v2 tangentVert;
                float height;
                float halfWidth;
                RouteVertexClassification classification;
                v2 offset;
                v4 colour;
            };
        }
    }
}