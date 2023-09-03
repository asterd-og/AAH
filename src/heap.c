#include <string.h>
#include "heap.h"

char heap[HEAP_SIZE];
int heapFree[HEAP_SIZE - (HEAP_SIZE / sizeof(Chunk))] = {0};
int freed = 0;
int heapPos = 0;
int heapSz = HEAP_SIZE - sizeof(Chunk);

int hpCreate() {
	for (int i = 0; i < HEAP_SIZE; i++)
		heap[i] = 0;
	return 0;
}

void* hpAlloc(size_t size) {
	if (size > heapSz)
		return NULL;
	Chunk* chk;
	if (heapPos >= HEAP_SIZE) {
		if (freed == 0)
			return NULL;
		bool found = false;
		for (int i = 0; i < freed; i++) {
			if (((Chunk*)&heap[heapFree[i]])->size >= size) {
				chk = (Chunk*)&heap[heapFree[i]];
				heapFree[i] = 0;
				freed--;
				found = true;
				break;
			}
		}
		if (!found) return NULL;
	} else {
		chk = (Chunk*)&heap[heapPos];
	}
	chk->magic = HEAP_MAGIC; chk->size = size; chk->hPos = heapPos;
	void* addr = &heap[heapPos + sizeof(Chunk)];
	heapPos += sizeof(Chunk) + size;
	heapSz -= sizeof(Chunk) + size;
	return addr;
}

int hpFree(void* ptr) {
	Chunk* chk = (Chunk*)(ptr - sizeof(Chunk));
	if (chk->magic != HEAP_MAGIC) return 1;
	heapFree[freed] = chk->hPos;
	freed++;
	memset(ptr, 0, chk->size);
	memset(chk, 0, sizeof(Chunk));
	return 0;
}

Chunk* hpGetChk(void* ptr) {
	return (Chunk*)((int)ptr - sizeof(Chunk));
}