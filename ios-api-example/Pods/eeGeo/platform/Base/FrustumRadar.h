// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"

namespace Eegeo
{
    struct BoundingBox;
    
	enum
	{
		kVisible	= 0x01,
		kMinX		= 0x02,
		kMaxX		= 0x04,
		kMinY		= 0x08,
		kMaxY		= 0x10,
		kMinZ		= 0x20,
		kMaxZ		= 0x40,
	};
	
	enum
	{
		kResultOutside,
		kResultInside,
		kResultClipped,
		kResultInvalid = 0xff,
	};
	
	class FrustumRadar
	{
		Eegeo::m44	m_world;
		
		float		m_nearD;
		float		m_farD;
		
		float		m_tang;
		float		m_sphereX;
		float		m_sphereY;
		
		float		m_ratio;
		float		m_width;
		float		m_height;
		
	public:
		FrustumRadar(const Eegeo::m44& world, float fov, float _near, float _far, float _ratio);
		
		u32 TestPoint(const Eegeo::v3& point);
		u32 GetPointVisibilty(const Eegeo::v3& point);
		
		u32 TestBoundingBox(const BoundingBox& box);
		u32 TestSphere(const Eegeo::v3& point, float radius);
		
#if MATH_NEON && !TARGET_IPHONE_SIMULATOR
		u32 TestBoundingBoxNeon(const BoundingBox& box);
		u32 TestSphereNeon(const Eegeo::v3& point, float radius);
#else
		u32 TestBoundingBoxNonNeon(const BoundingBox& box);
		u32 TestSphereNonNeon(const Eegeo::v3& point, float radius);
#endif
		
		const Eegeo::m44&	getWorld() const { return m_world; }
	};
	
	inline u32 FrustumRadar::TestBoundingBox(const BoundingBox& box)
	{
#if MATH_NEON && !TARGET_IPHONE_SIMULATOR
		return TestBoundingBoxNeon(box);
#else
		return TestBoundingBoxNonNeon(box);
#endif
	}

	inline u32 FrustumRadar::TestSphere(const Eegeo::v3& point, float radius)
	{
#if MATH_NEON && !TARGET_IPHONE_SIMULATOR
		return TestSphereNeon(point, radius);
#else
		return TestSphereNonNeon(point, radius);
#endif
	}
}
