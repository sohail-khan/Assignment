// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "AnimatedObjects.h"
#include "Camera.h"
#include "DebugRendering.h"
#include "GlobeCamera.h"
#include "Culling.h"
#include "Helpers.h"
#include "Lighting.h"
#include "Location.h"
#include "AsyncTexturing.h"
#include "Resources.h"
#include "Buildings.h"
#include "CityThemes.h"
#include "PlaceNames.h"
#include "Roads.h"
#include "Navigation.h"
#include "Terrain.h"
#include "EegeoSearch.h"
#include "Space.h"
#include "Streaming.h"
#include "CoverageTrees.h"
#include "Traffic.h"
#include "TrafficCongestion.h"
#include "Web.h"
#include "GLHelpers.h"
#include "TextMeshes.h"
#include "AsyncModels.h"
#include "EegeoRootDeclarations.h"
#include "Weather.h"
#include "Routes.h"
#include "EegeoUI.h"
#include "Fonts.h"

//! Contains Eegeo Apps on Maps SDK for mobile
namespace Eegeo
{
    //! Creation, lifetime management and control of animated models
    namespace AnimatedObjects {}
    
    //! Android-specific platform types
    namespace Android {}

    //! Camera types and utilities
    namespace Camera
    {
        //! Camera controllers suitable for typical Apps on Maps
        namespace GlobeCamera {}
        
        //! Camera utility functions
        namespace CameraHelpers {}
    }

    //! View determination and frustum culling of renderable resources
    namespace Culling {}
    
    //! Utility types and functions for debugging and performance profiling
    namespace Debug {}
    
    //! Debug visualisation utilities
    namespace DebugRendering {}
    
    //! Geometric primitives, intersection queries, containment queries
    namespace Geometry {}
    
    //! Miscellaneous utility types and functions
    namespace Helpers {}
    
    //! Deserialisation of data formats
    namespace IO
    {
        //! PowerVR POD format deserialisation
        namespace POD {}
        
        //! Eegeo streamied resource format deserialisation
        namespace ChunkedFileFormat {}
    }

    //! iOS-specific platform types
    namespace iOS {}
    
    //! Process scheduling
    namespace Infrastructure {}
    
    //! Render lighting and fogging
    namespace Lighting {}
    
    //! Navigation and geographic concerns
    namespace Location {}

    //! Pins
    namespace Pins {}
    
    //! Rendering types, including materials and shaders
    namespace Rendering
    {

        //! asynchronous fetching and lifetime mangement of texture resources
        namespace AsyncTexturing {}
        
        //! Font-based geometry
        namespace Text {}
    }

    //! Streamed Apps on Maps resources
    namespace Resources
    {
        //! Building resources
        namespace Buildings {}
        
        //! Themed skinning of resources
        namespace CityThemes {}
        
        //! Place name resources
        namespace PlaceNames {}
        
        //! Road resources
        namespace Roads {}
        
        //! \deprecated
        //! Shadow geometry resources
        namespace Shadows {}
        
        //! Terrain resources
        namespace Terrain {}
    }
    
    //! Contains types and helper functions relating to Routes
    namespace Routes
    {
        //! Types concerned with transforming routes into multiple sections clipped against cell boundaries
        namespace Clipping {}
        
        //! Fitting routes against road and rail navigation graph resources
        namespace Fitting {}
        
        //! Contains types and helper functions relating to Route Simulation
        namespace Simulation
        {
            //! Contains types and helper functions relating to Route Simulation Camera Controllers
            namespace Camera {}
            
            //! Contains types and helper functions relating to Route Simulation View Binding
            namespace View {}
        }
        
        //! visual styling of rendered routes
        namespace Style
        {
            //! styling of thickness attribute
            namespace Thickness {}
        }
        
        //! Contains types and helper functions relating to Route Rendering
        namespace View {}
    }
    
    //! Contains types and helper functions relating to coordinate space manipulation
    namespace Space
    {
        //! Types and helper functions relating to projecting Earth sphere to and from a cube
        namespace CubeMap {}
    }
    
    //! View determination, fetching and level of detail management of streamed resources
    namespace Streaming
    {
        //! specification of area coverage for streamed resources sources
        namespace CoverageTrees {}
    }
    
    //! Traffic simulation and vehicle rendering
    namespace Traffic {}
    
    //! User interface
    namespace UI {}
    
    //! Unicode character support
    namespace Unicode
    {
        //! Utf-8 Unicode character encoding/decoding
        namespace Utf8 {}
    }
    
    //! Weather effects
    namespace Weather {}
    
    //! Internet connectivity and http services
    namespace Web {}
}
