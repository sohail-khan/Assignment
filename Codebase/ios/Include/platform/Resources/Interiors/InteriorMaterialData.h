// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "LayerIds.h"
#include "VectorMath.h"

#include <string>
#include <vector>
#include <map>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            struct InteriorMaterialData
            {
            public:
            
                typedef std::pair<std::string, std::string> SemanticStringPair;
                typedef std::pair<std::string, v4> SemanticColorPair;
                typedef std::pair<std::string, float> SemanticScalarPair;
                typedef std::pair<std::string, bool> SemanticBooleanPair;
                
                
                //! \deprecated
                static InteriorMaterialData Make(const std::string& materialName,
                                                 Rendering::LayerIds::Values renderableLayer,
                                                 int renderableDepth);
                
                //! \deprecated
                static InteriorMaterialData Make(const std::string& materialName,
                                                 Rendering::LayerIds::Values renderableLayer,
                                                 int renderableDepth,
                                                 const std::vector<SemanticStringPair>& strings,
                                                 const std::vector<SemanticColorPair>& colors,
                                                 const std::vector<SemanticScalarPair>& scalars);
                
                static InteriorMaterialData Make(const std::string& materialName);
                
                static InteriorMaterialData Make(const std::string& materialName,
                                                 const std::vector<SemanticStringPair>& strings,
                                                 const std::vector<SemanticColorPair>& colors,
                                                 const std::vector<SemanticScalarPair>& scalars);
                
                static InteriorMaterialData Make(const std::string& materialName,
                                                 const std::vector<SemanticStringPair>& strings,
                                                 const std::vector<SemanticColorPair>& colors,
                                                 const std::vector<SemanticScalarPair>& scalars,
                                                 const std::vector<SemanticBooleanPair>& booleans);
                
                InteriorMaterialData();
                

                
                std::string MaterialName() const { return m_materialName; }
                
                bool HasString(const std::string& semantic) const;
                bool HasColor(const std::string& semantic) const;
                bool HasScalar(const std::string& semantic) const;
                bool HasBoolean(const std::string& semantic) const;
               
                std::string GetString(const std::string& semantic) const;
                v4 GetColor(const std::string& semantic) const;
                float GetScalar(const std::string& semantic) const;
                bool GetBoolean(const std::string& semantic) const;
                
                std::string GetStringOrDefault(const std::string& semantic, const std::string& defaultValue) const;
                v4 GetColorOrDefault(const std::string& semantic, const v4& defaultValue) const;
                float GetScalarOrDefault(const std::string& semantic, const float defaultValue) const;
                bool GetBooleanOrDefault(const std::string& semantic, const bool defaultValue) const;
                
                void SetMaterialName(const std::string& materialName)
                {
                    m_materialName = materialName;
                }
                
            private:
                InteriorMaterialData(
                                     const std::string& materialName,
                                     const std::map<std::string, std::string>& strings,
                                     const std::map<std::string, v4>& colors,
                                     const std::map<std::string, float>& scalars,
                                     const std::map<std::string, bool>& booleans);

                std::string m_materialName;
                
                std::map<std::string, std::string> m_strings;
                std::map<std::string, v4> m_colors;
                std::map<std::string, float> m_scalars;
                std::map<std::string, bool> m_booleans;
            };

        }
    }
}