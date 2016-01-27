// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "GLState.h"
#include "DynamicBuffer.h"
#include "Streaming.h"
#include "Geometry.h"
#include "Fonts.h"
#include "DebugRendering.h"
#include "Camera.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace DebugRendering
    {
        m44 MakeOrthoMatrix(const Rendering::RenderContext& renderContext);
    
        class DebugRenderer
        {
        public:
            DebugRenderer(Fonts::FontInstance& fontInstance,
                          Rendering::Materials::IMaterial* pDebugMaterial,
                          Rendering::Materials::IMaterial* pDebugTextMaterial,
                          const Rendering::VertexLayouts::VertexBinding& coloredVertexBinding,
                          const Rendering::VertexLayouts::VertexBinding& textVertexBinding,
                          Rendering::RenderableFilters& renderableFilters,
                          float lineWidth);
            
            ~DebugRenderer();
            
            //! Set the Line Width for rendering.  Affects all line rendering & best called before Draw().
            void SetLineWidth(float lineWidth);
            
            //! Set the Depth Testing on or off.  Used for the Draw() call and will determine if all rendered geometry is depth tested or not.
            void SetDepthTestEnabled(bool depthTest);
            
            //! Draw a simple line between two ECEF points
            void DrawLine(const dv3& ecefPointA, //!< The start ECEF point of the line
                          const dv3& ecefPointB, //!< The end ECEF point of the line
                          const v4& color, //!< the color of the line. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                          );
            
            
            //! Draw a polyline - A set of ECEF points connected together
            void DrawPolyLine(const std::vector<dv3>& ecefPoints, //!< the set of ECEF points of the polyline
                              const v4& color, //!< the color of the line. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                              const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
            );
            
            //! Draw a set of axes at the given ecef point.  The color of the axes is preset at red (x axis), green (y axis) and blue (z axis)
            void DrawAxes(const dv3& ecefCentre, //!< the centre origin ECEF coordinates of the axis
                          const v3& xAxis, //!< orientation of the x axis
                          const v3& yAxis, //!< orientation of the y axis
                          const v3& zAxis, //!< orientation of the z axis
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                          );
            
            //! Draw a set of axes at the given ecef point.
            void DrawAxes(const dv3& ecefCentre, //!< the centre origin ECEF coordinates of the axis
                          const v3& xAxis, //!< orientation of the x axis
                          const v3& yAxis, //!< orientation of the y axis
                          const v3& zAxis, //!< orientation of the z axis
                          const v4& xColor, //!< Color of the X Axis
                          const v4& yColor, //!< Color of the Y AXis
                          const v4& zColor, //!< Color of the Z Axis
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                          );
            
            //! Draw a coloured unlit quad aligned to the XY axes facing along the Z axis;
            void DrawQuad(const dv3& ecefCentre, //!< the centre ECEF coordinate of the quad
                          const v3& xAxis, //!< axis defining the width of the quad
                          const v3& yAxis, //!< axis defining the height of the quad
                          const v3& zAxis, //!< axis defining the facing direction of the quad
                          const v4& color, //!< the color of the quad. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
            );
                          
            //! Draw a solid unlit cube with specific orientation and dimensions around an ECEF centre point
            void DrawCube(const dv3& ecefCentre, //!< the cube centre ECEF point
                          const v3& xAxis, //!< axis defining the width of the cube along the x axis
                          const v3& yAxis, //!< axis defining the height of the cube along the y axis
                          const v3& zAxis, //!< axis defining the breadth of the cube along the z axis
                          const v4& color, //!< the color of the sphere. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                          );
            
            //! Draw a solid unlit sphere of a specific radius at the ECEF point
            void DrawSphere(const dv3& ecefCentre, //!< the sphere centre ECEF point
                            const float radius, //!< radius of the sphere in metres
                            const v4& color, //!< the color of the sphere. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                            const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
            );
            
            //! Draw a wireframe representation of a frustum.
            void DrawWireFrustum(const dv3& ecefCenter,  //!< The ECEF origin of the frustum.
                                 const Geometry::Frustum& frustum, //!< The frustum itself. Ensure it has valid planes
                                 const v4& color, //!< the color of the frustum. Each vector component should be a normalised value between 0.0f and 1.0f. The .w component is the alpha value.
                                 const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                                 );
            
            //! Draw text at the specified ECEF location. Text is center justified around the ecefCenter point, and colour of all text is defined on the Renderer.
            void DrawText(const dv3& ecefCenter, //!< The ECEF origin of the center justified text
                          const std::string& text, //!< The text to display
                          const float size, //!< The size of the text
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
                          );
            
            //! Draw text at the specified screen space. Text is justified left, and colour of all text is defined on the Renderer.
            void DrawTextScreenSpace(const v2& leftOriginCenter, //!< The top-left of the line in screen space.
                          const std::string& text, //!< The text to display
                          const float size, //!< The size of the text
                          const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
            );

            //! Draw a simple line between 2d points given in screen coordinates
            void DrawLineScreenSpace(
                    const v2& screenPointA, //!< The line's screen start coordinates
                    const v2& screenPointB, //!< The line's screen end coordinates
                    const v4& color, //!< The color of the line
                    const float lifetimeInSeconds = 0.0f //!< optional: A duration of zero (the default) will draw the primitive for one frame (i.e. you must re-submit every frame). A duration of greater than zero seconds will draw the primitive for this duration (useful for fire-and-forget rendering)
            );
            
            void Update(float dt, const Camera::RenderCamera& renderCamera);
            void GenerateGeometry(const Camera::RenderCamera& renderCamera);
            
        private:

            Renderers::DebugLineRendererEcef* m_pLineRendererEcef;
            Renderers::DebugLineRendererScreenSpace* m_pLineRendererScreenSpace;
            Renderers::DebugPrimitiveRendererEcef* m_pPrimitiveRendererEcef;
            Renderers::DebugTextRendererEcef* m_pTextRendererEcef;
            Renderers::DebugTextRendererScreenSpace* m_pTextRendererScreenSpace;
        };
    }
}