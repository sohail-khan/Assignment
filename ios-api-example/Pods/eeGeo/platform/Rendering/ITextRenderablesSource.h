// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "ISceneElementSource.h"
#include "TextRenderable.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        typedef std::vector<Renderables::TextRenderable*> TTextRenderables;
        
        /*!
         * \brief Interface to a source of TextRenderable objects.
         */
        class ITextRenderablesSource : public Scene::ISceneElementSource<Renderables::TextRenderable>
        {
        public:
            virtual ~ITextRenderablesSource() {}
        };
    }
}
