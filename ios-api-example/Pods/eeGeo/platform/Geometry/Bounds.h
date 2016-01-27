// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "SingleSphere.h"
#include <limits>
#include <vector>

namespace Eegeo
{
    namespace Geometry
    {
        class Bounds3D
        {
            v3 m_min;
            v3 m_max;
            
            Bounds3D() {}
            
        public:
            static inline Bounds3D Degenerate()
            {
                const float fMax = std::numeric_limits<float>::max();
                const float fMin = -fMax;
                
                return Bounds3D(fMax, fMax, fMax, fMin, fMin, fMin);
            }
            
            static inline Bounds3D Empty()
            {
                return Bounds3D(v3::Zero(), v3::Zero());
            }
            
            static Bounds3D CreateFromPoints(const std::vector<v3>& points);
            
            static inline Bounds3D CreateFromPointPair(const v3& a, const v3& b)
            {
                Bounds3D bounds;
                 
                if(a.x < b.x)
                {
                    bounds.m_min.x = a.x;
                    bounds.m_max.x = b.x;
                }
                else
                {
                    bounds.m_min.x = b.x;
                    bounds.m_max.x = a.x;
                }
                 
                if(a.y < b.y)
                {
                    bounds.m_min.y = a.y;
                    bounds.m_max.y = b.y;
                }
                else
                {
                    bounds.m_min.y = b.y;
                    bounds.m_max.y = a.y;
                }
                 
                if(a.z < b.z)
                {
                    bounds.m_min.z = a.z;
                    bounds.m_max.z = b.z;
                }
                else
                {
                    bounds.m_min.z = b.z;
                    bounds.m_max.z = a.z;
                }
                 
                return bounds;
            }
            
            inline Bounds3D(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
            : m_min(minX, minY, minZ)
            , m_max(maxX, maxY, maxZ)
            {
            }
            
            Bounds3D(v3 min, v3 max)
            : m_min(min)
            , m_max(max)
            {
            }
            
            v3 GetMin() const { return m_min; }
            v3 GetMax() const { return m_max; }
            
            v3 Center() const { return (m_min + m_max) * 0.5f; }
            
            void SetMinMax(v3 min, v3 max)
            {
                m_min = min;
                m_max = max;
            }
            
            inline void Encapsulate(const v3& vertex)
            {
                if(vertex.GetX() < m_min.GetX()) m_min.SetX(vertex.GetX());
                if(vertex.GetY() < m_min.GetY()) m_min.SetY(vertex.GetY());
                if(vertex.GetZ() < m_min.GetZ()) m_min.SetZ(vertex.GetZ());
                
                if(vertex.GetX() > m_max.GetX()) m_max.SetX(vertex.GetX());
                if(vertex.GetY() > m_max.GetY()) m_max.SetY(vertex.GetY());
                if(vertex.GetZ() > m_max.GetZ()) m_max.SetZ(vertex.GetZ());
            }
            
            inline bool intersects(const Bounds3D& bounds) const
            {
                if(m_max.x < bounds.m_min.x || m_min.x > bounds.m_max.x) return false;
                if(m_max.y < bounds.m_min.y || m_min.y > bounds.m_max.y) return false;
                if(m_max.z < bounds.m_min.z || m_min.z > bounds.m_max.z) return false;
                return true;
            }
            
            bool intersectsXY(const Bounds3D& bounds) const
            {
                return (m_max.GetX() >= bounds.m_min.GetX()) &&
                (m_min.GetX() <= bounds.m_max.GetX()) &&
                (m_max.GetY() >= bounds.m_min.GetY()) &&
                (m_min.GetY() <= bounds.m_max.GetY());
            }
            
            bool intersectsSphere(const SingleSphere& sphere) const
            {
                float radiusSq = sphere.radius * sphere.radius;
                
                v3 deltaMin = sphere.centre - m_min;
                v3 deltaMax = sphere.centre - m_max;
                
                if (deltaMin.x < 0.f)
                {
                    radiusSq -= deltaMin.x*deltaMin.x;
                }
                else if (deltaMax.x > 0.f)
                {
                    radiusSq -= deltaMax.x*deltaMax.x;
                }
            
                if (deltaMin.y < 0.f)
                {
                    radiusSq -= deltaMin.y*deltaMin.y;
                }
                else if (deltaMax.y > 0.f)
                {
                    radiusSq -= deltaMax.y*deltaMax.y;
                }
                
                if (deltaMin.z < 0.f)
                {
                    radiusSq -= deltaMin.z*deltaMin.z;
                }
                else if (deltaMax.z > 0.f)
                {
                    radiusSq -= deltaMax.z*deltaMax.z;
                }
            
                return radiusSq > 0.f;
            }
                        
            v3 Size() const { return (m_max - m_min); };
        };
        
        class DoubleBounds3D
        {
            Eegeo::dv3 m_min;
            Eegeo::dv3 m_max;
            
        public:
            const dv3& GetMin() const
            {
                return m_min;
            }
            
            const dv3& GetMax() const
            {
                return m_max;
            }
            
            void SetMinMax(Eegeo::dv3 min, Eegeo::dv3 max)
            {
                m_min = min;
                m_max = max;
            }
            
            Eegeo::dv3 Center() const { return m_min + ((m_max - m_min)/2.0); }
            
            void Encapsulate(Eegeo::dv3 vertex)
            {
                if(vertex.GetX() < m_min.GetX()) m_min.SetX(vertex.GetX());
                if(vertex.GetY() < m_min.GetY()) m_min.SetY(vertex.GetY());
                if(vertex.GetZ() < m_min.GetZ()) m_min.SetZ(vertex.GetZ());
                
                if(vertex.GetX() > m_max.GetX()) m_max.SetX(vertex.GetX());
                if(vertex.GetY() > m_max.GetY()) m_max.SetY(vertex.GetY());
                if(vertex.GetZ() > m_max.GetZ()) m_max.SetZ(vertex.GetZ());
            }
            
            Eegeo::dv3 Size() const { return (m_max - m_min); };
        };
                
        struct Bounds2D
        {
            Eegeo::v2 min;
            Eegeo::v2 max;
            
            static Bounds2D Degenerate()
            {
                return Bounds2D(
                                Eegeo::v2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max()),
                                Eegeo::v2(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max())
                                );
            }
            
            static Bounds2D Empty()
            {
                return Bounds2D(Eegeo::v2::Zero(), Eegeo::v2::Zero());
            }
            
            Bounds2D( Eegeo::v2 min,  Eegeo::v2 max):min(min), max(max)
            {
            }
            
            bool intersects(const Bounds2D& bounds) const
            {
                return (max.GetX() >= bounds.min.GetX()) &&
                (min.GetX() <= bounds.max.GetX()) &&
                (max.GetY() >= bounds.min.GetY()) &&
                (min.GetY() <= bounds.max.GetY());
            }
            
            bool contains(float x, float y) const
            {
                return (max.GetX() >= x) &&
                (min.GetX() <= x) &&
                (max.GetY() >= y) &&
                (min.GetY() <= y);
            }
            
            void addPoint(Eegeo::v2 point)
            {
                min = v2::Min(min, point);
                max = v2::Max(max, point);
            }
            
            void GetClockwiseVertices(v4* pVertices) const
            {
                pVertices[0] = v4(min.GetX(), min.GetY(), 0, 1);
                pVertices[1] = v4(min.GetX(), max.GetY(), 0, 1);
                pVertices[2] = v4(max.GetX(), max.GetY(), 0, 1);
                pVertices[3] = v4(max.GetX(), min.GetY(), 0, 1);
            }

            Eegeo::v2 center() const
            {
                return (min + max) * 0.5f;
            }
        };
    }
    
}
