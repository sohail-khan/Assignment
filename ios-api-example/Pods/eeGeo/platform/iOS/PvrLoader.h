// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"

#if defined(EEGEO_IOS)

namespace Eegeo
{
    namespace Helpers
    {
        namespace GLHelpers
        {
            struct TextureInfo;
        }
    }
        
    namespace iOS
    {
        struct PVR_Texture_Header
        {
            u32 dwHeaderSize;                    
            u32 dwHeight;                        
            u32 dwWidth;                         
            u32 dwMipMapCount;                   
            u32 dwpfFlags;                       
            u32 dwTextureDataSize;               
            u32 dwBitCount;                      
            u32 dwRBitMask;                      
            u32 dwGBitMask;                      
            u32 dwBBitMask;                      
            u32 dwAlphaBitMask;                  
            u32 dwPVR;                           
            u32 dwNumSurfs;                      
        } ;
        
        const u32 PVRTEX_MIPMAP          = (1<<8);           
        const u32 PVRTEX_TWIDDLE         = (1<<9);           
        const u32 PVRTEX_BUMPMAP         = (1<<10);          
        const u32 PVRTEX_TILING          = (1<<11);          
        const u32 PVRTEX_CUBEMAP         = (1<<12);          
        const u32 PVRTEX_FALSEMIPCOL     = (1<<13);          
        const u32 PVRTEX_VOLUME          = (1<<14);          
        const u32 PVRTEX_ALPHA			= (1<<15);		
        const u32 PVRTEX_VERTICAL_FLIP	= (1<<16);		
        
        const u32 PVRTEX_PIXELTYPE		= 0xff;			
        const u32 PVRTEX_IDENTIFIER      = 0x21525650;       
        
        const u32 PVRTEX_V1_HEADER_SIZE  = 44;			
        
        const u32 PVRTC2_MIN_TEXWIDTH	= 16;
        const u32 PVRTC2_MIN_TEXHEIGHT	= 8;
        const u32 PVRTC4_MIN_TEXWIDTH	= 8;
        const u32 PVRTC4_MIN_TEXHEIGHT	= 8;
        const u32 ETC_MIN_TEXWIDTH		= 4;
        const u32 ETC_MIN_TEXHEIGHT		= 4;
        const u32 DXT_MIN_TEXWIDTH		= 4;
        const u32 DXT_MIN_TEXHEIGHT		= 4;
        
        
        enum PixelType
        {
            MGLPT_ARGB_4444 = 0x00,
            MGLPT_ARGB_1555,
            MGLPT_RGB_565,
            MGLPT_RGB_555,
            MGLPT_RGB_888,
            MGLPT_ARGB_8888,
            MGLPT_ARGB_8332,
            MGLPT_I_8,
            MGLPT_AI_88,
            MGLPT_1_BPP,
            MGLPT_VY1UY0,
            MGLPT_Y1VY0U,
            MGLPT_PVRTC2,
            MGLPT_PVRTC4,
            
            
            OGL_RGBA_4444= 0x10,
            OGL_RGBA_5551,
            OGL_RGBA_8888,
            OGL_RGB_565,
            OGL_RGB_555,
            OGL_RGB_888,
            OGL_I_8,
            OGL_AI_88,
            OGL_PVRTC2,
            OGL_PVRTC4,
            OGL_BGRA_8888,
            OGL_A_8,
            OGL_PVRTCII4,	
            OGL_PVRTCII2,	
            
#ifdef _WIN32
            
            D3D_DXT1 = 0x20,
            D3D_DXT2,
            D3D_DXT3,
            D3D_DXT4,
            D3D_DXT5,
#endif
            
            
            D3D_RGB_332
#ifndef _WIN32
            = 0x25
#endif
            ,
            D3D_AL_44,
            D3D_LVU_655,
            D3D_XLVU_8888,
            D3D_QWVU_8888,
            
            
            D3D_ABGR_2101010,
            D3D_ARGB_2101010,
            D3D_AWVU_2101010,
            
            
            D3D_GR_1616,
            D3D_VU_1616,
            D3D_ABGR_16161616,
            
            
            D3D_R16F,
            D3D_GR_1616F,
            D3D_ABGR_16161616F,
            
            
            D3D_R32F,
            D3D_GR_3232F,
            D3D_ABGR_32323232F,
            
            
            ETC_RGB_4BPP,
            ETC_RGBA_EXPLICIT,				
            ETC_RGBA_INTERPOLATED,			
            
            D3D_A8 = 0x40,
            D3D_V8U8,
            D3D_L16,
            
            D3D_L8,
            D3D_AL_88,
            
            
            D3D_UYVY,
            D3D_YUY2,
            
            
            DX10_R32G32B32A32_FLOAT= 0x50,
            DX10_R32G32B32A32_UINT ,
            DX10_R32G32B32A32_SINT,
            
            DX10_R32G32B32_FLOAT,
            DX10_R32G32B32_UINT,
            DX10_R32G32B32_SINT,
            
            DX10_R16G16B16A16_FLOAT ,
            DX10_R16G16B16A16_UNORM,
            DX10_R16G16B16A16_UINT ,
            DX10_R16G16B16A16_SNORM ,
            DX10_R16G16B16A16_SINT ,
            
            DX10_R32G32_FLOAT ,
            DX10_R32G32_UINT ,
            DX10_R32G32_SINT ,
            
            DX10_R10G10B10A2_UNORM ,
            DX10_R10G10B10A2_UINT ,
            
            DX10_R11G11B10_FLOAT ,				
            
            DX10_R8G8B8A8_UNORM ,
            DX10_R8G8B8A8_UNORM_SRGB ,
            DX10_R8G8B8A8_UINT ,
            DX10_R8G8B8A8_SNORM ,
            DX10_R8G8B8A8_SINT ,
            
            DX10_R16G16_FLOAT ,
            DX10_R16G16_UNORM ,
            DX10_R16G16_UINT ,
            DX10_R16G16_SNORM ,
            DX10_R16G16_SINT ,
            
            DX10_R32_FLOAT ,
            DX10_R32_UINT ,
            DX10_R32_SINT ,
            
            DX10_R8G8_UNORM ,
            DX10_R8G8_UINT ,
            DX10_R8G8_SNORM ,
            DX10_R8G8_SINT ,
            
            DX10_R16_FLOAT ,
            DX10_R16_UNORM ,
            DX10_R16_UINT ,
            DX10_R16_SNORM ,
            DX10_R16_SINT ,
            
            DX10_R8_UNORM,
            DX10_R8_UINT,
            DX10_R8_SNORM,
            DX10_R8_SINT,
            
            DX10_A8_UNORM,
            DX10_R1_UNORM,
            DX10_R9G9B9E5_SHAREDEXP,	
            DX10_R8G8_B8G8_UNORM,		
            DX10_G8R8_G8B8_UNORM,		
            
#ifdef _WIN32
            DX10_BC1_UNORM,
            DX10_BC1_UNORM_SRGB,
            
            DX10_BC2_UNORM,
            DX10_BC2_UNORM_SRGB,
            
            DX10_BC3_UNORM,
            DX10_BC3_UNORM_SRGB,
            
            DX10_BC4_UNORM,				
            DX10_BC4_SNORM,				
            
            DX10_BC5_UNORM,				
            DX10_BC5_SNORM,				
#endif
            
            
            
            ePT_VG_sRGBX_8888  = 0x90,
            ePT_VG_sRGBA_8888,
            ePT_VG_sRGBA_8888_PRE,
            ePT_VG_sRGB_565,
            ePT_VG_sRGBA_5551,
            ePT_VG_sRGBA_4444,
            ePT_VG_sL_8,
            ePT_VG_lRGBX_8888,
            ePT_VG_lRGBA_8888,
            ePT_VG_lRGBA_8888_PRE,
            ePT_VG_lL_8,
            ePT_VG_A_8,
            ePT_VG_BW_1,
            
            
            ePT_VG_sXRGB_8888,
            ePT_VG_sARGB_8888,
            ePT_VG_sARGB_8888_PRE,
            ePT_VG_sARGB_1555,
            ePT_VG_sARGB_4444,
            ePT_VG_lXRGB_8888,
            ePT_VG_lARGB_8888,
            ePT_VG_lARGB_8888_PRE,
            
            
            ePT_VG_sBGRX_8888,
            ePT_VG_sBGRA_8888,
            ePT_VG_sBGRA_8888_PRE,
            ePT_VG_sBGR_565,
            ePT_VG_sBGRA_5551,
            ePT_VG_sBGRA_4444,
            ePT_VG_lBGRX_8888,
            ePT_VG_lBGRA_8888,
            ePT_VG_lBGRA_8888_PRE,
            
            
            ePT_VG_sXBGR_8888,
            ePT_VG_sABGR_8888 ,
            ePT_VG_sABGR_8888_PRE,
            ePT_VG_sABGR_1555,
            ePT_VG_sABGR_4444,
            ePT_VG_lXBGR_8888,
            ePT_VG_lABGR_8888,
            ePT_VG_lABGR_8888_PRE,
            
            
            END_OF_PIXEL_TYPES,
            
            MGLPT_NOTYPE = 0xffffffff
            
        };
        
        
        bool LoadPvr (const void* pointer, Eegeo::Helpers::GLHelpers::TextureInfo & textureInfo);
    }
}

#endif
