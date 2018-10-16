#include "util.h"

inline uint32_t get_big_endian32(uint32_t little_endian)
{
    uint8_t *bytes = &little_endian;
    uint32_t big_endian = ((bytes[0] & 0xff) << 24) | ((bytes[1] & 0xff) << 16) | 
        ((bytes[2] & 0xff) << 8) | (bytes[3] & 0xff);
    return big_endian;
}

inline uint16_t get_big_endian16(uint16_t little_endian)
{
    uint8_t *bytes = &little_endian;
    uint16_t big_endian = (((bytes[0] & 0xff) << 8) | (bytes[1] & 0xff));
    return big_endian;
}

inline uint16_t read_uint16_big(FILE *file)
{
    uint16_t uint16;
    fread(&uint16, 2, 1, file);
    return get_big_endian16(uint16);
}

inline uint32_t read_uint32_big(FILE *file)
{
    uint32_t uint32;
    fread(&uint32, 4, 1, file);
    return get_big_endian32(uint32);
}

inline uint32_t read_uint32_big2(FILE *file)
{
    uint8_t uint32[4];
    fread(uint32, 1, 4, file);
    uint32_t big_endian = ((uint32[0] & 0xff) << 24) | ((uint32[1] & 0xff) << 16) | 
        ((uint32[2] & 0xff) << 8) | (uint32[3] & 0xff);
    return big_endian;
}