windows:
	gcc -DHEAP_SIZE=2097152 src/main.c src/heap.c -o out/main.exe
	out\main.exe

linux:
	gcc -DHEAP_SIZE=2097152 src/main.c src/heap.c -o out/main
	./out/main