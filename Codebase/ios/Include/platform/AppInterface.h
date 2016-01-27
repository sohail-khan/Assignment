// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"

class AppInterface
{
public:
	struct RotateData
	{
		float rotation;
		float velocity;
		int numTouches;
	};
	
	struct PinchData
	{
		float scale;
	};

	struct PanData
	{
		Eegeo::v2 pointRelative;
		Eegeo::v2 pointAbsolute;
        Eegeo::v2 pointRelativeNormalized;
        Eegeo::v2 velocity;
        Eegeo::v2 touchExtents;
		int		numTouches;
        float majorScreenDimension;
	};

	struct TapData
	{
		Eegeo::v2 point;
	};

	struct TouchHeldData
	{
		Eegeo::v2 point;
	};

	struct TouchData
	{
		Eegeo::v2 point;
	};

	struct KeyboardData
	{
		char keyCode;
		u32 metaKeys;
		bool printable;
	};

	struct ZoomData
	{
		float distance;
	};

	struct TiltData
	{
		float distance;
		float screenHeight;
		float screenPercentageNormalized;
	};
};
