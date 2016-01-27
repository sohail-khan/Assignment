// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "POD.h"

#include <vector>

#define MESH_MAX_UV_CHANNELS        (2)

namespace Eegeo
{
	typedef void (*HeightCB)(const void* pVB, u32 numVertices, u32 numStride, const void* pIB, u32 numIndices);

	typedef struct {
		
		float x, y, z;
		float nx, ny, nz;
		float u, v;
		
	} Mesh_Vertex;


	typedef struct {
		
		float x, y, z;
		float u, v;
		float u2, v2;
		
	} Mesh_Vertex_Multi;

	struct QuadrantData
	{
		u32          startIndex;
		u32          numIndices;
		
		Eegeo::v3         min;
		Eegeo::v3         max;
		
		QuadrantData*   pChildren;
		
		QuadrantData() : startIndex(0), numIndices(0), pChildren(NULL)
		{
			min.Set( FLT_MAX,  FLT_MAX,  FLT_MAX);
			max.Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
		}
	};

	class FrustumRadar;

	class ModelMesh {
		bool    		m_isSkin;
		bool			m_isPreLit;
		bool			m_includeNormals;
        bool            m_isTriStripped;
		
		u32  			m_compression;
		
		
		u32 			m_vertexBuffer;

#if !defined (ANDROID)
		u32 			m_vertexArray;
#endif
				
		u32 			m_indexBuffer;
		
		u32 			m_numVertices;
		u32 			m_numIndices;
		u32 			m_numUVChannels;
		
		u32 			m_vertexStride;
		u32 			m_normalStride;
		u32             m_UVStride[MESH_MAX_UV_CHANNELS];
		
		const u8* 		m_pVertexData;
		const u8* 		m_pNormalData;
		const u8* 		m_pUVData[MESH_MAX_UV_CHANNELS];
		const u8* 		m_pBoneWeightData;
		const u8* 		m_pBoneIndexData;
        
        const u32*      m_pTriStripLengths;
        u32             m_numTriStrips;
		
		std::vector<s32>	m_boneRemap;
		
		QuadrantData*	m_pQuadrants;
		

	public:

		ModelMesh				();
		~ModelMesh				();
			
        static ModelMesh* CreateFromPODMesh(
                                       const IO::POD::PODMesh* podMesh,
                                       HeightCB createHeightData,
                                       bool isPreLit
                                       );
		void Create 			(Eegeo::Rendering::GLState& glState, Mesh_Vertex* pVertices, u32 numVertices, u16* pIndices, u32 numIndices);
		void Parse				(void* pMeshData);
		void Draw 				(Eegeo::Rendering::GLState& glState, const Eegeo::m44& world, Eegeo::FrustumRadar* pFrustum, bool clip);
		
		bool IsSkinned			() 			{ return m_isSkin; }
		u32  GetNumSkinMatrices	() 			{ return static_cast<u32>(m_boneRemap.size()); }
		u32  GetSkinMatrix		(int index) { return m_boneRemap[index]; }

		Eegeo::v3 		m_extentsMin;
		Eegeo::v3 		m_extentsMax;
		Eegeo::v3 		m_centre;
		float 			m_radius;
        
    private:
        void InitFromPODMesh    (const IO::POD::PODMesh* podMesh);
        void InitRenderData (
                             HeightCB createHeightData,
                             bool isPreLit,
                             const void* pInterleavedData,
                             const void* pIndexData,
                             u32 numBonesVert,
                             const s32* batchBoneCounts
                             );
	};
}
