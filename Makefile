OUT=main fib.bin fib.o

.PHONY: all
all: $(OUT)

main: fib.c
	clang -g -O0 fib.c -o main

fib.bin: fib.o
	objcopy -O binary fib.o fib.bin

fib.o: fib.s
	clang -c fib.s -o fib.o

clean:
	rm $(OUT)
