// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Lighting.h"
#include "IdTypes.h"
#include "MaterialRepository.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        class EnvironmentMaterialFactory : protected Eegeo::NonCopyable
        {
        private:
            Eegeo::Rendering::Shaders::PackedDiffuseTransitionShader* m_pPackedDiffuseTransitionShader;
            Eegeo::Rendering::Shaders::PackedDiffuseShader* m_pPackedDiffuseShader;
            Eegeo::Rendering::Shaders::PackedDiffuseFoggedShader* m_pPackedDiffuseFoggedShader;
            
            Eegeo::Rendering::Shaders::PackedDiffuseTransitionShader* m_pPunchThroughPackedDiffuseTransitionShader;
            Eegeo::Rendering::Shaders::PackedDiffuseShader* m_pPunchThroughPackedDiffuseShader;
            Eegeo::Rendering::Shaders::PackedDiffuseFoggedShader* m_pPunchThroughPackedDiffuseFoggedShader;
            
            Eegeo::Rendering::Shaders::PackedStencilShadowShader* m_pPackedStencilShadowShader;
            Eegeo::Rendering::Shaders::ColorShader* m_pColorShader;
            Eegeo::Rendering::Shaders::DiffuseShader* m_pDiffuseShader;
            Eegeo::Rendering::Shaders::LightmappedPackedDiffuseTransitionShader* m_pLightmapPackedDiffuseTransitionShader;
            Eegeo::Rendering::Shaders::LightmappedPackedDiffuseShader* m_pLightmapPackedDiffuseShader;
            Eegeo::Rendering::Shaders::WaterShader* m_pWaterShader;
            Eegeo::Rendering::Shaders::WaterTransitionShader* m_pWaterTransitionShader;
            Eegeo::Rendering::Shaders::ModelShader* m_pModelShader;
            Eegeo::Rendering::Shaders::PackedDiffuseAlphaShader* m_pPackedDiffuseAlphaShader;
            Eegeo::Rendering::Shaders::PackedDiffuseAlphaShader* m_pPunchThroughPackedDiffuseAlphaShader;
            
            Eegeo::Rendering::EnvironmentMaterialRepository* m_pMaterialRepository;

            Eegeo::Rendering::MaterialRepository* m_pDiffuseMaterials;
            Eegeo::Rendering::MaterialRepository* m_pLightmappedMaterials;
            Eegeo::Rendering::MaterialRepository* m_pTransitionMaterials;
            Eegeo::Rendering::MaterialRepository* m_pFoggedMaterials;
            Rendering::Materials::PackedStencilShadowMaterial* m_pShadowMaterial;
            Rendering::Materials::ShadowMaterial* m_pShadowQuadMaterial;
            
            Eegeo::Lighting::GlobalLighting& m_lighting;
            Eegeo::Lighting::GlobalFogging& m_fogging;
            Eegeo::Lighting::GlobalShadowing& m_shadowing;
            Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
            
        public:
            EnvironmentMaterialFactory(
                                       Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                       Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                       Eegeo::Lighting::GlobalLighting& globalLighting,
                                       Eegeo::Lighting::GlobalFogging& globalFogging,
                                       Eegeo::Lighting::GlobalShadowing& globalShadowing,
                                       TTextureId placeholderTextureId
                                       );
            
            ~EnvironmentMaterialFactory();
            Eegeo::Rendering::EnvironmentMaterialRepository& GetMaterialRepository();
            
        private:
            MaterialRepository* CreatePackedDiffuseFoggedMaterial(TTextureId placeholderTextureId);
            MaterialRepository* CreateTransitionMaterials(TTextureId placeholderTextureId);
            MaterialRepository* CreateDiffuseMaterials(TTextureId placeholderTextureId);
            MaterialRepository* CreateLightmappedMaterials(TTextureId placeholderTextureId);

            void AddRasterTerrainMaterials(Rendering::IMaterialRepository* pMaterialRepository, TTextureId placeholderTextureId);
            void AddVehicleMaterials(Rendering::IMaterialRepository* pMaterialRepository, TTextureId placeholderTextureId);

            Rendering::Materials::ShadowMaterial* CreateShadowMaterial();
            Rendering::Materials::WaterTransitionMaterial* CreateWaterTransitionMaterial(const std::string& materialName, TTextureId diffuseTextureId, TTextureId normalMapTextureId, TTextureId reflectionMapTextureId);
            Rendering::Materials::WaterMaterial2* CreateWaterMaterial(const std::string& materialName, TTextureId diffuseTextureId, TTextureId normalMapTextureId, TTextureId reflectionMapTextureId);
            Rendering::Materials::LightmappedPackedDiffuseMaterial* CreateLightmappedPackedDiffuseMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::PackedDiffuseMaterial* CreatePackedDiffuseMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::DiffuseMaterial* CreateDiffuseMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::UniqueDiffuseMaterial* CreateUniqueDiffuseMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::CustomLandmarkDiffuseMaterial* CreateLandmarkDiffuseMaterial(const std::string& materialName);
            Rendering::Materials::CustomLandmarkDiffuseMaterial* CreatePunchThroughLandmarkDiffuseMaterial(const std::string& materialName);
            Rendering::Materials::CustomLandmarkDiffuseFoggedMaterial* CreateLandmarkDiffuseFoggedMaterial(const std::string& materialName);
            Rendering::Materials::CustomLandmarkDiffuseFoggedMaterial* CreatePunchThroughLandmarkDiffuseFoggedMaterial(const std::string& materialName);
            Rendering::Materials::PackedDiffuseFoggedMaterial* CreatePackedDiffuseFoggedMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::PackedDiffuseTransitionMaterial* CreatePackedDiffuseTransitionMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::CustomLandmarkDiffuseTransitionMaterial* CreateLandmarkDiffuseTransitionMaterial(const std::string& materialName);
            Rendering::Materials::CustomLandmarkDiffuseTransitionMaterial* CreatePunchThroughLandmarkDiffuseTransitionMaterial(const std::string& materialName);
            Rendering::Materials::LightmappedPackedDiffuseTransitionMaterial* CreateLightmappedPackedDiffuseTransitionMaterial(const std::string& materialName, TTextureId textureId);
            Rendering::Materials::PackedStencilShadowMaterial* CreatePackedStencilShadowMaterial();
            
            Rendering::Materials::ModelMaterial* CreateModelMaterial(const std::string& materialName, TTextureId& texture);
        };
    }
}
