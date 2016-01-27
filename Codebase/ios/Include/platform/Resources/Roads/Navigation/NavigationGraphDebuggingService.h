// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Navigation.h"
#include "Rendering.h"
#include "Camera.h"
#include "NavigationGraphAddedCallback.h"
#include "NavigationGraphRemovalCallback.h"
#include "DebugNavigationGraphMesh.h"
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace Roads
        {
            namespace Navigation
            {
                class NavigationGraphDebuggingService : public Eegeo::NonCopyable
                {
                    struct GraphAndMetadata
                    {
                        const NavigationGraph* graph;
                        int previousNumConnections;
                        DebugNavigationGraphMesh* debugNavGraphMesh;
                    };
                    
                    NavigationGraphRepository& m_navGraphRepo;
                    
                    bool m_debugVisualisation;
                    std::vector<GraphAndMetadata> m_graphs;
                    
                    DebugNavigationGraphMeshConfig m_config;
                    
                    TNavigationGraphAddedCallback<NavigationGraphDebuggingService> m_addedCallback;
                    TNavigationGraphRemovalCallback<NavigationGraphDebuggingService> m_removalCallback;
                    
                    void HandleNavGraphAdded(const NavigationGraph& navGraph);
                    void HandleNavGraphRemoved(const NavigationGraph& navGraph);
                    void BuildDebugNavigationGraphMeshVisualisation(GraphAndMetadata& graphAndMetadata, Eegeo::Rendering::GLState& glState);
                    void SetConfig(const DebugNavigationGraphMeshConfig& config) { m_config = config; }

                public:
                    NavigationGraphDebuggingService(
                                                    NavigationGraphRepository& navGraphRepo,
                                                    const DebugNavigationGraphMeshConfig& config);

                    virtual ~NavigationGraphDebuggingService();
                    
                    void ToggleDebuggingEnabled();
                    
                    void Draw(const Rendering::RenderContext& renderContext, Eegeo::Rendering::GLState& glState);

                    bool IsEnabled() const { return m_debugVisualisation; }
                    
                };
            }
        }
    }
}