// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

enum GameDeviceType
{
    GAME_DEVICE_IPHONE1 = 0,
    GAME_DEVICE_IPHONE3G,
    GAME_DEVICE_IPHONE3GS,
    GAME_DEVICE_IPHONE4,
    GAME_DEVICE_IPHONE4S,
    GAME_DEVICE_IPHONE5,
    GAME_DEVICE_IPHONE5S,
    GAME_DEVICE_IPHONE6PLUS,
    GAME_DEVICE_IPHONE6,
    // IMPORTANT: Remember to update the following when adding new phone devices.
    GAME_DEVICE_LAST_PHONE = GAME_DEVICE_IPHONE6,
    
    GAME_DEVICE_IPOD1GEN,
    GAME_DEVICE_IPOD2GEN,
    GAME_DEVICE_IPOD3GEN,
    GAME_DEVICE_IPOD4GEN,
    GAME_DEVICE_IPOD5GEN,
    GAME_DEVICE_IPOD6GEN,
    // IMPORTANT: Remember to update the following when adding new small devices.
    GAME_DEVICE_LAST_SMALL_DEVICE = GAME_DEVICE_IPOD6GEN,
    
    GAME_DEVICE_IPAD1,
    GAME_DEVICE_IPAD2,
    GAME_DEVICE_IPAD3,
    GAME_DEVICE_IPAD4,
    GAME_DEVICE_IPADAIR,
    // IMPORTANT: Remember to update the following when adding new full sized ipad devices.
    GAME_DEVICE_LAST_FULL_SIZE_IPAD = GAME_DEVICE_IPAD4,
    
    GAME_DEVICE_IPADMINI_1GEN,
    GAME_DEVICE_IPADMINI_RETINA,
    GAME_DEVICE_SIMULATOR,
};

enum OrientationMode
{
    ORIENTATION_MODE_UNKNOWN,
    ORIENTATION_MODE_PORTRAIT,
    ORIENTATION_MODE_LANDSCAPE
};

class App
{
	static bool				m_gpsValid;
    static double           m_altitude;
    static double           m_speed;
	static double 			m_latitude;
	static double 			m_longitude;
    static double           m_heading;
	
    static u32				m_device;
    static bool             m_hasRetinaDisplay;

    static float            m_deviceDpi;
	
	static char*			m_versionString;
	static char*			m_buildString;

	static void				DeterminePlatform		();
    static bool             DetermineHasRetinaDisplay();
    
	
public:
	
	static void				Initialise				();
	static void				Shutdown				();
	
	static u32 				GetDevice 				();
    static bool             HasRetinaDisplay        ();
    static float            GetDeviceDpi            ();
	static bool 			IsDeviceSmall 			();
	static bool 			IsDevicePhone			();
    static bool             IsDeviceMultiCore       ();
    static OrientationMode  GetOrientationMode      ();
    static OrientationMode  DetermineOrientationMode();
    
    static int              GetMajorSystemVersion   ();
	
	static const char* 		GetVersionString 		()	{ return m_versionString; }
	static const char* 		GetBuildString 			()	{ return m_buildString; }
    
    static bool             IsVersionGreaterThan    (const char* version);
    static bool             IsVersionLessThan       (const char* version);

	static void 			LaunchBrowser			(const char* url);
	static void 			LaunchEMail				(const char* mailTo);
	static void 			LaunchPhone				(const char* number);
	static void 			LaunchSMS				(const char* number);
	
	static bool				IsGPSInfoValid			() { return m_gpsValid;}
	static void 			SetGPSInfo				(double altitude, double speed, double latitude, double longitude);
	static void 			GetGPSInfo				(double& altitude, double& speed, double& latitude, double& longitude);
	static void 			SetHeading				(double heading);
	static float 			GetHeading				();
	
	static void 			LongLatToMercator		(double lon, double lat, double& x, double& y);
	static void 			MercatorToLongLat		(double x, double y, double& lon, double& lat);
	
	static void 			LongLatOSGB36ToOSGrid	(double lon, double lat, double& x, double& y);
	static void 			OSGridToLongLatOSGB36	(double x, double y, double& lon, double& lat);
	
	static void 			ConvertOSGB36ToWGS84	(double inLon, double inLat, double& outLon, double& outLat);
	static void 			ConvertWGS84ToOSGB36	(double inLon, double inLat, double& outLon, double& outLat);

};
