// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

class IOSHelper
{
public:
	static size_t GetTaskTotalMemoryUsageInBytes	();
    static size_t GetTaskVirtualMemoryUsageInBytes();
    static size_t GetFreeMemoryInBytes();
    
    static const char* 	GetDocumentsFolder				();
	static const char* 	GetCachesFolder					();
	static const char* 	GetApplicationSupportFolder		(bool write);

};
