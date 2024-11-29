#ifndef INC_MEM_H
#define INC_MEM_H
#include <common.h>
void mem_cpy(const void* restrict src, void* restrict dst, uint32_t nbytes);
void mem_set(void* dst, uint8_t value, uint32_t size);
bool mem_cmp(const void* restrict left, const void* restrict right, uint32_t size);
uint32_t read32_from_le_bytes(const uint8_t* bytes);
uint32_t str_len(const uint8_t* bytes);
#endif // !INC_MEM_H
