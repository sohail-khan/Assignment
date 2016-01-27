// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"
#include "WebLoadRequestCompletionCallback.h"
#include "Helpers.h"
#include "SQLiteDbWebLoaderCompletedHandler.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteDbWebLoader : public Eegeo::NonCopyable
        {
        public:
            typedef Eegeo::Helpers::ICallback1<const SQLiteDbWebLoaderResponse&> LoadCompleteCallback;
            
            SQLiteDbWebLoader(Web::IWebLoadRequestFactory& webRequestFactory,
                              SQLiteDbDownloadFailedHandler& downloadFailedHandler,
                              Eegeo::Helpers::IFileIO& fileIO);
            
            void Load(const std::string& url, const std::string& destDbFilename, const LoadCompleteCallback& loadCompleteCallback);

            bool IsLoading() const { return m_pendingLoad; }
        private:
            Web::IWebLoadRequestFactory& m_webRequestFactory;
            SQLiteDbDownloadFailedHandler& m_downloadFailedHandler;
            Eegeo::Helpers::IFileIO& m_fileIO;
            
            bool m_pendingLoad;
            
            void WebLoadRequestComplete(Eegeo::Web::IWebResponse& webLoadRequest);
            
            bool TryWriteDbFile(Eegeo::Web::IWebResponse& webLoadRequest);
            
            Eegeo::Web::TWebLoadRequestCompletionCallback<SQLiteDbWebLoader> m_webLoadRequestCompleteHandler;
        };
    }
}