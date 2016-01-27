// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#if defined (EEGEO_IOS)
#define TEXTURE2D(s, uv) "texture2D(" #s "," #uv ", -1.0)"
#else
#define TEXTURE2D(s, uv) "texture2D(" #s "," #uv ")"
#endif
#define EEGEO_ALPHA_TEST_VALUE "0.5"
