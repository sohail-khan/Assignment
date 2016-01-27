// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
	struct BoundingBox
	{
		Eegeo::v3	corners[8];
		
		void Set(const Eegeo::v3& min, const Eegeo::v3& max);
		void Set(const Eegeo::v3& min, const Eegeo::v3& max, const Eegeo::m44& world);
		void Set(const Eegeo::v3& min, const Eegeo::v3& max, const Eegeo::v3& worldPos);
	};
}