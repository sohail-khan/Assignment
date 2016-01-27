// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <map>
#include <string>

#include "Rendering.h"
#include "SceneElement.h"
#include "ISceneElementInGraphObserver.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Buildings
        {
            class LandmarkToRenderableRepository : public Rendering::Scene::ISceneElementInGraphObserver<Rendering::Renderables::PackedRenderable>
            {
            public:

                typedef Eegeo::Helpers::ICallback2<const std::string &, Rendering::Renderables::CustomLandmarkRenderable&> TCallback;
                
                void OnAddedToSceneGraph(Rendering::Scene::SceneElement<Rendering::Renderables::PackedRenderable>* resource);
                void OnRemovedFromSceneGraph(Rendering::Scene::SceneElement<Rendering::Renderables::PackedRenderable>* resource);
                
                const std::vector<Rendering::Renderables::CustomLandmarkRenderable*> GetLandmarksWithTextureName(const std::string& textureName);
                const std::vector<Rendering::Renderables::CustomLandmarkRenderable*> GetLandmarksWhereTextureNameContainsString(const std::string& stringToMatch);
            
                void RegisterRenderableAddedCallback(TCallback& callback);
                void RegisterRenderableRemovedCallback(TCallback& callback);
                void UnregisterRenderableAddedCallback(TCallback& callback);
                void UnregisterRenderableRemovedCallback(TCallback& callback);
                
            private:
                typedef std::map<std::string, std::vector<Rendering::Renderables::CustomLandmarkRenderable*> > TLandmarksToRenderables;
                TLandmarksToRenderables m_landmarkToRenderables;
                
                Eegeo::Helpers::CallbackCollection2<const std::string&, Rendering::Renderables::CustomLandmarkRenderable&> m_addedCallbacks;
                Eegeo::Helpers::CallbackCollection2<const std::string&, Rendering::Renderables::CustomLandmarkRenderable&> m_removedCallbacks;
            };
        }
    }
}