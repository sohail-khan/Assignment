// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

namespace Eegeo
{ 
    namespace Web
    {
        struct ImageUploadData
        {
            enum ImageType
            {
                JPEG,
                PNG
            };

            ImageUploadData()
            : path("")
            , filename("")
            , type(JPEG)
            {}

            ImageUploadData(const std::string& path,
                            const std::string& filename,
                            const ImageType& type)
            : path(path)
            , filename(filename)
            , type(type)
            {
                
            }
            
            std::string path;
            std::string filename;
            ImageType type;
        };
    }
}
