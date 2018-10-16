#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stdio.h>

#define MP4_TAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MP4_BETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

typedef enum Boolean
{
    False = 0,
    True,
} Boolean;

uint32_t get_big_endian32(uint32_t little_endian);

uint16_t get_big_endian16(uint16_t little_endian);

uint16_t read_uint16_big(FILE *file);

uint32_t read_uint32_big(FILE *file);

#endif