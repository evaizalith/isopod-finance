// isopod-finance
// --------------
// args.h
// Declarations for functions and structs pertaining to arguments passed to the program 
// --------------

#ifndef ISPDF_ARGS
#define ISPDF_ARGS

typedef struct {
    int interactiveShell; // 0 if non-shell, 1 if shell
    int addTransaction; // 0 if null, 1 if add 
    int removeTransaction; //0 if null, 1 if remove
    int timespan; // 0 if all, 1 if last week, 2 if last month, 3 if last year
    int byType; // 0 if null, 1 if print transactions by type
    int setTotal; // 0 if null, 1 if user wants to set total amount in account
    
    int transAmount;
    char* transType;
    char* transPartner;
    char* transDate;
    char* transNotes;

    int transID;
} arguments_t;

int parseArgs(arguments_t* args, int argc, char* argv[]); 
void printHelp(int argc, char* argv[]);

#endif
