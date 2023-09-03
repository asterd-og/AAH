# AAH
Astrido's Amazing Heap
## Usage
- Initialisation
```c
  hpCreate();
```
- Allocation
```c
  char* ptr = hpAlloc(12);
  strcpy(ptr, "Hello World!");
```
- Deallocation (Free)
```c
  hpFree(ptr);
```
## How it works
  The heap uses a fixed size array defined by the compilation argument (-DHEAP_SIZE=n in bytes), then, inside of that array it allocates and deallocates. The allocation works by first checking if the size is greater than the limit of the heap, if it is, it will look inside another array for places that have been freed already, after that, it simply defines the header in that memory address and returns the pointer to the address that you can use. Deallocation works by reading and comparing the header from the pointer, and if it passes the checks, it will set that memory region to null once again.
