// isopod-finance
// --------------
// main.c
// --------------

#include <stdio.h>
#include "term.h"
#include "db.h"
#include "config.h"
#include "args.h"

int main(int argc, char* argv[]) {
    arguments_t args;
    int res = parseArgs(args, argc, argv);
    if (res != 0) {
        return res;
    }
}
