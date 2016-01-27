// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "GLState.h"
#include <vector>
#include "GLHelpers.h"

namespace Eegeo
{
    namespace Rendering
    {
        //! Template class for representing a dynamic GL Buffer with an in memory representation of the data (Vertex or Index data) that can be glBufferSubData copied.
        template<class T>
        class DynamicBuffer
        {
        public:
            DynamicBuffer(GLenum bufferType, int initialCapacity)
            : m_glBuffer(0)
            , m_bufferType(bufferType)
            {
                m_bufferData.reserve(initialCapacity);
                GenerateBuffers();
            }
            
            ~DynamicBuffer()
            {
                DestroyBuffers();
            }
            
            void GenerateBuffers()
            {
                Eegeo::Helpers::GLHelpers::LockGL contextLock;
                Eegeo_ASSERT(m_glBuffer == 0);
                Eegeo_GL(glGenBuffers(1, &m_glBuffer));
                Eegeo_GL(glBindBuffer(m_bufferType, m_glBuffer));
                Eegeo_GL(glBufferData(m_bufferType, BufferCapacityBytes(), m_bufferData.data(), GL_DYNAMIC_DRAW));
                Eegeo_GL(glBindBuffer (m_bufferType, 0));
            }
            
            void DestroyBuffers()
            {
                Eegeo_GL(glDeleteBuffers(1, &m_glBuffer));
                m_glBuffer = 0;
            }

            void Reset()
            {
                m_bufferData.clear();
            }

            void AddElement(const T& element)
            {
                size_t prevCapacity = m_bufferData.capacity();

                m_bufferData.push_back(element);
                
                if (prevCapacity != m_bufferData.capacity())
                {
                    DestroyBuffers();
                    GenerateBuffers();
                }
            }
            
            int CurrentElementCount() const { return static_cast<int>(m_bufferData.size()); }
            int BufferCapacity() const { return m_bufferData.capacity(); }
            size_t BufferCapacityBytes() const { return m_bufferData.capacity() * sizeof(T); }
            size_t BufferDataBytes() const { return m_bufferData.size() * sizeof(T); }
            
            const std::vector<T>& GetBufferData() const { return m_bufferData; }
            
            u32 GetGLBuffer() { return m_glBuffer; }
            
        private:
            u32 m_glBuffer;
            GLenum m_bufferType;
            std::vector<T> m_bufferData;
        };
    }
}