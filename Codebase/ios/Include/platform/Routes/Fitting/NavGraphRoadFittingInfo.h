// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Navigation.h"
#include "Geometry.h"
#include "VectorMathDecl.h"
#include "SingleSphere.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {

            class NavGraphRoadFittingInfo
            {
            public:
                NavGraphRoadFittingInfo(const Resources::Roads::Navigation::NavigationGraphRoad& road, const Resources::Roads::Navigation::NavigationGraph& navGraph);
                
                ~NavGraphRoadFittingInfo();
                
                const Resources::Roads::Navigation::NavigationGraphRoad& Road() const { return m_road; }
                const Resources::Roads::Navigation::NavigationGraph& NavGraph() const { return m_navGraph; }
                const Geometry::Point3Spline& Spline() const { return *m_pPoint3Spline; }
                const Geometry::SingleSphere& BoundingSphere() const { return m_boundingSphere; }
                int RoadIndex() const { return m_roadIndex; }
                
                
            private:
                const Resources::Roads::Navigation::NavigationGraphRoad& m_road;
                const Resources::Roads::Navigation::NavigationGraph& m_navGraph;
                const Geometry::Point3Spline* m_pPoint3Spline;
                Geometry::SingleSphere m_boundingSphere;
                const int m_roadIndex;
                
                
                static Geometry::Point3Spline* CreateNavGraphRoadSpline(const Resources::Roads::Navigation::NavigationGraphRoad& road, const dv3& ecefCellOrigin);
            };

        }
    }
}
