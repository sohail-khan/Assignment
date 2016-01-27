// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoPlatformMacros.h"

#if defined (EEGEO_WIN)
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include <float.h>


#define ARC4RANDOM_MAX      0x100000000
#define ARC4RANDOM_INVMAX   (1.0f/(float)ARC4RANDOM_MAX)

namespace Eegeo
{
	template <typename T>
	T Min(const T in1, const T in2)
	{
		if(in1 < in2)
		{
			return in1;
		}
		else
		{
			return in2;
		}
	}
    
	template <typename T>
	T Max(const T in1, const T in2)
	{
		if(in1 > in2)
		{
			return in1;
		}
		else
		{
			return in2;
		}
	}
    
	template <typename T>
	T Clamp(const T in, const T min, const T max)
	{
		if(in < min)
		{
			return min;
		}
		else if(in > max)
		{
			return max;
		}
		else
		{
			return in;
		}
	}
    
	namespace Math
	{
        // pi as float - use M_PI for double precision
		const float kPI			= static_cast<float>(M_PI);
		const float kFloatMax	= FLT_MAX;
        const float kEpsilon    = 0.0001f;
		
		inline double	Deg2Rad		( double deg )			{ return (deg * M_PI) / 180.0;}
		inline double	Rad2Deg		( double rad )			{ return (rad * 180.0) / M_PI;}
        
		inline float	Deg2Rad		( float deg )			{ return (deg * kPI) / 180.0f;}
		inline float	Rad2Deg		( float rad )			{ return (rad * 180.0f) / kPI;}
		inline float	Abs			( float x )				{ return fabsf(x); }
		inline float	Sin			( float theta )			{ return sinf(theta); }
		inline float	Cos			( float theta )			{ return cosf(theta); }
		inline float	Tan			( float theta )			{ return tanf(theta); }
		inline float	ASin		( float theta )			{ return asinf(theta); }
		inline float	ACos		( float theta )			{ return acosf(theta); }
		inline float	ATan		( float theta )			{ return atanf(theta); }
		inline float	ATan2		( float y, float x )	{ return atan2f(y, x); }
		
		inline float	Pow			( float x, float y )	{ return powf(x, y); }
		 
		inline float	Log			( float x )				{ return logf(x); }
		inline float	Exp			( float x )				{ return expf(x); }
		
		inline float	Sqrtf		( float x )				{ return sqrtf(x); }
        inline double	Sqrtd		( double x )			{ return sqrt(x); }

        inline float    Modf        ( float x, float* pI )  { return modff(x, pI); }
		
		float 			SmoothStep	( float in );
		float 			SmoothStep	( float min, float max, float in );
		
		float 			SmootherStep( float in );
		float 			SmootherStep( float min, float max, float in );

        inline float Clamp01(float x);
        inline double Clamp01(double x);

        inline float SinEaseInOut(float t);
        
        template <typename T>
        T Clamp(const T in, const T min, const T max)
        {
            return Eegeo::Clamp(in, min, max);
        }
        
        template <typename T>
        T Lerp(const T x, const T y, const T t);
        
        template <>
        inline float Lerp(const float x, const float y, const float t)
        {
            return x * (1.0f - t) + y * t;
        }
        
        template <>
        inline double Lerp(const double x, const double y, const double t)
        {
            return x * (1.0 - t) + y * t;
        }
	}

	inline float Math::SmoothStep(float in)
	{
		return in * in * (3.0f - 2.0f * in);
	}
	
	inline float Math::SmoothStep(float min, float max, float in)
	{
		in = ((in - min)/(max - min));
		
		if (in < 0.0f)
		{
			in = 0.0f;
		}
		else if (in > 1.0f)
		{
			in = 1.0f;
		}
		
		return in * in * (3.0f - 2.0f * in);
	}
	
	inline float Math::SmootherStep(float in)
	{
		return in * in * in * (in * (in * 6 - 15) + 10);
	}
	
	inline float Math::SmootherStep(float min, float max, float in)
	{
		in = ((in - min)/(max - min));
		
		if (in < 0.0f)
		{
			in = 0.0f;
		}
		else if (in > 1.0f)
		{
			in = 1.0f;
		}
		
		return in * in * in * (in * (in * 6 - 15) + 10);
	}
    
    inline float Math::Clamp01(float x)
    {
        return Clamp(x, 0.f, 1.f);
    }

    inline double Math::Clamp01(double x)
    {
        return Clamp(x, 0.0, 1.0);
    }
    
    inline float Math::SinEaseInOut(float t)
    {
        return 1.0f - 0.5f * (1.0f + Cos(t * kPI));
    }
}
