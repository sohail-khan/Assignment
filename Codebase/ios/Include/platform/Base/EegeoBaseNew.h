// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <new>
#include "Types.h"
#include "Allocator.h"

#define Eegeo_BASE_NEW(allocator, type)						new((void*)(allocator)->Alloc(__alignof(type), sizeof(type), __FILE__, __LINE__))type

template <typename T>
void Eegeo_BASE_DELETE(Eegeo::Allocator* pAllocator, T* data)
{
	if(data)
	{
		data->~T();
		pAllocator->Free(data);
		data = NULL;
	}
}

inline void* MemAllocArray(Eegeo::Allocator* pAllocator, size_t align, size_t typeSize, size_t num, const char* file, int line)
{
    
    
	void* 	pData	= pAllocator->Alloc(align, sizeof(size_t) + align + num * typeSize, file, line);
	size_t*	pDim	= static_cast<size_t*>(pData);
	
	*pDim	= num;
	size_t dataOffset = (align > sizeof(size_t)) ? align : sizeof(size_t);
	return static_cast<int*>(pData) + dataOffset;
}