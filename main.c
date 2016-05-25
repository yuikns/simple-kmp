#include <stdio.h>
#include <string.h>
#include "kmp.h"

int main() {
    char strings[] = "aaaaaaabbabbccdeggefegggabbaaaadfbdcdfasdfasdfasdaadaaaaaabbaaaaaaaaabbba";
    char key[] = "abba";
    int index = 0;
    int ai = 0;  // all index = 0;
    int again = 1;
    do {
        index = kmp(strings + ai, key);
        printf("[found] offset: %d:\n [%s] \n-> [%s]  \n-> [%s]\n\n", index, strings, strings + index + ai,
               strings + index + strlen(key) + ai);
        ai += index;
        ai += strlen(key);
    } while (index != -1);
    //}while(again--);
    return 0;
}
