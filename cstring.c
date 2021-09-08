/* cstring -- A string library
 *
 * Version 1.0 September 2021
 *
 * Copyright (c) 2021, James Barford-Evans
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"

cstring *cstringCreate(unsigned int size) {
    cstring *cstr = NULL;

    if ((cstr = (cstring *)malloc(sizeof(cstring))) == NULL)
        return NULL;

    if ((cstr->buf = (char *)malloc(size * sizeof(char))) == NULL) {
        free(cstr);
        return NULL;
    }

    cstr->buf[size] = '\0';
    cstr->len = 0;

    return cstr;
}

cstring *cstringEmpty() {
    return cstringCreate(1);
}

static int cstringRealloc(cstring **cstr, unsigned int additional) {
    char *newPtr = NULL;
    unsigned int newsize = (*cstr)->len + additional;

    if ((newPtr = (char *)realloc((*cstr)->buf, newsize + 1)) == NULL)
        return -1;

    (*cstr)->buf = newPtr;

    return 1;
}

cstring *cstringConcat(cstring *cstr, char *str2) {
    cstring *newcstr = cstr;
    unsigned int len = strlen(str2);

    if (cstringRealloc(&cstr, len) == -1)
        return cstr; // handle error somehow

    strcat(newcstr->buf, str2);
    cstr->len = len + cstr->len;
    newcstr->buf[cstr->len + 1] = '\0';
    return cstr;
}

cstring *cstringFromChars(char *str) {
    cstring *cstr = cstringEmpty();
    return cstringConcat(cstr, str);
}

void cstringRelease(cstring *cstr) {
    cstr->len = 0;
    free(cstr->buf);
    free(cstr);
}

/**
 *
 * Case sensative string matching
 * hello
 * llo
 * -> 1
 * 1 on match, 0 on no match
 */
int cstringEndsWith(cstring *cstr, char *pattern) {
    char *ptr = &(cstr->buf[cstr->len - 1]);
    char *pattern_ptr = &(pattern[strlen(pattern) - 1]);

    while (*ptr != '\0' && *pattern_ptr != '\0') {
        if (*ptr != *pattern_ptr)
            return 0;
        // We have got to the beginning of our string and there was no match
        if (ptr == cstr->buf)
            return 0;
        ptr--;
        pattern_ptr--;
    }

    return 1;
}

int cstringStartsWith(cstring *cstr, char *pattern) {
    char *ptr = cstr->buf;
    char *pattern_ptr = pattern;

    while (*ptr != '\0' && *pattern_ptr != '\0') {
        if (*ptr != *pattern_ptr)
            return 0;
        ptr++;
        pattern_ptr++;
    }

    // if we got to the end of our string
    // and not the pattern, this is not a match
    if (*ptr == '\0' && *pattern_ptr != '\0')
        return 0;

    return 1;
}

cstring *cstringDup(cstring *cstr) {
    // create string big enough to contain our string
    cstring *duped = cstringCreate(cstr->len);
    memcpy(duped->buf, cstr->buf, cstr->len * sizeof(char *));

    duped->len = cstr->len;

    return duped;
}

void cstringRemoveChars(cstring *cstr, char *sequence) {
    char tmp[cstr->len];
    char *ptr = cstr->buf;
    unsigned int pos = 0;
    unsigned int seqlen = strlen(sequence);

    while (*ptr != '\0') {
        for (unsigned int i = 0; i < seqlen; ++i) {
            if (*ptr != sequence[i]) {
                tmp[pos++] = *ptr;
            }
        }
        ptr++;
    }

    tmp[pos + 1] = '\0';
    cstr->len = pos;
    memcpy(cstr->buf, tmp, cstr->len * sizeof(char *));
}

void cstringToLowerCase(cstring *cstr) {
    char *ptr = cstr->buf;
    while (*ptr != '\0') {
        if (*ptr >= 65 && *ptr <= 90) {
            *ptr = *ptr + 32;
        }
        ptr++;
    }
}

void cstringToUpperCase(cstring *cstr) {
    char *ptr = cstr->buf;
    while (*ptr != '\0') {
        if (*ptr >= 97 && *ptr <= 122) {
            *ptr = *ptr - 32;
        }
        ptr++;
    }
}

int _stringExactMatch(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

/* Avoid using this function, prefer cstringComp instead */
int cstringExactMatch(cstring *cstr, char *str) {
    return _stringExactMatch(cstr->buf, str);
}

int cstringIndexOfMatch(cstring *cstr, char *str) {
    char *ptr1 = cstr->buf;

    while (*ptr1 != '\0') {
        if ((*ptr1 == *str) && _stringExactMatch(ptr1, str)) {
            return (ptr1 - cstr->buf);
        };
        ptr1++;
    }

    return -1;
}

void _makeSpace(cstring *cstr, unsigned int idx, unsigned int seqlen,
        unsigned int replen)
{
    char *start;
    char tmp[cstr->len];
    unsigned int end_idx;

    if (idx > cstr->len)
        return;

    // check there is enough room
    if (cstringRealloc(&cstr, replen) == -1)
        return;

    // find index of where to create space
    start = &(cstr->buf[idx]);
    end_idx = idx + seqlen;

    // store the end of the string in a temporary buffer
    memcpy(tmp, &(cstr->buf[end_idx]), (cstr->len - end_idx) + 1);

    // add ' ' spaces to that position and NULL out the rest of the string
    for (unsigned int i = 0; i < replen; ++i) {
        *start = ' ';
        start++;
    }
    *start = '\0';

    // glue back temporary buffer
    strcat(&(cstr->buf[idx + replen]), tmp);
}

void cstringReplaceFirstInstance(cstring *cstr, char *sequence,
        char *replacement)
{
    int idx = cstringIndexOfMatch(cstr, sequence);
    unsigned int replen;
    unsigned int seqlen;

    if (idx == -1)
        return;

    replen = strlen(replacement);
    seqlen = strlen(sequence);

    if (replen > seqlen) {
        _makeSpace(cstr, idx, seqlen, replen);
    }

    for (unsigned int i = 0; i < replen; ++i) {
        cstr->buf[i + idx] = replacement[i];
    }

    cstr->len = (cstr->len - seqlen) + replen;
    cstr->buf[cstr->len] = '\0';
}

/* compare length first for speed */
int cstringComp(cstring *s1, cstring *s2) {
    return s1->len == s2->len && (memcmp(s1->buf, s2->buf, s2->len) == 0);
}

/* returns a null terminated array */
cstring **cstringSplit(cstring *cstr, char delimiter) {
    cstring **cstrArr = malloc(1);

    char *ptr = cstr->buf;
    int count = 0;
    int i = 0;
    char temp[BUFSIZ];

    while (*ptr != '\0') {
        if (*ptr == delimiter) {
            temp[i] = '\0';

            cstrArr = (cstring **)realloc(cstrArr, sizeof(cstring) *
                    (count + 1));
            cstrArr[count] = cstringEmpty();
            cstrArr[count]->buf = strdup(temp);
            cstrArr[count]->len = i;

            i = 0;
            count++;
            ptr++;
            memset(temp, 0, BUFSIZ);
            continue;
        }

        temp[i++] = *ptr;
        ptr++;
    }

    cstrArr = (cstring **)realloc(cstrArr, sizeof(cstring) * (count + 2));
    cstrArr[count] = cstringEmpty();
    cstrArr[count]->buf = strdup(temp);
    cstrArr[count]->len = i;
    count++;
    cstrArr[count] = NULL;

    return cstrArr;
}

void cstringReleaseArray(cstring **cstrArr) {
    int i = 0;
    cstring **ptr = cstrArr;

    while (*ptr != NULL) {
        ptr++;
        cstringRelease(cstrArr[i]);
        i++;
    }
    free(cstrArr);
}
