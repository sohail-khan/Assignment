#pragma once

#include <WinSock2.h>
#include <d3d9.h>
#define WIN32_LEAN_AND_MEAN
#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif

#include <atlbase.h>
#include <uv.h>

#undef near
#undef far
#undef ERROR
#undef DrawText
#undef FAR
#undef DeleteFile
#undef GetMessage

//for jmorecfg.h
//(jpeg.lib)
#define HAVE_BOOLEAN
#define XMD_H

#include <iterator>
#include <algorithm>
#include <functional>
#include <cctype>

#include <stdint.h>

//typedef struct timeval {
//	long tv_sec;
//	long tv_usec;
//} timeval;

static int gettimeofday(timeval * tp, struct timezone * tzp)
{
	static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

	SYSTEMTIME  system_time;
	FILETIME    file_time;
	uint64_t    time;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	time = ((uint64_t)file_time.dwLowDateTime);
	time += ((uint64_t)file_time.dwHighDateTime) << 32;

	tp->tv_sec = (long)((time - EPOCH) / 10000000L);
	tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
	return 0;
}