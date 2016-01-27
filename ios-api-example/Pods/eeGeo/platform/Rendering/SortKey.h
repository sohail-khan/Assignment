// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <sstream>

namespace Eegeo
{
    namespace Rendering
    {
        class SortKey
        {
            typedef u64 SortKeyValue;
            
            static const u32            LayerFieldWidth = 6;
            static const u32            LayerFieldShift = 58;
            static const u64            LayerFieldMask = ((((u64)1) << LayerFieldWidth) - 1);
            static const SortKeyValue   LayerFieldInPlaceMask = (LayerFieldMask << LayerFieldShift);
            static const SortKeyValue   LayerFieldInPlaceInverseMask = (~LayerFieldInPlaceMask);
            
            static const u32            UserDefinedFieldWidth = 8;
            static const u32            UserDefinedFieldShift = 50;
            static const u64            UserDefinedFieldMask = ((((u64)1) << UserDefinedFieldWidth) - 1);
            static const SortKeyValue   UserDefinedInPlaceMask = (UserDefinedFieldMask << UserDefinedFieldShift);
            static const SortKeyValue   UserDefinedInPlaceInverseMask = (~UserDefinedInPlaceMask);

            static const u32            TranslucencyTypeFieldWidth = 2;
            static const u32            TranslucencyTypeFieldShift = 48;
            static const u64            TranslucencyTypeFieldMask = ((((u64)1) << TranslucencyTypeFieldWidth) - 1);
            static const SortKeyValue   TranslucencyTypeFieldInPlaceMask = (TranslucencyTypeFieldMask << TranslucencyTypeFieldShift);
            static const SortKeyValue   TranslucencyTypeFieldInPlaceInverseMask = (~TranslucencyTypeFieldInPlaceMask);

            static const u32            DepthFieldWidth = 24;
            static const u32            DepthFieldShift = 24;
            static const u64            DepthFieldMask = ((((u64)1) << DepthFieldWidth) - 1);
            static const SortKeyValue   DepthFieldInPlaceMask = (DepthFieldMask << DepthFieldShift);
            static const SortKeyValue   DepthFieldInPlaceInverseMask = (~DepthFieldInPlaceMask);
            
            static const u32            ShaderProgramFieldWidth = 8;
            static const u32            ShaderProgramFieldShift = 16;
            static const u64            ShaderProgramFieldMask = ((((u64)1) << ShaderProgramFieldWidth) - 1);
            static const SortKeyValue   ShaderProgramFieldInPlaceMask = (ShaderProgramFieldMask << ShaderProgramFieldShift);
            static const SortKeyValue   ShaderProgramFieldInPlaceInverseMask = (~ShaderProgramFieldInPlaceMask);
            
            static const u32            MaterialFieldWidth = 11;
            static const u32            MaterialFieldShift = 5;
            static const u64            MaterialFieldMask = ((((u64)1) << MaterialFieldWidth) - 1);
            static const SortKeyValue   MaterialFieldInPlaceMask = (MaterialFieldMask << MaterialFieldShift);
            static const SortKeyValue   MaterialFieldInPlaceInverseMask = (~MaterialFieldInPlaceMask);
            
        public:
            
            static const u64            MaxLayerValue = LayerFieldMask;
            static const u64            MaxTranslucencyValue = TranslucencyTypeFieldMask;
            static const u64            MaxShaderProgramValue = ShaderProgramFieldMask;
            static const u64            MaxMaterialValue = MaterialFieldMask;
            static const u64            MaxDepthValue = DepthFieldMask;
            
            SortKey()
            : m_key(0)
            {
            }
            
            inline void SetUserDefined(u64 userDefined)
            {
                Eegeo_ASSERT(userDefined <= UserDefinedFieldMask, "user defined %ld is greater than maximum allowed value %ld", userDefined, UserDefinedFieldMask);
                m_key = (m_key & UserDefinedInPlaceInverseMask) | (userDefined << UserDefinedFieldShift);
            }
            
            inline u64 GetUserDefined() const
            {
                return ((m_key & UserDefinedInPlaceMask) >> UserDefinedFieldShift);
            }
            
            inline void SetLayer(u64 layer)
            {
                Eegeo_ASSERT(layer <= LayerFieldMask, "layer %ld is greater than maximum allowed value %ld", layer, LayerFieldMask);
                m_key = (m_key & LayerFieldInPlaceInverseMask) | (layer << LayerFieldShift);
            }
            
            inline u64 GetLayer() const
            {
                return ((m_key & LayerFieldInPlaceMask) >> LayerFieldShift);
            }
            
            inline void SetTranslucencyType(u64 translucencyType)
            {
                Eegeo_ASSERT(translucencyType <= TranslucencyTypeFieldMask, "translucencyType %ld is greater than maximum allowed value %ld", translucencyType, TranslucencyTypeFieldMask);
                m_key = (m_key & TranslucencyTypeFieldInPlaceInverseMask) | (translucencyType << TranslucencyTypeFieldShift);
            }
            
            inline u64 GetTranslucencyType() const
            {
                return ((m_key & TranslucencyTypeFieldInPlaceMask) >> TranslucencyTypeFieldShift);
            }
            
            inline void SetShaderProgram(u64 shaderProgram)
            {
                Eegeo_ASSERT(shaderProgram <= ShaderProgramFieldMask);
                m_key = (m_key & ShaderProgramFieldInPlaceInverseMask) | (shaderProgram << ShaderProgramFieldShift);
            }
            
            inline u64 GetShaderProgram() const
            {
                return ((m_key & ShaderProgramFieldInPlaceMask) >> ShaderProgramFieldShift);
            }
            
            inline void SetMaterial(u64 materialId)
            {
                Eegeo_ASSERT(materialId <= MaterialFieldMask);
                m_key = (m_key & MaterialFieldInPlaceInverseMask) | (materialId << MaterialFieldShift);
            }
            
            inline u64 GetMaterial() const
            {
                return ((m_key & MaterialFieldInPlaceMask) >> MaterialFieldShift);
            }
            
            inline void SetDepth(u64 depth)
            {
                Eegeo_ASSERT(depth <= DepthFieldMask, "depth index %ld is greater than maximum allowed value %ld", depth, DepthFieldMask);
                m_key = (m_key & DepthFieldInPlaceInverseMask) | (depth << DepthFieldShift);
            }
            
            inline u32 GetDepth() const
            {
                return ((m_key & DepthFieldInPlaceMask) >> DepthFieldShift);
            }
            
            inline SortKeyValue GetKey() const
            {
                return m_key;
            }
            
            inline bool operator< (const SortKey &otherKey) const
            {
                return m_key < otherKey.m_key;
            }
            
            inline bool operator!= (const SortKey &otherKey) const
            {
                return m_key != otherKey.m_key;
            }
            
            static std::string ToString(const SortKey& key)
            {
                std::stringstream stream;
                
                stream << "Lyer:" << key.GetLayer() << "\tUD:" << key.GetUserDefined() << "\tTrns:" << key.GetTranslucencyType() << "\tShdr:" << key.GetShaderProgram() << "\tMtl:" << key.GetMaterial() << "\tDep:" << key.GetDepth();
                
                return stream.str();
            }
            
        private:
            SortKeyValue m_key;
        };

    }
}
