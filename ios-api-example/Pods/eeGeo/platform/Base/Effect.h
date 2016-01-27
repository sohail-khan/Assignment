// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "FogShaderUniforms.h"
#include "Lighting.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
	typedef enum
	{
		EFFECT_ATTRIB_INVALID = 0xffffffff,

		EFFECT_ATTRIB_VERTEX = 0,
		EFFECT_ATTRIB_NORMAL,
		EFFECT_ATTRIB_COLOR,
		EFFECT_ATTRIB_UV0,
		EFFECT_ATTRIB_UV1,
		EFFECT_ATTRIB_FLOAT1,
		EFFECT_ATTRIB_FLOAT2,
		EFFECT_ATTRIB_BONE_WEIGHT,
		EFFECT_ATTRIB_BONE_INDEX,
		
		NUM_ATTRIBUTES

	} EFFECT_ATTRIB;

	typedef enum
	{
		EFFECT_UNIFORM_INVALID = 0xffffffff,
		
		EFFECT_UNIFORM_MATRIX44_MODELVIEWPROJECTION = 0,
		EFFECT_UNIFORM_MATRIX44_MODELVIEW,
		EFFECT_UNIFORM_VECTOR4_MODELWORLDOFFSET,
		EFFECT_UNIFORM_VECTOR3_LIGHTDIR,
		EFFECT_UNIFORM_VECTOR3_LIGHTCOL,
		EFFECT_UNIFORM_VECTOR3_LIGHTAMBIENT,
		EFFECT_UNIFORM_VECTOR3_EYEPOSITION,
		EFFECT_UNIFORM_TEXTURE0,
		EFFECT_UNIFORM_TEXTURE1,
		EFFECT_UNIFORM_NORMALMAP,
		EFFECT_UNIFORM_REFLECTIONMAP,
		EFFECT_UNIFORM_MATRIX44_LIGHTDIR,
		EFFECT_UNIFORM_MATRIX44_LIGHTCOL,
		EFFECT_UNIFORM_FLOAT_SCALE,    
		
		EFFECT_UNIFORM_MATRIX44_BONE_LIST,

		EFFECT_UNIFORM_VECTOR4_ANIMUV,

		EFFECT_UNIFORM_FLOAT_SHADOWEXTRUDEDHEIGHTADJUST,
        
        EFFECT_UNIFORM_FLOAT_ALPHA,
		NUM_UNIFORMS,
		
	} EFFECT_UNIFORM;


	class Effect {

		u32 m_uProgram;
		s32 m_uniforms[NUM_UNIFORMS];
        
        Rendering::Shaders::FogShaderUniforms m_fogShaderUniforms;
		
		bool LinkProgram 	(s32 prog);
		
	public:
		
		Effect				();
		~Effect				();
		
		void LoadEffect 	(std::string& vertShaderSource,
                             std::string& fragShaderSource,
                             EFFECT_ATTRIB* attribList,
                             u32 numAttribs,
                             EFFECT_UNIFORM* uniformList,
                             u32 numUniforms);

		void PreWarm 		(Rendering::GLState& glState);


        void UseProgram_GlState (Eegeo::Rendering::GLState& glState);

		
		bool IsUniformValid (EFFECT_UNIFORM uniform);

		void SetInt 		(EFFECT_UNIFORM uniform, int val);
		void SetFloat 		(EFFECT_UNIFORM uniform, float val);
		void SetVector2 	(EFFECT_UNIFORM uniform, const Eegeo::v2* vector);
		void SetVector3 	(EFFECT_UNIFORM uniform, const Eegeo::v3* vector);
		void SetVector4 	(EFFECT_UNIFORM uniform, const Eegeo::v4* vector);
		void SetMatrix33 	(EFFECT_UNIFORM uniform, const Eegeo::m33* matrix);
		void SetMatrix44 	(EFFECT_UNIFORM uniform, const Eegeo::m44* matrix);
		void SetMatrix44List(EFFECT_UNIFORM uniform, const Eegeo::m44* matrix, u32 numMatrices);
        void SetFogState(const Lighting::GlobalFoggingUniformValues& foggingValues, const Eegeo::v3& cameraRelativeModelOrigin);
        void SetPerMaterialFogState(const Lighting::GlobalFoggingUniformValues& foggingValues);
        void SetPerModelFogState(const Eegeo::v3& cameraRelativeModelOrigin);
		
	};
}
