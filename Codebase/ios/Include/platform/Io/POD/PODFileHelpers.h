// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include <fstream>

#define PVRTMODELPOD_TAG_MASK			(0x80000000)
#define PVRTMODELPOD_TAG_START			(0x00000000)
#define PVRTMODELPOD_TAG_END			(0x80000000)

namespace Eegeo
{
    class Texture;

    namespace IO
    {
        namespace POD
        {        
            enum EPODFileName
            {
                ePODFileVersion				= 1000,
                ePODFileScene,
                ePODFileExpOpt,
                ePODFileHistory,
                ePODFileEndiannessMisMatch  = -402456576,
                
                ePODFileColourBackground	= 2000,
                ePODFileColourAmbient,
                ePODFileNumCamera,
                ePODFileNumLight,
                ePODFileNumMesh,
                ePODFileNumNode,
                ePODFileNumMeshNode,
                ePODFileNumTexture,
                ePODFileNumMaterial,
                ePODFileNumFrame,
                ePODFileCamera,		
                ePODFileLight,		
                ePODFileMesh,		
                ePODFileNode,		
                ePODFileTexture,	
                ePODFileMaterial,	
                ePODFileFlags,
                ePODFileFPS,
                
                ePODFileMatName				= 3000,
                ePODFileMatIdxTexDiffuse,
                ePODFileMatOpacity,
                ePODFileMatAmbient,
                ePODFileMatDiffuse,
                ePODFileMatSpecular,
                ePODFileMatShininess,
                ePODFileMatEffectFile,
                ePODFileMatEffectName,
                ePODFileMatIdxTexAmbient,
                ePODFileMatIdxTexSpecularColour,
                ePODFileMatIdxTexSpecularLevel,
                ePODFileMatIdxTexBump,
                ePODFileMatIdxTexEmissive,
                ePODFileMatIdxTexGlossiness,
                ePODFileMatIdxTexOpacity,
                ePODFileMatIdxTexReflection,
                ePODFileMatIdxTexRefraction,
                ePODFileMatBlendSrcRGB,
                ePODFileMatBlendSrcA,
                ePODFileMatBlendDstRGB,
                ePODFileMatBlendDstA,
                ePODFileMatBlendOpRGB,
                ePODFileMatBlendOpA,
                ePODFileMatBlendColour,
                ePODFileMatBlendFactor,
                ePODFileMatFlags,
                
                ePODFileTexName				= 4000,
                
                ePODFileNodeIdx				= 5000,
                ePODFileNodeName,
                ePODFileNodeIdxMat,
                ePODFileNodeIdxParent,
                ePODFileNodePos,
                ePODFileNodeRot,
                ePODFileNodeScale,
                ePODFileNodeAnimPos,
                ePODFileNodeAnimRot,
                ePODFileNodeAnimScale,
                ePODFileNodeMatrix,
                ePODFileNodeAnimMatrix,
                ePODFileNodeAnimFlags,
                ePODFileNodeAnimPosIdx,
                ePODFileNodeAnimRotIdx,
                ePODFileNodeAnimScaleIdx,
                ePODFileNodeAnimMatrixIdx,
                
                ePODFileMeshNumVtx			= 6000,
                ePODFileMeshNumFaces,
                ePODFileMeshNumUVW,
                ePODFileMeshFaces,
                ePODFileMeshStripLength,
                ePODFileMeshNumStrips,
                ePODFileMeshVtx,
                ePODFileMeshNor,
                ePODFileMeshTan,
                ePODFileMeshBin,
                ePODFileMeshUVW,			
                ePODFileMeshVtxCol,
                ePODFileMeshBoneIdx,
                ePODFileMeshBoneWeight,
                ePODFileMeshInterleaved,
                ePODFileMeshBoneBatches,
                ePODFileMeshBoneBatchBoneCnts,
                ePODFileMeshBoneBatchOffsets,
                ePODFileMeshBoneBatchBoneMax,
                ePODFileMeshBoneBatchCnt,
                ePODFileMeshUnpackMatrix,
                
                ePODFileLightIdxTgt			= 7000,
                ePODFileLightColour,
                ePODFileLightType,
                ePODFileLightConstantAttenuation,
                ePODFileLightLinearAttenuation,
                ePODFileLightQuadraticAttenuation,
                ePODFileLightFalloffAngle,
                ePODFileLightFalloffExponent,
                
                ePODFileCamIdxTgt			= 8000,
                ePODFileCamFOV,
                ePODFileCamFar,
                ePODFileCamNear,
                ePODFileCamAnimFOV,
                
                ePODFileDataType			= 9000,
                ePODFileN,
                ePODFileStride,
                ePODFileData
            };


            enum EPODBlendFunc
            {
                ePODBlendFunc_ZERO=0,
                ePODBlendFunc_ONE,
                ePODBlendFunc_BLEND_FACTOR,
                ePODBlendFunc_ONE_MINUS_BLEND_FACTOR,
                
                ePODBlendFunc_SRC_COLOR = 0x0300,
                ePODBlendFunc_ONE_MINUS_SRC_COLOR,
                ePODBlendFunc_SRC_ALPHA,
                ePODBlendFunc_ONE_MINUS_SRC_ALPHA,
                ePODBlendFunc_DST_ALPHA,
                ePODBlendFunc_ONE_MINUS_DST_ALPHA,
                ePODBlendFunc_DST_COLOR,
                ePODBlendFunc_ONE_MINUS_DST_COLOR,
                ePODBlendFunc_SRC_ALPHA_SATURATE,
                
                ePODBlendFunc_CONSTANT_COLOR = 0x8001,
                ePODBlendFunc_ONE_MINUS_CONSTANT_COLOR,
                ePODBlendFunc_CONSTANT_ALPHA,
                ePODBlendFunc_ONE_MINUS_CONSTANT_ALPHA
            };

            enum EPVRTDataType {
                EPODDataNone,
                EPODDataFloat,
                EPODDataInt,
                EPODDataUnsignedShort,
                EPODDataRGBA,
                EPODDataARGB,
                EPODDataD3DCOLOR,
                EPODDataUBYTE4,
                EPODDataDEC3N,
                EPODDataFixed16_16,
                EPODDataUnsignedByte,
                EPODDataShort,
                EPODDataShortNorm,
                EPODDataByte,
                EPODDataByteNorm,
                EPODDataUnsignedByteNorm,
                EPODDataUnsignedShortNorm,
                EPODDataUnsignedInt
            };

            struct ePODData {
                
                ePODData()
                : type(EPODDataNone), num(0), stride(0), pOffset(NULL), dynamicallyAllocated(false)
                {};
                
                EPVRTDataType   type;
                u32          	num;
                u32          	stride;
                u8*          	pOffset;
                bool            dynamicallyAllocated;
            };

            class PODFileHelpers
            {                
            public:
                
                static void ParseFileTexture (Eegeo::Helpers::ITextureFileLoader * loader,
                                              std::istream& stream,
                                              u32 fileOffset,
                                              u32 fileSize,
                                              u32& pTexture);

                static void ReadMarker (std::istream& stream, u32* pName, u32* pLength);
                
                static void ReadArray (std::istream& stream, u8* pData, u32 numByte);
                static void ReadArray16(std::istream& stream, u16* pData, u32 size);
                static void ReadArray32(std::istream& stream, u32* pData, u32 size);
                
                static void ReadString(std::istream& stream, std::string &destString);
                
                static void ReadCPODData(std::istream& stream, u32 fileOffset, u32 fileSize, u32 spec, ePODData* pData, bool validData);
                
                static u32 GetDataTypeSize (EPVRTDataType type);
                
                template <typename T>
                static void ReadS32(std::istream& stream, T* value)
                {
                    unsigned char ub[4];
                    
                    stream.read((char*)( &ub[0] ), 4);
                    
                    int *pn = (int*)value;
                    *pn = (int) ((ub[3] << 24) | (ub[2] << 16) | (ub[1] << 8) | ub[0]);
                }
                
                template <typename T>
                static void Read32(std::istream& stream, T* value)
                {
                    unsigned char ub[4];
                    
                    stream.read((char*)( &ub[0] ), 4);
                    
                    unsigned int *pn = (unsigned int*)value; 
                    *pn = (unsigned int) ((ub[3] << 24) | (ub[2] << 16) | (ub[1] << 8) | ub[0]);
                }
                
                
                template <typename T>
                static void Read16(std::istream& stream, T* value)
                {
                    unsigned char ub[2];
                    
                    stream.read((char*)( &ub[0] ), 2);
                    
                    unsigned short *pn = (unsigned short*)value;    
                    *pn = (unsigned short) ((ub[1] << 8) | ub[0]);
                }
                
            };
        }
    }
}
