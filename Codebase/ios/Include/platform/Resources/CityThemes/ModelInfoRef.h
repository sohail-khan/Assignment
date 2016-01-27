// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CityThemes.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Models.h"
#include "HttpAsyncTextureLoader.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            struct ModelInfoRef
            {
                ModelInfoRef()
                : pTargetThemeData(NULL)
                , ecefOrigin(Eegeo::dv3::Zero())
                , framerateScale(0.0f)
                , used(false)
                , pModel(NULL)
                {
                }
                
                ModelInfoRef(const CityThemeData* pTargetThemeData,
                              Eegeo::dv3 ecefOrigin,
                              float framerateScale
                              )
                : pTargetThemeData(pTargetThemeData)
                , ecefOrigin(ecefOrigin)
                , framerateScale(framerateScale)
                , used(false)
                , pModel(NULL)
                {
                }
                
                const CityThemeData* pTargetThemeData;
                bool used;
                Eegeo::Model* pModel;
                Eegeo::dv3 ecefOrigin;
                float framerateScale;
                Eegeo::Rendering::AsyncTexturing::TIAsyncTextures asyncTextures;
            };
        }
    }
}