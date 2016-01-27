// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ISpline.h"
#include "VectorMath.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Geometry
    {
        namespace TimeParameterizationMethod
        {
            enum Values
            {
                Uniform = 0, // Parameters for points are equidistant, regardless of Euclidean distances. This causes fast/slow sections depending on distance between points.
                Chordal,     // Parameters for points are based using Euclidean distances. This reduces the effect of looping & fast/slow sections
                Centripetal  // Parameters for points are based using Sqr Root Euclidean distances. As with chordal, but produces a much stiffer curve.
            };

            bool TryParseTimeParameterizationMethod(const std::string& s, TimeParameterizationMethod::Values& out_value);
            std::string ToString(const TimeParameterizationMethod::Values value);
        }
        
        struct CatmullRomSplinePoint
        {
            CatmullRomSplinePoint()
            : Position(dv3::Zero())
            , T(0)
            {}
            
            CatmullRomSplinePoint(dv3& position)
            : Position(position)
            , T(0)
            {}
            
            dv3 Position;
            double T;
        };
        
        class CatmullRomSpline : public ISpline
        {
        public:
            CatmullRomSpline();
            
            void SetTimeParameterizationMethod(TimeParameterizationMethod::Values method);
            
            void GetInterpolatedPositionInPlace(double t, dv3& out_position) const;
            bool IsValid() const;
            
            int GetNumberOfPoints() const { return static_cast<int>(m_points.size()); }
            const std::vector<CatmullRomSplinePoint>& GetPoints() const { return m_points; }
            
            void AddPoint(dv3 position);
            void RemovePoint(int index);
            void RemoveLastPoint();
            void Clear();
            
        private:
            
            void RecalculateTimeParameters();
            void RecalculateUniformTimeParameters();
            void RecalculateEuclidianDistanceTimeParameters(bool useCentripetal);
            int GetPointIndexForT(double t) const;
            void GetRelevantPointsForTime(double t,
                                          CatmullRomSplinePoint& out_p0,
                                          CatmullRomSplinePoint& out_p1,
                                          CatmullRomSplinePoint& out_p2,
                                          CatmullRomSplinePoint& out_p3,
                                          double& localT) const;
            
            TimeParameterizationMethod::Values m_timeParameterizationMethod;
            std::vector<CatmullRomSplinePoint> m_points;
            
            std::vector<double> m_scratchDoubles;
        };
    }
}
