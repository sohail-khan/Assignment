// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

extern "C"
{
    struct sqlite3_api_routines;
    struct sqlite3;
    
    int sqlite3_eegeoext_init(sqlite3 *db, char **pzErrMsg, const sqlite3_api_routines *pApi);
}
