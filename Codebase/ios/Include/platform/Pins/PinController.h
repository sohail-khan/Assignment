// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IPinObserver.h"
#include "PinRepository.h"
#include "TerrainHeightProvider.h"
#include "IPinViewFactory.h"
#include "PinViewRenderer.h"
#include "Pin.h"
#include "PinView.h"
#include "Pins.h"
#include <map>
#include <algorithm>

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Controller (in the Model-View-Controller sense) for a set of Pins.
         *
         *  This class updates the terrain height for a set of Pins ands maps them to and from PinViews for display and 
         *  collision detection purposes. 
         *
         */       
        class PinController : protected Eegeo::NonCopyable, public IPinObserver
        {
        public:
            /*! Create PinController object.
             * \param pinRepository The repository of Pin model objects to be mapped to/from PinView objects.
             * \param terrainHeightProvider The TerrainHeightProvider to be used for updating the positions of the Pin object with respect to the terrain.
             * \param viewFactory The factory to be used for creating views to represent the models in the repository.
             * \param viewRenderer The renderer that will be used to displat the view objects.
             * \return A new PinController object.
             */
            PinController(PinRepository& pinRepository, Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider, IPinViewFactory& viewFactory, PinViewRenderer& viewRenderer)
            : m_pinRepository(pinRepository)
            , m_terrainHeightProvider(terrainHeightProvider)
            , m_viewFactory(viewFactory)
            , m_viewRenderer(viewRenderer)
            {
                m_pinRepository.AddPinObserver(*this);
            }
            
            ~PinController()
            {
                m_pinRepository.RemovePinObserver(*this);
                
                for(TViewsByModel::iterator it = m_viewsByModel.begin(); it != m_viewsByModel.end(); ++it)
                {
                    PinView* pView = it->second;
                    m_viewRenderer.RemoveView(*pView);
                    Eegeo_DELETE pView;
                }
                m_viewsByModel.clear();
            }
            
            /*! Update the state of the PinController
             * \param deltaTime The time, in seconds, since this method was last called.
             * \param renderCamera The current active renderCamera
             */
            void Update(float deltaTime, const Camera::RenderCamera& renderCamera)
            {
                UpdateTerrainHeights();
                UpdateViews();
                m_viewRenderer.Update(renderCamera);
            }
            
            /*! The method to receive notification that a Pin object has been added to the repository.
             * \param pin The Pin that has been added to the repository.
             */
            virtual void OnPinAdded(Pin& pin)
            {
                Eegeo_ASSERT(!HasViewForModel(pin), "Attempt to add duplicate model to PinController.");
                
                PinView* pView = m_viewFactory.CreateViewForPin(pin);
                
                m_pinsNeedingHeightLookup.push_back(&pin);
                m_viewsByModel[&pin] = pView;
                m_viewRenderer.AddView(*pView);
            }
            
            /*! The method to receive notification that a Pin object has been removed from the repository.
             * \param pin The Pin that has been removed from the repository.
             */
            virtual void OnPinRemoved(Pin& pin)
            {
                Eegeo_ASSERT(HasViewForModel(pin), "Attempt to remove unknown model from PinController.");
                PinView* pView = GetViewForModel(pin);
                
                m_pinsNeedingHeightLookup.erase(std::remove(m_pinsNeedingHeightLookup.begin(), m_pinsNeedingHeightLookup.end(), &pin), m_pinsNeedingHeightLookup.end());
                m_viewsByModel.erase(&pin);
                m_viewRenderer.RemoveView(*pView);
                
                Eegeo_DELETE(pView);
            }
            
            /*! Retrieve the 2D screen bounds for a given Pin's view.
             * \param pin The Pin to retrieve screen bounds for.
             * \param outScreenBounds The vector to receive the bounds of the given Pin in screen pixel coordinates.
             */
            void GetScreenBoundsForPin(const Pin& pin, Geometry::Bounds2D& outScreenBounds) const
            {
                const PinView* pView = GetViewForModel(pin);
                Eegeo_ASSERT(pView != NULL, "Can't find screen bounds for a pin model that doesn't have a corresponding view.");
                
                outScreenBounds = pView->GetScreenSpaceBounds();
            }

            /*! Test the Pins in the repository for intersection with a given screen point.
             * \param screenPoint The screen point (in screen pixel coordinates) to test for intersection with the Pins.
             * \param outIntersectingPins A vector to be populated, in order of increasing distance from the camera, with the Pins whose views intersect screenPoint.
             * \return true if any Pin's views intersected screenPoint, otherwise false.
             */
            bool TryGetPinsIntersectingScreenPoint(const v2& screenPoint, std::vector<Pin*>& outIntersectingPins) const
            {
                outIntersectingPins.clear();
                
                std::vector<PinView*> intersectingViews;
                if(m_viewRenderer.TryGetViewsIntersectingScreenPoint(screenPoint, intersectingViews))
                {
                    for(std::vector<PinView*>::const_iterator it = intersectingViews.begin(); it != intersectingViews.end(); ++it)
                    {
                        PinView* pView = *it;
                        outIntersectingPins.push_back(&(pView->GetPin()));
                    }
                }
                
                return (outIntersectingPins.size() > 0);
            }
            
            
            /*! Retrieve the uniform scale for a given Pin's view.
             * \param pin The Pin to retrieve scale for.
             * \return The uniform scale value for the pin.
             */
            float GetScaleForPin(const Pin& pin) const
            {
                const PinView* pView = GetViewForModel(pin);
                Eegeo_ASSERT(pView != NULL, "Can't get scale for a pin model that doesn't have a corresponding view.");
                return pView->GetScale();
            }
            
            /*! Set the uniform scale for a given Pin's view.
             * \param pin The Pin to retrieve scale for.
             * \param pinScale The new uniform scale value for the pin.
             */
            void SetScaleForPin(const Pin& pin, float pinScale)
            {
                PinView* pView = GetViewForModel(pin);
                Eegeo_ASSERT(pView != NULL, "Can't set scale for a pin model that doesn't have a corresponding view.");
                pView->SetScale(pinScale);
            }
            
        protected:
            virtual void UpdateViews()
            {
                for(TViewsByModel::iterator it = m_viewsByModel.begin(); it != m_viewsByModel.end(); ++it)
                {
                    const Pin* pPin = it->first;
                    PinView* pView = it->second;
                    
                    const dv3& origin = pPin->GetEcefPosition();
                    pView->SetEcefOrigin(origin);
                }
            }
            
        private:
            PinRepository& m_pinRepository;
            Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
            IPinViewFactory& m_viewFactory;
            PinViewRenderer& m_viewRenderer;
            
            typedef std::map<Pin*, PinView*> TViewsByModel;
            
            std::vector<Pin*> m_pinsNeedingHeightLookup;
            
            TViewsByModel m_viewsByModel;
            
            PinView* GetViewForModel(const Pin& pin) const
            {
                TViewsByModel::const_iterator foundPin = m_viewsByModel.find(const_cast<Pin*>(&pin));
                
                if(foundPin != m_viewsByModel.end())
                {
                    return foundPin->second;
                }
                
                return NULL;
            }
            
            bool HasViewForModel(const Pin& pin) const
            {
                return (GetViewForModel(pin) != NULL);
            }
            
            void UpdateTerrainHeights()
            {
                const int maxPinsToUpdatePerFrame = 30;
                const int numberOfPinsNeedingLookup = static_cast<int>(m_pinsNeedingHeightLookup.size());
                int pinsToUpdateThisFrame = std::min(numberOfPinsNeedingLookup, maxPinsToUpdatePerFrame);
                
                while (pinsToUpdateThisFrame--)
                {
                    Pin* pPin = m_pinsNeedingHeightLookup.back();
                    
                    float terrainHeight;
                    int queryTerminationLevel;
                    
                    if(m_terrainHeightProvider.TryGetHeight(pPin->GetEcefGeoidLocation(),
                                                            0,
                                                            pPin->TerrainHeightLevel(),
                                                            pPin->TerrainHeight(),
                                                            queryTerminationLevel,
                                                            terrainHeight))
                    {
                        pPin->SetTerrainHeight(terrainHeight, queryTerminationLevel);
                    }
                    
                    m_pinsNeedingHeightLookup.pop_back();
                }
                
                int numOfPinsInRepo = m_pinRepository.GetNumOfPins();
                if (m_pinsNeedingHeightLookup.empty() && numOfPinsInRepo > 0)
                {
                    RepopulatePinLookupVector();
                }
            }
            
            void RepopulatePinLookupVector()
            {
                for (int pinIndex = 0; pinIndex < m_pinRepository.GetNumOfPins(); ++pinIndex)
                {
                    Pin *pPin = m_pinRepository.GetPinAtIndex(pinIndex);
                    m_pinsNeedingHeightLookup.push_back(pPin);
                }
            }
        };
    }
}
