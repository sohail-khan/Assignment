// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Bounds.h"
#include "Pins.h"

namespace Eegeo
{
    namespace Pins
    {
        /*!
         * \brief A view object representing a Pin in the world as 2.5D billboard sprite.
         *
         *  This class deals with the concerns of displaying a Pin in the 3D scene as a 2.5D billboard sprite.
         *
         */
        class PinView : protected Eegeo::NonCopyable
        {
        public:
            /*! Create a new PinView with a given sprite.
             * \param pin The Pin model that the view represents.
             * \param modelVertexBounds the bounds of the pin in model space (this should typically be a bounds with x, y size, but with the z component set to 0)
             */            
            PinView(Pin& pin, const Eegeo::Geometry::Bounds3D& modelVertexBounds);
            
            /*! Delete a PinView and its underlying sprite.
             */            
            ~PinView();

            /*! Retrieve the Pin model that the view represents.
             * \return The view's Pin model.
             */
            Pin& GetPin() const;
            
            /*! Set the uniform scale for the view.
             * \param value The uniform scale value for the view.
             */
            void SetScale(float value);

            /*! Retrieve the uniform scale for the view.
             * \return The uniform scale value for the view.
             */
            float GetScale() const;

            /*! Set the world space dimensions for the sprite
             * \param value the dimensions in metres (x component = width, y component = height)
             */
            void SetDimensions(const v2& value);

            /*! Get the world space dimensions for the sprite
             * \return The dimensions in metres (x component = width, y component = height)
             */
            v2 GetDimensions() const;

            /*! Set the position of the PinView within the world.
             * \param ecefOrigin The world position at which the PinView's sprite will be rendered.
             */
            void SetEcefOrigin(const dv3& ecefOrigin);
            
            /*! Retrieve the position of the PinView.
             * \return The world position at which the PinView's sprite will be rendered.
             */            
            const dv3& GetEcefOrigin() const;

            /*! Retrieve the height of the PinView above the terrrain in metres.
             * \return The height of the PinView above the terrain in metres.
             */
            float GetHeightAboveTerrain() const;

            /*! Set the model-view-projection matrix that will be used to position and orient the PinView's sprite.
             * \param modelViewProjection The model-view-projection matrix to set.
             */
            void SetModelViewProjection(const m44& modelViewProjection);

            /*! Retrieve the model-view-projection matrix to be used for positioning and orienting the PinView's sprite.
             * \return The model-view-projection matrix being used to render the PinView's sprite.
             */
            const m44& GetModelViewProjection() const;

            /*! Update the bounds for the PinView based on it's current model-view-projection matrix.
             * \param screenWidth The width of the screen in pixels.
             * \param screenHeight The height of the screen in pixels.
             */
            void UpdateBounds(int screenWidth, int screenHeight);

            /*! Retrieve the 3D bounds of the PinView in View space. This method returns the last set of bounds that were calculated by a call to UpdateBounds().
             * \return The bounds of the PinView in normalized device coordinates.
             */
            const Geometry::Bounds3D& GetViewSpaceBounds() const;

            /*! Retrieve the 2D bounds of the PinView in Screen space. This method returns the last set of bounds that were calculated by a call to UpdateBounds().
             * \return The bounds of the PinView in screen pixels.
             */
            const Geometry::Bounds2D& GetScreenSpaceBounds() const;

        private:
            m44 m_mvp;
            dv3 m_ecefOrigin;
            Geometry::Bounds3D m_vertexBounds;
            Geometry::Bounds3D m_viewSpaceBounds;
            Geometry::Bounds2D m_screenSpaceBounds;
            float m_scale;
            Pin& m_pin;

            void SetViewSpaceBounds(const Geometry::Bounds3D& viewSpaceBounds);
            void SetScreenSpaceBounds(const Geometry::Bounds2D& screenSpaceBounds);
        };
    }
}
