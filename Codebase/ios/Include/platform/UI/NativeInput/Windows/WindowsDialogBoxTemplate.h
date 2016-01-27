// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once
#include "Types.h"


namespace Eegeo
{
	class DialogTemplate
	{
	public:
		void AlignToDword()
		{
			if (v.size() % 4) Write(NULL, 4 - (v.size() % 4));
		}

		void Write(LPCVOID pvWrite, DWORD cbWrite)
		{
			v.insert(v.end(), cbWrite, 0);
			if (pvWrite) CopyMemory(&v[v.size() - cbWrite], pvWrite, cbWrite);
		}

		template<typename T> void Write(T t) { Write(&t, sizeof(T)); }
		void WriteString(LPCWSTR psz)
		{
			Write(psz, (lstrlenW(psz) + 1) * sizeof(WCHAR));
		}


		const std::vector<BYTE>& GetBuffer() const
		{
			return v;
		}
	private:
		std::vector<BYTE> v;
	};
}