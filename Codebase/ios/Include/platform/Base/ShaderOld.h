// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Graphics.h"

namespace Eegeo
{
class Allocator;

class ShaderOld
{
public:
	enum Type
	{
		kVertexShader,
		kFragmentShader
	};

	ShaderOld						( Type type, const char* filename );
	ShaderOld						( Type type, Allocator* pAllocator, void* pData, u32 size );
	~ShaderOld						();

	GLuint			GetProgram	() const	{ return m_program; }

	void*			GetData		() const	{ return m_pData; }
	u32				GetSize		() const	{ return m_size; }
    Type            GetType     () const    { return m_type; }

private:
	Type			m_type;
	GLuint 			m_program;

	Allocator*		m_pAllocator;
	void*			m_pData;
	u32				m_size;
};

class GLShader
{
public:
	GLShader		( ShaderOld* pVS, ShaderOld* pFS);
	~GLShader		();

	int				GetUniformLocation		( const char* name );
	int				GetAttributeLocation	( const char* name );

	GLuint			GetProgram	() const	{ return m_program; }

private:
	ShaderOld*			m_pVS;
	ShaderOld*			m_pFS;
	GLuint			m_program;
};

}
