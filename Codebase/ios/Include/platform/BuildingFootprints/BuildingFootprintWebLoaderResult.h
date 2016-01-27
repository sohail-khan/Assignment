// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "BuildingFootprints.h"

namespace Eegeo
{
    namespace BuildingFootprints
    {
        struct BuildingFootprintWebLoaderResult
        {
            BuildingFootprintWebLoaderResult()
            : m_success(false)
            , m_notFound(false)
            , m_pResource(NULL)
            {}
            
            BuildingFootprintWebLoaderResult(bool success, bool notFound, const BuildingFootprintResource* pResource)
            : m_success(success)
            , m_notFound(notFound)
            , m_pResource(pResource)
            {
            }
            
            bool IsSuccess() const { return m_success; }
            bool IsNotFound() const { return m_notFound; }
            const BuildingFootprintResource* GetResource() const { return m_pResource; }
            
        private:
            bool m_success;
            bool m_notFound;
            const BuildingFootprintResource* m_pResource;
        };
    }
}