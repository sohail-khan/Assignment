// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Blitter.h"
#include "Rendering.h"
#include "Helpers.h"
#include "Fonts.h"
#include "Camera.h"

namespace Eegeo
{
	namespace OSX
	{
		class OSXTextRenderer
		{
		private:
			Eegeo::Blitter& m_blitter;
			Eegeo::Helpers::IFileIO& m_fileIO;
			Eegeo::Helpers::ITextureFileLoader& m_textureFileLoader;
			Fonts::FontInstance* m_pFont;

		public:
			OSXTextRenderer(
					Eegeo::Blitter& blitter,
					Eegeo::Helpers::IFileIO& fileIO,
					Eegeo::Helpers::ITextureFileLoader& textureFileLoader);

			~OSXTextRenderer();

            void DrawText(const Camera::RenderCamera& renderCamera,
                          Rendering::GLState& glState,
                          const char* pText,
                          int x,
                          int y,
                          float screenWidth,
                          float screenHeight,
                          float scale=0.6f,
                          u32 color=Eegeo::MakeRGBA(1.0f, 0.0f, 0.7f, 1.0f));
		};
	}
}
