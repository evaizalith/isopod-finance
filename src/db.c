#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "term.h"

void printDbError(const char* err, const char* func, const char* file) {
    printf(TERM_COLOR_RED "SQL Error in %s(), %s:\n\t %s \n" TERM_COLOR_RESET, func, file, err);
}

static int callback(void *data, int argc, char **argv, char **azColName) {
    printf("[%s] %s for %s; with %s; %s. %s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);

    return 0;
}

int initDb(database_t *database) {
    char* sql = "CREATE TABLE IF NOT EXISTS Transactions(" \
                 "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
                 "amount REAL NOT NULL," \
                 "type TEXT NOT NULL," \
                 "partner TEXT NOT NULL," \
                 "date TEXT NOT NULL," \
                 "notes TEXT);";

    char *err;
    int ret = sqlite3_exec(database->db, sql, NULL, NULL, &err);

    if (ret != SQLITE_OK) {
        printDbError(err, __func__, __FILE__);
        return 1;
    }

    return 0;
}

int connectDb(database_t *database) {
    int ret = sqlite3_open(database->name, &database->db);

    if (ret) {
        printf(TERM_COLOR_RED "Error: Unable to open database %s\n" TERM_COLOR_RESET, database->name);
        return 1;
    } else {
        return 0;
    }
}

int addTransaction(database_t* database, transaction_t trans) {
    char sql[2048];
    snprintf(sql, 2048, "INSERT INTO Transactions(amount, type, partner, date, notes) VALUES(%f, '%s', '%s', '%s', '%s');", trans.amount, trans.type, trans.partner, trans.date, trans.notes);

    char *err;
    int ret = sqlite3_exec(database->db, sql, NULL, NULL, &err);

    if (ret != SQLITE_OK) {
        printDbError(err, __func__, __FILE__);
        return 1;
    }

    char* sql2 = "SELECT * FROM Transactions";
    ret = sqlite3_exec(database->db, sql2, callback, 0, &err);
    if (ret != SQLITE_OK) {
        printDbError(err, __func__, __FILE__);
        return 1;
    }

    return 0;
}

union transactionResult_t removeTransaction(database_t* db, transaction_t trans) {
    char buf[12];
    snprintf(buf, 12, "%d", trans.id);
    char* sql1 = "SELECT * FROM Transactions WHERE id = ";
    char* sql2 = "DELETE * FROM Transactions WHERE id = ";
    strcat(sql1, buf);
    strcat(sql2, buf);

    union transactionResult_t result;

    return result;
}

union transactionResult_t* retrieveTransactions(database_t* db, char* type, char* partner, int timeRange) {
   union transactionResult_t* result;

   return result;
}
