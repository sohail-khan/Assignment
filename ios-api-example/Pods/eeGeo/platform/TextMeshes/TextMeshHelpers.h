// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "FontCharacter.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace TextMeshes
    {
        namespace TextMeshHelpers
        {
            inline void CalcLocalQuadPointsSceenSpace(const Fonts::FontCharacter& fontCharacter, float x, float y, float z, float fontLineHeight, float sizeFactor, v3 out_points[4])
            {
                // http://www.angelcode.com/products/bmfont/doc/render_text.html
                
                const float w = fontCharacter.width * sizeFactor;
                const float h = fontCharacter.height * sizeFactor;
                const float ox = fontCharacter.offsetX * sizeFactor;
                
                const float left = x + ox;
                const float right = left + w;
                
                float bottom = y + (fontLineHeight*sizeFactor);
                float top = bottom - h;

                out_points[0].Set(left, top, z);
                out_points[1].Set(right, top, z);
                out_points[2].Set(left, bottom, z);
                out_points[3].Set(right, bottom, z);
            }
            
            inline void CalcLocalQuadPoints(const Fonts::FontCharacter& fontCharacter, float x, float y, float z, float fontLineHeight, float sizeFactor, v3 out_points[4], bool anchoredBottom=false)
            {
                // http://www.angelcode.com/products/bmfont/doc/render_text.html
                
                const float w = fontCharacter.width * sizeFactor;
                const float h = fontCharacter.height * sizeFactor;
                const float ox = fontCharacter.offsetX * sizeFactor;
                
                const float left = x + ox;
                const float right = left + w;
                
                float top = 0.f;
                float bottom = 0.f;
                if (anchoredBottom)
                {
                    bottom = y + (fontLineHeight*sizeFactor);
                    top = bottom - h;
                }
                else
                {
                    top = y + (fontLineHeight - fontCharacter.offsetY)*sizeFactor;
                    bottom = top - h;
                }
                
                out_points[0].Set(left, top, z);
                out_points[1].Set(right, top, z);
                out_points[2].Set(left, bottom, z);
                out_points[3].Set(right, bottom, z);
            }
            
            inline void CalcQuadTexCoords(const Fonts::FontCharacter& fontCharacter, float oneOverScaleW, float oneOverScaleH, v2& out_leftBottom, v2& out_rightTop)
            {
                const float left = fontCharacter.x * oneOverScaleW;
                const float right = (fontCharacter.x + fontCharacter.width) * oneOverScaleW;
                // OpenGL texcoord(0,0) is bottom left
                // fontCharacter x,y (0,0) is top left of texture, y addresses top of glyph
                const float top = 1.0f - fontCharacter.y * oneOverScaleH;
                const float bottom = 1.0f - (fontCharacter.y + fontCharacter.height) * oneOverScaleH;
                out_leftBottom.Set(left, bottom);
                out_rightTop.Set(right, top);
            }
            
        }
    }
}