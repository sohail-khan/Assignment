set(headers ${headers} sqlite/sqlite3
)
set(currsources
  sqlite/sqlite3/eegeoext.c
  sqlite/sqlite3/eegeoext.h
  sqlite/sqlite3/fts4rank.c
  sqlite/sqlite3/geodistance.c
  sqlite/sqlite3/spellfix.c
  sqlite/sqlite3/sqlite3.c
  sqlite/sqlite3/sqlite3.h
  sqlite/sqlite3/sqlite3ext.h
)
set(sources ${sources} ${currsources})
source_group(\\sqlite3 FILES ${currsources})
