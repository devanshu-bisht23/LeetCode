#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return ""; // Handle empty array case

    char* prefix = strs[0];  // Start with the first string as prefix
    int length = strlen(prefix);  // Get its length 6

    for (int i = 0; i < length; i++) {
        char comp = prefix[i];  // Character to compare in each string

        for (int j = 1; j < strsSize; j++) {  // Start from the second string
            if (strs[j][i] != comp || strs[j][i] == '\0') {
                prefix[i] = '\0';  // we set the 2nd index of the first prefix "flower" null so it return fl
                return prefix;
            }
        }
    }

    return prefix;
}