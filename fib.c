#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void usage(void) {
  printf("Usage:\n"
         "\t./fib [fib.bin] [nth]\n\n"
         "fib.bin: raw-binary code that calulates fibbonacci sequences\n"
         "nth: the nth term of the sequence to be printed\n");
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "[ERROR] Missing mandatory arguments\n");
    usage();
    return -1;
  }

  int binfd = open(argv[1], O_RDWR);
  assert(binfd >= 0 && "[ERROR]: Coudn't open file");

  struct stat binfilestat;
  fstat(binfd, &binfilestat);

  void *code =
      mmap(NULL, binfilestat.st_size, PROT_EXEC | PROT_WRITE | PROT_READ,
           MAP_PRIVATE | MAP_ANON, -1, 0);

  assert(code != MAP_FAILED && "[ERROR]: Coudn't map memory");

  read(binfd, code, binfilestat.st_size);

  int nth = atoi(argv[2]); // doesn't consider 0, 1 first digist
  unsigned long res = ((int (*)(int))code)(nth);

  printf("The %dth fibbonacci digit is %zu\n", nth, res);
  return 0;
}
