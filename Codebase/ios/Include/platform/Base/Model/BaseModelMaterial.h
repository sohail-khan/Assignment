// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include "EffectHandler.h"
#include "PODMaterial.h"
#include "AsyncTexturing.h"

#include <vector>
#include <string>

namespace Eegeo
{
	typedef enum {
		
		MATERIAL_TYPE_STANDARD,
		MATERIAL_TYPE_MULTI
		
	} MATERIAL_TYPE;

	enum MaterialFlags
	{
		kMaterialFlag_None		= 0x00000000,
		kMaterialFlag_Blend		= 0x00000001,
		
		kMaterialFlag_Default	= kMaterialFlag_None,
	};
	
	class ModelMaterial
	{
        std::string m_name;
        
		Eegeo::EffectHandler::GraphicsEffect m_effect;

		s32 m_diffuseTexturePodId;
        u32 m_diffuseTextureGlId;
        
		s32 m_shadowMapTextureID;
		s32 m_shaderIndex;
		
		float m_animUScale;
		float m_animVScale;
		
		u32 m_materialFlags;
                
        float m_alpha;
        
        void InitFromPODMaterial(const IO::POD::PODMaterial* podMaterial, bool isPreLit);
 		
	public:
		ModelMaterial();
		~ModelMaterial();
        
        static ModelMaterial* CreateFromPODMaterial(const IO::POD::PODMaterial* podMaterial, bool isPreLit);

        const std::string& GetName() const;
        
        typedef std::vector<Eegeo::Rendering::AsyncTexturing::IAsyncTexture*> TTexturesByPodId;
		bool AssignTexture (const TTexturesByPodId& texturesByPodId);
		
		void 				Use 				(Eegeo::Rendering::GLState& glState);
		
		Eegeo::EffectHandler::GraphicsEffect GetEffect 			();
		void            	SetEffect 			(Eegeo::EffectHandler::GraphicsEffect effect);
		
		u32 GetDiffuseTexture();
		void SetDiffuseTexture(u32 pTexture);
		
		float				GetAnumUScale		();
		void 				SetAnumUScale		(float scale);
		
		float				GetAnumVScale		();
		void 				SetAnumVScale		(float scale);

		
		bool				IsAlpha				() const { return (m_materialFlags & kMaterialFlag_Blend); }

		u32           		GetMaterialFlags	() const { return (m_materialFlags); }
        void                SetAlpha            (float value)
        {
            m_materialFlags |= kMaterialFlag_Blend;
            m_alpha = value;
        }
        float GetAlpha(void) const;
	};
}
