// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterialProvider.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "CityThemes.h"
#include "IdTypes.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        class EnvironmentMaterialRepository : protected Eegeo::NonCopyable, public IMaterialProvider
        {
        private:
            IMaterialRepository* m_pDiffuseMaterialRepository;
            IMaterialRepository* m_pLightMappedDiffuseMaterialRepository;
            IMaterialRepository* m_pFoggedMaterialRepository;
            IMaterialRepository* m_pTransitionMaterialRepository;
            
            IMaterialRepository* m_pCurrentMaterialRepository;

        public:
            EnvironmentMaterialRepository(
                                          IMaterialRepository& diffuseMaterialRepository,
                                          IMaterialRepository& lightMappedMaterialRepository,
                                          IMaterialRepository& foggedMaterialRepository,
                                          IMaterialRepository& transitionMaterialRepository
                                         );

            ~EnvironmentMaterialRepository();
            
            bool ContainsMaterial(const std::string& materialName) const;
            
            Rendering::Materials::IMaterial* GetMaterial(const std::string& materialName) const;
            
            std::vector<Rendering::Materials::IMaterial*> GetMaterials() const;
            
            void SetCurrentRepository(const Resources::CityThemes::CityThemeState& fromState, const EnvironmentStateTextures& fromTextures, const Resources::CityThemes::CityThemeState& toState, const EnvironmentStateTextures& toTextures);
            
            void UpdateMaterials(float deltaTime, const dv3& ecefCameraPosition);
            
            void UpdateAnimatedEnvironmentMaterials(float deltaTime, const dv3& ecefCameraPosition, IMaterialRepository* pRepository);
            
            void SetTransitionParam(float t);
            
        private:
            void SetFromToDiffuseTextures(const EnvironmentStateTextures& fromStateTextures, const EnvironmentStateTextures& toStateTextures, const std::string& fromLandmarkPostfix, const std::string& toLandmarkPostfix);
            
            void SetFromToTexturesOnMaterial(const std::string& materialName, TTextureId fromTextureId, TTextureId toTextureId);
            
            void SetFromToTexturesOnLightmappedMaterial(const std::string& materialName, TTextureId fromTextureId, TTextureId toTextureId);
            
            void SetDiffuseTextures(const EnvironmentStateTextures& stateTextures, const std::string& landmarkPostfix);
            
            void SetSingleTextureOnMaterial(const std::string& materialName, TTextureId textureId);
            
            void SetWaterTexturesOnWaterMaterial(const std::string& materialName, TTextureId diffuseTextureId, TTextureId normalMapTextureId, TTextureId reflectionMapTextureId);
            
            void SetWaterTexturesOnWaterTransitionMaterial(const std::string& materialName, TTextureId fromDiffuseTextureId, TTextureId toDiffuseTextureId, TTextureId normalMapTextureId, TTextureId fromReflectionMapTextureId, TTextureId toReflectionMapTextureId);
            
            bool HasLightmap(const Resources::CityThemes::CityThemeState& state) const;
            bool HasFogging(const Resources::CityThemes::CityThemeState& state) const;
            bool TexturesDiffer(const EnvironmentStateTextures& fromTextures, const EnvironmentStateTextures& toTextures);
            void UpdateTransitionParamForMaterial(const std::string& materialName, float t);
            void UpdateTransitionParamForWaterMaterial(const std::string& materialName, float t);
            void UpdateTransitionParamForLightmappedMaterial(const std::string& materialName, float t);
        };
    }
}
