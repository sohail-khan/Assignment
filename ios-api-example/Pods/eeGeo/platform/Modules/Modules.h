// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class CoreModule;
            class RenderingModule;
            class LightingModule;
            class FontsModule;
            class AsyncLoadersModule;
            class DebugRenderingModule;
            class SceneModelsModule;
        }
        
        namespace Map
        {
            class MapModule;
            class StreamingModule;
            class CoverageTreeModule;
            class WeatherModule;
            class EnvironmentMaterialModule;
            class CityThemesModule;
            class MapDebugModule;

            namespace Layers
            {
                class TerrainStreamingModule;
                class TerrainModelModule;
                class TerrainPresentationModule;

                class BuildingStreamingModule;
                class BuildingModelModule;
                class BuildingPresentationModule;

                class TransportStreamingModule;
                class TransportModelModule;
                class TransportPresentationModule;

                class PlaceNamesStreamingModule;
                class PlaceNamesPresentationModule;
                class PlaceNamesModelModule;
                
                class InteriorsModelModule;
                class InteriorsPresentationModule;
                class InteriorsStreamingModule;
                
                class ShadowModelModule;
                class ShadowPresentationModule;
            }
        }
        
        namespace Data
        {
            class DataModule;
            class GeofenceModule;
            class PolyChartModule;
        }
        
        class RoutesModule;
        class TrafficModule;
        class AnimatedObjectsModule;
        class FireworksModule;
        class DataModule;
        class BuildingFootprintsModule;
        class CollisionVisualizationModule;
        
        class IPlatformAbstractionModule;
        
        class SQLiteModule;
    }
    
    namespace iOS
    {
        class iOSPlatformAbstractionModule;
    }
    
    namespace Android
    {
        class AndroidPlatformAbstractionModule;
    }

	namespace Windows
	{
		class WindowsPlatformAbstractionModule;
	}
}
