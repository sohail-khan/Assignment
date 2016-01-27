// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"

namespace Eegeo
{
	class Quaternion
	{
    public:
    	float x, y, z, w;
        
        Quaternion              ();
        Quaternion              (float nx, float ny, float nz, float nw);
		
		void Identity 			();
		void Normalise 			();
		
		void Set 				(const Eegeo::v3& v3Axis, float angle);
		void GetAxisAngle 		(Eegeo::v3& v3Axis, float& angle) const;
		void GetMatrix 			(Eegeo::m44& matrix) const;
        Eegeo::v3 RotatePoint 	(Eegeo::v3 point) const;
		
		static void Multiply 	(Quaternion& dest, const Quaternion& source1, const Quaternion& source2);
		static void Slerp 		(Quaternion& dest, const Quaternion& source1, const Quaternion& source2, float delta);
        
        static Quaternion ExtractQuaternion(const Eegeo::m33 & inMat);
        static void ExtractQuaternion(Quaternion& outQuat, const Eegeo::m33 & inMat);
        
        static Quaternion CreateIdentity();
	};

}
