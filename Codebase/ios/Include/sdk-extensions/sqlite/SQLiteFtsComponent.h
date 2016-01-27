// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include "SQLiteFtsSnippetFormattingConfig.h"
#include "SQLiteFtsTokenizerType.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteFtsComponent : public Eegeo::NonCopyable
        {
        public:
            SQLiteFtsComponent(const SQLiteTextSearchableTable* pTextSearchableTable,
                               const SQLiteSpellfixTable* pSpellfixTable,
                               const SQLiteFtsQuerySpellingFixer* pSpellFixer);
            
            ~SQLiteFtsComponent();
            
            const SQLiteTextSearchableTable& GetTextSearchableTable() const { return *m_pTextSearchableTable; }
            
            const SQLiteFtsQuerySpellingFixer& GetFtsQuerySpellFixer() const { return *m_pSpellFixer; }
            
        private:
            const SQLiteTextSearchableTable* m_pTextSearchableTable;
            const SQLiteSpellfixTable* m_pSpellfixTable;
            const SQLiteFtsQuerySpellingFixer* m_pSpellFixer;
        };
    }
}