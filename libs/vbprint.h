#ifndef __VBPRINT_H__
#define __VBPRINT_H__

#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>

#define MAX_STR_LEN 1024

// String width.
typedef enum {
    NARROW, WIDE
} StringWidth;

// Struct holding the last message recorded.
typedef struct {
    StringWidth width;

    union {
        char __message[MAX_STR_LEN];
        wchar_t __wessage[MAX_STR_LEN];
    } __msg;
} MessageMeta;

extern MessageMeta Message;

void vbprintf(FILE *stream, const char *format, ...);

void vbwprintf(FILE *stream, const wchar_t *format, ...);

bool get_verbose_print_status(void);

void set_verbose_print_status(const bool status);

#endif  // __VBPRINT_H__
