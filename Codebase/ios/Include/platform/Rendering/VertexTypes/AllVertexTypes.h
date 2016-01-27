// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexTypes
        {
            struct TextVertex
            {
                float x,y,z,altitude;
                float u,v,shadow;
            };
            
            inline TextVertex CreateTextVertex(float x, float y, float z, float altitude, float u, float v, float shadow)
            {
                TextVertex vtx;
                vtx.x = x;
                vtx.y = y;
                vtx.z = z;
                vtx.altitude = altitude;
                vtx.u = u;
                vtx.v = v;
                vtx.shadow = shadow;
                return vtx;
            }
            
            struct PackedDiffuseVertex
            {
                u16 x,y,z,lightDots;
                u16 u,v;
            };

            struct PackedDiffuseUvLightDotColorVertex
            {
                u16 x,y,z,lightDots;
                u16 u,v;
                Byte r, g, b, a;
            };
            
            struct PackedPositionNormalUvColorVertex
            {
                u16 x,y,z,pad1;
                Byte nx,ny,nz,pad2;
                u16 u,v;
                Byte r, g, b, a;
            };
            
            struct PackedPositionNormalUvVertex
            {
                u16 x,y,z,pad1;
                Byte nx,ny,nz,pad2;
                u16 u,v;
            };
            
            struct PackedTwoTextureVertex
            {
                u16 x,y,z,lightDots;
                u16 u,v;
                u16 u2,v2;
            };
            
            struct PackedStencilShadowVertex
            {
                u16 x,y,z,h;
            };
            
            struct ShortPositionVertex
            {
                u16 x,y,z;
            };
            
            struct DiffuseVertex
            {
                float x,y,z,lightDots;
                float u,v;
            };
            
            
            struct PositionVertex
            {
                float x,y,z;
            };
            
            struct TexturedVertex
            {
                float x,y,z;
                float u,v;
            };
            
            struct ColoredVertex
            {
                float x,y,z;
                float r,g,b,a;
            };
            
            struct TexturedColoredVertex
            {
                float x,y,z;
                float u,v;
                float r,g,b,a;
            };
            
            struct ModelDiffuseVertex
            {
                float x,y,z;
                float nx,ny,nz;
                float u,v;
            };
            
            inline ColoredVertex CreateColoredVertex(const v3& position, const v4& color)
            {
                ColoredVertex vert;
                vert.x = position.GetX();
                vert.y = position.GetY();
                vert.z = position.GetZ();
                
                vert.r = color.GetX();
                vert.g = color.GetY();
                vert.b = color.GetZ();
                vert.a = color.GetW();
                
                return vert;
            }
            
            inline ColoredVertex CreateColoredVertex(const v3& position, const v3& color)
            {
                ColoredVertex vert = CreateColoredVertex(position, v4(color, 1.f));
                return vert;
            }
            
            inline TexturedColoredVertex CreateTexturedColoredVertex(const v3& position, const v2& uv, const v4& color)
            {
                TexturedColoredVertex vert;
                vert.x = position.GetX();
                vert.y = position.GetY();
                vert.z = position.GetZ();
                
                vert.u = uv.x;
                vert.v = uv.y;
                
                vert.r = color.GetX();
                vert.g = color.GetY();
                vert.b = color.GetZ();
                vert.a = color.GetW();
                
                return vert;

            }
            
            inline PositionVertex CreatePositionVertex(float x, float y, float z)
            {
                PositionVertex vtx;
                vtx.x = x;
                vtx.y = y;
                vtx.z = z;
                return vtx;
            }

            inline PositionVertex CreatePositionVertex(const Eegeo::v3& p)
            {
                return CreatePositionVertex(p.x, p.y, p.z);
            }
            
            inline TexturedVertex CreateTexturedVertex(float x, float y, float z, float u, float v)
            {
                TexturedVertex vtx;
                vtx.x = x;
                vtx.y = y;
                vtx.z = z;
                vtx.u = u;
                vtx.v = v;
                return vtx;
            }
            
            inline TexturedVertex CreateTexturedVertex(const Eegeo::v3& p, const Eegeo::v2& uv)
            {
                return CreateTexturedVertex(p.x, p.y, p.z, uv.x, uv.y);
            }
            
            struct Textured2DVertex
            {
                float x, y, u, v;
            };
            
            inline Textured2DVertex CreateTextured2DVertex(float x, float y, float u, float v)
            {
                Textured2DVertex vtx;
                vtx.x = x;
                vtx.y = y;
                vtx.u = u;
                vtx.v = v;
                return vtx;
            }
            
            inline ModelDiffuseVertex CreateModelDiffuseVertex(const Eegeo::v3& position, const Eegeo::v3& normal, const Eegeo::v2& uv)
            {
                ModelDiffuseVertex vtx;
                vtx.x = position.x;
                vtx.y = position.y;
                vtx.z = position.z;
                vtx.nx = normal.x;
                vtx.ny = normal.y;
                vtx.nz = normal.z;
                vtx.u = uv.x;
                vtx.v = uv.y;
                return vtx;
            }
        }
    }
    
}
