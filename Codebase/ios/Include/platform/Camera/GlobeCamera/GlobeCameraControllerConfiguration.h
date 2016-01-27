// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            //! Configuration constants for GlobeCameraController
            struct GlobeCameraControllerConfiguration
            {
                //! distance from camera to interest point in metres, above which "globe mode" is entered
                float globeModeZoomDistance;
                
                //! altitude in metres above sea level at which camera pitch angle interpolation begins
                float globeModeBeginPitchAltitude;
                
                //! altitude in metres above sea level at which camera pitch angle interpolation ends
                float globeModeEndPitchAltitude;
                
                //! altitude in metres above sea level at which camera field-of-view angle interpolation begins
                float globeModeBeginFOVChangeAltitude;
                
                //! altitude in metres above sea level at which camera field-of-view angle interpolation ends
                float globeModeEndFOVChangeAltitude;
                
                //! minimum tilt (towards horizon)
                float minimumTilt;
                
                //! pitch angle in degrees used at and below globeModeBeginPitchAltitude
                float pitchCityMode;
                
                //! pitch angle in degrees used at and above globeModeEndPitchAltitude
                float pitchGlobeMode;
                
                //! maximum camera altitude above sea level, metres
                float maxAltitude;
                
                //! altitude used in defining field of view and touch input sensitivity
                float zoomAltitudeLow;
                
                //! altitude used in defining field of view and touch input sensitivity
                float zoomAltitudeHigh;
                
                //! sensitivity scale of touch pinch-zoom gestures at or below zoomAltitudeLow
                float touchZoomScaleAtAltitudeLow;
                
                //! sensitivity scale of touch pinch-zoom gestures at or above zoomAltitudeHigh
                float touchZoomScaleAtAltitudeHigh;
                
                //! sensitivity scale of touch pan gestures at or below zoomAltitudeLow
                float touchPanScaleAtAltitudeLow;
                
                //! sensitivity scale of touch pan gestures at or above zoomAltitudeHigh
                float touchPanScaleAtAltitudeHigh;
                
                //! field of view in degrees used for altitudes at or below zoomAltitudeLow
                float fovZoomedInCity;
                
                //! field of view in degrees used at globeModeBeginFOVChangeAltitude
                float fovZoomedInGlobe;
                
                //! field of view in degrees used at or above globeModeEndFOVChangeAltitude
                float fovZoomedOutGlobe;
                
                //! at altitudes below this threshold, camera near and far clip plane distances are altered based on altitude
                //! in order to maximise z-buffer precision, minimising rendering artifacts due to z-order fighting
                float clipPlaneThresholdAltitude;
                
                //! animation time in seconds when transitioning from city to globe mode
                float transitionTimeToPolarPanHeadingSeconds;
                
                //! if true, attempt to keep the interest of the camera approximately on the Earth's terrain surface
                bool terrainFollowingEnabled;
                
                //! If true, automatically compute a near & far plane based on camera altitude, this is required for high altitude cameras
                //! due to depth precision balancing due to the size of our world space.
                bool computeNearFarPlanes;
                
                //! If computeNearFarPlanes is false, use this near plane value;
                float nearPlane;
                
                //! If computeNearFarPlanes is false, use this far plane value;
                float farPlane;
                
                //! The camera interest point is constrained to lie on the (bumpy) Earth's terrain, with interpolation applied to
                //! smooth out sudden discontinuities in terrain height. This parameter controls the amount of smoothing applied,
                //! with the interest point eventually settling onto the terrain after approximately
                //! (3 x altitudeSmoothingTimeConstant) seconds
                float altitudeSmoothingTimeConstant;
                
                //! maximum difference in height between current interest point and point on terrain.
                //! Beyond this delta, interest point snaps onto terrain surface without interpolation
                float altitudeSmoothingMaxHeightDelta;
                
                //! \param useLowLodSettings if true, values suitable for use on low performance hardware devices are used
                //! \return a GlobeCameraControllerConfiguration instance with fields set to default values
                static GlobeCameraControllerConfiguration CreateDefault(bool useLowLodSettings);
            };
        }
    }
}
