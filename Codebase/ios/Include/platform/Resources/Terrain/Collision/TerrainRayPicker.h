// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"
#include "Collision.h"
#include "IRayPicker.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Terrain
        {
            namespace Collision
            {
                /*!
                 *  Implements IRayPicker to provide ray intersection query against streamed terrain collision resources. 
                 *  Collision resources are provided by ICollisionBvhProvider 
                 *  (an appropriate instance can be obtained via EegeoWorld::GetCollisionMeshResourceProvider)
                 */
                class TerrainRayPicker : public Eegeo::Collision::IRayPicker, protected Eegeo::NonCopyable
                {
                public:
                    TerrainRayPicker(const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                                     const Eegeo::Collision::ICollisionBvhProvider& collisionMeshResourceProvider);
                    
                    virtual ~TerrainRayPicker();
                    
                    /*!
                     *  Performs a ray intersection query against streamed terrain collision mesh resources. If an intersection is found,
                     *  returns true, with intersection information passed in out parameters.
                     *  If no intersection with terrain collision mesh is found, a fallback test is performed. If the ray intersects
                     *  the Earth-sphere (a sphere with radius of Earth at sea-level), terrain height is queried at this point. If 
                     *  successful, the point on terrain above the Earth-sphere intersection is assiged as output parameter, and returns true.
                     *  If fallback test also fails to find an intersection, returns false.
                     *  \param rayOrigin start point of ray, in Ecef coordinates
                     *  \param rayDirection normalised direction of ray, in Ecef coordinates
                     *  \param out_ecefIntersectionPoint [out] point of intersection in Ecef coordinates if successful, else zero vector
                     *  \param out_param [out] distance in metres from rayOrigin to out_ecefIntersectionPoint if successful, else zero
                     *  \return true if intersection found, else false
                     */
                    virtual bool TryGetRayIntersection(const Eegeo::dv3& rayOrigin, const Eegeo::dv3& rayDirection, Eegeo::dv3& out_ecefIntersectionPoint, double& out_param);
                    
                private:
                    const Eegeo::Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                    Eegeo::Collision::CollisionMeshRayPicker* m_collisionMeshRayPicker;
                };
                
                //! \deprecated
                typedef Eegeo::Collision::ICollisionBvhProvider ICollisionMeshResourceProvider;
            }
        }
	}
}