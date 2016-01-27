// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "Frustum.h"

namespace Eegeo
{
    namespace Camera
    {
        /*! \brief Defines camera world, view and projection transforms
         */
        class RenderCamera
        {
        public:
            
            RenderCamera();
            ~RenderCamera();
            
            //! Set the camera origin point in ECEF coordinates
            //! \param ecefLocation camera origin point
            void SetEcefLocation(const Eegeo::dv3& ecefLocation);
            
            //! \return camera origin point in ECEF coordinates
            const Eegeo::dv3& GetEcefLocation() const { return m_ecefLocation; }
            
            //! \return the altitude above sea level in metres of the camera origin
            float GetAltitude() const { return m_altitude; }
            
            //! \param m a rotation matrix orienting the camera in the ECEF coordinate frame
            void SetOrientationMatrix(const Eegeo::m33& m);
            
            //! Set the viewport of the camera in absolute screen pixel coords, with screen origin being top left
            //! Calling this method will recompute a projection matrix using the values passed to SetProjection()
            //! \param x horizontal pixel coordinate defining the left of viewport rectangle
            //! \param y vertical pixel coordinate defining the top of viewport rectangle
            //! \param width width in pixels
            //! \param height height in pixels
            void SetViewport(float x, float y, float width, float height);
            
            //! Set the camera projection transform
            //! \param nominalVerticalFovRadians field of view angle, in radians, of the vertical view extents
            //! \param nearZ distance to near clip plane, in metres
            //! \param farZ distance to far clip plane, in metres
            void SetProjection (float nominalVerticalFovRadians, float nearZ, float farZ);
            
            //! Set an explicit projection transform
            //! \param projectionMatrix projection matrix
            void SetProjectionMatrix (m44& projectionMatrix);
            
            //! Project a camera-relative Ecef point to screenspace
            //! \param cameraRelativeWorldPosition point in ECEF coordinate frame, with translation relative to camera origin
            //! \param screenPosition [out] projected position in screenspace
            void Project(const Eegeo::v3& cameraRelativeWorldPosition, Eegeo::v3& screenPosition) const;
            
            //! Transform a screen-space position to a camera-relative Ecef point
            //! \param screenPosition screen-space point
            //! \param cameraRelativeWorldPosition [out] point in ECEF coordinate frame, with translation relative ot camera origin
            void UnProject(const Eegeo::v3& screenPosition, Eegeo::v3& cameraRelativeWorldPosition) const;

            //! \return model-to-world orientation transform of camera, with translation component set to zero
            const Eegeo::m44& GetModelMatrix() const	{ return m_modelMatrix; }
            
            //! \return world-to-view transform
            const Eegeo::m44& GetViewMatrix() const;
            
            //! \return projection transform
            const Eegeo::m44& GetProjectionMatrix() const;
            
            //! \return view-projection transform (view transform multiplied by projection transform)
            const Eegeo::m44& GetViewProjectionMatrix() const;
            
            //! \return inverse of view-projection transform
            const Eegeo::m44& GetInverseViewProjectionMatrix() const;

            //! \return distance to near clip plane
            float GetNearClip() const 	{ return m_nearZ; }
            
            //! \return distance to far clip plane
            float GetFarClip() const 	{ return m_farZ; }
            
            //! \return 2 * distance to near clip plane / height of near plane.
            float GetNearClipRatio() const;
            
            //! \return vertical field of view angle, in radians
            float GetFOV() const 	{ return m_fov; }
            
            //! \return horizontal-to-vertical aspect ratio (width / height)
            float GetAspect() const 	{ return m_aspect; }
            
            //! \return viewport width in pixels
            float GetViewportWidth() const { return m_viewportWidth; }
            
            //! \return viewport height in pixels
            float GetViewportHeight() const { return m_viewportHeight; }
            
            //! \return viewport origin in screen coords (screen origin top left)
            v2 GetViewportOrigin() const { return v2(m_viewportX, m_viewportY); }
            
            //! \return camera frustum
            const Eegeo::Geometry::Frustum& GetFrustum() const;
            
            const static float NominalAspectRatio;
            const static float MinAspectRatioForPortraitMode;
            
        private:
            float 		m_nearZ;
            float 		m_farZ;
            
            float 		m_fov;
            float 		m_aspect;
            
            Eegeo::dv3 m_ecefLocation;
            Eegeo::m44 m_modelMatrix;

            
            float m_viewportX;
            float m_viewportY;
            float m_viewportWidth;
            float m_viewportHeight;
            float m_altitude;
            
            class CachedState
            {
            private:
                Eegeo::m44 	m_viewMatrix;
                Eegeo::m44 	m_projMatrix;
                Eegeo::m44 	m_viewProjMatrix;
                Eegeo::m44 	m_inverseViewProjMatrix;
                Eegeo::Geometry::Frustum m_frustum;
                std::vector<Geometry::Plane> m_scratchFrustumPlanes;
                
                bool m_projectionDirty;
                bool m_viewDirty;
                bool m_viewProjectionDirty;
                bool m_frustumDirty;
            public:
                
                CachedState();
                
                void InvalidateProjection() { m_projectionDirty = true; }
                void InvalidateView() { m_viewDirty = true; }
                
                void InvalidateCachedTransforms();

                void SetExplicitProjection(Eegeo::m44& projectionMatrix);

                const Eegeo::m44& GetViewMatrix(const RenderCamera& camera);
                const Eegeo::m44& GetProjectionMatrix(const RenderCamera& camera);
                const Eegeo::m44& GetViewProjectionMatrix(const RenderCamera& camera);
                const Eegeo::m44& GetInverseViewProjectionMatrix(const RenderCamera& camera);
                const Eegeo::Geometry::Frustum& GetFrustum(const RenderCamera& camera);
                
            };
            
            mutable CachedState m_cachedState;
            
            void CalculateViewMatrix(Eegeo::m44& viewMatrix) const;
            void CalculateProjectionMatrix(Eegeo::m44& projectionMatrix) const;
        };
    }
}