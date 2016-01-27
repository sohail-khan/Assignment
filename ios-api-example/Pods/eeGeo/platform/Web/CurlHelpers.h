#pragma once

#include <curl.h>
#include "Types.h"

#define CHECK_CURL_E(x) \
    if(x != CURLE_OK) \
    { \
        Eegeo_ASSERT(false, "CURL_E Error: %d", x); \
    }

#define CHECK_CURL_M(x) \
    if(x != CURLM_OK) \
    { \
        Eegeo_ASSERT(false, "CURL_M Error: %d", x); \
    }

#define CHECK_UV(x) \
    if(x < 0) \
    { \
        Eegeo_ASSERT(false, "UV error name: %s", uv_err_name(x)); \
    }
