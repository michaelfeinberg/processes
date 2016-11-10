test: process.c
	gcc process.c -o test
run: test
	./test