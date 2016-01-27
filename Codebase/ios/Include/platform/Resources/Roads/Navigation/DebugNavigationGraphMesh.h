// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Navigation.h"
#include "VectorMath.h"
#include "DebugRendering.h"
#include "DebugRenderable.h"
#include <vector>

namespace Eegeo
{
    
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                struct DebugNavigationGraphMeshConfig
                {
                    float VerticalOffset;
                    float GapLengthBetweenRoadVertices;
                    float CellConnectionMarkerLength;
                    float CellConnectionMarkerWidth;
                    float RoadLinkMarkerLength;
                    float RoadLinkMarkerWidth;
                    bool ColourCodeRoadDirections;
                };
                
                class DebugNavigationGraphMesh : protected Eegeo::NonCopyable
                {
                public:
                    
                    // IH: Dependency on GLState in construction. These objects should only be constructed
                    // during the app's Draw() phase
                    DebugNavigationGraphMesh(const NavigationGraph& navGraph,
                                             const DebugNavigationGraphMeshConfig& config,
                                             Eegeo::Rendering::GLState& glState);
                    
                    ~DebugNavigationGraphMesh();
                    
                    void Draw(const Camera::RenderCamera& renderCamera, Rendering::GLState& glState);
                    
                    void SetPositionECEF(const Eegeo::dv3& posECEF);

                    void Regenerate(const NavigationGraph& navGraph, Eegeo::Rendering::GLState& glState);
                    
                    static DebugNavigationGraphMeshConfig CreateDefaultConfig();
                private:
                    void GenerateGeometry(const NavigationGraph& navGraph, Eegeo::Rendering::GLState& glState);
                    void AddQuad(std::vector<Eegeo::v3>& verts,
                                 std::vector<Eegeo::v3>& colors,
                                 std::vector<Eegeo::v2>& uvs,
                                 std::vector<u16>& indices,
                                 const Eegeo::v3& up,
                                 const Eegeo::v3& v0,
                                 const Eegeo::v3& v1,
                                 const Eegeo::v3& startColor,
                                 const Eegeo::v3& endColor,
                                 const float halfWidth);
                    
                    void AddToConnections(std::vector<Eegeo::v3>& verts,
                                 std::vector<Eegeo::v3>& colors,
                                 std::vector<Eegeo::v2>& uvs,
                                 std::vector<u16>& indices,
                                 const NavigationGraph& navGraph,
                                 const NavigationGraphRoad& road,
                                 const Eegeo::v3& color,
                                 const float halfWidth);
                    
                    void AddFromConnections(std::vector<Eegeo::v3>& verts,
                                          std::vector<Eegeo::v3>& colors,
                                          std::vector<Eegeo::v2>& uvs,
                                          std::vector<u16>& indices,
                                          const NavigationGraph& navGraph,
                                          const NavigationGraphRoad& road,
                                          const Eegeo::v3& color,
                                          const float halfWidth);
                    
                    void AddLinkConnections(std::vector<Eegeo::v3>& verts,
                                            std::vector<Eegeo::v3>& colors,
                                            std::vector<Eegeo::v2>& uvs,
                                            std::vector<u16>& indices,
                                            const NavigationGraph& navGraph,
                                            const NavigationGraphRoad& road);
                    
                    
                    
                    DebugRendering::SphereMesh* AddSphere(Eegeo::Rendering::GLState& glState);
                    
                    std::vector<Eegeo::DebugRendering::SphereMesh*> m_singleVertexRoadSpheres;
                    
                    DebugRendering::DebugRenderable m_renderable;
                    Eegeo::dv3 m_pos;
                    Eegeo::v3 m_roadColor;
                    DebugNavigationGraphMeshConfig m_config;
                };
            }
        }
    }
}
