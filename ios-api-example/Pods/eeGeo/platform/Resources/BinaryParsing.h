// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"
#include <streambuf>
#include <istream>

namespace Eegeo 
{
    namespace Resources
    {
        namespace BinaryParsing
        {
            class membuf : public std::basic_streambuf<char>, protected Eegeo::NonCopyable
            {
            public:
                membuf(char* p, size_t n) {
                    setg(p, p, p + n);
                }
                
                char* getCurrent() const
                {
                    return gptr();
                }
    
            protected:
                virtual pos_type seekoff( off_type off, std::ios_base::seekdir dir,
                             std::ios_base::openmode which = std::ios_base::in | std::ios_base::out )
                {
                    //Eegeo_ASSERT(which == std::ios_base::in);


                    if (dir == std::ios::cur)
                    {
                        setg(eback(), gptr() + off, egptr());
                    }
                    else if (dir == std::ios::beg)
                    {
                        setg(eback(), eback() + off, egptr());
                    }
                    else if (dir == std::ios::end)
                    {
                        setg(eback(), egptr() - off, egptr());
                    }

                    if (gptr() < eback())
                        return -1;
                    if (gptr() > egptr())
                        return -1;
                    return gptr() - eback();
                }
    
                virtual pos_type seekpos( pos_type off,
                                         std::ios_base::openmode which = std::ios_base::in | std::ios_base::out )
                {
                    return seekoff(off, std::ios::beg, which);
                };

            };

            template <class T>
            T Parse(std::istream& reader, size_t *parseSize)
            {     
                T result; 
                reader.read((char*)&result, sizeof(T));
                
                *parseSize += sizeof(T);
                
                return result;
            }
            
            template <class T>
            T Parse(std::istream& reader)
            {
                T result;
                reader.read((char*)&result, sizeof(T));
                return result;
            }

            template <class T, size_t N>
            void Parse(std::istream& reader, T (&result)[N])
            {
                reader.read((char*)&result, sizeof(T) * N);
            }

            // todo - does v3 need w comp (for alignment)?
            template <>
            inline Eegeo::v3 Parse<Eegeo::v3>(std::istream& reader)
            {
                Eegeo::v3 result;
                reader.read((char*)&result, sizeof(float)*3);
                return result;
            }
            
            template <class T>
            void ParseShortString(std::istream& reader, std::string& outputString)
            {
            	size_t length = Parse<T>(reader);

                outputString.resize(length);
                reader.read((char*)&outputString[0], length * sizeof(char));
            }

            std::string ParseFourCC(std::istream& reader);

            u32 Read7BitEncodedInt(std::istream& reader);
        }
    }
}
