// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Spinlock.h"
#include "Graphics.h"
#include "Streaming.h"
#include <deque>
#include <map>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        /*!
         * \brief A pool of Open GL buffers.
         *
         * The cost of creating Open GL buffers can be high on some platforms. 
         * This class allows buffers to be recycled, thus avoiding the high cost of creating them.
         */
        class GlBufferPool  : protected Eegeo::NonCopyable
        {
        private:
            typedef std::deque<GLuint> TFreeList;
            
            Eegeo::SpinLock m_pSpinLock;
            
            TFreeList m_freeIndexBuffers;
            TFreeList m_freeVertexBuffers;
            
            int m_numOfAllocations;
            int m_numOfReleases;
            int m_numAllocated;
            int m_orphanedBufferSize;
            
            bool m_canOrphanInitialised;
            bool m_canOrphanBuffers;
            
            void AllocateBuffers(TFreeList& freeBuffers);

            void ReleaseBuffer(GLuint bufferId, GLint bufferType);
            void OrphanBuffer(GLuint bufferId, GLint bufferType);
            void DeleteBuffers(std::deque<GLuint>& toDelete);
            void DeleteBuffer(GLuint bufferId);
            GLuint AllocateBuffer(GLint bufferType, size_t bufferSize, const std::string& debugName);

            bool DetermineCanOrphanBuffers(int orphanedBufferSize) const;
            
            void AmortizedReleaseBuffers();
            
            struct GLBufferDebugInfo
            {
                GLuint bufferId;
                GLint bufferType;
                size_t size;
                std::string name;
                
            };
            
            std::map<GLuint, GLBufferDebugInfo> m_debugInfo;
            
        public:
            GlBufferPool(bool tryToEnableBufferPooling);
            virtual ~GlBufferPool();

            void Update(float dt);
            GLuint AllocateVertexBuffer(size_t bufferSize, const std::string& debugName);
            GLuint AllocateIndexBuffer(size_t bufferSize, const std::string& debugName);
            void ReleaseVertexBuffer(GLuint bufferId);
            void ReleaseIndexBuffer(GLuint bufferId);

            void DumpDebugInfo();
            
            int GetNumOfAllocations() const;
            int GetNumOfReleases() const;
            int GetNumOfFree();
            int GetNumOfAllocated();
            
            static std::string CreateDebugString(const std::string& prefix, int meshIndex, const Streaming::MortonKey& mortonKey);
        };
    }
}
