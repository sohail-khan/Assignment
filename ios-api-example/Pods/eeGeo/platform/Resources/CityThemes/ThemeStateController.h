// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ICityThemeStateObservable.h"
#include "Rendering.h"
#include "Lighting.h"
#include "Weather.h"

// TODO: Move implementation into cpp and get rid of all these includes.
#include "WeatherOverlayMaterial2.h"
#include "WeatherOverlayController.h"
#include "PackedRenderable.h"
#include "EnvironmentMaterialRepository.h"
#include "VectorMath.h"
#include "IInterestPointProvider.h"
#include "GlobalShadowing.h"
#include "HttpAsyncTextureLoader.h"
#include "ICityThemeStateObserver.h"
#include "SceneElementRepository.h"
#include "EnvironmentStateTextures.h"
#include "GlobalLighting.h"
#include "GlobalFogging.h"
#include "EarthConstants.h"
#include "CityThemeState.h"
#include "SpaceHelpers.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class ThemeStateController
                : protected Eegeo::NonCopyable
                , public ICityThemeStateObservable
            {
            public:
                ThemeStateController(
                        Rendering::EnvironmentMaterialRepository& materialRepository,
                        Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& buildingsRenderables, // this concern can go to another type..?
                        Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& transportRenderables,
                        Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& terrainRenderables,
                        Lighting::GlobalLighting& globalLighting,
                        Lighting::GlobalFogging& globalFogging,
                        Lighting::GlobalShadowing& globalShadowing,
                        Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                        Rendering::AsyncTexturing::HttpAsyncTextureLoader& asyncTextureLoader,
                        Eegeo::Weather::WeatherOverlayController & weatherOverlayController,
                        Rendering::Materials::WeatherOverlayMaterial2& weatherOverlayMaterial)
                : m_materialRepository(materialRepository)
                , m_transportRenderables(transportRenderables)
                , m_terrainRenderables(terrainRenderables)
                , m_buildingRenderables(buildingsRenderables)
                , m_globalLighting(globalLighting)
                , m_globalFogging(globalFogging)
                , m_globalShadowing(globalShadowing)
                , m_vertexBindingPool(vertexBindingPool)
                , m_asyncTextureLoader(asyncTextureLoader)
                , m_weatherOverlayController(weatherOverlayController)
                , m_weatherOverlayMaterial(weatherOverlayMaterial)
                , m_fromTextures(NULL)
                , m_toTextures(NULL)
                {
                }
                
                void SetState(const Resources::CityThemes::CityThemeState& state, const Rendering::EnvironmentStateTextures& stateTextures)
                {
                    m_fromState = state;
                    m_fromTextures = &stateTextures;
                    m_toState = state;
                    m_toTextures = &stateTextures;
                    
                    SetMaterials();

                    NotifyObservers(state);
                }
                
                void StartTransitionToState(const Resources::CityThemes::CityThemeState& targetState, const Rendering::EnvironmentStateTextures& targetStateTextures)
                {
                    m_toState = targetState;
                    m_toTextures = &targetStateTextures;
                    
                    SetMaterials();
                    if(targetState.OverlayIntensity > 0.0f)
                    {
                        m_weatherOverlayMaterial.SetTextureId(targetStateTextures.GetOverlayEffect());
                        m_weatherOverlayController.SetWeatherLayersParameters(targetState.OverlayLayerOneOffset,
                                                                          targetState.OverlayLayerOneVelocity,
                                                                          targetState.OverlayLayerOneAlpha,
                                                                          targetState.OverlayLayerOneScale,
                                                                          targetState.OverlayLayerTwoOffset,
                                                                          targetState.OverlayLayerTwoVelocity,
                                                                          targetState.OverlayLayerTwoAlpha,
                                                                          targetState.OverlayLayerTwoScale);
                    }
                    
                }
            
                void UpdateMaterialsOnRenderables(const Rendering::Scene::ISceneElementSource<Rendering::Renderables::PackedRenderable>& sceneElements)
                {
                    typedef std::vector<Rendering::Scene::SceneElement<Rendering::Renderables::PackedRenderable>*> TSceneElementPtrVec;
                    TSceneElementPtrVec allSceneElements;
                    sceneElements.GetSceneElements(allSceneElements);
                    
                    for (TSceneElementPtrVec::iterator iter = allSceneElements.begin(); iter != allSceneElements.end(); ++iter)
                    {
                        Rendering::Renderables::PackedRenderable& renderable = (*iter)->GetResource();
                        const std::string& materialName = renderable.GetMaterial()->GetName();
                        Rendering::Materials::IMaterial* material = m_materialRepository.GetMaterial(materialName);
                        renderable.SetMaterial(material, m_vertexBindingPool);
                    }
                }
                
                void SetTransition(float t, const dv3& ecefInterestPoint)
                {
                    m44 interpolatedLightColours;
                    m44::Lerp(interpolatedLightColours, m_fromState.Lighting, m_toState.Lighting, t);
                    m_globalLighting.SetLightColourMatrix(interpolatedLightColours);
                    m_materialRepository.SetTransitionParam(t);
                    m_globalLighting.SetNightLightmapColour(v3::Lerp(m_fromState.LightMapColor, m_toState.LightMapColor, t));
                    m_globalLighting.SetNightGlowLightmapIntensity(Math::Lerp(m_fromState.LightMapIntensity, m_toState.LightMapIntensity, t));
                    m_globalLighting.SetAlternativeAmbientColour(v3::Lerp(m_fromState.AlternativeAmbientLight, m_toState.AlternativeAmbientLight, t));
                    
                    float fogDensity = Math::Lerp(m_fromState.FogIntensity, m_toState.FogIntensity, t);
                    m_globalFogging.SetFogDensity(fogDensity);
                    
                    v3 fogColor = v3::Lerp(m_fromState.FogColor, m_toState.FogColor, t);
                    m_globalFogging.SetFogColour(v4(fogColor.GetX(), fogColor.GetY(), fogColor.GetZ(), 1.f));
                    
                    m_globalFogging.SetBaseAltitude(static_cast<float>(Space::SpaceHelpers::GetAltitude(ecefInterestPoint)));
                    
                    v3 shadowColor = v3::Lerp(m_fromState.ShadowColor, m_toState.ShadowColor, t);
                    m_globalShadowing.SetShadowColor(shadowColor);
                    

                    float fromIntensity = m_fromState.OverlayIntensity;
                    float toIntensity = m_toState.OverlayIntensity;
                    
                    m_weatherOverlayController.SetIntensity(Math::Lerp(fromIntensity, toIntensity,t));
                }
                
                Resources::CityThemes::CityThemeState& GetFromState() { return m_fromState; }
                const Resources::CityThemes::CityThemeState& GetToState() const { return m_toState; }

                void RegisterObserver(ICityThemeStateObserver& themeStateObserver)
                {
                    m_observers.push_back(&themeStateObserver);
                }

                void UnregisterObserver(ICityThemeStateObserver& themeStateObserver)
                {
                    TObservers::iterator toRemove = std::find(m_observers.begin(), m_observers.end(), &themeStateObserver);
                    if(toRemove != m_observers.end())
                    {
                        m_observers.erase(toRemove);
                    }
                }
            
            private:
                void SetMaterials()
                {
                    m_materialRepository.SetCurrentRepository(m_fromState, *m_fromTextures, m_toState, *m_toTextures);
                    m_asyncTextureLoader.UpdatePlaceholderEnvironmentTexture(m_toTextures->GetAsyncPlaceholderEnvironmentTexture());
                    UpdateMaterialsOnRenderables(m_buildingRenderables);
                    UpdateMaterialsOnRenderables(m_transportRenderables);
                    UpdateMaterialsOnRenderables(m_terrainRenderables);
                }

                void NotifyObservers(const Resources::CityThemes::CityThemeState& state)
                {
                    for(TObservers::const_iterator it = m_observers.begin(); it != m_observers.end(); ++it)
                    {
                        (*it)->OnThemeStateChanged(state);
                    }
                }
                
                Rendering::EnvironmentMaterialRepository& m_materialRepository;
                
                Resources::CityThemes::CityThemeState m_fromState;
                const Rendering::EnvironmentStateTextures* m_fromTextures;
                
                Resources::CityThemes::CityThemeState m_toState;
                const Rendering::EnvironmentStateTextures* m_toTextures;
                
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_transportRenderables;
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_terrainRenderables;
                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& m_buildingRenderables;
                
                Lighting::GlobalLighting& m_globalLighting;
                Lighting::GlobalFogging& m_globalFogging;
                Lighting::GlobalShadowing& m_globalShadowing;
                
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
     
                Rendering::AsyncTexturing::HttpAsyncTextureLoader& m_asyncTextureLoader;
                
                Eegeo::Weather::WeatherOverlayController& m_weatherOverlayController;
                Rendering::Materials::WeatherOverlayMaterial2& m_weatherOverlayMaterial;

                typedef std::vector<ICityThemeStateObserver*> TObservers;
                TObservers m_observers;
            };
        }
    }
}
