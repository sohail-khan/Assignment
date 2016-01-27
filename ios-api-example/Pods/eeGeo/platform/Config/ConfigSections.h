// Copyright eeGeo Ltd (2012-2014), All Rights Reserved
#pragma once

#include "InteriorsConfiguration.h"
#include "InteriorsPresentationModule.h"

#include <string>

namespace Eegeo
{
    namespace Config
    {
        static const std::string CoverageTreeManifestUrlDefault = "http://cdn1.eegeo.com/coverage-trees/vglobal/v867/manifest.bin.gz";
        static const std::string CityThemesManifestUrlDefault   = "http://d2xvsc8j92rfya.cloudfront.net/mobile-themes-new/v499/manifest.txt.gz";

        enum DeviceSpec
        {
            VeryLow,
            Low,
            Standard
        };

        /*!
         * \brief Config for controlling the coverage tree loading behaviour.
         *
         */
        struct CoverageTreeConfigSection
        {
            CoverageTreeConfigSection()
            : ManifestUrl(CoverageTreeManifestUrlDefault)
            , ManifestDownloadTimeoutInSeconds(0)
            {

            }

            explicit CoverageTreeConfigSection(const std::string& manifestUrl)
            : ManifestUrl(manifestUrl)
            , ManifestDownloadTimeoutInSeconds(0)
            {

            }

            std::string ManifestUrl;
            int ManifestDownloadTimeoutInSeconds;
        };

        /*!
         * \brief Config for controlling the city themes.
         *
         * This config lets you customize the theming of map tiles.
         *
         */
        struct CityThemesConfigSection
        {
            CityThemesConfigSection()
            : StreamedManifestUrl(CityThemesManifestUrlDefault)
            , EmbeddedThemeManifestFile("embedded_manifest.txt")
            , EmbeddedThemeTexturePath("Textures/EmbeddedTheme")
            , EmbeddedThemeNameContains("Summer")
            , EmbeddedThemeStateName("DayDefault")
            , StreamedThemeNameContains("Summer")
            , StreamedThemeStateName("DayDefault")
            {

            }

            CityThemesConfigSection(
                    const std::string& manifestUrl,
                    const std::string& embeddedThemeManifestFile,
                    const std::string& embeddedThemeTexturePath,
                    const std::string& embeddedThemeNameContains,
                    const std::string& embeddedThemeStateName,
                    const std::string& streamedThemeNameContains,
                    const std::string& streamedThemeStateName)
            : StreamedManifestUrl(manifestUrl)
            , EmbeddedThemeManifestFile(embeddedThemeManifestFile)
            , EmbeddedThemeTexturePath(embeddedThemeTexturePath)
            , EmbeddedThemeNameContains(embeddedThemeNameContains)
            , EmbeddedThemeStateName(embeddedThemeStateName)
            , StreamedThemeNameContains(streamedThemeNameContains)
            , StreamedThemeStateName(streamedThemeStateName)
            {

            }

            //! The url from which to load the manifest for the streamed city themes
            std::string StreamedManifestUrl;
            
            //! The local file from which to load the embedded theme
            std::string EmbeddedThemeManifestFile;
            
            //! The local path to the textures used by the embedded theme
            std::string EmbeddedThemeTexturePath;

            //! String that must appear in your embedded theme name (e.g., "Summer"). A theme name containing this string must exist in your embedded manifest.
            std::string EmbeddedThemeNameContains;

            //! The name of the embedded theme state that will be used on startup (e.g., "DayDefault"). This must exist in your embedded manifest.
            std::string EmbeddedThemeStateName;

            //! String that must appear in your streamed theme name (e.g., "Summer"). A theme name containing this string must exist in your streamed manifest.
            std::string StreamedThemeNameContains;

            //! The name of the streamed theme state that will be used once it has loaded (e.g., "DayDefault"). This must exist in your streamed manifest.
            std::string StreamedThemeStateName;
        };


        struct GraphicsConfigSection
        {
            bool BufferPoolingEnabled;
            bool ManuallyGenerateMipmapsFor565PixelType;

            GraphicsConfigSection()
            : BufferPoolingEnabled(true)
            , ManuallyGenerateMipmapsFor565PixelType(false)
            {

            }
        };

        struct PerformanceConfigSection
        {
            DeviceSpec DeviceSpecification;

            PerformanceConfigSection()
            : DeviceSpecification(Eegeo::Config::Standard)
            {

            }
        };
        
        struct CompatibilityConfigSection
        {
            bool Requires_Cpp11_Runtime_Fix;
            
            CompatibilityConfigSection()
            : Requires_Cpp11_Runtime_Fix(false)
            {
                
            }
        };
        
        struct OptionsConfigSection
        {
            //! if false, app is responsible for manually starting Eegeo::Modules::Map::MapModule by calling MapModule::Start()
            bool StartMapModuleAutomatically;
            
            //! if true, collision-detection structures will be generated for all map resources types, where source data provides collision
            //! if false, collision-detection structures will only be generated for terrain
            bool GenerateCollisionForAllResources;
            
            bool EnableInteriors;
            
            //! if true, platform will create a set material instance for use by interiors; if false, app is reponsible for creating and registering these
            bool CreateDefaultInteriorMaterials;
            
            //! If true, interiors will be flattened by the environment flattening system, otherwise they will remain unflattened. Default is true.
            bool InteriorsAffectedByFlattening;
            
            OptionsConfigSection()
            : StartMapModuleAutomatically(true)
            , GenerateCollisionForAllResources(false)
            , EnableInteriors(true)
            , CreateDefaultInteriorMaterials(true)
            , InteriorsAffectedByFlattening(false)
            {
                
            }
        };
        
        struct MapLayersConfigSection
        {
            Resources::Interiors::InteriorsConfiguration Interiors;
            
            MapLayersConfigSection()
            : Interiors(Modules::Map::Layers::InteriorsPresentationModule::DefaultConfig())
            {
                
            }
        };
    }
}

