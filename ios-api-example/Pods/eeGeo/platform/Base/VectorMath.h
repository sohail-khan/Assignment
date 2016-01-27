// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MathFunc.h"
#include "VectorMathDecl.h"
#include <cmath>

#include <cstring>

namespace Eegeo
{	
	class v2
	{
    public:
		float	x;
		float	y;

		v2		( ) {};
		v2		( const v2& src );
		v2		( float x, float y );
		v2		( float* pSrc );
		
		void	Set		( const v2& src );
		void	Set		( float x, float y );
		void	SetZero	();
		
		float	GetX	() const;
		float	GetY	() const;
		
		void	SetX	( float data );
		void	SetY	( float data );

		v2		SplatX	() const;
		v2		SplatY	() const;
		
		static v2 Add	( const v2& src1, const v2& src2 );
		static v2 Sub	( const v2& src1, const v2& src2 );
		static v2 Mul	( const v2& src1, const v2& src2 );
		static v2 Div	( const v2& src1, const v2& src2 );
		
		static v2 Scale		( const v2& src1, float scale );
		static v2 InvScale	( const v2& src1, float scale );
		
		static v2 Neg		( const v2& src );
		
		static float Dot	( const v2& src1, const v2& src2 );
		
		static v2 Lerp		( const v2& src1, const v2& src2, float ratio );
		
		float		Length		() const;
		float		LengthSq	() const;
		v2			Norm		() const;
		
		v2 operator -	( ) const;
		
		v2 operator +	( const v2& rhs ) const;
		v2 operator -	( const v2& rhs ) const;
		v2 operator *	( const v2& rhs ) const;
		v2 operator /	( const v2& rhs ) const;
		v2 operator *	( const float rhs ) const;
		v2 operator /	( const float rhs ) const;
		
		v2& operator +=	( const v2& rhs );
		v2& operator -=	( const v2& rhs );
		v2& operator *=	( const v2& rhs );
		v2& operator /=	( const v2& rhs );
		
		v2& operator *=	( const float rhs );
		v2& operator /=	( const float rhs );
		
		static v2	Min( const v2& src1, const v2& src2 );
		static v2	Max( const v2& src1, const v2& src2 );
        static bool IsFinite(const v2& v);

        
        static const v2 Zero();
        static const v2 One();
	};

    v2 operator * ( const float lhs, const v2& rhs);
    
    class dv2
	{
	public:
        double	x;
        double	y;

        dv2		( ) {};
		dv2		( const dv2& src );
		dv2		( double x, double y );
		dv2		( double* pSrc );
		
		void	Set		( const dv2& src );
		void	Set		( double x, double y );
		void	SetZero	();
		
		double	GetX	() const;
		double	GetY	() const;
		
		void	SetX	( double data );
		void	SetY	( double data );
        
		dv2		SplatX	() const;
		dv2		SplatY	() const;
		
		static dv2 Add	( const dv2& src1, const dv2& src2 );
		static dv2 Sub	( const dv2& src1, const dv2& src2 );
		static dv2 Mul	( const dv2& src1, const dv2& src2 );
		static dv2 Div	( const dv2& src1, const dv2& src2 );
		
		static dv2 Scale		( const dv2& src1, double scale );
		static dv2 InvScale     ( const dv2& src1, double scale );
		
		static dv2 Neg		( const dv2& src );
		
		static double Dot	( const dv2& src1, const dv2& src2 );
		
		static dv2 Lerp		( const dv2& src1, const dv2& src2, double ratio );
		
		double		Length		() const;
		double		LengthSq	() const;
		dv2			Norm		() const;
        
        static v2 ToSingle( const dv2& src);
        v2 ToSingle() const;
		
		dv2 operator -	( ) const;
		
		dv2 operator +	( const dv2& rhs ) const;
		dv2 operator -	( const dv2& rhs ) const;
		dv2 operator *	( const dv2& rhs ) const;
		dv2 operator /	( const dv2& rhs ) const;
		dv2 operator *	( const double rhs ) const;
		dv2 operator /	( const double rhs ) const;
		
		dv2& operator +=	( const dv2& rhs );
		dv2& operator -=	( const dv2& rhs );
		dv2& operator *=	( const dv2& rhs );
		dv2& operator /=	( const dv2& rhs );
		
		dv2& operator *=	( const double rhs );
		dv2& operator /=	( const double rhs );
		
		static dv2	Min( const dv2& src1, const dv2& src2 );
		static dv2	Max( const dv2& src1, const dv2& src2 );
        static bool IsFinite(const dv2& v);
        
        static const dv2 Zero();
        static const dv2 One();
	};

    dv2 operator * ( const double lhs, const dv2& );
	
	class v3
	{
	public:
        float	x;
        float	y;
        float	z;

        friend class v4;
		friend class dv4;
		friend class dv3;
		friend class m44;
		friend class m33;
		friend class dm44;
		friend class dm33;
		
		v3		( ) {};
		
		v3		( const v3& src );
		v3		( float x, float y, float z );
		v3		( const float* pSrc );
		v3		( const v4& src );
		v3& operator= (const v3& rhs);
        
		void	Set		( float x, float y, float z );
		void	SetZero	();
		
		float	GetX	() const;
		float	GetY	() const;
		float	GetZ	() const;

		void	SetX	( float data );
		void	SetY	( float data );
		void	SetZ	( float data );

		v3		SplatX	() const;
		v3		SplatY	() const;
		v3		SplatZ	() const;
		
		static v3 Add	( const v3& src1, const v3& src2 );
		static v3 Sub	( const v3& src1, const v3& src2 );
		static v3 Mul	( const v3& src1, const v3& src2 );
		static v3 Div	( const v3& src1, const v3& src2 );
		
		static v3 Scale		( const v3& src1, float scale );
		static v3 InvScale	( const v3& src1, float scale );
		
		static v3 Neg		( const v3& src );
		
		static float Dot	( const v3& src1, const v3& src2 );
		static v3 Cross		( const v3& src1, const v3& src2 );
		
		static v3 Lerp		( const v3& src1, const v3& src2, float ratio );
		
		static v3 Mul		( const v3& src, const m33& matrix );
		static v3 Mul		( const v3& src, const m44& matrix );
		static v3 MulRotate	( const v3& src, const m44& matrix );
        static v3 Clamped   ( const v3& src, float maxLength);
        static v3 Abs(const v3& src);
        inline float SquareDistanceTo( const v3& a ) const;
		
		float	Length		() const;
		float	LengthSq	() const;
		v3		Norm		() const;
        
        bool operator== (const v3 &rhs) const;
        bool operator!= (const v3 &rhs) const;
		
		v3 operator -	( ) const;
		
		v3 operator +	( const v3& rhs ) const;
		v3 operator -	( const v3& rhs ) const;
		v3 operator *	( const v3& rhs ) const;
		v3 operator /	( const v3& rhs ) const;
		v3 operator *	( const float rhs ) const;
		v3 operator /	( const float rhs ) const;
		
		v3& operator +=	( const v3& rhs );
		v3& operator -=	( const v3& rhs );
		v3& operator *=	( const v3& rhs );
		v3& operator /=	( const v3& rhs );
		
		v3& operator *=	( const float rhs );
		v3& operator /=	( const float rhs );
		
		static v3	Min( const v3& src1, const v3& src2 );
		static v3	Max( const v3& src1, const v3& src2 );
        static bool IsFinite(const v3& v);
        
        static const v3 Zero();
        static const v3 One();
	};

    v3 operator *   ( const float lhs, const v3& rhs);
    
    class dv3
	{
	public:
        double	x;
        double	y;
        double	z;

        friend class v4;
		friend class dv4;
		friend class m44;
		friend class dm44;
		friend class dm33;
		
		dv3		( ) : x(0.0), y(0.0), z(0.0) {};
		
		dv3		( const dv3& src );
		dv3		( double x, double y, double z );
		dv3		( const double* pSrc );
		dv3		( const v4& src );
		dv3		( const dv4& src );
        dv3		( const v3& src );
		
		void	Set		( double x, double y, double z );
		void	SetZero	();
		
		double	GetX	() const;
		double	GetY	() const;
		double	GetZ	() const;
        
		void	SetX	( double data );
		void	SetY	( double data );
		void	SetZ	( double data );
        
		dv3		SplatX	() const;
		dv3		SplatY	() const;
		dv3		SplatZ	() const;
		
		static dv3 Add	( const dv3& src1, const dv3& src2 );
		static dv3 Sub	( const dv3& src1, const dv3& src2 );
		static dv3 Mul	( const dv3& src1, const dv3& src2 );
		static dv3 Div	( const dv3& src1, const dv3& src2 );
        
		static dv3 Add	( const dv3& src1, const v3& src2 );
		static dv3 Sub	( const dv3& src1, const v3& src2 );
		static dv3 Mul	( const dv3& src1, const v3& src2 );
		static dv3 Div	( const dv3& src1, const v3& src2 );
		
		static dv3 Scale	( const dv3& src1, double scale );
		static dv3 InvScale	( const dv3& src1, double scale );
		
		static dv3 Neg		( const dv3& src );
		
		static double Dot	( const dv3& src1, const dv3& src2 );
		static dv3 Cross	( const dv3& src1, const dv3& src2 );
		
		static dv3 Lerp		( const dv3& src1, const dv3& src2, double ratio );
		
		static dv3 Mul          ( const dv3& src, const m33& matrix );
		static dv3 Mul          ( const dv3& src, const m44& matrix );
		static dv3 MulRotate	( const dv3& src, const m44& matrix );
		static dv3 Mul          ( const dv3& src, const dm44& matrix );
		static dv3 MulRotate	( const dv3& src, const dm44& matrix );
		
		static v3 ToSingle( const dv3& src);
        static dv3 FromSingle( const v3& src);
        
        inline double SquareDistanceTo(const dv3& a) const;
        
        double  Length      () const;
        double  LengthSq    () const;
        dv3     Norm        () const;
        dv3& Normalise();
        v3 ToSingle() const;
        
		dv3 operator -	( ) const;
		
		dv3 operator +	( const dv3& rhs ) const;
		dv3 operator -	( const dv3& rhs ) const;
		dv3 operator *	( const dv3& rhs ) const;
		dv3 operator /	( const dv3& rhs ) const;
		dv3 operator *	( const double rhs ) const;
		dv3 operator /	( const double rhs ) const;
		
		dv3& operator +=	( const dv3& rhs );
		dv3& operator -=	( const dv3& rhs );
		dv3& operator *=	( const dv3& rhs );
		dv3& operator /=	( const dv3& rhs );
		
		dv3& operator *=	( const double rhs );
		dv3& operator /=	( const double rhs );
        
		dv3 operator +	( const v3& rhs ) const;
		dv3 operator -	( const v3& rhs ) const;
		dv3 operator *	( const v3& rhs ) const;
		dv3 operator /	( const v3& rhs ) const;
		dv3 operator *	( const float rhs ) const;
		dv3 operator /	( const float rhs ) const;
		
		dv3& operator +=	( const v3& rhs );
		dv3& operator -=	( const v3& rhs );
		dv3& operator *=	( const v3& rhs );
		dv3& operator /=	( const v3& rhs );
		
		static dv3	Min( const dv3& src1, const dv3& src2 );
		static dv3	Max( const dv3& src1, const dv3& src2 );
        static bool IsFinite(const dv3& v);

        
        static const dv3 Zero();
        static const dv3 One();
	};

    dv3 operator * ( const double lhs, const dv3& rhs);

    class v4
	{
	public:
        float	x;
        float	y;
        float	z;
        float	w;

        friend class dv3;
		friend class dv4;
		friend class v3;
		friend class Quaternion;
		friend class m44;
		friend class dm33;
		
		v4		() {}
		
		v4		( const v4& src );
		v4		( float x, float y, float z, float w );
		v4		( const v3& src, float w );
		
		void	Set		( float x, float y, float z, float w );
		void	SetZero	();
		
		float	GetX	() const;
		float	GetY	() const;
		float	GetZ	() const;
		float	GetW	() const;
		
		void	SetX	( float data );
		void	SetY	( float data );
		void	SetZ	( float data );
		void	SetW	( float data );
		
		v4		SplatX	() const;
		v4		SplatY	() const;
		v4		SplatZ	() const;
		v4		SplatW	() const;
		
		void	Load	( const float* pSrc );
		void	Store	( float* pDest ) const;
		
		
		static v4 Add	( const v4& src1, const v4& src2 );
		static v4 Sub	( const v4& src1, const v4& src2 );
		static v4 Mul	( const v4& src1, const v4& src2 );
		static v4 Div	( const v4& src1, const v4& src2 );
		static v4 Dot	( const v4& src1, const v4& src2 );
		
		static v4 Lerp		( const v4& src1, const v4& src2, float ratio );
		
		static v4 Mul		( const v4& src, const m44& matrix );
		static v4 MulTransposed		( const v4& src, const m44& matrix );
        static v4 Neg(const v4& src);
		
		v4		Length		() const;
		v4		LengthSq	() const;
		v4		Norm		() const;
        
        
        v4 operator - () const;
		
		v4 operator +	( const v4& rhs ) const;
		v4 operator -	( const v4& rhs ) const;
		v4 operator *	( const v4& rhs ) const;
		v4 operator /	( const v4& rhs ) const;
		v4 operator *	( const float rhs ) const;
		v4 operator /	( const float rhs ) const;
		
		v4& operator +=	( const v4& rhs );
		v4& operator -=	( const v4& rhs );
		v4& operator *=	( const v4& rhs );
		v4& operator /=	( const v4& rhs );
		
		v4& operator *=	( const float rhs );
		v4& operator /=	( const float rhs );
		
		static v4	Min( const v4& src1, const v4& src2 );
		static v4	Max( const v4& src1, const v4& src2 );
        static bool IsFinite(const v4& v);
        
        const static v4 Zero();
        const static v4 One();
	};
	
    
    
    class dv4
	{
	public:
        double	x;
        double	y;
        double	z;
        double	w;

        friend class v4;
		friend class dv3;
		
		friend class m44;
		friend class dm44;
		friend class dm33;
		
		dv4		( ) {};
		
		dv4		( const dv4& src );
		dv4		( double x, double y, double z, double w );
		dv4		( const double* pSrc );
		dv4		( const v3& src );
		//dv4		( const dv3& src );
		dv4		( const dv3& src, double w );
        dv4		( const v4& src );
		
		void	Set		( double x, double y, double z, double w );
		void	SetZero	();
		
		
		double	GetX	() const;
		double	GetY	() const;
		double	GetZ	() const;
		double	GetW	() const;
		
		void	SetX	( double data );
		void	SetY	( double data );
		void	SetZ	( double data );
		void	SetW	( double data );
		
		dv4		SplatX	() const;
		dv4		SplatY	() const;
		dv4		SplatZ	() const;
		dv4		SplatW	() const;
		
		static dv4 Add	( const dv4& src1, const dv4& src2 );
		static dv4 Sub	( const dv4& src1, const dv4& src2 );
		static dv4 Mul	( const dv4& src1, const dv4& src2 );
		static dv4 Div	( const dv4& src1, const dv4& src2 );
        
		static dv4 Add	( const dv4& src1, const v4& src2 );
		static dv4 Sub	( const dv4& src1, const v4& src2 );
		static dv4 Mul	( const dv4& src1, const v4& src2 );
		static dv4 Div	( const dv4& src1, const v4& src2 );
		
		static dv4 Scale	( const dv4& src1, double scale );
		static dv4 InvScale	( const dv4& src1, double scale );
		
		static dv4 Neg		( const dv4& src );
		
		static double Dot	( const dv4& src1, const dv4& src2 );
		
		static dv4 Lerp		( const dv4& src1, const dv4& src2, double ratio );
		
		static dv4 Mul          ( const dv4& src, const m44& matrix );
		static dv4 MulTransposed ( const dv4& src, const m44& matrix );
		
		static v4 ToSingle( const dv4& src);
        static dv4 FromSingle( const v4& src);
        
        double  Length      () const;
        double  LengthSq    () const;
        dv4     Norm        () const;
        dv4& Normalise();
        v4 ToSingle() const;
        
		dv4 operator -	( ) const;
		
		dv4 operator +	( const dv4& rhs ) const;
		dv4 operator -	( const dv4& rhs ) const;
		dv4 operator *	( const dv4& rhs ) const;
		dv4 operator /	( const dv4& rhs ) const;
		dv4 operator *	( const double rhs ) const;
		dv4 operator /	( const double rhs ) const;
		
		dv4& operator +=	( const dv4& rhs );
		dv4& operator -=	( const dv4& rhs );
		dv4& operator *=	( const dv4& rhs );
		dv4& operator /=	( const dv4& rhs );
		
		dv4& operator *=	( const double rhs );
		dv4& operator /=	( const double rhs );
        
		dv4 operator +	( const v4& rhs ) const;
		dv4 operator -	( const v4& rhs ) const;
		dv4 operator *	( const v4& rhs ) const;
		dv4 operator /	( const v4& rhs ) const;
		dv4 operator *	( const float rhs ) const;
		dv4 operator /	( const float rhs ) const;
		
		dv4& operator +=	( const v4& rhs );
		dv4& operator -=	( const v4& rhs );
		dv4& operator *=	( const v4& rhs );
		dv4& operator /=	( const v4& rhs );
		
		static dv4	Min( const dv4& src1, const dv4& src2 );
		static dv4	Max( const dv4& src1, const dv4& src2 );
        static bool IsFinite(const dv4& v);
        
        static const dv4 Zero();
        static const dv4 One();
	};
    
	class m33
	{
	public:
		float _11, _12, _13;
		float _21, _22, _23;
		float _31, _32, _33;
		
	public:
        m33		();
        m33		( const m44& src );
		void		Identity	();
		static void	Transpose	( m33& dst, const m33& src );
        
		bool            Decompose   (v3& outScale, Quaternion& outRotation);
		static bool		Decompose   (const m33& src, v3& outScale, Quaternion& outRotation);

		void		SetRow		( int row, const v3& data );
		void        SetFromBasis(const v3& right, const v3& up, const v3& forward);
		v3	GetRow		( int row ) const;

		void		Scale		( float scale );
		void		Scale		( const v3& scale );

		void		RotateX		( float theta );
		void		RotateY		( float theta );
		void		RotateZ		( float theta );
		void		Rotate		( float x, float y, float z );
		void		Rotate		( const v3& axis, float angle );

		static void	Inverse		( m33& dst, const m33& src );
		static void	Mul			( m33& dst, const m33& src1, const m33& src2 );
		void Mul                ( const float scale );

        m44 ToM44() const;
        
        static m33 CreateIdentity();
	};
	
	class dm33
	{
	public:
		double _11, _12, _13;
		double _21, _22, _23;
		double _31, _32, _33;

		friend class dv3;
		friend class dv4;
		friend class v3;
		friend class v4;
		friend class m33;
        friend class Quaternion;

	public:
		dm33		();
		dm33		( const dm44& src );
		void		Identity	();
		static void	Transpose	( dm33& dst, const dm33& src );

		bool            Decompose   (dv3& outScale, Quaternion& outRotation);
		static bool		Decompose   (const dm33& src, dv3& outScale, Quaternion& outRotation);

		void		SetRow		( int row, const dv3& data );
		void        SetFromBasis(const dv3& right, const dv3& up, const dv3& forward);
		dv3	GetRow		( int row ) const;

		void		Scale		( double scale );
		void		Scale		( const dv3& scale );

		void		RotateX		( double theta );
		void		RotateY		( double theta );
		void		RotateZ		( double theta );
		void		Rotate		( double x, double y, double z );
		void		Rotate		( const dv3& axis, double angle );

		static void	Inverse		( dm33& dst, const dm33& src );
		static void	Mul			( dm33& dst, const dm33& src1, const dm33& src2 );
		void Mul                ( const double scale );
	};

	class m44
	{
		v4	m_rows[4];
		
	public:
		friend class dv3;
		friend class dv4;
		friend class v3;
		friend class v4;
		friend class m33;
        friend class Quaternion;
		
		m44						() {}
		m44						( const v4& row0, const v4& row1, const v4& row2, const v4& row3 );
        m44                     (float values[16]);
		void		SetRow		( int row, const v4& data )	{ m_rows[row] = data; }
        void        SetFromBasis(const v3& right, const v3& up, const v3& forward, const v3& pos);
		const v4&	GetRow		( int row ) const			{ return m_rows[row]; }
		
		void		Load		( const float* pSrc );
		void		Store		( float* pDest ) const;
		
		void		Identity	();
        bool        IsIdentity  () const;
		void		Scale		( float scale );
		void		Scale		( const v3& scale );
		
		void 		OrthProjection 	(float left, float right, float top, float bottom, float near, float far, float scale);
		void 		Projection		(float fovyRadians, float aspect, float nearZ, float farZ);
		
		void		RotateX		( float theta );
		void		RotateY		( float theta );
		void		RotateZ		( float theta );
		void		Rotate		( float x, float y, float z );
		void		Rotate		( const v3& axis, float angle );
        
		bool            Decompose   (v3& outScale, Quaternion& outRotation, v3& outTranslation);
		static bool		Decompose   (const m44& src, v3& outScale, Quaternion& outRotation, v3& outTranslation);
		
		static void	Transpose	( m44& dst, const m44& src );
		static void	Inverse		( m44& dst, const m44& src );
		static void	OrthoInverse( m44& dst, const m44& src );
		static void	Mul			( m44& dst, const m44& src1, const m44& src2 );
        void Mul                ( const float scale );
        static void Lerp        ( m44& dst, const m44& from, const m44& to, float t );
        
        static const m44 Zero();
        
        static m44  CreateIdentity();
        static m44  CreateFromRowMajorElements( const float* pRowMajorElements );
	};
	
	class dm44
	{
		dv4	m_rows[4];

	public:
		friend class dv3;
		friend class dv4;
		friend class v3;
		friend class v4;
		friend class m33;
		friend class dm33;
        friend class Quaternion;

		dm44						() {}
		dm44						( const dv4& row0, const dv4& row1, const dv4& row2, const dv4& row3 );
		void		SetRow		( int row, const dv4& data )	{ m_rows[row] = data; }
        void        SetFromBasis(const dv3& right, const dv3& up, const dv3& forward, const dv3& pos);
		const dv4&	GetRow		( int row ) const			{ return m_rows[row]; }

		void		Identity	();
		void		Scale		( double scale );
		void		Scale		( const dv3& scale );

		void 		OrthProjection 	(double left, double right, double top, double bottom, double near, double far, double scale);
		void 		Projection		(double fovyRadians, double aspect, double nearZ, double farZ);

		void		RotateX		( double theta );
		void		RotateY		( double theta );
		void		RotateZ		( double theta );
		void		Rotate		( double x, double y, double z );
		void		Rotate		( const dv3& axis, double angle );

		bool            Decompose   (dv3& outScale, Quaternion& outRotation, dv3& outTranslation);
		static bool		Decompose   (const dm44& src, dv3& outScale, Quaternion& outRotation, dv3& outTranslation);

		static void	Transpose	( dm44& dst, const dm44& src );
		static void	Inverse		( dm44& dst, const dm44& src );
		static void	OrthoInverse( dm44& dst, const dm44& src );
		static void	Mul			( dm44& dst, const dm44& src1, const dm44& src2 );
        void Mul                ( const double scale );
	};
	
	
	
	
	inline v2::v2( const v2& src )
	{
		x = src.x;
		y = src.y;
	}
	
	inline v2::v2( float _x, float _y )
	{
		x = _x;
		y = _y;
	}
	
	inline v2::v2( float* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
	}
	
	inline void v2::Set( const v2& src )
	{
		x = src.x;
		y = src.y;
	}

	inline void v2::Set( float _x, float _y )
	{
		x = _x;
		y = _y;
	}

	inline void v2::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
	}
	
	inline v2 v2::SplatX() const
	{
		return v2(x, x);
	}
	
	inline v2 v2::SplatY() const
	{
		return v2(y, y);
	}
	
	inline float v2::GetX() const
	{
		return x;
	}
	
	inline float v2::GetY() const
	{
		return y;
	}
	
	inline void v2::SetX( float data )
	{
		x = data;
	}
	
	inline void v2::SetY( float data )
	{
		y = data;
	}
	
	
	inline v2 v2::Add( const v2& src1, const v2& src2 )
	{
		return v2(src1.x + src2.x, src1.y + src2.y);
	}
	
	inline v2 v2::Sub( const v2& src1, const v2& src2 )
	{
		return v2(src1.x - src2.x, src1.y - src2.y);
	}
	
	inline v2 v2::Mul( const v2& src1, const v2& src2 )
	{
		return v2(src1.x * src2.x, src1.y * src2.y);
	}
	
	inline v2 v2::Div( const v2& src1, const v2& src2 )
	{
		return v2(src1.x / src2.x, src1.y / src2.y);
	}
	
	inline float v2::Dot( const v2& src1, const v2& src2 )
	{
		float dot = src1.x * src2.x + src1.y * src2.y;
		return dot;
	}
	
	inline v2 v2::Lerp( const v2& src1, const v2& src2, float ratio )
	{
		v2	temp = src2 * ratio;
		temp	+= src1 * (1.0f - ratio);
		
		return temp;
	}
	
	inline v2 v2::Scale( const v2& src, float scale )
	{
		return v2(src.x * scale, src.y * scale);
	}
	
	inline v2 v2::InvScale( const v2& src, float scale )
	{
		return v2(src.x / scale, src.y / scale);
	}
	
	inline float v2::Length() const
	{
		float dot = x * x + y * y;
		float length = Math::Sqrtf(dot);
		return length;
	}
	
	inline float v2::LengthSq() const
	{
		return Dot(*this, *this);
	}
	
	inline v2 v2::Norm() const
	{
		float dot = x * x + y * y;
		float length = Math::Sqrtf(dot);
		return v2(x/length, y/length);
	}
	
	inline v2 v2::Neg(const v2& src)
	{
		return v2(-src.x, -src.y);
	}
	
	inline v2 v2::operator - () const
	{
		return Neg(*this);
	}
	
	inline v2 v2::operator + ( const v2& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline v2 v2::operator - ( const v2& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline v2 v2::operator * ( const v2& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline v2 v2::operator * ( const float rhs ) const
	{
		return Scale(*this, rhs);
	}

    inline v2 operator * ( const float lhs, const v2& rhs)
    {
        return v2::Scale(rhs, lhs);
    }
	
	inline v2 v2::operator / ( const v2& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline v2 v2::operator / ( const float rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline v2& v2::operator +=	( const v2& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline v2& v2::operator -=	( const v2& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline v2& v2::operator *=	( const v2& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline v2& v2::operator /=	( const v2& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline v2& v2::operator *=	( const float rhs )
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	
	inline v2& v2::operator /=	( const float rhs )
	{
		x /= rhs;
		y /= rhs;
		
		return *this;
	}
	
	inline v2 v2::Min( const v2& src1, const v2& src2 )
	{
		return v2(	src1.x < src2.x ? src1.x : src2.x,
				  src1.y < src2.y ? src1.y : src2.y );
	}
	
	inline v2 v2::Max( const v2& src1, const v2& src2 )
	{
		return v2(	src1.x > src2.x ? src1.x : src2.x,
				  src1.y > src2.y ? src1.y : src2.y );
	}
	
    inline dv2::dv2( const dv2& src )
	{
		x = src.x;
		y = src.y;
	}
	
	inline dv2::dv2( double _x, double _y )
	{
		x = _x;
		y = _y;
	}
	
	inline dv2::dv2( double* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
	}
	
	inline void dv2::Set( const dv2& src )
	{
		x = src.x;
		y = src.y;
	}
    
	inline void dv2::Set( double _x, double _y )
	{
		x = _x;
		y = _y;
	}
    
	inline void dv2::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
	}
	
	inline dv2 dv2::SplatX() const
	{
		return dv2(x, x);
	}
	
	inline dv2 dv2::SplatY() const
	{
		return dv2(y, y);
	}
	
	inline double dv2::GetX() const
	{
		return x;
	}
	
	inline double dv2::GetY() const
	{
		return y;
	}
	
	inline void dv2::SetX( double data )
	{
		x = data;
	}
	
	inline void dv2::SetY( double data )
	{
		y = data;
	}
	
	
	inline dv2 dv2::Add( const dv2& src1, const dv2& src2 )
	{
		return dv2(src1.x + src2.x, src1.y + src2.y);
	}
	
	inline dv2 dv2::Sub( const dv2& src1, const dv2& src2 )
	{
		return dv2(src1.x - src2.x, src1.y - src2.y);
	}
	
	inline dv2 dv2::Mul( const dv2& src1, const dv2& src2 )
	{
		return dv2(src1.x * src2.x, src1.y * src2.y);
	}
	
	inline dv2 dv2::Div( const dv2& src1, const dv2& src2 )
	{
		return dv2(src1.x / src2.x, src1.y / src2.y);
	}
	
	inline double dv2::Dot( const dv2& src1, const dv2& src2 )
	{
		double dot = src1.x * src2.x + src1.y * src2.y;
		return dot;
	}
	
	inline dv2 dv2::Lerp( const dv2& src1, const dv2& src2, double ratio )
	{
		dv2	temp = src2 * ratio;
		temp	+= src1 * (1.0f - ratio);
		
		return temp;
	}
	
	inline dv2 dv2::Scale( const dv2& src, double scale )
	{
		return dv2(src.x * scale, src.y * scale);
	}
	
	inline dv2 dv2::InvScale( const dv2& src, double scale )
	{
		return dv2(src.x / scale, src.y / scale);
	}
	
	inline double dv2::Length() const
	{
		double dot = x * x + y * y;
		double length = Math::Sqrtd(dot);
		return length;
	}
	
	inline double dv2::LengthSq() const
	{
		return Dot(*this, *this);
	}
	
	inline dv2 dv2::Norm() const
	{
		double invMagnitude = 1.0 / Length();
		return dv2(x * invMagnitude, y * invMagnitude);
	}
    
    inline v2 dv2::ToSingle( const dv2& src)
    {
        return v2(static_cast<float>(src.x), static_cast<float>(src.y));
    }
    
    inline v2 dv2::ToSingle() const
    {
        return ToSingle(*this);
    }
	
	inline dv2 dv2::Neg(const dv2& src)
	{
		return dv2(-src.x, -src.y);
	}
	
	inline dv2 dv2::operator - () const
	{
		return Neg(*this);
	}
	
	inline dv2 dv2::operator + ( const dv2& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline dv2 dv2::operator - ( const dv2& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline dv2 dv2::operator * ( const dv2& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline dv2 dv2::operator * ( const double rhs ) const
	{
		return Scale(*this, rhs);
	}

    inline dv2 operator * ( const double lhs, const dv2& rhs )
    {
        return dv2::Scale(rhs, lhs);
    }
	
	inline dv2 dv2::operator / ( const dv2& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline dv2 dv2::operator / ( const double rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline dv2& dv2::operator +=	( const dv2& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline dv2& dv2::operator -=	( const dv2& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline dv2& dv2::operator *=	( const dv2& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline dv2& dv2::operator /=	( const dv2& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline dv2& dv2::operator *=	( const double rhs )
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	
	inline dv2& dv2::operator /=	( const double rhs )
	{
		x /= rhs;
		y /= rhs;
		
		return *this;
	}
	
	inline dv2 dv2::Min( const dv2& src1, const dv2& src2 )
	{
		return dv2(	src1.x < src2.x ? src1.x : src2.x,
                   src1.y < src2.y ? src1.y : src2.y );
	}
	
	inline dv2 dv2::Max( const dv2& src1, const dv2& src2 )
	{
		return dv2(	src1.x > src2.x ? src1.x : src2.x,
                   src1.y > src2.y ? src1.y : src2.y );
	}

	inline v3::v3( const v3& src )
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}
	
	inline v3::v3( float _x, float _y, float _z )
	{
		x = _x;
		y = _y;
		z = _z;
	}
	
	inline v3::v3( const float* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
		z = pSrc[2];
	}
	
	inline v3::v3(const v4& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}
	
    inline v3& v3::operator= (const v3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }
    
    inline bool v3::operator== (const v3 &rhs) const
    {
        return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
    }
    
    inline bool v3::operator!= (const v3 &rhs) const
    {
        return (x != rhs.x) || (y != rhs.y) || (z != rhs.z);
    }
    
	inline void	v3::Set( float _x, float _y, float _z )
	{
		x = _x;
		y = _y;
		z = _z;
	}
	
	inline void v3::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	
	inline v3 v3::SplatX() const
	{
		return v3(x, x, x);
	}
	
	inline v3 v3::SplatY() const
	{
		return v3(y, y, y);
	}
	
	inline v3 v3::SplatZ() const
	{
		return v3(z, z, z);
	}
	
	inline float v3::GetX() const
	{
		return x;
	}
	
	inline float v3::GetY() const
	{
		return y;
	}
	
	inline float v3::GetZ() const
	{
		return z;
	}
	
	inline void v3::SetX( float data )
	{
		x = data;
	}
	
	inline void v3::SetY( float data )
	{
		y = data;
	}

	inline void v3::SetZ( float data )
	{
		z = data;
	}

	inline v3 v3::Add( const v3& src1, const v3& src2 )
	{
		return v3(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z);
	}
	
	inline v3 v3::Sub( const v3& src1, const v3& src2 )
	{
		return v3(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z);
	}
	
	inline v3 v3::Mul( const v3& src1, const v3& src2 )
	{
		return v3(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z);
	}
	
	inline v3 v3::Div( const v3& src1, const v3& src2 )
	{
		return v3(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z);
	}
	
	inline float v3::Dot( const v3& src1, const v3& src2 )
	{

		float dot = src1.x * src2.x + src1.y * src2.y + src1.z * src2.z;
		return dot;

	}
	
	inline v3 v3::Lerp( const v3& src1, const v3& src2, float ratio )
	{
		v3	temp = src2 * ratio;
		temp	+= src1 * (1.0f - ratio);
		
		return temp;
	}
	
	inline v3 v3::Cross( const v3& src1, const v3& src2 )
	{
		return v3(	src1.y * src2.z - src1.z * src2.y,
				  src1.z * src2.x - src1.x * src2.z,
				  src1.x * src2.y - src1.y * src2.x );
	}
	
	inline v3 v3::Mul (const v3& src, const m33& matrix)
	{
		
#if 0
		v3 destVector;
		int tmp;
		asm volatile (
					  "mov                    %3, #12                                 \n\t"   
					  "vld1.32                {d0, d1}, [%1]                  \n\t"   
					  "vld1.32                {d2, d3}, [%0], %3              \n\t"   
					  "vld1.32                {d4, d5}, [%0], %3              \n\t"   
					  "vld1.32                {d6, d7}, [%0], %3              \n\t"   
					  
					  "vmul.f32               q9, q1, d0[0]                   \n\t"   
					  "vmla.f32               q9, q2, d0[1]                   \n\t"   
					  "vmla.f32               q9, q3, d1[0]                   \n\t"   
					  "vmov.f32               q0, q9                                  \n\t"   
					  
					  "vst1.32                d0, [%2]!                               \n\t"   
					  "fsts                   s2, [%2]                                \n\t"   
					  
					  : "+r"(&matrix), "+r"(&src), "+r"(destVector), "+r"(tmp):
					  : "q0", "q9", "q10","q11", "q12", "q13", "memory"
					  );      

		return destVector;
#else
		
		v3 tempMatrix;
		
		tempMatrix.x = matrix._11*src.x + matrix._21*src.y + matrix._31*src.z;
		tempMatrix.y = matrix._12*src.x + matrix._22*src.y + matrix._32*src.z;
		tempMatrix.z = matrix._13*src.x + matrix._23*src.y + matrix._33*src.z;
		
		return tempMatrix;
		
#endif
		
	}

	inline v3 v3::Mul( const v3& src, const m44& matrix )
	{
		float x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z + matrix.m_rows[3].x;
		float y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z + matrix.m_rows[3].y;
		float z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[3].z;
		
		return v3(x, y, z);
	}
	
	inline v3 v3::MulRotate( const v3& src, const m44& matrix )
	{
		float x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z;
		float y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z;
		float z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z;
		
		return v3(x, y, z);
	}
    
    inline v3 v3::Clamped( const v3& src, float maxLength)
    {
        float length = src.Length();
        v3 result = (length > maxLength) ? v3::Scale(src, maxLength/length) : src;
        return result;
    }
    
    inline v3 v3::Abs(const v3& src)
    {
        return v3(Math::Abs(src.x), Math::Abs(src.y), Math::Abs(src.z));
    }
    
	inline v3 v3::Scale( const v3& src, float scale )
	{
		return v3(src.x * scale, src.y * scale, src.z * scale);
	}
	
	inline v3 v3::InvScale( const v3& src, float scale )
	{
		return v3(src.x / scale, src.y / scale, src.z / scale);
	}
	
	inline float v3::Length() const
	{
		float dot = x * x + y * y + z * z;
		float length = Math::Sqrtf(dot);
		return length;
	}
	
	inline float v3::LengthSq() const
	{
		return Dot(*this, *this);
	}
    
    inline float v3::SquareDistanceTo( const v3& a ) const
    {
        float dx = a.x - x;
        float dy = a.y - y;
        float dz = a.z - z;
        return dx*dx + dy*dy + dz*dz;
    }
	
	inline v3 v3::Norm() const
	{
		float dot = x * x + y * y + z * z;
		float length = Math::Sqrtf(dot);
		return v3(x/length, y/length, z/length);
	}
	
	inline v3 v3::Neg(const v3& src)
	{
		return v3(-src.x, -src.y, -src.z);
	}
	
	inline v3 v3::operator - () const
	{
		return Neg(*this);
	}
	
	inline v3 v3::operator + ( const v3& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline v3 v3::operator - ( const v3& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline v3 v3::operator * ( const v3& rhs ) const
	{
		return Mul(*this, rhs);
	}

	inline v3 v3::operator * ( const float rhs ) const
	{
		return Scale(*this, rhs);
	}

    inline v3 operator * ( const float lhs, const v3& rhs )
    {
        return v3::Scale(rhs, lhs);
    }

    inline v3 v3::operator / ( const v3& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline v3 v3::operator / ( const float rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline v3& v3::operator +=	( const v3& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline v3& v3::operator -=	( const v3& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline v3& v3::operator *=	( const v3& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline v3& v3::operator /=	( const v3& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline v3& v3::operator *=	( const float rhs )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}
	
	inline v3& v3::operator /=	( const float rhs )
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		
		return *this;
	}
	
	inline v3 v3::Min( const v3& src1, const v3& src2 )
	{
		return v3(	src1.x < src2.x ? src1.x : src2.x,
				  src1.y < src2.y ? src1.y : src2.y,
				  src1.z < src2.z ? src1.z : src2.z );
	}
	
	inline v3 v3::Max( const v3& src1, const v3& src2 )
	{
		return v3(	src1.x > src2.x ? src1.x : src2.x,
				  src1.y > src2.y ? src1.y : src2.y,
				  src1.z > src2.z ? src1.z : src2.z );
	}
    
    inline dv3::dv3( const dv3& src )
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}
	
	inline dv3::dv3( double _x, double _y, double _z )
	{
		x = _x;
		y = _y;
		z = _z;
	}
	
	inline dv3::dv3( const double* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
		z = pSrc[2];
	}
	
	inline dv3::dv3(const v4& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}

	inline dv3::dv3(const dv4& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}

    inline dv3::dv3(const v3& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}
	
	inline void	dv3::Set( double _x, double _y, double _z )
	{
		x = _x;
		y = _y;
		z = _z;
	}
	
	inline void dv3::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	
	inline dv3 dv3::SplatX() const
	{
		return dv3(x, x, x);
	}
	
	inline dv3 dv3::SplatY() const
	{
		return dv3(y, y, y);
	}
	
	inline dv3 dv3::SplatZ() const
	{
		return dv3(z, z, z);
	}
	
	inline double dv3::GetX() const
	{
		return x;
	}
	
	inline double dv3::GetY() const
	{
		return y;
	}
	
	inline double dv3::GetZ() const
	{
		return z;
	}
	
	inline void dv3::SetX( double data )
	{
		x = data;
	}
	
	inline void dv3::SetY( double data )
	{
		y = data;
	}
    
	inline void dv3::SetZ( double data )
	{
		z = data;
	}
    
	inline dv3 dv3::Add( const dv3& src1, const dv3& src2 )
	{
		return dv3(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z);
	}
	
	inline dv3 dv3::Sub( const dv3& src1, const dv3& src2 )
	{
		return dv3(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z);
	}
	
	inline dv3 dv3::Mul( const dv3& src1, const dv3& src2 )
	{
		return dv3(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z);
	}
	
	inline dv3 dv3::Div( const dv3& src1, const dv3& src2 )
	{
		return dv3(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z);
	}
    
	inline dv3 dv3::Add( const dv3& src1, const v3& src2 )
	{
		return dv3(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z);
	}
	
	inline dv3 dv3::Sub( const dv3& src1, const v3& src2 )
	{
		return dv3(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z);
	}
	
	inline dv3 dv3::Mul( const dv3& src1, const v3& src2 )
	{
		return dv3(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z);
	}
	
	inline dv3 dv3::Div( const dv3& src1, const v3& src2 )
	{
		return dv3(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z);
	}
    
	inline double dv3::Dot( const dv3& src1, const dv3& src2 )
	{
#if MATH_NEON && !TARGET_IPHONE_SIMULATOR   
		
		double ret[3];
		asm volatile (
					  "vld1.32                {d2}, [%0]                      \n\t"   
					  "flds                   s6, [%0, #8]            \n\t"   
					  "vld1.32                {d4}, [%1]                      \n\t"   
					  "flds                   s10, [%1, #8]   \n\t"   
					  
					  "vmul.f32               d0, d2, d4                      \n\t"   
					  "vpadd.f32              d0, d0, d0                      \n\t"   
					  "vmla.f32               d0, d3, d5                      \n\t"   
					  
					  "vstr.32               d0, [%2]                        \n\t"
					  
					  :: "r"(&src1), "r"(&src2), "=r"(ret)
					  : "d0","d1","d2","d3","d4","d5"
					  );
		
		return ret[0];
		
#else
		double dot = src1.x * src2.x + src1.y * src2.y + src1.z * src2.z;
		return dot;
#endif
	}
	
	inline dv3 dv3::Lerp( const dv3& src1, const dv3& src2, double ratio )
	{
		dv3	temp = src2 * ratio;
		temp	+= src1 * (1.0f - ratio);
		
		return temp;
	}
	
	inline dv3 dv3::Cross( const dv3& src1, const dv3& src2 )
	{
		return dv3(	src1.y * src2.z - src1.z * src2.y,
                   src1.z * src2.x - src1.x * src2.z,
                   src1.x * src2.y - src1.y * src2.x );
	}
	
	inline dv3 dv3::Mul (const dv3& src, const m33& matrix)
	{
		
#if 0
		dv3 destVector;
		int tmp;
		asm volatile (
					  "mov                    %3, #12                                 \n\t"   
					  "vld1.32                {d0, d1}, [%1]                  \n\t"   
					  "vld1.32                {d2, d3}, [%0], %3              \n\t"   
					  "vld1.32                {d4, d5}, [%0], %3              \n\t"   
					  "vld1.32                {d6, d7}, [%0], %3              \n\t"   
					  
					  "vmul.f32               q9, q1, d0[0]                   \n\t"   
					  "vmla.f32               q9, q2, d0[1]                   \n\t"   
					  "vmla.f32               q9, q3, d1[0]                   \n\t"   
					  "vmov.f32               q0, q9                                  \n\t"   
					  
					  "vst1.32                d0, [%2]!                               \n\t"   
					  "fsts                   s2, [%2]                                \n\t"   
					  
					  : "+r"(&matrix), "+r"(&src), "+r"(destVector), "+r"(tmp):
					  : "q0", "q9", "q10","q11", "q12", "q13", "memory"
					  );      
        
		return destVector;
#else
		
		dv3 tempMatrix;
		
		tempMatrix.x = matrix._11*src.x + matrix._21*src.y + matrix._31*src.z;
		tempMatrix.y = matrix._12*src.x + matrix._22*src.y + matrix._32*src.z;
		tempMatrix.z = matrix._13*src.x + matrix._23*src.y + matrix._33*src.z;
		
		return tempMatrix;
		
#endif
		
	}
    
	inline dv3 dv3::Mul( const dv3& src, const m44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z + matrix.m_rows[3].x;
		double y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z + matrix.m_rows[3].y;
		double z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[3].z;
		
		return dv3(x, y, z);
	}
	
	inline dv3 dv3::MulRotate( const dv3& src, const m44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z;
		double y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z;
		double z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z;
		
		return dv3(x, y, z);
	}

	inline dv3 dv3::Mul( const dv3& src, const dm44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z + matrix.m_rows[3].x;
		double y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z + matrix.m_rows[3].y;
		double z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[3].z;

		return dv3(x, y, z);
	}

	inline dv3 dv3::MulRotate( const dv3& src, const dm44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z;
		double y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z;
		double z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z;

		return dv3(x, y, z);
	}
	
    inline v3 dv3::ToSingle( const dv3& src)
    {
        return v3(static_cast<float>(src.x), static_cast<float>(src.y), static_cast<float>(src.z));
    }
    
    inline dv3 dv3::FromSingle( const v3& src)
    {
        return dv3(src.GetX(), src.GetY(), src.GetZ());
    }
    
	inline dv3 dv3::Scale( const dv3& src, double scale )
	{
		return dv3(src.x * scale, src.y * scale, src.z * scale);
	}
	
	inline dv3 dv3::InvScale( const dv3& src, double scale )
	{
		return dv3(src.x / scale, src.y / scale, src.z / scale);
	}
	
    inline double dv3::SquareDistanceTo(const dv3& a) const
    {
        double dx = a.x - x;
        double dy = a.y - y;
        double dz = a.z - z;
        return dx*dx + dy*dy + dz*dz;
    }
    
	inline double dv3::Length() const
	{
		double dot = x * x + y * y + z * z;
		double length = Math::Sqrtd(dot);
		return length;
	}
	
	inline double dv3::LengthSq() const
	{
		return Dot(*this, *this);
	}
	
	inline dv3 dv3::Norm() const
	{
		double invMagnitude = 1.0 / Length();
		return dv3(x * invMagnitude, y * invMagnitude, z * invMagnitude);
	}
    
    inline dv3& dv3::Normalise()
    {
        *this = Norm();
        return *this;
    }
    
    inline v3 dv3::ToSingle() const
    {
        return ToSingle(*this);
    }
    
	inline dv3 dv3::Neg(const dv3& src)
	{
		return dv3(-src.x, -src.y, -src.z);
	}
	
	inline dv3 dv3::operator - () const
	{
		return Neg(*this);
	}
	
	inline dv3 dv3::operator + ( const v3& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline dv3 dv3::operator - ( const v3& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline dv3 dv3::operator * ( const v3& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline dv3 dv3::operator * ( const float rhs ) const
	{
		return Scale(*this, rhs);
	}

    inline dv3 operator * ( const double lhs, const dv3& rhs)
    {
        return dv3::Scale(rhs, lhs);
    }

    inline dv3 dv3::operator / ( const v3& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline dv3 dv3::operator / ( const float rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline dv3& dv3::operator +=	( const v3& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator -=	( const v3& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator *=	( const v3& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator /=	( const v3& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
    
	
	inline dv3 dv3::operator + ( const dv3& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline dv3 dv3::operator - ( const dv3& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline dv3 dv3::operator * ( const dv3& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline dv3 dv3::operator * ( const double rhs ) const
	{
		return Scale(*this, rhs);
	}
	
	inline dv3 dv3::operator / ( const dv3& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline dv3 dv3::operator / ( const double rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline dv3& dv3::operator +=	( const dv3& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator -=	( const dv3& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator *=	( const dv3& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator /=	( const dv3& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline dv3& dv3::operator *=	( const double rhs )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}
	
	inline dv3& dv3::operator /=	( const double rhs )
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		
		return *this;
	}
	
	inline dv3 dv3::Min( const dv3& src1, const dv3& src2 )
	{
		return dv3(	src1.x < src2.x ? src1.x : src2.x,
                   src1.y < src2.y ? src1.y : src2.y,
                   src1.z < src2.z ? src1.z : src2.z );
	}
	
	inline dv3 dv3::Max( const dv3& src1, const dv3& src2 )
	{
		return dv3(	src1.x > src2.x ? src1.x : src2.x,
                   src1.y > src2.y ? src1.y : src2.y,
                   src1.z > src2.z ? src1.z : src2.z );
	}
	
	
	
	
	
	
	inline v4::v4( const v4& src )
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = src.w;
	}
	
	inline v4::v4( float _x, float _y, float _z, float _w )
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	
	inline v4::v4( const v3& src, float _w )
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = _w;
	}
	
	inline void v4::Set( float _x, float _y, float _z, float _w )
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	
	inline void v4::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}
	
	inline float v4::GetX() const
	{
		return x;
	}
	
	inline float v4::GetY() const
	{
		return y;
	}
	
	inline float v4::GetZ() const
	{
		return z;
	}
	
	inline float v4::GetW() const
	{
		return w;
	}
	
	inline void v4::SetX( float data )
	{
		x = data;
	}
	
	inline void v4::SetY( float data )
	{
		y = data;
	}
	
	inline void v4::SetZ( float data )
	{
		z = data;
	}

	inline void v4::SetW( float data )
	{
		w = data;
	}

	inline v4 v4::SplatX() const
	{
		return v4(x, x, x, x);
	}
	
	inline v4 v4::SplatY() const
	{
		return v4(y, y, y, y);
	}
	
	inline v4 v4::SplatZ() const
	{
		return v4(z, z, z, z);
	}
	
	inline v4 v4::SplatW() const
	{
		return v4(w, w, w, w);
	}
	
	inline void v4::Load( const float* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
		z = pSrc[2];
		w = pSrc[3];
	}
	
    inline void	v4::Store( float* pDest ) const
    {
        pDest[0] = x;
        pDest[1] = y;
        pDest[2] = z;
        pDest[3] = w;
    }
	
	
	
	
	inline v4 v4::Add( const v4& src1, const v4& src2 )
	{
		return v4(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z, src1.w + src2.w);
	}
	
	inline v4 v4::Sub( const v4& src1, const v4& src2 )
	{
		return v4(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z, src1.w - src2.w);
	}
	inline v4 v4::Mul( const v4& src1, const v4& src2 )
	{
		return v4(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z, src1.w * src2.w);
	}
	
	inline v4 v4::Div( const v4& src1, const v4& src2 )
	{
		return v4(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z, src1.w / src2.w);
	}
	
	inline v4 v4::Dot( const v4& src1, const v4& src2 )
	{
		float	dot = src1.x * src2.x + src1.y * src2.y + src1.z * src2.z + src1.w * src2.w;
		return v4(dot, dot, dot, dot);
	}
	
	inline v4 v4::Lerp( const v4& src1, const v4& src2, float ratio )
	{
		v4	temp = src2 * ratio;
		temp	+= src1 * (1.0f - ratio);
		
		return temp;
	}
    
    inline v4 v4::Neg(const v4& src)
    {
        return v4(-src.x, -src.y, -src.z, -src.w);
    }
    
    inline v4 v4::operator - () const
    {
        return Neg(*this);
    }
	
	inline v4 v4::operator + ( const v4& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline v4 v4::operator - ( const v4& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline v4 v4::operator * ( const v4& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline v4 v4::operator / ( const v4& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline v4 v4::operator * ( const float rhs ) const
	{
		return v4(x * rhs, y * rhs, z * rhs, w * rhs);
	}
	
	inline v4 v4::operator / ( const float rhs ) const
	{
		return v4(x / rhs, y / rhs, z / rhs, w / rhs);
	}
	
	inline v4& v4::operator +=	( const v4& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline v4& v4::operator -=	( const v4& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline v4& v4::operator *=	( const v4& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline v4& v4::operator /=	( const v4& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline v4& v4::operator *=	( const float rhs )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		
		return *this;
	}
	
	inline v4& v4::operator /=	( const float rhs )
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		
		return *this;
	}
	
	inline v4 v4::Min( const v4& src1, const v4& src2 )
	{
		return v4(	src1.x < src2.x ? src1.x : src2.x,
				  src1.y < src2.y ? src1.y : src2.y,
				  src1.z < src2.z ? src1.z : src2.z,
				  src1.w < src2.w ? src1.w : src2.w);
	}
	
	inline v4 v4::Max( const v4& src1, const v4& src2 )
	{
		return v4(	src1.x > src2.x ? src1.x : src2.x,
				  src1.y > src2.y ? src1.y : src2.y,
				  src1.z > src2.z ? src1.z : src2.z,
				  src1.w > src2.w ? src1.w : src2.w);
	}
	
	inline v4 v4::Mul( const v4& src, const m44& matrix )
	{
		float x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z + matrix.m_rows[3].x * src.w;
		float y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z + matrix.m_rows[3].y * src.w;
		float z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[3].z * src.w;
		float w = matrix.m_rows[0].w * src.x + matrix.m_rows[1].w * src.y + matrix.m_rows[2].w * src.z + matrix.m_rows[3].w * src.w;
		
		return v4(x, y, z, w);
	}
	
	inline v4 v4::MulTransposed( const v4& src, const m44& matrix )
	{
		float x = matrix.m_rows[0].x * src.x + matrix.m_rows[0].y * src.y + matrix.m_rows[0].z * src.z + matrix.m_rows[0].w * src.w;
		float y = matrix.m_rows[1].x * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[1].z * src.z + matrix.m_rows[1].w * src.w;
		float z = matrix.m_rows[2].x * src.x + matrix.m_rows[2].y * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[2].w * src.w;
		float w = matrix.m_rows[3].x * src.x + matrix.m_rows[3].y * src.y + matrix.m_rows[3].z * src.z + matrix.m_rows[3].w * src.w;
		
		return v4(x, y, z, w);
	}
	
	inline v4 v4::Length() const
	{
		float dot = x * x + y * y + z * z + w * w;
		float length = Math::Sqrtf(dot);
		return v4(length, length, length, length);
	}
	
	inline v4 v4::LengthSq() const
	{
		return Dot(*this, *this);
	}
    
    
    inline dv4::dv4( const dv4& src )
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = src.w;
	}

    inline dv4::dv4( const dv3& src, double _w )
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = _w;
	}
	
	inline dv4::dv4( double _x, double _y, double _z, double _w )
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	
	inline dv4::dv4( const double* pSrc )
	{
		x = pSrc[0];
		y = pSrc[1];
		z = pSrc[2];
		w = pSrc[3];
	}
	
	inline dv4::dv4(const v4& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = src.w;
	}
    
    inline dv4::dv4(const v3& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = 0.0;
	}
	
	inline void	dv4::Set( double _x, double _y, double _z , double _w )
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	
	inline void dv4::SetZero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	inline dv4 dv4::SplatX() const
	{
		return dv4(x, x, x, x);
	}
	
	inline dv4 dv4::SplatY() const
	{
		return dv4(y, y, y, y);
	}
	
	inline dv4 dv4::SplatZ() const
	{
		return dv4(z, z, z, z);
	}
    
	inline dv4 dv4::SplatW() const
	{
		return dv4(w, w, w, w);
	}
	
	inline double dv4::GetX() const
	{
		return x;
	}
	
	inline double dv4::GetY() const
	{
		return y;
	}
	
	inline double dv4::GetZ() const
	{
		return z;
	}
    
	inline double dv4::GetW() const
	{
		return w;
	}
	
	inline void dv4::SetX( double data )
	{
		x = data;
	}
	
	inline void dv4::SetY( double data )
	{
		y = data;
	}
    
	inline void dv4::SetZ( double data )
	{
		z = data;
	}
    
	inline void dv4::SetW( double data )
	{
		w = data;
	}
    
	inline dv4 dv4::Add( const dv4& src1, const dv4& src2 )
	{
		return dv4(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z, src1.w + src2.w);
	}
	
	inline dv4 dv4::Sub( const dv4& src1, const dv4& src2 )
	{
		return dv4(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z, src1.w - src2.w);
	}
	
	inline dv4 dv4::Mul( const dv4& src1, const dv4& src2 )
	{
		return dv4(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z, src1.w * src2.w);
	}
	
	inline dv4 dv4::Div( const dv4& src1, const dv4& src2 )
	{
		return dv4(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z, src1.w / src2.w);
	}
    
	inline dv4 dv4::Add( const dv4& src1, const v4& src2 )
	{
		return dv4(src1.x + src2.x, src1.y + src2.y, src1.z + src2.z, src1.w + src2.w);
	}
	
	inline dv4 dv4::Sub( const dv4& src1, const v4& src2 )
	{
		return dv4(src1.x - src2.x, src1.y - src2.y, src1.z - src2.z, src1.w - src2.w);
	}
	
	inline dv4 dv4::Mul( const dv4& src1, const v4& src2 )
	{
		return dv4(src1.x * src2.x, src1.y * src2.y, src1.z * src2.z, src1.w * src2.w);
	}
	
	inline dv4 dv4::Div( const dv4& src1, const v4& src2 )
	{
		return dv4(src1.x / src2.x, src1.y / src2.y, src1.z / src2.z, src1.w / src2.w);
	}
    
	inline double dv4::Dot( const dv4& src1, const dv4& src2 )
	{
		double dot = src1.x * src2.x + src1.y * src2.y + src1.z * src2.z + src1.w * src2.w;
		return dot;
	}
	
	inline dv4 dv4::Lerp( const dv4& src1, const dv4& src2, double ratio )
	{
		dv4	temp = src2 * ratio;
		temp	+= src1 * (1.0 - ratio);
		return temp;
	}
    
	inline dv4 dv4::Mul( const dv4& src, const m44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[1].x * src.y + matrix.m_rows[2].x * src.z + matrix.m_rows[3].x * src.w;
		double y = matrix.m_rows[0].y * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[2].y * src.z + matrix.m_rows[3].y * src.w;
		double z = matrix.m_rows[0].z * src.x + matrix.m_rows[1].z * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[3].z * src.w;
		double w = matrix.m_rows[0].w * src.x + matrix.m_rows[1].w * src.y + matrix.m_rows[2].w * src.z + matrix.m_rows[3].w * src.w;
		
		return dv4(x, y, z, w);
	}
    
	inline dv4 dv4::MulTransposed( const dv4& src, const m44& matrix )
	{
		double x = matrix.m_rows[0].x * src.x + matrix.m_rows[0].y * src.y + matrix.m_rows[0].z * src.z + matrix.m_rows[0].w * src.w;
		double y = matrix.m_rows[1].x * src.x + matrix.m_rows[1].y * src.y + matrix.m_rows[1].z * src.z + matrix.m_rows[1].w * src.w;
		double z = matrix.m_rows[2].x * src.x + matrix.m_rows[2].y * src.y + matrix.m_rows[2].z * src.z + matrix.m_rows[2].w * src.w;
		double w = matrix.m_rows[3].x * src.x + matrix.m_rows[3].y * src.y + matrix.m_rows[3].z * src.z + matrix.m_rows[3].w * src.w;
		
		return dv4(x, y, z, w);
	}
	
    inline v4 dv4::ToSingle( const dv4& src)
    {
        return v4(static_cast<float>(src.x), static_cast<float>(src.y), static_cast<float>(src.z), static_cast<float>(src.w));
    }
    
    inline dv4 dv4::FromSingle( const v4& src)
    {
        return dv4(src.GetX(), src.GetY(), src.GetZ(), src.GetW());
    }
    
	inline dv4 dv4::Scale( const dv4& src, double scale )
	{
		return dv4(src.x * scale, src.y * scale, src.z * scale, src.w * scale);
	}
	
	inline dv4 dv4::InvScale( const dv4& src, double scale )
	{
		return dv4(src.x / scale, src.y / scale, src.z / scale, src.w / scale);
	}
	
	inline double dv4::Length() const
	{
		double dot = x * x + y * y + z * z + w * w;
		double length = Math::Sqrtd(dot);
		return length;
	}
	
	inline double dv4::LengthSq() const
	{
		return Dot(*this, *this);
	}
	
	inline dv4 dv4::Norm() const
	{
        double invMagnitude = 1.0 / Length();
		return dv4(x * invMagnitude, y * invMagnitude, z * invMagnitude, w * invMagnitude);
	}
    
    inline dv4& dv4::Normalise()
    {
        *this = Norm();
        return *this;
    }
    
    inline v4 dv4::ToSingle() const
    {
        return ToSingle(*this);
    }
    
	inline dv4 dv4::Neg(const dv4& src)
	{
		return dv4(-src.x, -src.y, -src.z, -src.w);
	}
	
	inline dv4 dv4::operator - () const
	{
		return Neg(*this);
	}
	
	inline dv4 dv4::operator + ( const v4& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline dv4 dv4::operator - ( const v4& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline dv4 dv4::operator * ( const v4& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline dv4 dv4::operator * ( const float rhs ) const
	{
		return Scale(*this, rhs);
	}
	
	inline dv4 dv4::operator / ( const v4& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline dv4 dv4::operator / ( const float rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline dv4& dv4::operator +=	( const v4& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator -=	( const v4& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator *=	( const v4& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator /=	( const v4& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
    
	
	inline dv4 dv4::operator + ( const dv4& rhs ) const
	{
		return Add(*this, rhs);
	}
	
	inline dv4 dv4::operator - ( const dv4& rhs ) const
	{
		return Sub(*this, rhs);
	}
	
	inline dv4 dv4::operator * ( const dv4& rhs ) const
	{
		return Mul(*this, rhs);
	}
	
	inline dv4 dv4::operator * ( const double rhs ) const
	{
		return Scale(*this, rhs);
	}
	
	inline dv4 dv4::operator / ( const dv4& rhs ) const
	{
		return Div(*this, rhs);
	}
	
	inline dv4 dv4::operator / ( const double rhs ) const
	{
		return InvScale(*this, rhs);
	}
	
	inline dv4& dv4::operator +=	( const dv4& rhs )
	{
		*this = Add(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator -=	( const dv4& rhs )
	{
		*this = Sub(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator *=	( const dv4& rhs )
	{
		*this = Mul(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator /=	( const dv4& rhs )
	{
		*this = Div(*this, rhs);
		return *this;
	}
	
	inline dv4& dv4::operator *=	( const double rhs )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		return *this;
	}
	
	inline dv4& dv4::operator /=	( const double rhs )
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		return *this;
	}
	
	inline dv4 dv4::Min( const dv4& src1, const dv4& src2 )
	{
		return dv4(	src1.x < src2.x ? src1.x : src2.x,
                   src1.y < src2.y ? src1.y : src2.y,
                   src1.z < src2.z ? src1.z : src2.z,
				   src1.w < src2.w ? src1.w : src2.w );
	}
	
	inline dv4 dv4::Max( const dv4& src1, const dv4& src2 )
	{
		return dv4(	src1.x > src2.x ? src1.x : src2.x,
                   src1.y > src2.y ? src1.y : src2.y,
                   src1.z > src2.z ? src1.z : src2.z,
				   src1.w > src2.w ? src1.w : src2.w );
	}
	
    
	inline void m33::Identity()
	{
		_11 = 1.0f; _12 = 0.0f; _13 = 0.0f;
		_21 = 0.0f; _22 = 1.0f; _23 = 0.0f;
		_31 = 0.0f; _32 = 0.0f; _33 = 1.0f;
	}
    
    inline m33 m33::CreateIdentity()
    {
        m33 newMatrix;
        newMatrix.Identity();
        return newMatrix;
    }
	
	inline void	m33::Transpose( m33& dst, const m33& src )
	{
		m33 temp = src;

        dst._11 = temp._11;
		dst._12 = temp._21;
		dst._13 = temp._31;

		dst._21 = temp._12;
        dst._22 = temp._22;
		dst._23 = temp._32;

		dst._31 = temp._13;
		dst._32 = temp._23;
        dst._33 = temp._33;
	}

	inline void	m33::SetRow	( int row, const v3& data )
	{
		float* dstRow = (&_11)+(row*3);
		dstRow[0] = data.GetX();
		dstRow[1] = data.GetY();
		dstRow[2] = data.GetZ();
	}

	inline void m33::SetFromBasis(const v3& right, const v3& up, const v3& forward)
	{
		SetRow(0, right);
		SetRow(1, up);
		SetRow(2, forward);
	}

	inline v3 m33::GetRow ( int row ) const
	{
		float x = *((&_11)+(row*3)+0);
		float y = *((&_11)+(row*3)+1);
		float z = *((&_11)+(row*3)+2);
		return v3(x, y, z);
	}

	inline void m33::Scale(float scale)
	{
		_11	= scale; 	_12 = 0.0f; 	_13 = 0.0f;
		_21	= 0.0f; 	_22 = scale; 	_23 = 0.0f;
		_31	= 0.0f; 	_32 = 0.0f; 	_33 = scale;
	}

	inline void m33::Scale(const v3& s)
	{
		_11	= s.GetX(); _12 = 0.0f; 	_13 = 0.0f;
		_21	= 0.0f; 	_22 = s.GetY();	_23 = 0.0f;
		_31	= 0.0f; 	_32 = 0.0f; 	_33 = s.GetZ();
	}

	inline void m33::RotateX(float theta)
	{
		Identity();

		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);

		SetRow(1, v3(0.0f, cos, -sin));
		SetRow(2, v3(0.0f, sin, cos));
	}

	inline void m33::RotateY(float theta)
	{
		Identity();

		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);

		SetRow(0, v3(cos, 0.0f, -sin));
		SetRow(2, v3(sin, 0.0f , cos));
	}

	inline void m33::RotateZ(float theta)
	{
		Identity();

		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);

		SetRow(0, v3(cos, -sin, 0.0f));
		SetRow(1, v3(sin, cos, 0.0f));
	}

	inline void m33::Rotate( float x, float y, float z )
	{
		m33	tempX;
		tempX.RotateX(x);
		m33	tempY;
		tempY.RotateY(-y);
		m33	tempZ;
		tempZ.RotateZ(z);
		m33	temp;

		Mul(temp, tempZ, tempY);
		Mul(*this, temp, tempX);
	}

	inline void m33::Rotate( const v3& axis, float angle )
	{
		float	c = Math::Cos(angle);
		float	s = Math::Sin(angle);
		float	t = 1.0f - c;

		float x = axis.GetX();
		float y = axis.GetY();
		float z = axis.GetZ();

		SetRow(0, v3(    (t*x*x) + c, (t*y*x) - (s*z), (t*z*x) + (s*y)));
		SetRow(1, v3((t*x*y) + (s*z),     (t*y*y) + c, (t*z*y) - (s*x)));
		SetRow(2, v3((t*x*z) - (s*y), (t*y*z) + (s*x),     (t*z*z) + c));
	}

	inline void m33::Mul( m33& dest, const m33& src1, const m33& src2 )
	{
		m33 temp;

		const v3& src1row0 = src1.GetRow(0);
		const v3& src1row1 = src1.GetRow(1);
		const v3& src1row2 = src1.GetRow(2);

		for(int i = 0; i < 3; i++)
		{
			const v3& src2rowI = src2.GetRow(i);

			float x = src2rowI.x * src1row0.x +
					  src2rowI.y * src1row1.x +
					  src2rowI.z * src1row2.x;

			float y = src2rowI.x * src1row0.y +
					  src2rowI.y * src1row1.y +
					  src2rowI.z * src1row2.y;

			float z = src2rowI.x * src1row0.z +
					  src2rowI.y * src1row1.z +
					  src2rowI.z * src1row2.z;

			temp.SetRow(i, v3(x, y, z));
		}

		memcpy(&dest, &temp, sizeof(dest));
	}

    inline void m33::Mul( const float scale )
	{
		_11 *= scale;
		_12 *= scale;
		_13 *= scale;
		_21 *= scale;
		_22 *= scale;
		_23 *= scale;
		_31 *= scale;
		_32 *= scale;
		_33 *= scale;
	}
    
    inline m44 m33::ToM44() const
    {
        m44 m;
        m.m_rows[0].Set(_11, _12, _13, 0.f);
        m.m_rows[1].Set(_21, _22, _23, 0.f);
        m.m_rows[2].Set(_31, _32, _33, 0.f);
        m.m_rows[3].Set(0.f, 0.f, 0.f, 1.f);
        return m;
    }
    
    inline m44 m44::CreateIdentity()
    {
        m44 newMatrix;
        newMatrix.Identity();
        return newMatrix;
    }
    
    inline m44 m44::CreateFromRowMajorElements( const float* pRowMajorElements )
	{
        m44 matrix;
        
		matrix.SetRow(0, Eegeo::v4(pRowMajorElements[0], pRowMajorElements[1], pRowMajorElements[2], pRowMajorElements[3]));
		matrix.SetRow(1, Eegeo::v4(pRowMajorElements[4], pRowMajorElements[5], pRowMajorElements[6], pRowMajorElements[7]));
        matrix.SetRow(2, Eegeo::v4(pRowMajorElements[8], pRowMajorElements[9], pRowMajorElements[10], pRowMajorElements[11]));
		matrix.SetRow(3, Eegeo::v4(pRowMajorElements[12], pRowMajorElements[13], pRowMajorElements[14], pRowMajorElements[15]));
        
        return matrix;
	}
    
	inline m44::m44( const v4& row0, const v4& row1, const v4& row2, const v4& row3 )
	{
		m_rows[0]	= row0;
		m_rows[1]	= row1;
		m_rows[2]	= row2;
		m_rows[3]	= row3;
	}

    inline m44::m44(float values[16])
    {
        m_rows[0] = v4(values[0], values[1], values[2], values[3]);
        m_rows[1] = v4(values[4], values[5], values[6], values[7]);
        m_rows[2] = v4(values[8], values[9], values[10], values[11]);
        m_rows[3] = v4(values[12], values[13], values[14], values[15]);
    }

    inline void m44::SetFromBasis(const v3& right, const v3& up, const v3& forward, const v3& pos)
    {
        m_rows[0] = v4(right, 0.f);
        m_rows[1] = v4(up, 0.f);
        m_rows[2] = v4(forward, 0.f);
        m_rows[3] = v4(pos, 1.f);
    }
	
	inline void m44::Load( const float* pSrc )
	{
		m_rows[0].Load(&pSrc[0]);
		m_rows[1].Load(&pSrc[4]);
		m_rows[2].Load(&pSrc[8]);
		m_rows[3].Load(&pSrc[12]);
	}
	
	inline void	m44::Store( float* pDest ) const
	{
		GetRow(0).Store(&pDest[0]);
		GetRow(1).Store(&pDest[4]);
		GetRow(2).Store(&pDest[8]);
		GetRow(3).Store(&pDest[12]);
	}
	
	inline void m44::Identity()
	{
		m_rows[0].x	= 1.0f; m_rows[0].y	= 0.0f; m_rows[0].z	= 0.0f; m_rows[0].w	= 0.0f;
		m_rows[1].x	= 0.0f; m_rows[1].y	= 1.0f; m_rows[1].z	= 0.0f; m_rows[1].w	= 0.0f;
		m_rows[2].x	= 0.0f; m_rows[2].y	= 0.0f; m_rows[2].z	= 1.0f; m_rows[2].w	= 0.0f;
		m_rows[3].x	= 0.0f; m_rows[3].y	= 0.0f; m_rows[3].z	= 0.0f; m_rows[3].w	= 1.0f;
	}
    
    inline bool m44::IsIdentity() const
    {
        return
        (
         (m_rows[0].x == 1.0f) && (m_rows[0].y == 0.0f) && (m_rows[0].z == 0.0f) && (m_rows[0].w == 0.0f) &&
         (m_rows[1].x == 0.0f) && (m_rows[1].y == 1.0f) && (m_rows[1].z == 0.0f) && (m_rows[1].w == 0.0f) &&
         (m_rows[2].x == 0.0f) && (m_rows[2].y == 0.0f) && (m_rows[2].z == 1.0f) && (m_rows[2].w == 0.0f) &&
         (m_rows[3].x == 0.0f) && (m_rows[3].y == 0.0f) && (m_rows[3].z == 0.0f) && (m_rows[3].w == 1.0f)
        );        
    }
	
	inline void m44::Scale(float scale)
	{
		m_rows[0].x	= scale; m_rows[0].y	=  0.0f; m_rows[0].z	=  0.0f; m_rows[0].w	=  0.0f;
		m_rows[1].x	=  0.0f; m_rows[1].y	= scale; m_rows[1].z	=  0.0f; m_rows[1].w	=  0.0f;
		m_rows[2].x	=  0.0f; m_rows[2].y	=  0.0f; m_rows[2].z	= scale; m_rows[2].w	=  0.0f;
		m_rows[3].x	=  0.0f; m_rows[3].y	=  0.0f; m_rows[3].z	=  0.0f; m_rows[3].w	=  1.0f;
	}
	
	inline void m44::Scale(const v3& scale)
	{
		m_rows[0] = v4(scale.GetX(),         0.0f,         0.0f, 0.0f);
		m_rows[1] = v4(        0.0f, scale.GetY(),         0.0f, 0.0f);
		m_rows[2] = v4(        0.0f,         0.0f, scale.GetZ(), 0.0f);
		m_rows[3] = v4(        0.0f,         0.0f,         0.0f, 1.0f);
	}
	
	inline void m44::RotateX(float theta)
	{
		Identity();
		
		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);
		
		m_rows[1]	= v4(0.0f, cos, -sin, 0.0f);
		m_rows[2]	= v4(0.0f, sin,  cos, 0.0f);
	}
	
	inline void m44::RotateY(float theta)
	{
		Identity();
		
		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);
		
		m_rows[0]	= v4( cos, 0.0f,-sin, 0.0f);
		m_rows[2]	= v4( sin, 0.0f, cos, 0.0f);
	}
	
	inline void m44::RotateZ(float theta)
	{
		Identity();
		
		float sin = Math::Sin(theta);
		float cos = Math::Cos(theta);
		
		m_rows[0]	= v4(cos, -sin, 0.0f, 0.0f);
		m_rows[1]	= v4(sin,  cos, 0.0f, 0.0f);
	}
	
	inline void m44::Rotate( float x, float y, float z )
	{
		m44	tempX;
		tempX.RotateX(x);
		m44	tempY;
		tempY.RotateY(-y);
		m44	tempZ;
		tempZ.RotateZ(z);
		
		m44	temp;

		Mul(temp, tempZ, tempY);
		Mul(*this, temp, tempX);
	}
	
	inline void m44::Rotate( const v3& axis, float angle )
	{
		float	c = Math::Cos(angle);
		float	s = Math::Sin(angle);
		float	t = 1.0f - c;
		
		float x = axis.GetX();
		float y = axis.GetY();
		float z = axis.GetZ();
		
		SetRow(0, v4(    (t*x*x) + c, (t*y*x) - (s*z), (t*z*x) + (s*y), 0.0f));
		SetRow(1, v4((t*x*y) + (s*z),     (t*y*y) + c, (t*z*y) - (s*x), 0.0f));
		SetRow(2, v4((t*x*z) - (s*y), (t*y*z) + (s*x),     (t*z*z) + c, 0.0f));
		SetRow(3, v4(0.0f, 0.0f, 0.0f, 1.0f));
	}
	
	inline void m44::Transpose(m44& dst, const m44& src)
	{
        m44 temp = src;

        v4 r0 = temp.GetRow(0);
        v4 r1 = temp.GetRow(1);
        v4 r2 = temp.GetRow(2);
        v4 r3 = temp.GetRow(3);

        dst.SetRow(0, v4(r0.x, r1.x, r2.x, r3.x));
        dst.SetRow(1, v4(r0.y, r1.y, r2.y, r3.y));
        dst.SetRow(2, v4(r0.z, r1.z, r2.z, r3.z));
        dst.SetRow(3, v4(r0.w, r1.w, r2.w, r3.w));
	}
	
	inline void m44::OrthoInverse(m44& dst, const m44& src)
	{
		v3 trans = v3(src.GetRow(3));
		
		v4 zero;
		zero.SetZero();
		
		dst = src;
		dst.SetRow(3, zero);
		
		Transpose(dst, dst);
		
		trans = -v3::MulRotate(trans, dst);
		
		dst.SetRow(3, v4(trans, 1.0f));
	}
	
	inline void m44::Mul( m44& dest, const m44& src1, const m44& src2 )
	{
		m44 temp;
		for(int i = 0; i < 4; i++)
		{			
			temp.m_rows[i].x = src2.m_rows[i].x * src1.m_rows[0].x + src2.m_rows[i].y * src1.m_rows[1].x + src2.m_rows[i].z * src1.m_rows[2].x + src2.m_rows[i].w * src1.m_rows[3].x;
			temp.m_rows[i].y = src2.m_rows[i].x * src1.m_rows[0].y + src2.m_rows[i].y * src1.m_rows[1].y + src2.m_rows[i].z * src1.m_rows[2].y + src2.m_rows[i].w * src1.m_rows[3].y;
			temp.m_rows[i].z = src2.m_rows[i].x * src1.m_rows[0].z + src2.m_rows[i].y * src1.m_rows[1].z + src2.m_rows[i].z * src1.m_rows[2].z + src2.m_rows[i].w * src1.m_rows[3].z;
			temp.m_rows[i].w = src2.m_rows[i].x * src1.m_rows[0].w + src2.m_rows[i].y * src1.m_rows[1].w + src2.m_rows[i].z * src1.m_rows[2].w + src2.m_rows[i].w * src1.m_rows[3].w;
			
		}
		
		memcpy(&dest, &temp, sizeof(dest));
	}
    
    inline void m44::Lerp( m44& dst, const m44& from, const m44& to, float t )
    {
        for (int i = 0; i < 4; ++i)
        {
            const Eegeo::v4& va = from.GetRow(i);
            const Eegeo::v4& vb = to.GetRow(i);
            Eegeo::v4 dest = Eegeo::v4::Lerp(va, vb, t);
            dst.SetRow(i, dest);
        }
    }
    
    inline void m44::Mul( const float scale )
	{
		for(int i = 0; i < 4; i++)
		{
			m_rows[i].x *= scale;
			m_rows[i].y *= scale;
			m_rows[i].z *= scale;
			m_rows[i].w *= scale;
		}
	}


	inline dm44::dm44( const dv4& row0, const dv4& row1, const dv4& row2, const dv4& row3 )
	{
		m_rows[0]	= row0;
		m_rows[1]	= row1;
		m_rows[2]	= row2;
		m_rows[3]	= row3;
	}

    inline void dm44::SetFromBasis(const dv3& right, const dv3& up, const dv3& forward, const dv3& pos)
    {
        m_rows[0].Set(right.GetX(), right.GetY(), right.GetZ(), 0.0);
        m_rows[1].Set(up.GetX(), up.GetY(), up.GetZ(), 0.0);
        m_rows[2].Set(forward.GetX(), forward.GetY(), forward.GetZ(), 0.0);
        m_rows[3].Set(pos.GetX(), pos.GetY(), pos.GetZ(), 1.0);
    }

	inline void dm44::Identity()
	{
		m_rows[0].x	= 1.0f; m_rows[0].y	= 0.0f; m_rows[0].z	= 0.0f; m_rows[0].w	= 0.0f;
		m_rows[1].x	= 0.0f; m_rows[1].y	= 1.0f; m_rows[1].z	= 0.0f; m_rows[1].w	= 0.0f;
		m_rows[2].x	= 0.0f; m_rows[2].y	= 0.0f; m_rows[2].z	= 1.0f; m_rows[2].w	= 0.0f;
		m_rows[3].x	= 0.0f; m_rows[3].y	= 0.0f; m_rows[3].z	= 0.0f; m_rows[3].w	= 1.0f;
	}

	inline void dm44::Scale(double scale)
	{
		m_rows[0].x	= scale; m_rows[0].y	=  0.0f; m_rows[0].z	=  0.0f; m_rows[0].w	=  0.0f;
		m_rows[1].x	=  0.0f; m_rows[1].y	= scale; m_rows[1].z	=  0.0f; m_rows[1].w	=  0.0f;
		m_rows[2].x	=  0.0f; m_rows[2].y	=  0.0f; m_rows[2].z	= scale; m_rows[2].w	=  0.0f;
		m_rows[3].x	=  0.0f; m_rows[3].y	=  0.0f; m_rows[3].z	=  0.0f; m_rows[3].w	=  1.0f;
	}

	inline void dm44::Scale(const dv3& scale)
	{
		m_rows[0] = dv4(scale.GetX(),         0.0f,         0.0f, 0.0f);
		m_rows[1] = dv4(        0.0f, scale.GetY(),         0.0f, 0.0f);
		m_rows[2] = dv4(        0.0f,         0.0f, scale.GetZ(), 0.0f);
		m_rows[3] = dv4(        0.0f,         0.0f,         0.0f, 1.0f);
	}

	inline void dm44::RotateX(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		m_rows[1]	= dv4(0.0f, cos, -sin, 0.0f);
		m_rows[2]	= dv4(0.0f, sin,  cos, 0.0f);
	}

	inline void dm44::RotateY(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		m_rows[0]	= dv4( cos, 0.0f,-sin, 0.0f);
		m_rows[2]	= dv4( sin, 0.0f, cos, 0.0f);
	}

	inline void dm44::RotateZ(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		m_rows[0]	= dv4(cos, -sin, 0.0f, 0.0f);
		m_rows[1]	= dv4(sin,  cos, 0.0f, 0.0f);
	}

	inline void dm44::Rotate( double x, double y, double z )
	{
		dm44	tempX;
		tempX.RotateX(x);
		dm44	tempY;
		tempY.RotateY(-y);
		dm44	tempZ;
		tempZ.RotateZ(z);

		dm44	temp;

		Mul(temp, tempZ, tempY);
		Mul(*this, temp, tempX);
	}

	inline void dm44::Rotate( const dv3& axis, double angle )
	{
		double	c = std::cos(angle);
		double	s = std::sin(angle);
		double	t = 1.0f - c;

		double x = axis.GetX();
		double y = axis.GetY();
		double z = axis.GetZ();

		SetRow(0, dv4(    (t*x*x) + c, (t*y*x) - (s*z), (t*z*x) + (s*y), 0.0f));
		SetRow(1, dv4((t*x*y) + (s*z),     (t*y*y) + c, (t*z*y) - (s*x), 0.0f));
		SetRow(2, dv4((t*x*z) - (s*y), (t*y*z) + (s*x),     (t*z*z) + c, 0.0f));
		SetRow(3, dv4(0.0f, 0.0f, 0.0f, 1.0f));
	}

	inline void dm44::Transpose(dm44& dst, const dm44& src)
	{
        dm44 temp = src;

        dv4 r0 = temp.GetRow(0);
        dv4 r1 = temp.GetRow(1);
        dv4 r2 = temp.GetRow(2);
        dv4 r3 = temp.GetRow(3);

        dst.SetRow(0, dv4(r0.x, r1.x, r2.x, r3.x));
        dst.SetRow(1, dv4(r0.y, r1.y, r2.y, r3.y));
        dst.SetRow(2, dv4(r0.z, r1.z, r2.z, r3.z));
        dst.SetRow(3, dv4(r0.w, r1.w, r2.w, r3.w));
	}

	inline void dm44::OrthoInverse(dm44& dst, const dm44& src)
	{
		dv3 trans = dv3(src.GetRow(3));

		dv4 zero;
		zero.SetZero();

		dst = src;
		dst.SetRow(3, zero);

		Transpose(dst, dst);

		trans = -dv3::MulRotate(trans, dst);

		dst.SetRow(3, dv4(trans, 1.0f));
	}

	inline void dm44::Mul( dm44& dest, const dm44& src1, const dm44& src2 )
	{
		dm44 temp;
		for(int i = 0; i < 4; i++)
		{
			temp.m_rows[i].x = src2.m_rows[i].x * src1.m_rows[0].x + src2.m_rows[i].y * src1.m_rows[1].x + src2.m_rows[i].z * src1.m_rows[2].x + src2.m_rows[i].w * src1.m_rows[3].x;
			temp.m_rows[i].y = src2.m_rows[i].x * src1.m_rows[0].y + src2.m_rows[i].y * src1.m_rows[1].y + src2.m_rows[i].z * src1.m_rows[2].y + src2.m_rows[i].w * src1.m_rows[3].y;
			temp.m_rows[i].z = src2.m_rows[i].x * src1.m_rows[0].z + src2.m_rows[i].y * src1.m_rows[1].z + src2.m_rows[i].z * src1.m_rows[2].z + src2.m_rows[i].w * src1.m_rows[3].z;
			temp.m_rows[i].w = src2.m_rows[i].x * src1.m_rows[0].w + src2.m_rows[i].y * src1.m_rows[1].w + src2.m_rows[i].z * src1.m_rows[2].w + src2.m_rows[i].w * src1.m_rows[3].w;

		}

		memcpy(&dest, &temp, sizeof(dest));
	}

    inline void dm44::Mul( const double scale )
	{
		for(int i = 0; i < 4; i++)
		{
			m_rows[i].x *= scale;
			m_rows[i].y *= scale;
			m_rows[i].z *= scale;
			m_rows[i].w *= scale;
		}
	}

	inline void dm33::Identity()
	{
		_11 = 1.0; _12 = 0.0; _13 = 0.0;
		_21 = 0.0; _22 = 1.0; _23 = 0.0;
		_31 = 0.0; _32 = 0.0; _33 = 1.0;
	}

	inline void	dm33::Transpose( dm33& dst, const dm33& src )
	{
        dm33 temp = src;

        dst._11 = temp._11;
        dst._12 = temp._21;
        dst._13 = temp._31;

        dst._21 = temp._12;
        dst._22 = temp._22;
        dst._23 = temp._32;

        dst._31 = temp._13;
        dst._32 = temp._23;
        dst._33 = temp._33;
	}

	inline void	dm33::SetRow	( int row, const dv3& data )
	{
		double* dstRow = (&_11)+(row*3);
		dstRow[0] = data.GetX();
		dstRow[1] = data.GetY();
		dstRow[2] = data.GetZ();
	}

	inline void dm33::SetFromBasis(const dv3& right, const dv3& up, const dv3& forward)
	{
		SetRow(0, right);
		SetRow(1, up);
		SetRow(2, forward);
	}

	inline dv3 dm33::GetRow ( int row ) const
	{
		double x = *((&_11)+(row*3)+0);
		double y = *((&_11)+(row*3)+1);
		double z = *((&_11)+(row*3)+2);
		return dv3(x, y, z);
	}

	inline void dm33::Scale(double scale)
	{
		_11	= scale; _12 = 0.0; _13 = 0.0;
		_21	= 0.0; _22 = scale; _23 = 0.0;
		_31	= 0.0; _32 = 0.0; _33 = scale;
	}

	inline void dm33::Scale(const dv3& s)
	{
		_11	= s.GetX(); _12 = 0.0; _13 = 0.0;
		_21	= 0.0; _22 = s.GetY(); _23 = 0.0;
		_31	= 0.0; _32 = 0.0; _33 = s.GetZ();
	}

	inline void dm33::RotateX(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		SetRow(1, dv3(0.0, cos, -sin));
		SetRow(2, dv3(0.0, sin, cos));
	}

	inline void dm33::RotateY(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		SetRow(0, dv3(cos, 0.0, -sin));
		SetRow(2, dv3(sin, 0.0 , cos));
	}

	inline void dm33::RotateZ(double theta)
	{
		Identity();

		double sin = std::sin(theta);
		double cos = std::cos(theta);

		SetRow(0, dv3(cos, -sin, 0.0));
		SetRow(1, dv3(sin, cos, 0.0));
	}

	inline void dm33::Rotate( double x, double y, double z )
	{
		dm33	tempX;
		tempX.RotateX(x);
		dm33	tempY;
		tempY.RotateY(-y);
		dm33	tempZ;
		tempZ.RotateZ(z);
		dm33	temp;

		Mul(temp, tempZ, tempY);
		Mul(*this, temp, tempX);
	}

	inline void dm33::Rotate( const dv3& axis, double angle )
	{
		double	c = std::cos(angle);
		double	s = std::sin(angle);
		double	t = 1.0 - c;

		double x = axis.GetX();
		double y = axis.GetY();
		double z = axis.GetZ();

		SetRow(0, dv3(    (t*x*x) + c, (t*y*x) - (s*z), (t*z*x) + (s*y)));
		SetRow(1, dv3((t*x*y) + (s*z),     (t*y*y) + c, (t*z*y) - (s*x)));
		SetRow(2, dv3((t*x*z) - (s*y), (t*y*z) + (s*x),     (t*z*z) + c));
	}

	inline void dm33::Mul( dm33& dest, const dm33& src1, const dm33& src2 )
	{
		dm33 temp;

		const dv3& src1row0 = src1.GetRow(0);
		const dv3& src1row1 = src1.GetRow(1);
		const dv3& src1row2 = src1.GetRow(2);

		for(int i = 0; i < 3; i++)
		{
			const dv3& src2rowI = src2.GetRow(i);

			double x = src2rowI.x * src1row0.x +
					  src2rowI.y * src1row1.x +
					  src2rowI.z * src1row2.x;

			double y = src2rowI.x * src1row0.y +
					  src2rowI.y * src1row1.y +
					  src2rowI.z * src1row2.y;

			double z = src2rowI.x * src1row0.z +
					  src2rowI.y * src1row1.z +
					  src2rowI.z * src1row2.z;

			temp.SetRow(i, dv3(x, y, z));
		}

		memcpy(&dest, &temp, sizeof(dest));
	}

    inline void dm33::Mul( const double scale )
	{
		_11 *= scale;
		_12 *= scale;
		_13 *= scale;
		_21 *= scale;
		_22 *= scale;
		_23 *= scale;
		_31 *= scale;
		_32 *= scale;
		_33 *= scale;
	}
}
