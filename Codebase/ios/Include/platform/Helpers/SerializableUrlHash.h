// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "tr1.h"
#include "IFileIO.h"
#include <string>
#include <iostream>
#include <vector>

namespace Eegeo
{
    namespace Helpers
    {
        class SerializableUrlHash
        {
        public:
            typedef Eegeo::unordered_set<std::string>::type TContainer;
            
        private:
            IFileIO& m_fileIO;
            TContainer m_members;
            const unsigned int Sentinel;
            
        public:
            
            SerializableUrlHash(IFileIO& fileIO)
            :m_fileIO(fileIO)
            ,Sentinel(0x3605C077)
            {}
            
            TContainer::const_iterator First() const { return m_members.begin(); }
            TContainer::const_iterator End() const { return m_members.end(); }
            
            bool Contains(const std::string& item) {
                return m_members.find(item) != m_members.end();
            }
            
            void Add(const std::string& item) {
                m_members.insert(item);
            }
            
            void Remove(const std::string& item) {
                TContainer::iterator it = m_members.find(item);
                Eegeo_ASSERT(it != m_members.end());
                m_members.erase(it);
            }
            
            void FromFile(const std::string& file)
            {
                std::fstream stream;
                size_t size;
                
                m_members.clear();

                //Check file mode (binary vs text) on windows
                if(m_fileIO.OpenFile(stream, size, file))
                {
                    int sentinelContainer = 0;
                    stream.read((char*)&sentinelContainer, sizeof(unsigned int));
                    
                    if(sentinelContainer != Sentinel)
                    {
                        //file is corrupted - bail
                        stream.close();
                        m_members.clear();
                        return;
                    }
                    
                    unsigned char labelSize = 0;
                    for(size_t index = sizeof(unsigned int); index < size - sizeof(unsigned int);) //room for sentinels
                    {
                        //string label length
                        stream.read((char*)&labelSize, sizeof(unsigned char));
                        
                        //read the buffer into a temp vector
                        std::vector<char> readBuffer(labelSize);
                        stream.read((char*)&readBuffer[0], sizeof(char)*labelSize);
                        
                        //copy the buffer into a string and add to members
                        std::string member;
                        member.assign(&readBuffer[0], labelSize);
                        
                        m_members.insert(member);
        
                        index += (sizeof(char) + (sizeof(char) * labelSize));
                    }
                    
                    sentinelContainer = 0;
                    stream.read((char*)&sentinelContainer, sizeof(unsigned int));
                    
                    if(sentinelContainer != Sentinel)
                    {
                        //file is corrupted - bail
                        stream.close();
                        m_members.clear();
                        return;
                    }
                    
                    stream.close();
                }
            }
            
            void ToFile(std::string file)
            {
                size_t size = 0;
                
                size += 4; //start sentinel bytes
                
                //calculate the size
                for(TContainer::const_iterator member = m_members.begin(); member != m_members.end(); ++ member)
                {
                    Eegeo_ASSERT(member->size() <= std::numeric_limits<unsigned char>::max()); //url should be <= 256 chars
                    size += sizeof(char); //url length
                    size += sizeof(char) * member->size(); //url chars
                }
                
                size += 4; //end sentinel bytes
                
                //make a buffer of correct size and copy data into it
                std::vector<Byte> buffer;
                buffer.resize(size);
                int writeHead = 0;
                
                *(unsigned int*)(&buffer[writeHead]) = Sentinel;
                writeHead += 4;
                
                for(TContainer::const_iterator member = m_members.begin(); member != m_members.end(); ++ member)
                {
                    unsigned char stringLength = (unsigned char)member->size();
                    
                    buffer[writeHead] = stringLength;
                    writeHead += sizeof(unsigned char);
                    
                    memcpy(&buffer[writeHead], member->c_str(), stringLength);
                    writeHead += sizeof(char) * stringLength;
                }
                
                *(unsigned int*)(&buffer[writeHead]) = Sentinel;
                writeHead += 4;
                
                Eegeo_ASSERT(writeHead == size);
                
                if(!m_fileIO.WriteFile(&buffer[0], size, file))
                {
                    Eegeo_ASSERT(false, "CACHE MANIFEST UPDATE FAILED");
                }
            }
        };
    }
}
