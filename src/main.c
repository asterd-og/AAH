#include <stdio.h>
#include <string.h>
#include "heap.h"

typedef struct {
	int id;
	int age;
} Person;

int main() {
	hpCreate();
	
	Person* p1 = hpAlloc(sizeof(Person));
	Person* p2 = hpAlloc(sizeof(Person));
	
	p1->id = 1;
	p1->age = 13;
	
	p2->id = 2;
	p2->age = 26;
	
	Chunk* p1c = hpGetChk(p1);
	Chunk* p2c = hpGetChk(p2);
	
	printf("mP1: 0x%x\tsP1: %d\tpP1: %d\n",
		p1c->magic, p1c->size, p1c->hPos);
	
	printf("mP2: 0x%x\tsP2: %d\tpP2: %d\n",
		p2c->magic, p2c->size, p2c->hPos);
	
	printf("-------------------------\n");
	
	printf("P1:\n\tID: %d\n\tAge: %d\n\nP2:\n\tID: %d\n\tAge: %d\n",
		   p1->id, p1->age, p2->id, p2->age);

	if (hpFree(p1)) printf("Something went wrong freeing p1\n");
	
	printf("-------------------------\n");
	
	printf("P1:\n\tID: %d\n\tAge: %d\n\nP2:\n\tID: %d\n\tAge: %d\n",
		   p1->id, p1->age, p2->id, p2->age);
	
	if (hpFree(p2)) printf("Something went wrong freeing p2\n");
	
	printf("-------------------------\n");
	
	printf("P1:\n\tID: %d\n\tAge: %d\n\nP2:\n\tID: %d\n\tAge: %d\n",
		   p1->id, p1->age, p2->id, p2->age);
	
	
	return 0;
}