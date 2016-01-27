// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
	class Random
	{
		static const int N = 624;
        
		u32 		mt[N];
		int 		mti;
		
		void 	init_by_array	(u32 init_key[], int key_length);
		void 	init_genrand	(u32 s);
		u32 	genrand_u32		(void);
		
	public:
		Random					( u32 seed );
		u32		GetNumber		();
		float	GetFloat		();	
		float	GetFloat2		();	
		float	GetFloat		( float min, float max );	
	};
}