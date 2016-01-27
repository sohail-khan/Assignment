// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"

#include <streambuf>

namespace Eegeo
{
	template<typename T>
	class ArrayBuffer : public std::streambuf
	{
		typedef T type;
	public:
		ArrayBuffer(const type *begin, const type *end) :
			m_pBegin(begin),
			m_pEnd(end),
			m_pCurrent(m_pBegin)
		{
			Eegeo_ASSERT(std::less_equal<const type *>()(m_pBegin, m_pEnd), "The end pointer is less than the begin pointer");
		}

		explicit ArrayBuffer(const type *str) :
			m_pBegin(str),
			m_pEnd(m_pBegin + std::strlen(str)),
			m_pCurrent(m_pBegin)
		{
		}

	private:
		int_type underflow()
		{
			if (m_pCurrent == m_pEnd)
				return traits_type::eof();

			return traits_type::to_int_type(*m_pCurrent);
		}

		int_type uflow()
		{
			if (m_pCurrent == m_pEnd)
				return traits_type::eof();

			return traits_type::to_int_type(*m_pCurrent++);
		}

		int_type pbackfail(int_type ch)
		{
			if (m_pCurrent == m_pBegin || (ch != traits_type::eof() && ch != m_pCurrent[-1]))
				return traits_type::eof();

			return traits_type::to_int_type(*--m_pCurrent);
		}

		std::streamsize showmanyc()
		{
			Eegeo_ASSERT(std::less_equal<const type *>()(m_pCurrent, m_pEnd), "The end pointer is less than the begin pointer")
				return m_pEnd - m_pCurrent;
		}

	private:
		const type * const m_pBegin;
		const type * const m_pEnd;
		const type * m_pCurrent;
	};
}