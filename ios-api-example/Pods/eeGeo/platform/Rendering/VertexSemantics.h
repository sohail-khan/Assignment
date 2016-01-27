// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Rendering
    {
        namespace VertexSemanticId
        {
            enum IdValues
            {
                Position,
                UV,
                UV2,
                Normal,
                Color,
                
                Max
            };
        }
        
        namespace VertexSemanticFlags
        {
            enum FlagValues
            {
                None            =   0,
                PositionFlag    =   (1 << VertexSemanticId::Position),
                UVFlag          =   (1 << VertexSemanticId::UV),
                UV2Flag         =   (1 << VertexSemanticId::UV2),
                Normal          =   (1 << VertexSemanticId::Normal),
                Color          =   (1 << VertexSemanticId::Color)
            };

            inline FlagValues GetFlagForSemantic(const VertexSemanticId::IdValues semantic)
            {
                return (VertexSemanticFlags::FlagValues)(1 << semantic);
            }
            
            inline FlagValues SetFlagForSemantic(const FlagValues flags, const VertexSemanticId::IdValues semantic)
            {
                return (VertexSemanticFlags::FlagValues)(flags | GetFlagForSemantic(semantic));
            }
            
            inline bool FlagsContainSemantic(const FlagValues flags, const VertexSemanticId::IdValues semantic)
            {
                return ((flags & GetFlagForSemantic(semantic)) != 0);
            }
        }
    }
}