// isopod-finance
// --------------
// db.h
// Declarations for functions and structs that manage the database
// -------------

#ifndef ISPDF_DB
#define ISPDF_DB

#include <sqlite3.h>

typedef struct {
    sqlite3 *db;
    char* name;
} database_t;

typedef struct {
    int id;
    float amount;
    char* type;
    char* partner;
    char* date;
    char* notes;
} transaction_t;

union transactionResult_t {
    transaction_t transaction;
    int error;
};

// Returns 0 on success, 1 on failure
// Side effects: creates tables for db
int initDb(database_t*);

// Returns 0 on success, 1 on failure
// Side effects: connects db 
int connectDb(database_t*);

// Returns 0 on success, 1 on failure
// Side effects: pushes entry to table
int addTransaction(database_t*, transaction_t);

// Returns { transaction, 0 } on success, { NULL, 1 } on failure 
// Side effects: removes transaction from table
union transactionResult_t removeTransaction(database_t*, transaction_t);

// Returns { transaction, 0 }[] on success, { NULL, 1 } on failure
// When type = NULL, selects from any type
// When partner = NULL, selects from any partner
// When timeRange = *:
//      0 - any time range
//      1 - last week 
//      2 - last month
//      3 - last year
union transactionResult_t* retrieveTransactions(database_t*, char* type, char* partner, int timeRange);

// Side effects: prints to screen
void printTransaction(transaction_t);

#endif
