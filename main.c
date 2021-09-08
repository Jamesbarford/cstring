#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"

void concatTest();
void headerTest(char *path, char *token);

typedef char *dstr;

int main(void) {
    cstring *cstr = cstringEmpty();
    cstr = cstringConcat(cstr, "hello, world");

    int match_end = cstringEndsWith(cstr, "ello, world");
    printf("ends with: %d\n", match_end);


    int match_start = cstringStartsWith(cstr, "hxxx");
    printf("starts with: %d\n", match_start);
    printf("%s\n", cstr->buf);
    cstringReplaceFirstInstance(cstr, "world", "universe");
    cstringToUpperCase(cstr);
    printf("len: %u, str: %s\n", cstr->len, cstr->buf);
    cstringToLowerCase(cstr);
    printf("len: %u, str: %s\n", cstr->len, cstr->buf);

    cstring *cstrCSV = cstringFromChars("foo,bar,baz");
    cstring **cstrArr = cstringSplit(cstrCSV, ',');
    cstring **ptr = cstrArr;
    while (*ptr != NULL) {
        printf("%s\n", (*ptr)->buf);
        ptr++;
    }
    cstringReleaseArray(cstrArr);
    cstringRelease(cstr);

    cstr = cstringFromChars("hello, world");
    printf("From chars-> len: %d, buf: %s, original-len: %ld\n", cstr->len,
           cstr->buf, strlen("hello, world"));
    headerTest("/api", "2312e133k1l1l2;312e111112312qasagdsa");
    printf("size: %ld\n", sizeof(unsigned long) + cstr->len);

    // concatTest();
}

void headerTest(char *path, char *token) {
    cstring *headers = cstringEmpty();

    cstringConcat(headers, "GET /api/v2%s HTTP/1.1\r\n");
    cstringReplaceFirstInstance(headers, "%s", path);
    cstringConcat(headers, "Circle-Token: %s\r\n");
    cstringReplaceFirstInstance(headers, "%s", token);
    cstringConcat(headers, "Host: circleci.com:443\r\n");
    cstringConcat(headers, "User-Agent: circlesh/1.0\r\n");
    cstringConcat(headers, "Content-Type: application-json\r\n\r\n");
    printf("%s", headers->buf);
    printf("%d\n", headers->len);
}

void concatTest() {
    cstring *cstr = cstringEmpty();
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "zzzz");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hzzo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hsadlo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "heasdo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hellzzzzzzzo");
    cstr = cstringConcat(cstr, "h");
    cstr = cstringConcat(cstr, "eo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hd   ello");
    cstr = cstringConcat(cstr, "h lo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "he  ppllo");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "helloasdasd");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "helloasdasd");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "helloasdasdasd");
    cstr = cstringConcat(cstr, "h");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");
    cstr = cstringConcat(cstr, "hello");

    printf("%s\n", cstr->buf);
    printf("%d\n", cstr->len);
    cstringRelease(cstr);
}
