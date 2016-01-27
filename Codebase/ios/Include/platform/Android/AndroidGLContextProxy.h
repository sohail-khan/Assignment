// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IGlTaskContextFactory.h"
#include "AndroidSharedGlContext.h"

namespace Eegeo
{
	namespace Android
	{
		class AndroidGlContextProxy : public Eegeo::Concurrency::Tasks::IGlTaskContext
		{
		public:
			AndroidGlContextProxy(AndroidSharedGlContext& sharedGLContext)
			: m_sharedGLContext(sharedGLContext)
			{
			}

			void CreateContext() { m_sharedGLContext.CreateContext(); }
			void SetContext() { m_sharedGLContext.SetContext(); }
			void FlushContext() { m_sharedGLContext.FlushContext(); }
			void Unbind() { m_sharedGLContext.Unbind(); }

		private:
			AndroidSharedGlContext& m_sharedGLContext;
		};
	}
}
