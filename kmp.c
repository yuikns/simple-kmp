#include "kmp.h"
#include <string.h>

void next_point(const char *pat, int next[]) {
    int times = 0;
    int j = 0, k = -1;
    next[0] = -1;

    while (j < (int)strlen(pat)) {
        times++;

        if (k == -1 || pat[j] == pat[k]) {
            j++;
            k++;
            next[j] = pat[k] == pat[j] ? next[k] : k;  // rewrite last line
        } else
            k = next[k];
    }
}

extern int nkmp(const char src[], const char key[], int len_of_src, int len_of_key) {
    int next[len_of_key];
    int index;
    int iter;
    int pos;
    next_point(key, next);

    for (index = 0; index < len_of_src; index++) {
        pos = 0;
        iter = index;

        while (pos < len_of_key && iter < len_of_src) {
            if (src[iter] == key[pos]) {
                iter++;
                pos++;
            } else {
                if (pos == 0)
                    iter++;
                else
                    pos = next[pos - 1] + 1;
            }
        }

        if (pos == len_of_key && (iter - index) == len_of_key) return index;

    }  // for end

    return -1;
}

extern int kmp(const char *src, const char *key) {
    int len_of_src = strlen(src);
    int len_of_key = strlen(key);
    return nkmp(src, key, len_of_src, len_of_key);
}