// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <ostream>

namespace Eegeo
{
	namespace Io
	{
		namespace BinarySerialization
		{
			template <class T>
			size_t Write(const T& value, std::ostream& writer)
			{
				writer.write(reinterpret_cast<const char*>(&value), sizeof(T));
				return sizeof(T);
			}

			void WriteFourCC(const std::string& s, std::ostream& writer);
			size_t WriteShortString(const std::string& s, std::ostream& writer);
			void WriteTimeT_u32(time_t v, std::ostream& writer);
			void WriteSizeT_u32(size_t v, std::ostream& writer);
		}
	}
}
