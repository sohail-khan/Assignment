// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "Geometry.h"
#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        class OrientedBox
        {
            Eegeo::dv3 m_centre;
            Eegeo::dv3 m_axisX;
            Eegeo::dv3 m_axisY;
            Eegeo::dv3 m_axisZ;
            Eegeo::dv3 m_halfWidthExtents;
            
        public:
            
            OrientedBox();
            
            OrientedBox(Eegeo::dv3 centre,
                        Eegeo::dv3 axisX,
                        Eegeo::dv3 axisY,
                        Eegeo::dv3 axisZ,
                        Eegeo::dv3 halfWidthExtents);
            
            double GetVolume();
            
            Eegeo::dv3 CalculateNormalizedCoordinates(Eegeo::dv3 vertex);
        };
        
        void ExpandBoxToContainVertices(Eegeo::dv3 xDir,
                                        Eegeo::dv3 yDir,
                                        Eegeo::dv3 zDir,
                                        std::vector<Eegeo::dv3>& verts,
                                        Eegeo::dv3 _massCenter,
                                        DoubleBounds3D& bounds);
        
        OrientedBox CreateFromPointCloudAndDirection(std::vector<Eegeo::dv3>& outlinePoints,
                                                     int numOutlinePoints,
                                                     Eegeo::dv3 massCenter,
                                                     Eegeo::dv3 direction,
                                                     Eegeo::dv3 knownUpDirection);
        
        Eegeo::dv3 CalculateMassCentre(std::vector<Eegeo::dv3>& outlinePoints, int numOutlinePoints);
        
        void CreateOrientedBoxFromOutlinePointCloud(std::vector<Eegeo::dv3>& outlinePoints,
                                                    Eegeo::dv3 upDirection,
                                                    OrientedBox& box);
    }
}