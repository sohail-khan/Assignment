// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "TextMaterial.h"
#include "FontInstance.h"
#include "MaterialIdGenerator.h"
#include "PlaceNamesMaterial.h"
#include "Roads.h"
#include "RoadNamesMaterial.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontMaterialSet : protected Eegeo::NonCopyable
        {
        public:
            typedef Rendering::Materials::TextMaterial TMaterial;
            typedef std::vector<TMaterial*> TMaterials;

            FontMaterialSet()
            {
            }
            
            ~FontMaterialSet()
            {
                for(TMaterials::iterator it = m_materials.begin(); it != m_materials.end(); ++it)
                {
                    Eegeo_DELETE (*it);
                }
                m_materials.clear();
            }
            
            // TODO: Add a material factory here.
            static FontMaterialSet* CreateFromPlaceNamesFont(Fonts::FontInstance& font, Rendering::Shaders::TextShader& textShader, Rendering::Materials::MaterialIdGenerator& materialIdGenerator)
            {
                FontMaterialSet* pMaterialSet = Eegeo_NEW(FontMaterialSet)();
                
                const std::vector<u32>& fontTextures = font.GetTextureList();
                
                for (std::vector<u32>::const_iterator iter = fontTextures.begin();
                     iter != fontTextures.end();
                     ++iter)
                {
                    u32 textureId = *iter;
                    
                    Resources::PlaceNames::PlaceNamesMaterial* pMaterial = Eegeo_NEW(Resources::PlaceNames::PlaceNamesMaterial)
                                                                            (
                                                                             materialIdGenerator.GetNextId(),
                                                                             "text_material",
                                                                             textShader,
                                                                             textureId
                                                                            );
                    pMaterialSet->AddMaterial(pMaterial);
                }
                
                return pMaterialSet;
            }
            
            // TODO: Add a material factory here.
            static FontMaterialSet* CreateFromRoadNamesFont(Fonts::FontInstance& font, Rendering::Shaders::TextShader& textShader, Rendering::Materials::MaterialIdGenerator& materialIdGenerator, const Resources::Roads::RoadNamesFadeController& roadNamesFadeController)
            {
                FontMaterialSet* pMaterialSet = Eegeo_NEW(FontMaterialSet)();
                
                const std::vector<u32>& fontTextures = font.GetTextureList();
                
                for (std::vector<u32>::const_iterator iter = fontTextures.begin();
                     iter != fontTextures.end();
                     ++iter)
                {
                    u32 textureId = *iter;
                    
                    Resources::Roads::RoadNamesMaterial* pMaterial = Eegeo_NEW(Resources::Roads::RoadNamesMaterial)
                    (
                     materialIdGenerator.GetNextId(),
                     "text_material",
                     textShader,
                     textureId,
                     roadNamesFadeController
                     );
                    pMaterialSet->AddMaterial(pMaterial);
                }
                
                return pMaterialSet;
            }

            
            void AddMaterial(TMaterial* pMaterial)
            {
                m_materials.push_back(pMaterial);
            }
            
            const TMaterials& GetMaterials() const
            {
                return m_materials;
            }
            
            int GetNumOfMaterials() const
            {
                return static_cast<int>(m_materials.size());
            }
            
            TMaterial& GetMaterial(int materialIndex) const
            {
                return *(m_materials.at(materialIndex));
            }
            
        private:
            TMaterials m_materials;
        };
    }
}
