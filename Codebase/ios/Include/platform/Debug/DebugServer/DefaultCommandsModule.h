#pragma once

#include "Types.h"
#include "EegeoWorld.h"
#include "CommandRegistry.h"
#include "CommandTerminal.h"

#include "HelpCommand.h"
#include "ListCommandsCommand.h"
#include "EchoCommand.h"

#include "FpsStatsCommand.h"
#include "ResetStatsCommand.h"
#include "MemStatsCommand.h"
#include "NetStatsCommand.h"
#include "RenderStatsCommand.h"

#include "StreamToggleCommand.h"
#include "StreamListCommand.h"
#include "StreamStatsCommand.h"

#include "CameraLocationCommand.h"
#include "CameraTiltToggleCommand.h"
#include "CameraJumpCommand.h"

#include "RoadNamesOpacityCommand.h"

#include "TransportPresentationModule.h"
#include "PlaceNamesPresentationModule.h"

#include "SetCongestionCommand.h"

#include "PrecacheCancelCommand.h"
#include "PrecacheStatusCommand.h"
#include "PrecacheViewCommand.h"

#include "DrawDebugLineCommand.h"
#include "DrawDebugTextCommand.h"
#include "DrawDebugSphereCommand.h"

#include "NewRouteCommand.h"
#include "RouteFittingCommand.h"

#include "StreamingModule.h"
#include "DebugRenderingModule.h"

#include "ProfileShowCommand.h"
#include "ProfileEnableCommand.h"
#include "PlaceNamesEnableCommand.h"
#include "PerformanceTestBeginCommand.h"
#include "PerformanceTestRunner.h"
#include "PerformanceTestRegisterSplineCommand.h"

#include "SetShadowColorCommand.h"
#include "SetLightColorCommand.h"
#include "DumpLightingCommand.h"
#include "SysInfoCommand.h"

#include "ChangeThemeStateCommand.h"
#include "CityThemesModule.h"
#include "WebCacheClearCommand.h"
#include "SetWebProxyCommand.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace DebugServer
        {
            class DefaultCommandsModule : protected Eegeo::NonCopyable
            {
            public:
                DefaultCommandsModule(EegeoWorld& world,
                                      Debug::IDebugStats& debugStats,
                                      Eegeo::Camera::GlobeCamera::GlobeCameraController& globeCameraController,
                                      Eegeo::Camera::ICameraJumpController& cameraJumpController,
                                      Eegeo::Streaming::IFrustumVolumeProvider& frustumVolumeProvider,
                                      Eegeo::Routes::IRouteCreator& routeCreator,
                                      Eegeo::Debug::Profile::PerformanceTestRunner& perfTestRunner,
                                      Commands::CommandRegistry& commandRegistry)

                : m_world(world)
                , m_debugStats(debugStats)
                , m_globeCameraController(globeCameraController)
                , m_cameraJumpController(cameraJumpController)
                , m_routeCreator(routeCreator)
                , m_frustumVolumeProvider(frustumVolumeProvider)
                , m_performanceTestRunner(perfTestRunner)
                , m_registry(commandRegistry)
                {
                    AddDefaultCommands();
                }
                
                ~DefaultCommandsModule()
                {
                    for (std::vector<Commands::Command*>::iterator it = m_defaultCommands.begin();
                         it != m_defaultCommands.end();
                         ++it)
                    {
                        Eegeo_DELETE (*it);
                    }
                    
                    m_defaultCommands.clear();
                }
                
            private:
                void AddDefaultCommands()
                {
                    AddCommand(Eegeo_NEW(Commands::HelpCommand)(m_registry));
                    AddCommand(Eegeo_NEW(Commands::EchoCommand)());
                    AddCommand(Eegeo_NEW(Commands::ListCommandsCommand)(m_registry));
                    
                    AddCommand(Eegeo_NEW(Commands::Stats::FpsStatsCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Stats::ResetStatsCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Stats::MemStatsCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Stats::NetStatsCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Stats::RenderStatsCommand)(m_debugStats));
                    
                    Modules::Map::StreamingModule& streamingModule = m_world.GetStreamingModule();
                    
                    AddCommand(Eegeo_NEW(Commands::Stream::StreamToggleCommand)(streamingModule.GetStreamingController()));
                    AddCommand(Eegeo_NEW(Commands::Stream::StreamListCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Stream::StreamStatsCommand)(m_debugStats, streamingModule.GetPayloadPool()));
                    
                    AddCommand(Eegeo_NEW(Commands::Camera::CameraLocationCommand)(m_debugStats));
                    AddCommand(Eegeo_NEW(Commands::Camera::CameraTiltToggleCommand)(m_globeCameraController));
                    AddCommand(Eegeo_NEW(Commands::Camera::CameraJumpCommand)(m_cameraJumpController));

                    Modules::Map::Layers::TransportPresentationModule& transportPresentationModule = m_world.GetTransportPresentationModule();
                    Modules::TrafficModule& trafficModule = m_world.GetTrafficModule();
                    
                    AddCommand(Eegeo_NEW(Commands::Roads::RoadNamesOpacityCommand)(transportPresentationModule.GetRoadNamesFadeController()));
                    AddCommand(Eegeo_NEW(Commands::TrafficCongestion::SetCongestionCommand)(trafficModule.GetTrafficCongestionService()));
                    
                    AddCommand(Eegeo_NEW(Commands::Precache::PrecacheCancelCommand)(streamingModule.GetPrecachingService()));
                    AddCommand(Eegeo_NEW(Commands::Precache::PrecacheStatusCommand)(streamingModule.GetPrecachingService()));
                    AddCommand(Eegeo_NEW(Commands::Precache::PrecacheViewCommand)(streamingModule.GetPrecachingService(),
                                                                                  m_frustumVolumeProvider));
                    
                    Modules::Core::DebugRenderingModule& debugRenderingModule = m_world.GetDebugRenderingModule();
                    
                    AddCommand(Eegeo_NEW(Commands::Rendering::DrawDebugLineCommand)(debugRenderingModule.GetDebugRenderer()));
                    AddCommand(Eegeo_NEW(Commands::Rendering::DrawDebugTextCommand)(debugRenderingModule.GetDebugRenderer()));
                    AddCommand(Eegeo_NEW(Commands::Rendering::DrawDebugSphereCommand)(debugRenderingModule.GetDebugRenderer()));
                    
                    AddCommand(Eegeo_NEW(Commands::Routes::NewRouteCommand)(m_routeCreator, m_cameraJumpController));
                    AddCommand(Eegeo_NEW(Commands::Routes::RouteFittingCommand)(m_routeCreator));
                    
                    AddCommand(Eegeo_NEW(Commands::Profile::ProfileShowCommand)(m_world.GetProfiler()));
                    AddCommand(Eegeo_NEW(Commands::Profile::ProfileEnableCommand)(m_world.GetProfiler()));
                    AddCommand(Eegeo_NEW(Commands::Profile::PerformanceTestRegisterSplineCommand)(m_performanceTestRunner));
                    AddCommand(Eegeo_NEW(Commands::Profile::PerformanceTestBeginCommand)(m_performanceTestRunner));

                    Modules::Map::Layers::PlaceNamesPresentationModule& placenamesPresentationModule = m_world.GetPlaceNamesPresentationModule();
                    AddCommand(Eegeo_NEW(Commands::PlaceNames::PlaceNamesEnableCommand)(placenamesPresentationModule.GetPlaceNamesViewFilter()));
                    
                    Eegeo::Resources::CityThemes::ThemeStateController& themeStateController = m_world.GetCityThemesModule().GetThemeStateController();
                    AddCommand(Eegeo_NEW(Commands::Lighting::SetShadowColorCommand)(themeStateController));
                    AddCommand(Eegeo_NEW(Commands::Lighting::SetLightColorCommand)(themeStateController));
                    AddCommand(Eegeo_NEW(Commands::Lighting::DumpLightingCommand)(themeStateController));
                    AddCommand(Eegeo_NEW(Commands::SysInfoCommand)());
                    
                    AddCommand(Eegeo_NEW(Commands::Themes::ChangeThemeStateCommand(m_world.GetCityThemesModule().GetCityThemesService())));

                    AddCommand(Eegeo_NEW(Commands::Web::WebCacheClearCommand)(m_world.GetPlatformAbstractionModule().GetHttpCache()));
                    AddCommand(Eegeo_NEW(Commands::Web::SetWebProxyCommand)(m_world.GetPlatformAbstractionModule().GetProxySettings()));
                }
                
                void AddCommand(Commands::Command* command)
                {
                    m_registry.RegisterCommand(command);
                    m_defaultCommands.push_back(command);
                }

                EegeoWorld& m_world;
                Eegeo::Camera::GlobeCamera::GlobeCameraController& m_globeCameraController;
                Eegeo::Camera::ICameraJumpController& m_cameraJumpController;
                Eegeo::Routes::IRouteCreator& m_routeCreator;
                Eegeo::Streaming::IFrustumVolumeProvider& m_frustumVolumeProvider;
                Debug::IDebugStats& m_debugStats;
                Eegeo::Debug::Profile::PerformanceTestRunner& m_performanceTestRunner;
                Commands::CommandRegistry& m_registry;
                std::vector<Commands::Command*> m_defaultCommands;
            };
        }
    }
}