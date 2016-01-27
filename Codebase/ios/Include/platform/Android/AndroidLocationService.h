// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <jni.h>
#include "ILocationService.h"
#include "Types.h"

struct AndroidNativeState;

namespace Eegeo
{
	namespace Android
	{
		class AndroidLocationService : public Eegeo::Location::ILocationService, protected Eegeo::NonCopyable
		{
	        private:
	            double latRadians;
	            double lonRadians;
	            double altitudeMeters;
	            double horizontalAccuracyMeters;
	            double headingDegrees;
	            bool hasLocation;
	            bool hasAccuracy;
	            bool hasAltitude;
	            bool hasHeading;
	            bool isAuthorized;

	            AndroidNativeState* pState;

	            void UpdateLatLongFromJNI();
	            void UpdateHeadingFromJNI();

	            jclass m_locationServiceClass;
	            jclass m_headingServiceClass;
	            jobject m_headingServiceInstance;

	        public:
	            AndroidLocationService(AndroidNativeState* pState);
	            ~AndroidLocationService();

	            void StopListening();

	            const bool GetIsAuthorized() const { return isAuthorized; }
	            bool GetLocation(Eegeo::Space::LatLong& latlong);
	            bool GetAltitude(double& altitude);
	            bool GetHorizontalAccuracy(double& accuracy);
	            bool GetHeadingDegrees(double& headingDegrees);
		};
	}
}
