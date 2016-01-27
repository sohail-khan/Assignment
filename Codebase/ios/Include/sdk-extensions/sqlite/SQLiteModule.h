// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Modules.h"
#include "Web.h"
#include "AlertBox.h"
#include "EegeoRootDeclarations.h"
#include "SQLite.h"
#include "Helpers.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        struct SQLiteModuleConfig
        {
            std::string DbDownloadFailedDialogCaption;
            std::string DbDownloadFailedDialogMessage;
            
            static SQLiteModuleConfig CreateDefault();
        };
    
        class SQLiteModule : protected Eegeo::NonCopyable
        {
        public:
            static SQLiteModule* Create(const SQLiteModuleConfig& config,
                                        Eegeo::Modules::IPlatformAbstractionModule& platformAbstractionModule,
                                        Eegeo::UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory);
            
            SQLiteModule(Eegeo::SQLite::SQLiteDbWebLoader* pSQLiteDbWebLoader,
                         Eegeo::SQLite::SQLiteDbDownloadFailedHandler* pSQLiteDbDownloadFailedHandler,
                         Eegeo::SQLite::SQLiteTextSearchableTableFactory* pSQLiteTextSearchableTableFactory,
                         Eegeo::SQLite::SQLiteSpellfixTableFactory* pSQLiteSpellfixTableFactory,
                         Eegeo::SQLite::SQLiteFtsComponentFactory* pSQLiteFtsComponentFactory,
                         Eegeo::SQLite::SQLiteFtsQueryTokenizer* pSQLiteFtsQueryTokenizer);
            
            virtual ~SQLiteModule();
            
            Eegeo::SQLite::SQLiteDbWebLoader& GetSQLiteDbWebLoader() const { return *m_pSQLiteDbWebLoader; }
            
            Eegeo::SQLite::SQLiteTextSearchableTableFactory& GetSQLiteTextSearchableTableFactory() const { return *m_pSQLiteTextSearchableTableFactory; }
            
            Eegeo::SQLite::SQLiteSpellfixTableFactory& GetSQLiteSpellfixTableFactory() const { return *m_pSQLiteSpellfixTableFactory; }
            
            Eegeo::SQLite::SQLiteFtsComponentFactory& GetSQLiteFtsComponentFactory() const { return *m_pSQLiteFtsComponentFactory; }
            
            Eegeo::SQLite::SQLiteFtsQueryTokenizer& GetSQLiteFtsQueryTokenizer() const { return *m_pSQLiteFtsQueryTokenizer; }
            
        private:
            Eegeo::SQLite::SQLiteDbWebLoader* m_pSQLiteDbWebLoader;
            Eegeo::SQLite::SQLiteDbDownloadFailedHandler* m_pSQLiteDbDownloadFailedHandler;
            Eegeo::SQLite::SQLiteTextSearchableTableFactory* m_pSQLiteTextSearchableTableFactory;
            Eegeo::SQLite::SQLiteSpellfixTableFactory* m_pSQLiteSpellfixTableFactory;
            Eegeo::SQLite::SQLiteFtsComponentFactory* m_pSQLiteFtsComponentFactory;
            Eegeo::SQLite::SQLiteFtsQueryTokenizer* m_pSQLiteFtsQueryTokenizer;
        };
    }
}