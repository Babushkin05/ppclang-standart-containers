#include "ppstring.h"

unsigned int HashString(String *str) {
    unsigned int hash = 5381;
    char *p = str->value;
    
    while (*p != '\0') {
        hash = ((hash << 5) + hash) + *p; 
        p++;
    }
    
    return hash;
}

_Bool StringEqual(String *left, String *right) {
    char *l = left->value;
    char *r = right->value;
    
    while (*l != '\0' && *r != '\0') {
        if (*l != *r) {
            return 0; 
        }
        l++;
        r++;
    }
    
    return (*l == '\0' && *r == '\0');
}