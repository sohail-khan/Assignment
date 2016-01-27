// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "AndroidSharedGlContext.h"

namespace Eegeo
{
	namespace Android
	{
		class AndroidGlTaskContextFactory : public Concurrency::Tasks::IGlTaskContextFactory
		{
		public:
			AndroidGlTaskContextFactory(EGLDisplay& display,
										EGLContext& context,
										EGLSurface& surface);

			~AndroidGlTaskContextFactory();

			Concurrency::Tasks::IGlTaskContext* Build();

			void UpdateSurface(EGLSurface& surface);
		private:
			EGLDisplay& m_display;
			EGLContext& m_context;
			EGLSurface& m_surface;

			Android::AndroidSharedGlContext* m_pAndroidSharedGlContext;
		};
	}
}
