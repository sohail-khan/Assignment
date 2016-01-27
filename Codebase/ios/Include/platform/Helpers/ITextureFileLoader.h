// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Helpers.h"
#include "Types.h"
#include "GLHelpers.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Helpers
	{
        class ITextureFileLoader
		{
		public:
			virtual ~ITextureFileLoader() { }

			virtual bool LoadTexture(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& fileName, bool mipmap=false)=0;
            virtual bool LoadFromBuffer(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& fileExtension, const Byte* resourceBuffer, size_t bufferSizeBytes, bool mipmap=false)=0;
            virtual bool LoadFromCubeFaces(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo, const CubeFaceFileNames& cubeFaceFileNames)=0;
		};
	}
}