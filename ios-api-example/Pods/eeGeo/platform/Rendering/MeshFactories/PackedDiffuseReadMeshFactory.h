// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ReadMeshFactory.h"
#include "QuantizedMeshSetChunkReader.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace MeshFactories
        {
            /*!
             * \brief Factory for creating meshes with the PackedDiffuseVertex vertex format from data in a QuantizedMeshInfo object.
             */
            class PackedDiffuseReadMeshFactory : protected ReadMeshFactory, public Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::IQuantizedMeshSetChunkReaderMeshFactory
            {
            public:
                PackedDiffuseReadMeshFactory(
                                             Eegeo::Rendering::GlBufferPool& glBufferPool,
                                             const VertexLayouts::VertexLayout& packedStencilShadowVertexLayout,
                                             const VertexLayouts::VertexLayout& packedDiffuseVertexLayout,
                                             const VertexLayouts::VertexLayout& packedPositionUvLightDotsColourVertexLayout,
                                             const VertexLayouts::VertexLayout& packedPositionNormalUvColorVertexLayout,
                                             const VertexLayouts::VertexLayout& packedPositionNormalUVVertexLayout);
                
                Rendering::Mesh* CreateMesh(const Eegeo::IO::ChunkedFileFormat::QuantizedMeshSetChunkReader::QuantizedMeshInfo& meshInfo,
                                            const void* pVertexData,
                                            const void* pIndexData,
                                            const std::string& debugName);
                
                const Eegeo::Rendering::VertexLayouts::VertexLayout& GetVertexLayoutForVertexFormat(const u32 vertexFormat) const;
            private:
                const VertexLayouts::VertexLayout& m_packedStencilShadowVertexLayout;
                const VertexLayouts::VertexLayout& m_packedDiffuseVertexLayout;
                const VertexLayouts::VertexLayout& m_packedPositionUvLightDotsColourVertexLayout;
                const VertexLayouts::VertexLayout& m_packedPositionNormalUvColorVertexLayout;
                const VertexLayouts::VertexLayout& m_packedPositionNormalUvVertexLayout;
            };            
        }
    }
}
