# cstring a simple sring library for c

For simpler management of strings in c.

## Structure

The `cstring` is a simple struct:

```c
typedef struct cstring {
    /* current length of the string */
    unsigned int len;
    /* the string buffer containing the string */
    char *buf;
} cstring;
```

## Example
```c
#include "cstring.h"

int main(void) {
    /* create an empty string */
    cstring *cstr = cstringEmpty();
	cstringConcat(cstr, "hello, world");
    
    printf("len: %d, string: %s\n", cstr->len, cstr->buf);
    /* len: 13, string: hello, world */
}
```

## Full Api
- `cstringCreate(unsigned int size)` create a `cstring` with a known size
- `cstringConcat(cstring *cstr, char *str2)` concatinate str2 on cstr's buf
- `cstringEmpty()` create an empty `cstring` with len initalised to 0 and buf being the size of 1 char.
- `cstringRelease(cstring *cstr)` free a cstring
- `cstringEndsWith(cstring *cstr, char *pattern)` returns 1 if the string ends with the pattern else 0.
- `cstringStartsWith(cstring *cstr, char *pattern)` returns 1 if the string starts with the pattern else 0
- `cstringDup(cstring *cstr)` duplicate the cstring
- `cstringFromChars(char *str)` create a cstring from `char *`
- `cstringComp(cstring *s1, cstring *s2)` returns 1 if s1 matches s2
- `cstringExactMatch(cstring *cstr, char *str)` returns 1 if the cstrings buffer exactly matches `str`
- `cstringIndexOfMatch(cstring *cstr, char *pattern)` returns the index in the string from where the match first occurs
- `cstringRemoveChars(cstring *cstr, char *pattern)` removes the charcters in `pattern`from the cstring.
- `cstringToLowerCase(cstring *cstr)` lowercase the cstring
- `cstringToUpperCase(cstring *cstr)` uppercase the cstring
- `cstringReplaceFirstInstance(cstring *cstr, char *pattern, char *replacement);` replaces the first instance of `pattern` with `replacement`
- `cstringSplit(cstring *cstr, char delimiter)` split a cstring on a delimiter, returns a null terminated array of cstrings
- `cstringReleaseArray(cstring **cstrArr)` frees an array of cstrings
