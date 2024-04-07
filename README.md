# exec-raw-bin
A system that executes raw-binary written in C

## How it works
1. This platform will map a memory region with execution permissions using [mmap](https://man7.org/linux/man-pages/man2/mmap.2.html)
2. Load a raw binary instructions data into the mapped memory region
3. Cast the pointer to that memory region into a function pointer
4. And then, pass the execution control to that function pointer with disired parameters

It is important to notice that the raw binary instructions to be loaded must follow the [x86 calling convention](https://en.m.wikipedia.org/wiki/X86_calling_conventions)

## This Implementation
The current implementation is a fibonacci sequence calculator, that given n as parameter will return the nth fibonacci term in the sequence.

The assembly code in [fib.s](fib.s) is platform specific and will only work under:
`Linux localhost 4.19.157-perf-27940246-abA235FXXU4DXA3 #1 SMP PREEMPT Thu Jan 18 13:59:45 +07 2024 aarch64 Android
`.
So you own will have to come with you platform `raw instructions data`. Although, the C program is platform agnostic.
