// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "Colors.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Data
    {
        namespace PolyChart
        {
            typedef std::string TPolyChartId;

            class PolyChartModel : private Eegeo::NonCopyable
            {
            public:
                class PolyChartStackSegment
                {
                public:
                    PolyChartStackSegment(const float topHeight, const float bottomHeight, const v4& color)
                    : m_color(color)
                    , m_topHeight(topHeight)
                    , m_bottomHeight(bottomHeight)
                    {
                    }
                    
                    const v4& GetColor() const { return m_color; }
                    const float GetTopHeight() const { return m_topHeight; }
                    const float GetBottomHeight() const { return m_bottomHeight; }
                private:
                    v4 m_color;
                    float m_topHeight;
                    float m_bottomHeight;
                };
                
                class PolyChartBuilder : private Eegeo::NonCopyable
                {
                public:
                    PolyChartBuilder(
                                    const TPolyChartId& id,
                                    const std::vector<Space::LatLongAltitude>& exteriorRingVertices,
                                    const v4& polygonColor)
                    : m_id(id)
                    , m_exteriorRingVertices(exteriorRingVertices)
                    , m_color(polygonColor)
                    , m_altitudeOffset(0.0f)
                    , m_finished(false)
                    {
                    }
                    
                    PolyChartBuilder(const TPolyChartId& id,
                                     const Space::LatLongAltitude& cylinderCentre,
                                     float radiusInMetres,
                                     const v4& polygonColor);
                    
                    PolyChartBuilder& AltitudeOffset(float altitudeOffset);
                    PolyChartBuilder& AddChartStack(const float heightInMetres, const v4& color);
                    PolyChartModel* Build();
                    
                private:
                    const std::string m_id;
                    std::vector<Space::LatLongAltitude> m_exteriorRingVertices;
                    const v4 m_color;
                    std::vector<PolyChartStackSegment> m_stackParts;
                    float m_altitudeOffset;
                    bool m_finished;
                };
                
                class LocalEcefPolyChartBuilder : private Eegeo::NonCopyable
                {
                public:
                    LocalEcefPolyChartBuilder(
                                     const TPolyChartId& id,
                                     const dv3& ecefCellCenter,
                                     const std::vector<v3>& exteriorRingVerticesLocalEcef,
                                     const std::vector<u16>& triangulationIndices,
                                     const v4& polygonColor)
                    : m_id(id)
                    , m_ecefCellCenter(ecefCellCenter)
                    , m_exteriorRingVerticesLocalEcef(exteriorRingVerticesLocalEcef)
                    , m_triangulationIndices(triangulationIndices)
                    , m_color(polygonColor)
                    {
                    }
                   
                    LocalEcefPolyChartBuilder& AddChartStack(const float heightInMetres, const v4& color);
                    PolyChartModel* Build();
                    
                private:
                    const std::string m_id;
                    dv3 m_ecefCellCenter;
                    std::vector<v3> m_exteriorRingVerticesLocalEcef;
                    std::vector<u16> m_triangulationIndices;
                    const v4 m_color;
                    std::vector<PolyChartStackSegment> m_stackParts;
                };
                
                const float GetScale() const { return m_scale; }
                void SetScale(float scale) { m_scale = scale; }
                
                const TPolyChartId& GetId() const { return m_id; }
                const dv3& GetEcefCellCenter() const { return m_ecefCellCenter; }
                
                const v4& GetColor() const { return m_color; }
                
                const std::vector<dv3>& GetEcefTriangleVertices() const { return m_ecefTriangleVerts; }
                const std::vector<dv3>& GetExteriorEcefVertices() const { return m_exteriorEcefVerts; }
                
                const float GetHeight() const;
                const size_t GetNumberOfStacks() const { return m_stacks.size(); }
                const PolyChartStackSegment& GetStackByIndex(int index) const { return m_stacks.at(index); }

            private:
                PolyChartModel() { };

                float m_scale;
                TPolyChartId m_id;
                std::vector<dv3> m_ecefTriangleVerts;
                std::vector<dv3> m_exteriorEcefVerts;
                std::vector<PolyChartStackSegment> m_stacks;
                v4 m_color;
                dv3 m_ecefCellCenter;
            };
        }
    }
}