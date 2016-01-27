// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContext.h"
#include "Graphics.h"

namespace Eegeo
{
	namespace Windows
	{
		class WindowsSharedGlContext : public Eegeo::Concurrency::Tasks::IGlTaskContext
		{
		public:
			WindowsSharedGlContext(EGLDisplay display, EGLContext context, EGLSurface surface);
            void CreateContext();
            void SetContext();
            void FlushContext();
            void Unbind();

            void UpdateSurface(EGLSurface surface);

		private:
			EGLContext m_context;
			EGLDisplay m_display;
			EGLSurface m_surface;
		};
	}
}
