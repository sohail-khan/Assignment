// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
class ShaderOld;
class GLShader;

struct FormatDataGL
{
	int			attribBinding;
	u32			number;
	u32			type;
	u32			offset;
};

class VertexFormat
{
public:
	enum Format
	{
		kFloat1,
		kFloat2,
		kFloat3,
		kFloat4,
		kByte4,

		kU32,
	};

	struct FormatData
	{
		const char* semanticName;
		u32			semanticIndex;
		u32			format;
		u32			stream;
		u32			offset;
	};

	VertexFormat						( u32 numAttributes, const FormatData* pAttributeData, GLShader* pShader );
	~VertexFormat						();

	static u32 ConvertFormat			( u32& type, u32& number, const u32 format );

	u32 			m_numAttributes;
	FormatDataGL*	m_pAttributeData;
	u32				m_stride;

};

}
