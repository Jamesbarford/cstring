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
#ifndef __CSTRING_H__
#define __CSTRING_H__

typedef struct cstring {
    unsigned int len;
    char *buf;
} cstring;

cstring *cstringCreate(unsigned int size);
cstring *cstringConcat(cstring *cstr, char *str2);
cstring *cstringEmpty();
void cstringRelease(cstring *cstr);
int cstringEndsWith(cstring *cstr, char *pattern);
int cstringStartsWith(cstring *cstr, char *pattern);

cstring *cstringDup(cstring *cstr);
cstring *cstringFromChars(char *str);
int cstringComp(cstring *s1, cstring *s2);

int cstringExactMatch(cstring *cstr, char *str);
int cstringIndexOfMatch(cstring *cstr, char *pattern);

void cstringRemoveChars(cstring *cstr, char *pattern);
void cstringToLowerCase(cstring *cstr);
void cstringToUpperCase(cstring *cstr);
void cstringReplaceFirstInstance(cstring *cstr, char *pattern,
                                 char *replacement);

cstring **cstringSplit(cstring *cstr, char delimiter);
void cstringReleaseArray(cstring **cstrArr);

#endif
