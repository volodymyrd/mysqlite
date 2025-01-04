/*
** This header file defines the interface that the SQLite library
** presents to client programs.
*/
#ifndef SQLITE3_H
#define SQLITE3_H
#include <stdarg.h>     /* Needed for the definition of va_list */

/*
** Flags For File Open Operations.
**
*/
#define SQLITE_OPEN_READONLY         0x00000001  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_READWRITE        0x00000002  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_CREATE           0x00000004  /* Ok for sqlite3_open_v2() */

/*
** Database Connection Handle.
*/
typedef struct sqlite3 sqlite3;

/*
** CAPI3REF: Opening A New Database Connection.
** CONSTRUCTOR: sqlite3
*/
int sqlite3_open_v2(
  const char *filename,   /* Database filename (UTF-8) */
  sqlite3 **ppDb,         /* OUT: SQLite db handle */
  int flags,              /* Flags */
  const char *zVfs        /* Name of VFS module to use */
);

#endif /* SQLITE3_H */
