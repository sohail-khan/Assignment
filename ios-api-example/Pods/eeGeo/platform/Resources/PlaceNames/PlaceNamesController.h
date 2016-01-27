// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PlaceNames.h"
#include "PlaceNameModel.h"
#include "PlaceNameView.h"
#include "Types.h"
#include "ICityThemeChangedObserver.h"
#include "Camera.h"
#include "Rendering.h"
#include "CityThemes.h"
#include "ITextRenderablesSource.h"
#include "PlaceNameCategory.h"
#include <functional>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace
        {
            class PlaceNamePrioritySort : public std::binary_function<const Eegeo::Resources::PlaceNames::PlaceNameModel*, const Eegeo::Resources::PlaceNames::PlaceNameModel*, bool>
            {
            public:
                inline bool operator()(const Eegeo::Resources::PlaceNames::PlaceNameModel* pA,
                                       const Eegeo::Resources::PlaceNames::PlaceNameModel* pB)
                {
                    float aPri = pA->GetPriority();
                    float bPri = pB->GetPriority();
                    if(aPri == bPri)
                    {
                        const Eegeo::Resources::PlaceNames::PlaceNameView& viewA = pA->GetView();
                        const Eegeo::Resources::PlaceNames::PlaceNameView& viewB = pB->GetView();
                        
                        float aY = viewA.GetScreenBounds().GetMax().GetY();
                        float bY = viewB.GetScreenBounds().GetMax().GetY();
                        if(aY == bY)
                        {
                            return viewA.GetScreenBounds().GetMax().GetX() > viewB.GetScreenBounds().GetMax().GetX();
                        }
                        return aY > bY;
                    }
                    return aPri < bPri;
                }
            };
        }
        
        namespace PlaceNames
        {
            static const float DefaultTargetAlpha = 1.0f;
            static const double DefaultTextMinOpaqueAltitude = 100.0;
            static const float DefaultTransitionSpeed = 5;
            static const int MaxOcclusionChecksPerFrame = 750;
            
            class PlaceNamesController : protected Eegeo::NonCopyable, public CityThemes::ICityThemeChangedObserver
            {
            private:
                static const float OtherSideOfWorldDotProdThreshold;
              
            public:
                PlaceNamesController(
                                     PlaceNamesRepository& placeNamesRepository,
                                     const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                     Resources::CityThemes::ICityThemesService& cityThemesService,
                                     float baseScale
                                     );
                
                ~PlaceNamesController();
                
                void Update(float deltaTime, const Camera::RenderCamera& renderCamera);
                
                void SetTargetAlpha(const float targetAlpha);
                float GetTargetAlpha() const;

                void SetTextMinOpaqueAltitude(double minOpaqueAltitutde);
                double GetTextMinOpaqueAltitude() const;

                void SetTransitionSpeed(float transitionSpeed);
                float GetTransitionSpeed() const;
                
                float GetBaseScale() const;
                void SetBaseScale(float baseScale);
                
                void OnPlaceNameModelAddedToSceneGraph(PlaceNameModel* pPlaceNameModel);
                void OnPlaceNameModelRemovedFromSceneGraph(PlaceNameModel* pPlaceNameModel);
                void BeforePlaceNameModelDeleted(PlaceNameModel* pPlaceNameModel);
                void OnThemeRequested(const CityThemes::CityThemeData& newTheme) {}
                void OnThemeChanged(const CityThemes::CityThemeData& newTheme);
                
                typedef std::vector<PlaceNameModel*> TPlaceNameModels;
                const TPlaceNameModels& GetSortedPlaceNamesInFrustum() const { return m_sortedPlaceNameModels; } const
                
                void GetRenderablesInScene(Eegeo::Rendering::TTextRenderables& out_Renderables) const;
                
            private:
                typedef std::vector<PlaceNameModel*> TPlaceNameModelVec;
                
                PlaceNamesRepository& m_placeNamesRepository;
                const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
                Resources::CityThemes::ICityThemesService& m_cityThemesService;
                
                float m_baseScale;

                double m_minOpaqueAltitude;
                float m_targetTextAlpha;
                float m_textAlpha;
                float m_transitionSpeed;
                float m_time;
                
                int m_nextCheckIndex;
                int m_nextCheckInnerIndex;
                TPlaceNameModelVec m_sortedPlaceNameModels;
                TPlaceNameModelVec m_placeNamesUpdatedThisFrame;
                
                void UpdateTextAltitudeAlpha(float deltaTime, const Camera::RenderCamera& renderCamera);
                void UpdateTransformsAndVisibility(bool visibleOnly, const Camera::RenderCamera& renderCamera);
                void UpdatePlaceNameOcclusions(const Camera::RenderCamera& renderCamera);
                void UpdateTransitions(float deltaTime);
                void PrunePlaceNames();
                void RestartOcclusionChecking();
                void UpdateCullState(PlaceNameRenderable& renderable) const;
                void ApplyCategoryStyleToView(PlaceNameView& view, const std::string& categoryKey, const std::map<std::string, Resources::PlaceNames::PlaceNameCategoryStyle>& styleMap);

                
                static void ResolveOcclusion(PlaceNameModel* pInnerPlaceNameModel, PlaceNameModel* pOuterPlaceNameModel);
                static int GetPriorityForCategory(PlaceNameCategory category);
            };
        }
    }
}
