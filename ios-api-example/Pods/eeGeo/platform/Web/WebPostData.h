#pragma once

#include "Types.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Web
    {
        namespace PostDataType
        {
            enum Values
            {
                Nothing = 0,
                Text,
                Buffer
            };
        }
        
        class WebPostData
        {
        public:
            WebPostData();
            
            static WebPostData CreateTextData(const std::string& textContent);
            static WebPostData CreateBufferData(const std::string& fileName, const std::vector<Byte>& bufferContents);

            PostDataType::Values GetPostDataType() const;
            const std::string& GetTextContent() const;

            const Byte* GetBufferPointer() const;
            const long GetBufferLength() const;

			const char* GetRawData() const;
			int GetRawDataSize() const;

        private:

            WebPostData(const PostDataType::Values postDataType,
                        const std::string& textContent);

            WebPostData(const PostDataType::Values postDataType,
                        const std::string& textContent,
                        const std::vector<Byte>& bufferContent);
            
            PostDataType::Values m_postDataType;
            std::string m_textContent;
            std::vector<Byte> m_bufferContent;
        };
    }
}