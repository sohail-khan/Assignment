// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            const int POD_MESH_MAX_UV_CHANNELS = 2;
            
            class PODMesh
            {
            private:
                u32     m_numVertices;
                u32     m_numIndices;
                u32     m_numUVChannels;
                
                u32     m_positionStride;
                u32     m_positionOffset;
                
                u32     m_normalStride;
                u32     m_normalOffset;

                u32     m_pUVStrides[POD_MESH_MAX_UV_CHANNELS];
                u32 	m_pUVOffsets[POD_MESH_MAX_UV_CHANNELS];
                
                void*   m_pInterleavedData;
                void*   m_pIndexData;
                
                u32*    m_pStripLengths;
                u32     m_numStrips;
                
                u32     m_boneIndexStride;
                u8*     m_pBoneIndexData;
                u32     m_numBonesVert;
                
                u32     m_boneWeightStride;
                u8*     m_pBoneWeightData;
                u32     m_numBoneWeights;
                
                s32     m_batchCount;
                s32     m_batchMax;
                s32*    m_pBatches;
                s32*    m_pBatchOffsets;
                s32*    m_pBatchBoneCounts;
            
                bool m_positionOffsetDynamicallyAllocated;
                bool m_normalOffsetDynamicallyAllocated;
                bool m_uvOffsetDynamicallyAllocated[POD_MESH_MAX_UV_CHANNELS];
                bool m_indexDataDynamicallyAllocated;
                bool m_boneIndexDataDynamicallyAllocated;
                bool m_boneWeightDataDynamicallyAllocated;
                
            public:
                PODMesh();
                ~PODMesh();
                
                void SetNumVertices(u32 numVertices);
                void SetNumIndices(u32 numIndices);                            
                void SetNumUVChannels(u32 numIndices);
                
                void SetPositionData(u32 offset, u32 stride, bool dynamicallyAllocated);
                void SetNormalData(u32 offset, u32 stride, bool dynamicallyAllocated);
                void SetUVData(u32 channel, u32 offset, u32 strid, bool dynamicallyAllocatede);
                
                void SetInterleavedData(void* pInterleavedData);
                void SetIndexData(void* pIndexData, bool dynamicallyAllocated);
                
                void SetStripLengths(u32* pStripLengths);
                void SetNumStrips(u32 numStrips);
                
                void SetBoneIndexData(u8* pBoneIndexData, u32 boneIndexStride, u32 numBonesVert, bool dynamicallyAllocated);
                void SetBoneWeightData(u8* pBoneWeightData, u32 stride, u32 numWeights, bool dynamicallyAllocated);
                void SetBatches(s32* pBatches);
                void SetBatchOffsets(s32* pBatchOffsets);
                void SetBatchBoneCounts(s32* pBatchBoneCounts);
                void SetBatchMax(u32 batchMax);
                void SetBatchCount(u32 batchCount);
                
                u32 GetNumVertices() const;
                u32 GetNumIndices() const;
                u32 GetNumUVChannels() const;
                
                u32 GetPositionStride() const;
                u32 GetPositionOffset() const;
                
                u32 GetNormalStride() const;
                u32 GetNormalOffset() const;

                u32 GetUVStride(u32 channel) const;
                u32 GetUVOffset(u32 channel) const;
                
                const void* GetInterleavedData() const;
                const void* GetIndexData() const;
                size_t GetIndexDataSize() const;
                
                u32 GetNumStrips() const;
                const u32* GetStripLengths() const;
                                
                const u8* GetBoneIndexData() const;
                size_t GetBoneIndexDataSize() const;
                u32 GetNumBonesVert() const;
                
                const u8* GetBoneWeightData() const;
                size_t GetBoneWeightDataSize() const;
                
                const s32* GetBoneBatchCounts() const;
            };
        }
    }
}