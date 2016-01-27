// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Graphics.h"
#include "EffectHandler.h"
#include "VectorMathDecl.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextra-semi"
namespace Eegeo
{
	inline u32 MakeRGBA(float r, float g, float b, float a)
	{
		return ((u32)(r*255.0f) << 0) | ((u32)(g*255.0f) << 8) | ((u32)(b*255.0f) << 16) | ((u32)(a*255.0f) << 24);
	}
    
    inline u32 MakeRGBA(const Eegeo::v4& rgba)
	{
		return MakeRGBA(rgba.GetX(), rgba.GetY(), rgba.GetZ(), rgba.GetW());
	}

enum
{
	kPrimCmdNumPrims,
	kPrimCmdVertexBuffer,
	kPrimCmdIndexBuffer,
	kPrimCmdVertexOffset,
	kPrimCmdIndexOffset,
	kPrimCmdVertexSize,
	kPrimCmdVertexFormat,
	kPrimCmdVertsPerPrim,
	kPrimCmdTopology,
	kPrimCmdOffsetAndScale,
	kPrimCmdViewScreen,
	kPrimCmdViewWorld,
	kPrimCmdTexture,
	kPrimCmdTextureBinding,

	kPrimCmdGLShader,
	kPrimCmdDepthWrite,
	kPrimCmdDepthTest,
	kPrimCmdBlendMode,
	kPrimCmdCullMode,

	kPrimCmdColourMask,
	kPrimCmStencilEnable,
	kPrimCmStencilFunc,
	kPrimCmStencilOp,

	kPrimCmdDraw,
};



class PrimCmdBuffer
{
public:
    typedef u64 u_ptr;
    
	PrimCmdBuffer		( u32 cmdBufferSize);

	~PrimCmdBuffer		();

	void	Reset		();
	void	Draw		( Eegeo::Rendering::GLState& glState, const Eegeo::m44& viewScreen, const Eegeo::m44& viewWorld, float screenWidth, float screenHeight );

	void	AddCmd		( u16 cmd );
	void	AddCmd		( u16 cmd, u_ptr data );
	void	AddCmd		( u16 cmd, u_ptr data, u_ptr data2 );
	void	AddCmd		( u16 cmd, u_ptr data, u_ptr data2, u_ptr data3 );
	void	AddCmd		( u16 cmd, u_ptr data, u_ptr data2, u_ptr data3, u_ptr data4 );
private:	
	u_ptr*				m_pCmdBuffer;

	u32					m_cmdBufferSize;
	u32					m_offset;
};




class ShaderOld;
class GLShader;
class PrimCmdBuffer;
class VertexFormat;

class Blitter
{
public:
    enum CullMode
    {
        kCullModeDisable,
        kCullModeCW,
        kCullModeCCW,
    };
    
    enum BlendMode
    {
        kBlendModeDisable,
        kBlendModeBlend,
        kBlendModeBlendImage,
        kBlendModeAdditive,
        kBlendModeModulate,
    };
    
    enum
    {
        kCompareNever		= GL_NEVER,
        kCompareAlways		= GL_ALWAYS,
        kCompareLess		= GL_LESS,
        kCompareLEqual		= GL_LEQUAL,
        kCompareEqual		= GL_EQUAL,
        kCompareGreater		= GL_GREATER,
        kCompareGEqual		= GL_GEQUAL,
        kCompareNotEqual	= GL_NOTEQUAL
    };
    
    enum
    {
        kStencilOpKeep		= GL_KEEP,
        kStencilOpReplace	= GL_REPLACE,
        kStencilOpIncr		= GL_INCR,
        kStencilOpDecr		= GL_DECR,
        kStencilOpInvert	= GL_INVERT,
        kStencilOpIncrWrap	= GL_INCR_WRAP,
        kStencilOpDecrWrap	= GL_DECR_WRAP
    };
    
    enum
    {
        kFaceFront			= GL_FRONT,
        kFaceBack			= GL_BACK,
        kFaceFrontAndBack	= GL_FRONT_AND_BACK
    };
    
    
	static const float	kDepthFront;
	static const float	kDepthBack;
	
	static void		Initialise		();
	static void		Shutdown		();
	static bool		IsInitialised	()	{ return m_isInitialised; }

    Blitter						( u32 sizeVB, u32 sizeIB, u32 sizeCmd, float screenWidth=0.f, float screenHeight=0.f);
	~Blitter					();

	template<typename T>
	void	Begin				( T*& pPrim, u32 numPrims );
	void	End					();

    void	Draw				( const Eegeo::m44& viewScreen, const Eegeo::m44& viewWorld, Rendering::GLState& glState, float screenWidth, float screenHeight);
	void	Reset				()	{ m_pPrimBuffer->Reset(); }

	void	SetTexture			(u32 textureHandle);
	void	SetDepthWrite		(bool enable);
	void	SetDepthTest		(u32 test);
	void	SetBlendMode		(u32 mode);
	void	SetCullMode			(u32 mode);

	void	SetColourMask		(bool enableR, bool enableG, bool enableB, bool enableA);
	void	SetStencilEnable	(bool enable);
	void	SetStencilFunc		(u32 func, s32 ref, u32 mask);
	void	SetStencilOp		(u32 fail, u32 zfail, u32 zpass);

	void	SetForce3D			(const bool force)	{ m_force3D = force; }
public:
	static bool					m_isInitialised;
    
	static ShaderOld*				m_pVertex2D;
	static ShaderOld*				m_pVertexTex2D;
	static ShaderOld*				m_pVertex3D;
	static ShaderOld*				m_pVertexTex3D;
	static ShaderOld*				m_pVertexFacingTex;
	static ShaderOld*				m_pFragment;
	static ShaderOld*				m_pFragmentTex;
	static ShaderOld*				m_pFragmentAlphaTex;

	static GLShader*			m_p2D;
	static GLShader*			m_p2DTex;
	static GLShader*			m_p2DAlphaTex;
	static GLShader*			m_p3D;
	static GLShader*			m_p3DTex;
	static GLShader*			m_p3DAlphaTex;
	static GLShader*			m_pFacingTex;

	static VertexFormat*		m_pVertex2DFormat;
	static VertexFormat*		m_pVertexTex2DFormat;
	static VertexFormat*		m_pVertex3DFormat;
	static VertexFormat*		m_pVertexTex3DFormat;
	static VertexFormat*		m_pVertexFacingTexFormat;

	static int					m_baseTexSampler2D;
	static int					m_baseAlphaTexSampler2D;
	static int					m_baseTexSampler3D;
	static int					m_baseAlphaTexSampler3D;
	static int					m_baseTexSamplerFacing;

	static int					m_offsetAndScale;
	static int					m_offsetAndScaleTex;
	static int					m_offsetAndScaleAlphaTex;

	static int					m_viewScreen;
	static int					m_viewScreenTex;
	static int					m_viewScreenAlphaTex;
	static int					m_viewScreenFacingTex;
	static int					m_viewWorldFacingTex;

	static bool					m_force3D;

private:

	PrimCmdBuffer*				m_pPrimBuffer;

	u32							m_offsetVB;
	u32							m_sizeVB;
	u8* m_pVB;
	
	u8* m_pIB;
	u32							m_offsetIB;
	u32							m_sizeIB;

	u32					m_texture;
};

	
struct Vertex
{
	float	m_x;
	float	m_y;
	float	m_z;

#if defined (FLOAT_COLOUR)
	float	m_r;
	float	m_g;
	float	m_b;
	float	m_a;
	void Set	(float x, float y, float z, float r, float g, float b, float a) { m_x=x; m_y=y; m_z=z; m_r=r; m_g=g; m_b=b; m_a=a;}
#else
	u32		m_colour;
	void Set	(float x, float y, float z, u32 colour) { m_x=x; m_y=y; m_z=z; m_colour=colour; }
	void Set	(float x, float y, float z, float r, float g, float b, float a) { m_x=x; m_y=y; m_z=z; m_colour = MakeRGBA(r,g,b,a);}
	
#endif
};

struct VertexTex
{
	float	m_x;
	float	m_y;
	float	m_z;
	float	m_u;
	float	m_v;

#if defined (FLOAT_COLOUR)
	float	m_r;
	float	m_g;
	float	m_b;
	float	m_a;
	void Set	(float x, float y, float z, float u, float v, float r, float g, float b, float a) { m_x=x; m_y=y; m_z=z; m_u=u; m_v=v; m_r=r; m_g=g; m_b=b; m_a=a;}
#else
	u32		m_colour;
	void Set	(float x, float y, float z, float u, float v, u32 colour) { m_x=x; m_y=y; m_z=z; m_u=u; m_v=v; m_colour=colour; }
	void Set	(float x, float y, float z, float u, float v, float r, float g, float b, float a) { m_x=x; m_y=y; m_z=z; m_u=u; m_v=v; m_colour=MakeRGBA(r,g,b,a);}
#endif
};

struct VertexFacingTex
{
	float	m_xCentre;
	float	m_yCentre;
	float	m_zCentre;

	float	m_u;
	float	m_v;

	float	m_xOffset;
	float	m_yOffset;
	float	m_rotation;

#if defined (FLOAT_COLOUR)
	float	m_r;
	float	m_g;
	float	m_b;
	float	m_a;
	void Set	(float x, float y, float z, float offsetx, float offsety, float rot, float u, float v, float r, float g, float b, float a) { m_xCentre=x; m_yCentre=y; m_zCentre=z; m_xOffset=offsetx; m_yOffset=offsety; m_rotation=rot; m_u=u; m_v=v; m_r=r; m_g=g; m_b=b; m_a=a; }
#else
	u32		m_colour;
	void Set	(float x, float y, float z, float offsetx, float offsety, float rot, float u, float v, u32 colour) { m_xCentre=x; m_yCentre=y; m_zCentre=z; m_xOffset=offsetx; m_yOffset=offsety; m_rotation=rot; m_u=u; m_v=v; m_colour=colour; }
#endif
};


#define PRIM_2D																						\
	static GLShader*			GetGLShader			()	{ return Blitter::m_p2D; }					\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_p3D; }					\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertex2DFormat; }		\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, static_cast<PrimCmdBuffer::u_ptr>(Blitter::m_offsetAndScale));			\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );											\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreen );							\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, -1 );											\
	}																								\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, -1 );											\
	}

#define PRIM_2D_TEX																					\
	static GLShader*			GetGLShader			()	{ return Blitter::m_p2DTex; }				\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_p3DTex; }				\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertexTex2DFormat; }	\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, static_cast<PrimCmdBuffer::u_ptr>(Blitter::m_offsetAndScaleTex ));			\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );											\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreen );							\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSampler2D );					\
	}																								\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSampler3D );					\
	}
	
#define PRIM_2D_ALPHATEX																			\
	static GLShader*			GetGLShader			()	{ return Blitter::m_p2DAlphaTex; }			\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_p3DAlphaTex; }			\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertexTex2DFormat; }	\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, static_cast<PrimCmdBuffer::u_ptr>(Blitter::m_offsetAndScaleAlphaTex ));	\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );											\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreenAlphaTex );							\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );												\
	}																								\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseAlphaTexSampler2D );			\
	}																								\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )					\
	{																								\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseAlphaTexSampler3D );			\
	}

#define PRIM_3D																							\
	static GLShader*			GetGLShader			()	{ return Blitter::m_p3D; }						\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_p3D; }						\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertex3DFormat; }			\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreen );								\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );													\
	}																									\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreen );								\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );													\
	}																									\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, -1 );												\
	}																									\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, -1 );												\
	}


#define PRIM_3D_TEX																						\
	static GLShader*			GetGLShader			()	{ return Blitter::m_p3DTex; }					\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_p3DTex; }					\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertexTex3DFormat; }		\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreenTex );							\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );													\
	}																									\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreen );								\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, -1 );													\
	}																									\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSampler3D );						\
	}																									\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSampler3D );						\
	}

#define PRIM_FACING_TEX																					\
	static GLShader*			GetGLShader			()	{ return Blitter::m_pFacingTex; }				\
	static GLShader*			GetGLShader3D		()	{ return Blitter::m_pFacingTex; }				\
	static VertexFormat*		GetFormat			()	{ return Blitter::m_pVertexFacingTexFormat; }	\
	static void					SetVSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreenFacingTex );						\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, Blitter::m_viewWorldFacingTex );						\
	}																									\
	static void					SetVSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdOffsetAndScale, -1 );												\
		pPrimBuffer->AddCmd( kPrimCmdViewScreen, Blitter::m_viewScreenFacingTex );						\
		pPrimBuffer->AddCmd( kPrimCmdViewWorld, Blitter::m_viewWorldFacingTex );						\
	}																									\
	static void					SetFSParam			( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSamplerFacing );					\
	}																									\
	static void					SetFSParam3D		( PrimCmdBuffer* pPrimBuffer )						\
	{																									\
		pPrimBuffer->AddCmd( kPrimCmdTextureBinding, Blitter::m_baseTexSamplerFacing );					\
	}
	

#define	PRIM_STRIP																\
	static const u32 m_indicesPerPrim	= 0;									\
	static const u32 m_vertsPerPrim		= 1;									\
	static const u32 m_topology			= GL_TRIANGLE_STRIP;

#define	PRIM_QUAD																\
	static const u32 m_indicesPerPrim	= 1;									\
	static const u32 m_vertsPerPrim		= 4;									\
	static const u32 m_topology			= GL_TRIANGLE_STRIP;

#define	PRIM_LINE																\
	static const u32 m_indicesPerPrim	= 0;									\
	static const u32 m_vertsPerPrim		= 2;									\
	static const u32 m_topology			= GL_LINES;

#define	PRIM_TRI																\
	static const u32 m_indicesPerPrim	= 0;									\
	static const u32 m_vertsPerPrim		= 3;									\
	static const u32 m_topology			= GL_TRIANGLES;

class Prim2DLine
{
public:
	Vertex	vertex[2];

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_LINE;
	PRIM_2D;
};

class Prim3DLine
{
public:
	Vertex	vertex[2];

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_LINE;
	PRIM_3D;
};

class Prim2DTri
{
public:
	Vertex	vertex[3];

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_TRI;
	PRIM_2D;
};

class Prim3DTri
{
public:
	Vertex	vertex[3];

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_TRI;
	PRIM_3D;
};

class Prim2DTriTex
{
public:
	VertexTex	vertex[3];

	static const u32 m_vertexSize	= sizeof(VertexTex);

	PRIM_TRI;
	PRIM_2D_TEX;
};

class Prim3DTriTex
{
public:
	VertexTex	vertex[3];

	static const u32 m_vertexSize	= sizeof(VertexTex);

	PRIM_TRI;
	PRIM_3D_TEX;
};

class Prim2DStrip
{
public:
	Vertex	vertex;

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_STRIP;
	PRIM_2D;
};

class Prim3DStrip
{
public:
	Vertex	vertex;

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_STRIP;
	PRIM_3D;
};

class Prim2DStripTex
{
public:
	VertexTex	vertex;

	static const u32 m_vertexSize	= sizeof(VertexTex);

	PRIM_STRIP;
	PRIM_2D_TEX;
};

class Prim3DStripTex
{
public:
	VertexTex	vertex;

	static const u32 m_vertexSize	= sizeof(VertexTex);

	PRIM_STRIP;
	PRIM_3D_TEX;
};

class Prim2DQuad
{
public:
	Vertex	vertex[4];

	static const u32 m_vertexSize	= sizeof(Vertex);

	PRIM_QUAD;
	PRIM_2D;
};

class Prim2DQuadTex
{
public:
	VertexTex	vertex[4];

	static const u32 m_vertexSize	= sizeof(VertexTex);

	PRIM_QUAD;
	PRIM_2D_TEX;
};

class Prim2DQuadAlphaTex
{
public:
	VertexTex	vertex[4];
		
	static const u32 m_vertexSize	= sizeof(VertexTex);
		
	PRIM_QUAD;
	PRIM_2D_ALPHATEX;
};

class Prim3DQuad
{
public:
	Vertex	vertex[4];
		
	static const u32 m_vertexSize	= sizeof(Vertex);
		
	PRIM_QUAD;
	PRIM_3D;
};
	
class Prim3DQuadTex
{
public:
	VertexTex	vertex[4];
		
	static const u32 m_vertexSize	= sizeof(VertexTex);
		
	PRIM_QUAD;
	PRIM_3D_TEX;
};

class PrimFacingTex
{
public:
	VertexFacingTex	vertex[4];

	static const u32 m_vertexSize	= sizeof(VertexFacingTex);

	PRIM_QUAD;
	PRIM_FACING_TEX;
};

template<typename T>
void Blitter::Begin( T*& pPrim, u32 numPrims )
{
    const int vertexSize = pPrim->m_vertexSize;
    const int vertsPrePrim = pPrim->m_vertsPerPrim;
    
	if((m_offsetVB + vertexSize * vertsPrePrim * numPrims) >= m_sizeVB)
	{
		m_offsetVB = 0;
	}

	pPrim	= (T*)(m_pVB + m_offsetVB);

	if (m_force3D)
	{
		m_pPrimBuffer->AddCmd( kPrimCmdGLShader, reinterpret_cast<PrimCmdBuffer::u_ptr>(pPrim->GetGLShader3D()));
	}
	else
	{
		m_pPrimBuffer->AddCmd( kPrimCmdGLShader, reinterpret_cast<PrimCmdBuffer::u_ptr>(pPrim->GetGLShader()));
	}
	
	m_pPrimBuffer->AddCmd( kPrimCmdNumPrims, numPrims );
	m_pPrimBuffer->AddCmd( kPrimCmdVertexBuffer, reinterpret_cast<PrimCmdBuffer::u_ptr>(m_pVB) );
	m_pPrimBuffer->AddCmd( kPrimCmdVertexOffset, m_offsetVB );
	m_pPrimBuffer->AddCmd( kPrimCmdVertexSize, pPrim->m_vertexSize );
	m_pPrimBuffer->AddCmd( kPrimCmdVertexFormat, reinterpret_cast<PrimCmdBuffer::u_ptr>(pPrim->GetFormat()) );
	m_pPrimBuffer->AddCmd( kPrimCmdVertsPerPrim, pPrim->m_vertsPerPrim);
	m_pPrimBuffer->AddCmd( kPrimCmdTopology, pPrim->m_topology);

	if (m_force3D)
	{
		pPrim->SetVSParam3D( m_pPrimBuffer );
		pPrim->SetFSParam3D( m_pPrimBuffer );
	}
	else
	{
		pPrim->SetVSParam( m_pPrimBuffer );
		pPrim->SetFSParam( m_pPrimBuffer );
	}
	

	if(pPrim->m_indicesPerPrim > 0)
	{
		if((m_offsetIB + 6 * numPrims * sizeof(u16)) >= m_sizeIB)
		{
			m_offsetIB = 0;
		}

		m_pPrimBuffer->AddCmd( kPrimCmdIndexBuffer, reinterpret_cast<PrimCmdBuffer::u_ptr>(m_pIB) );
		m_pPrimBuffer->AddCmd( kPrimCmdIndexOffset, m_offsetIB );

		u16* pData = (u16*)m_pIB;
		u32 offset = m_offsetIB/sizeof(u16);

		for(u16 i = 0; i < numPrims; i++)
		{

			if(i > 0)
			{
				pData[offset++] = i*4+0;
			}


			pData[offset++] = i*4+0;
			pData[offset++] = i*4+1;
			pData[offset++] = i*4+3;
			pData[offset++] = i*4+2;

			if(i < numPrims - 1)
			{
				pData[offset++] = i*4+2;
			}
		}

		m_offsetIB += sizeof(u16) * ((numPrims * 6) - 2);

	}
	else
	{
		m_pPrimBuffer->AddCmd( kPrimCmdIndexBuffer, reinterpret_cast<PrimCmdBuffer::u_ptr>((void*)NULL) );
		m_pPrimBuffer->AddCmd( kPrimCmdIndexOffset, 0 );
	}

	m_offsetVB	+= numPrims * sizeof(T);	
}

inline void Blitter::End()
{
	m_pPrimBuffer->AddCmd( kPrimCmdDraw, 0 );

}

inline void Blitter::SetTexture(u32 texture)
{
	Eegeo_ASSERT(texture);
	m_texture = texture;
	m_pPrimBuffer->AddCmd( kPrimCmdTexture, (u32)m_texture);
}

inline void Blitter::SetDepthWrite(bool enable)
{
	m_pPrimBuffer->AddCmd( kPrimCmdDepthWrite, static_cast<PrimCmdBuffer::u_ptr>(enable));
}

inline void Blitter::SetDepthTest(u32 test)
{
	m_pPrimBuffer->AddCmd( kPrimCmdDepthTest, static_cast<PrimCmdBuffer::u_ptr>(test));
}

inline void Blitter::SetBlendMode(u32 mode)
{
	m_pPrimBuffer->AddCmd( kPrimCmdBlendMode, static_cast<PrimCmdBuffer::u_ptr>(mode));
}

inline void Blitter::SetCullMode(u32 mode)
{
	m_pPrimBuffer->AddCmd( kPrimCmdCullMode, static_cast<PrimCmdBuffer::u_ptr>(mode));
}
	
inline void Blitter::SetColourMask(bool enableR, bool enableG, bool enableB, bool enableA)
{
	m_pPrimBuffer->AddCmd( kPrimCmdColourMask, static_cast<PrimCmdBuffer::u_ptr>(enableR), static_cast<PrimCmdBuffer::u_ptr>(enableG), static_cast<PrimCmdBuffer::u_ptr>(enableB), static_cast<PrimCmdBuffer::u_ptr>(enableA));
}

inline void Blitter::SetStencilEnable(bool enable)
{
	m_pPrimBuffer->AddCmd( kPrimCmStencilEnable, static_cast<PrimCmdBuffer::u_ptr>(enable));
}

inline void Blitter::SetStencilFunc(u32 func, s32 ref, u32 mask)
{
	m_pPrimBuffer->AddCmd( kPrimCmStencilFunc, static_cast<PrimCmdBuffer::u_ptr>(func), static_cast<PrimCmdBuffer::u_ptr>(ref), static_cast<PrimCmdBuffer::u_ptr>(mask));
}

inline void Blitter::SetStencilOp(u32 fail, u32 zfail, u32 zpass)
{
	m_pPrimBuffer->AddCmd( kPrimCmStencilOp, static_cast<PrimCmdBuffer::u_ptr>(fail), static_cast<PrimCmdBuffer::u_ptr>(zfail), static_cast<PrimCmdBuffer::u_ptr>(zpass));
}

inline void Blitter::Draw(const Eegeo::m44& viewScreen, const Eegeo::m44& viewWorld, Rendering::GLState& glState, float screenWidth, float screenHeight)
{
	EffectHandler::Reset();
	m_pPrimBuffer->Draw(glState, viewScreen, viewWorld, screenWidth, screenHeight);
}

	
	
}

#pragma clang diagnostic pop
