// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextMeshGenerator.h"
#include "CharacterEntry.h"
#include "VectorMathDecl.h"
#include "Fonts.h"
#include <vector>


namespace Eegeo
{
    namespace TextMeshes
    {
        namespace Internal
        {
            class InstancedTextMeshGenerator : public TextMeshGenerator
            {
            private:
                virtual void AddTextGeometry(std::vector<Internal::CharacterEntry>::const_iterator characterRangeBegin,
                                             int characterCount,
                                             const v3& up,
                                             const m44& reverseSideTransform,
                                             float shadowParam,
                                             float z);
            
                void AddCharInstanced(const Fonts::FontCharacter& fontCharacter, float x, float y, float z, float fontSize, const v3& up, const Eegeo::m44& transform, float shadowParam, float altitudeOffset);
                
            };
        }
    }
}