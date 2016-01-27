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
	namespace Windows
	{
		class WindowsTextRenderer
		{
		private:
			Eegeo::Blitter& blitter;
			Eegeo::Helpers::IFileIO& fileIO;
			Eegeo::Helpers::ITextureFileLoader& textureFileLoader;
			Fonts::FontInstance* m_pFont;

		public:
			WindowsTextRenderer(
					Eegeo::Blitter& blitter,
					Eegeo::Helpers::IFileIO& fileIO,
					Eegeo::Helpers::ITextureFileLoader& textureFileLoader);

			~WindowsTextRenderer();

			void DrawText(const Eegeo::Camera::RenderCamera& renderCamera, Eegeo::Rendering::GLState& glState, int screenWidth, int screenHeight, const char* pText, int x, int y, float scale=0.6f, u32 color=Eegeo::MakeRGBA(1.0f, 0.0f, 0.7f, 1.0f));
		};
	}
}
