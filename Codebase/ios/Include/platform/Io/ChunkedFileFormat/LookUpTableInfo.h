
#include "ChunkedFileFormat.h"
#include "AllVertexTypes.h"
#include "Types.h"

namespace Eegeo
{
    namespace IO
    {
        namespace ChunkedFileFormat
        {
            namespace QuantizedMeshSetChunkReader
            {
                struct ShortVector3
                {
                    s16 x;
                    s16 y;
                    s16 z;
                };
                
                struct ByteVector3
                {
                    s8 x;
                    s8 y;
                    s8 z;
                };
                
                struct UShortVector3
                {
                    u16 x;
                    u16 y;
                    u16 z;
                };
                
                struct LookUpTableInfo
                {
                public:
                    LookUpTableInfo(const UShortVector3* pPositionsLUT,
                                    const ByteVector3* pNormalsLUT,
                                    const u32* pColoursLUT,
                                    
                                    size_t positionsLUTCount,
                                    size_t normalsLUTCount,
                                    size_t coloursLUTCount)
                    : m_pPositionsLUT(pPositionsLUT)
                    , m_pNormalsLUT(pNormalsLUT)
                    , m_pColoursLUT(pColoursLUT)
                    , m_positionsLUTCount(positionsLUTCount)
                    , m_normalsLUTCount(normalsLUTCount)
                    , m_coloursLUTCount(coloursLUTCount)
                    {}
                    
                    const UShortVector3* PositionsLUT() const { return m_pPositionsLUT; }
                    const ByteVector3* NormalsLUT() const { return m_pNormalsLUT; }
                    const u32* ColoursLUT() const { return m_pColoursLUT; }
                    
                    size_t PositionsLUTCount() const { return m_positionsLUTCount; }
                    size_t NormalsLUTCount() const { return m_normalsLUTCount; }
                    size_t ColoursLUTCount() const { return m_coloursLUTCount; }
                    
                    
                private:
                    const UShortVector3* m_pPositionsLUT;
                    const ByteVector3* m_pNormalsLUT;
                    const u32* m_pColoursLUT;
                    
                    size_t m_positionsLUTCount;
                    size_t m_normalsLUTCount;
                    size_t m_coloursLUTCount;
                    
                };
            }
        }
    }
}
