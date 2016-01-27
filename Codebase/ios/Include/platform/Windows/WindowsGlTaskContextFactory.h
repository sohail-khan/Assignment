// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "WindowsSharedGlContext.h"

namespace Eegeo
{
	namespace Windows
	{
		class WindowsGlTaskContextFactory : public Concurrency::Tasks::IGlTaskContextFactory
		{
		public:
			WindowsGlTaskContextFactory(EGLDisplay& display,
										EGLContext& context,
										EGLSurface& surface);

			~WindowsGlTaskContextFactory();

			Concurrency::Tasks::IGlTaskContext* Build();

			void UpdateSurface(EGLSurface& surface);
		private:
			EGLDisplay& m_display;
			EGLContext& m_context;
			EGLSurface& m_surface;

			Windows::WindowsSharedGlContext* m_pWindowsSharedGlContext;
		};
	}
}
