// Copyright eeGeo Ltd (2012-2015), All Rights Reserved
#pragma once

#include "WorkItem.h"
#include "CityThemes.h"
#include "ICallback.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Resources
    {
        namespace CityThemes
        {
            class CityThemeParseManifestWorkItem : public Eegeo::Concurrency::Tasks::WorkItem
            {
            public:
                CityThemeParseManifestWorkItem(
                        const std::string& cityThemesManifestJson,
                        Eegeo::Resources::CityThemes::CityThemeLoader& cityThemeLoader);

                virtual ~CityThemeParseManifestWorkItem() {}

                virtual void DoWork();
                virtual void DoFinalizeOnMainThread();
            private:
                std::vector<CityThemeData*> m_cityThemeData;
                std::string m_cityThemesManifestJson;
                Eegeo::Resources::CityThemes::CityThemeLoader& m_cityThemeLoader;
            };
        }
    }
}
