// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Lighting.h"

#include <vector>

#define EFFECTMANAGER_MAX_EFFECTS       (8)

namespace Eegeo
{
    class Effect;
    
	class EffectHandler 
	{
    public:
        enum GraphicsEffect
        {
            kGraphicsEffectLightTex = 0,
            kGraphicsEffectPrelitTex,
            kGraphicsNumEffects
        };
    private:
        
		static std::vector <Effect*> m_effectList;
		static s32			m_nCurrentEffect;
		
		
		static Eegeo::m44     m_modelMatrix;
		static Eegeo::m44     m_viewMatrix;
		static Eegeo::m44     m_projectionMatrix;
		
		static Eegeo::m44     m_viewProjMatrix;
		static Eegeo::m44     m_modelViewProjectionMatrix;
		static Eegeo::m44    	m_boneMatrices[32];
		static Eegeo::m44     m_modelViewMatrix;
		
		static Eegeo::m33     m_invModelMatrix;
		
		static Eegeo::v4		m_modelWorldOffset;

		static Eegeo::v3      m_v3EyePosition;
		static float        m_fScale;
		
		static u32			m_numBoneMatrices;
		
		static Eegeo::v3      m_v3LightDirection[3];
		static Eegeo::v3      m_v3LightColor[3];
		static Eegeo::v3      m_v3LightAmbient;
		static s32			m_anTextureIndex[4];

		static Eegeo::v4      m_v4AnimUVSettings;

		static float		m_fShadowExtrudedHeightAdjust;
        static float        m_fAlpha;
		
		static void UpdateModelViewProjectionMatrix 	();
		static void UpdateModelBoneMatrices				();
		static void UpdateModelViewMatrix 				();
		static void UpdateModelWorldOffset 				();
		static void UpdateLightDirection 				();
		static void UpdateLightColor 					();
		static void UpdateLightAmbient 					();
		static void UpdateTextureIndex 					(u32 channel);
		static void UpdateEyePosition 					();    
		static void UpdateScale 						(); 
		static void UpdateAnimUVSettings 				();
		static void UpdateShadowExtrudedHeightAdjust 	();
    public:
        static void UpdateAlpha                         ();
    private:
		static void CalculateModelViewProjectionMatrix 	();
		static void CalculateInvModelMatrix 			();
        static void CalculateInvModelMatrixUniformScale ();
		static void CalculateModelViewMatrix 			();
		
		static u32 				m_effectIndexList [kGraphicsNumEffects];
		
	public:
        
        static void Temp_UpdateFromRenderContext(const Eegeo::Rendering::RenderContext& renderContext);
		
		static void    			Initialise 			();
		static void    		 	Shutdown 			();
		static void				Reset 				();
    private:
		static s32				AddEffect			(Effect* effect);
		static Effect*			GetEffect 			(u32 effectIndex);
        static void				UseEffect_GlState   (u32 effectIndex, Rendering::GLState& glState);
        static void CreateEffects();
        static void DestroyEffects();
        static void AddEffectByType(GraphicsEffect effectType, Effect* effect);
        static Effect* GetEffectByType(GraphicsEffect effectType);
		
		static void    			PreWarmEffects		();
    public:
        static void UseEffectByType_GlState(GraphicsEffect effectType, Rendering::GLState& glState);
        
		static void    			SetModelMatrix 		(const Eegeo::m44& matrix);
        static void    			SetModelMatrixUniformScale(const Eegeo::m44& matrix);
		static void    			SetViewMatrix 		(const Eegeo::m44& matrix);
		static void    			SetProjectionMatrix (const Eegeo::m44& matrix);

		static void    			SetModelWorldOffset	(const Eegeo::v4& offset);
		
		static void    			SetEyePosition 		(const Eegeo::v3& position);
		static void    			SetScale 			(float scale);
		
		static void     		SetAnimUVSettings 	(const Eegeo::v4& settings);
		static void				SetLightDirection 	(u32 lightIndex, const Eegeo::v3& direction);
		static void    			SetLightColor 		(u32 lightIndex, const Eegeo::v3& colour);
		static void    			SetLightAmbient		(const Eegeo::v3& ambient);

		static void     		SetShadowExtrudedHeightAdjust	(float fValue);
		static void     		SetAlpha                        (float fValue);
	
		static void    			SetTexture 			(u32 channel, u32 textureIndex);
		static void    			SetDirty 			();

		static const Eegeo::m44*	GetModelViewProjectionMatrix ();

		static const Eegeo::v4* 	GetAnimUVSettings 	();
		static const Eegeo::v3*	GetLightDirection 	(u32 lightIndex);
		static const Eegeo::v3* 	GetLightColor 		(u32 lightIndex);
		static const Eegeo::v3* 	GetLightAmbient 	();
		
		static void				SetNumSkinMatrices	( u32 munSkinMatrices ) 			{ m_numBoneMatrices = munSkinMatrices; }
		static void				SetSkinMatrix		( const Eegeo::m44& bone, u32 index ) { m_boneMatrices[index] = bone; }

        static void SetFogState(const Lighting::GlobalFoggingUniformValues& foggingValues);
        static void SetPerMaterialFogState(const Lighting::GlobalFoggingUniformValues& foggingValues);
        static void SetPerModelFogState(const Eegeo::v3& cameraRelativeModelOrigin);
	};
}
