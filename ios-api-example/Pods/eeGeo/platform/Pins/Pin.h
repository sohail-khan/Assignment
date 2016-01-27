// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Pins.h"
#include "VectorMath.h"
#include "LatLongAltitude.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief Defines the data model for a Pin placed in the 3D world.
         *
         *  Pin defines a Pin placed in the 3D world. It is intended to be used for the 
         *  representation of items of point data such as Point Of Interests (POIs) within the
         *  world. The Pin class is a model class in the Model-View-Controller sense in 
         *  that it doesn't deal with display concerns, simply the position of point
         *  data within the 3D environment.
         *
         */
        class Pin : protected Eegeo::NonCopyable
        {
         public:
            /*! Create a Pin object at a particular position in the world.
             * \param id A unique identifier for the Pin.
             * \param latLong The position of the Pin on the geoid. That is, the position of the Pin with an altitude of sea level.
             * \param heightAboveTerrainInMetres The Pin's height above the terrain in metres.
             * \param categoryId An application provided identifier denoting the Pin's category.
             * \param pUserData An optional piece of application user data to be attached to the Pin. N.B. It is the application's responsibility to manage the lifetime of any user data it attaches to Pin objects.
             * \return A Pin object
             */
            Pin(const TPinId id, const Space::LatLong& latLong, float heightAboveTerrainInMetres, int categoryId, const void* pUserData = NULL);
            
            /*! Get the unique identifier for the Pin.
             * \return The Pin's unique identifier. 
             */
            TPinId GetId() const;

            /*! Get the category identifier for the Pin.
             * \return The Pin's category identifier. 
             */
            int GetCategoryId() const;
            
            /*! Get the application supplied user data for the Pin.
             * \return The Pin's application supplied user data. 
             */
            const void* GetUserData() const;
            
            /*! Get the Pin's ECEF location on the surface of the geoid. That is, the location of the Pin at sea level.
             * \return The Pin's location at sea level.
             */
            const dv3& GetEcefGeoidLocation() const;
            
            /*! Get the ECEF position of the Pin, accounting for the terrain height at its latitude/longitude.
             * \return The Pin's position following adjustment for the terrain height at its latitude/longitude.
             */
            const dv3& GetEcefPosition() const;
            
            /*! Set the terrain height that should be used to adjust the Pin's altitude.
             * \param terrainHeight height of terrain above sea level in metres.
             * \param terrainHeightLevel level of terrain resource in the environment spatial structure.
             */
            void SetTerrainHeight(float terrainHeight, int terrainHeightLevel);

            /*! Get the Pin's height above the terrain in metres.
             * \return The Pin's height above the terrain in metres.
             */
            float GetHeightAboveTerrain() const;
            
            /*! Set the Pin's height above the terrain in metres.
             * \param heightAboveTerrainInMetres The Pin's height above the terrain in metres.
             */
            void SetHeightAboveTerrain(float heightAboveTerrainInMetres);
            
            /*! Set the Pin's category.
             * \param categoryId An application provided identifier denoting the Pin's category.
             */
            void SetCategoryId(int categoryId);
           
            /*! Test whether the Pin has previously had its terrain height set.
             * \return true is SetTerrainHeight() has been called for this Pin, otherwise false.
             */            
            bool HasTerrainHeight() const;
            
            /*! Get the terrain in metres at the ECEF location of the Pin.
             * \return The terrain height in meters at the ECEF location of the Pin if HasTerrainHeight() is true, otherwise 0.f.
             */
            float TerrainHeight() const;
            
            /*! Get the level of the terrain height for the Pin.
             * \return the terrain height level if HasTerrainHeight() is true for this Pin, otherwise -1.
             */
            int TerrainHeightLevel() const;
            
        private:
            TPinId m_id;
            Space::LatLong m_latLong;
            float m_heightAboveTerrainInMetres;
            dv3 m_ecefGeoidLocation;
            int m_categoryId;
            const void* const m_pUserData;
            
            float m_terrainHeight;
            bool m_hasTerrainHeight;
            int m_terrainHeightLevel;
            dv3 m_cachedTerrainHeightCorrectedEcefOrigin;
            
            void UpdateEcefPosition();
        };
    }
}
