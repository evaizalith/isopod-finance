// isopod-finance
// --------------
// main.c
// --------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "term.h"
#include "db.h"
#include "config.h"
#include "args.h"

int main(int argc, char* argv[]) {
    arguments_t args;
    int res = parseArgs(&args, argc, argv);
    if (res != 0) {
        return res;
    }

    database_t database;
    char* defaultName = "ispdf_db";
    database.name = malloc(strlen(defaultName));
    strncpy(database.name, defaultName, strlen(defaultName));

    res = connectDb(&database);
    if (res != 0) {
        return res;
    }

    res = initDb(&database);
    if (res != 0) {
        return res;
    }
    
    if (args.addTransaction) {
        transaction_t trans;
        trans.amount = args.transAmount;
        trans.type = args.transType;
        trans.partner = args.transPartner;
        trans.notes = args.transNotes;
        trans.date = args.transDate;

        addTransaction(&database, trans);
    }

    printf("Database '%s' created\n", database.name);
    return 0;
}
