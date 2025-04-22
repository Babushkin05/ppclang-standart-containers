#ifndef __string__
#define __string__

typedef struct String {
    char value[256];
} String;

unsigned int HashString(String *str);

_Bool StringEqual(String *left, String *right);

#endif