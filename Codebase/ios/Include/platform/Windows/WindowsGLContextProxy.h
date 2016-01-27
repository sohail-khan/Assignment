// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "WindowsSharedGlContext.h"

namespace Eegeo
{
	namespace Windows
	{
		class WindowsGlContextProxy : public Eegeo::Concurrency::Tasks::IGlTaskContext
		{
		public:
			WindowsGlContextProxy(WindowsSharedGlContext& sharedGLContext)
			: m_sharedGLContext(sharedGLContext)
			{
			}

			void CreateContext() { m_sharedGLContext.CreateContext(); }
			void SetContext() { m_sharedGLContext.SetContext(); }
			void FlushContext() { m_sharedGLContext.FlushContext(); }
			void Unbind() { m_sharedGLContext.Unbind(); }

		private:
			WindowsSharedGlContext& m_sharedGLContext;
		};
	}
}
