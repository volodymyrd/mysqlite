// Entry point.
//
#include <stdio.h>
#include "sqlite3.h"

/*
** State information about the database connection is contained in an
** instance of the following structure.
*/
typedef struct ShellState ShellState;
struct ShellState {
    sqlite3 *db;           /* The database */
    int openFlags;         /* Additional flags to open.  (SQLITE_OPEN_NOFOLLOW) */
    struct AuxDb {         /* Storage space for auxiliary database connections */
      sqlite3 *db;               /* Connection pointer */
      const char *zDbFilename;   /* Filename used to open the connection */
    } aAuxDb[5],           /* Array of all database connections */
      *pAuxDb;             /* Currently active database connection */
};

void initShellState(ShellState *pState, const char *zDbFilename) {
    pState->db = NULL;             /* Initialize the main database pointer */
    pState->openFlags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
    pState->pAuxDb = &pState->aAuxDb[0]; /* Use the first AuxDb as the active one */
    pState->pAuxDb->db = NULL;     /* Initialize auxiliary database pointer */
    pState->pAuxDb->zDbFilename = zDbFilename; /* Set auxiliary database filename */
}

int main(int argc, const char * argv[]) {
    ShellState state;
    
    initShellState(&state, "my_sqllite.db");
    
    const char *zDbFilename = state.pAuxDb->zDbFilename;
    
    int rc = sqlite3_open_v2(zDbFilename, &state.db, state.openFlags, 0);
    
    if(rc == 0) {
        printf("Database opened successfully!");
    }
    
    return 0;
}
