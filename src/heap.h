#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define HEAP_MAGIC 0xA57B92

#ifndef HEAP_SIZE
#define HEAP_SIZE 64000 //64 KB
#endif

typedef struct {
	uint32_t magic;
	size_t size;
	int hPos;
} Chunk;

int    hpCreate();
void*  hpAlloc(size_t size);
int    hpFree(void* ptr);
Chunk* hpGetChk(void* ptr);