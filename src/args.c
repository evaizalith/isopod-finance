#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "term.h"
#include "args.h"

// Parses command line arguments
// Returns 0 on success, 1 on failure
// Side effects: may write to terminal 
int parseArgs(arguments_t* args, int argc, char* argv[]) {
    if (argc == 1) {
        printf(TERM_COLOR_RED "Error: Not enough arguments!\n" TERM_COLOR_RESET);
        printHelp(argc, argv);
        return 1; 
    }

    args->interactiveShell = 0;
    args->addTransaction = 0;
    args->removeTransaction = 0;
    args->timespan = 0;
    args->byType = 0;
    args->setTotal = 0;
    args->transAmount = 0;
    args->transType = NULL;
    args->transDate = NULL;
    args->transNotes = NULL;
    args->transID = 0;

    int addLoc;
    int remLoc; 

    for (int i = 0; i < argc; i++) {
        if (strncmp(argv[i], "-h", 2) == 0) { printHelp(argc, argv); }
        if (strncmp(argv[i], "-s", 2) == 0) { args->interactiveShell = 1; }
        if (strncmp(argv[i], "-a", 2) == 0) { args->addTransaction = 1; addLoc = i; }
        if (strncmp(argv[i], "-r", 2) == 0) { args->removeTransaction = 1; remLoc = i; }
    }

    if (args->addTransaction == 1) {
        if (argc < 7) {
            printf(TERM_COLOR_RED "Not enough arguments to add transaction\n" TERM_COLOR_RESET);
            printf("Usage: %s -a <amount> <type> <partner> <date> <notes>\n", argv[0]);
            return 1;
        }

        args->transAmount = atoi(argv[addLoc + 1]);

        args->transType = malloc(strlen(argv[addLoc + 2]) + 1);
        strcpy(args->transType, argv[addLoc + 2]);

        args->transDate = malloc(strlen(argv[addLoc + 3]) + 1);
        strcpy(args->transDate, argv[addLoc + 3]);

        args->transNotes = malloc(strlen(argv[addLoc + 4]) + 1);
        strcpy(args->transNotes, argv[addLoc + 4]);
    }

    if (args->removeTransaction == 1) {
        if (argc < 3) {
            printf(TERM_COLOR_RED "Not enough arguments to remove transaction\n" TERM_COLOR_RESET);
            printf("Usage: %s -r <transaction-id>\n", argv[0]);
            return 1;
        }

        args->transID = atoi(argv[remLoc + 1]);
    }

    return 0;
}

// Side effects: writes to terminal
void printHelp(int argc, char* argv[]) {
    printf(TERM_COLOR_CYAN "Isopod Finance Usage:\n" TERM_COLOR_RESET);
    printf(TERM_COLOR_MAGENTA "Valid Arguments:\n" TERM_COLOR_RESET);

    printf(TERM_COLOR_MAGENTA "-h \n" TERM_COLOR_RESET);
    printf("\tDisplay this info\n");

    printf(TERM_COLOR_MAGENTA "-a \n" TERM_COLOR_RESET);
    printf("\tAdd new financial transaction to database. \n");
    printf("\tUsage: %s -a <amount> <type> <partner> <date> <notes>\n", argv[0]);
    printf("\tRemember to place quotation marks around arguments with spaces!\n");

    printf(TERM_COLOR_MAGENTA "-r \n" TERM_COLOR_RESET);
    printf("\tRemove transaction by id \n");
    printf("\tUsage: %s -r <transaction-id>\n", argv[0]);

    printf(TERM_COLOR_MAGENTA "-s \n" TERM_COLOR_RESET);
    printf("\tStart interactive shell \n");
}
