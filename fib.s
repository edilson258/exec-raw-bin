// x0, x1, x2 used for calc fibbonacci digit
// x3 stores nth digit to stop
// x4 is the counter

.section .text
  .globl main
main:
  mov x3, x0 // set x3 with arg provided by c program
  
  // set 0, 1 as first digits
  mov x0, 0x0
  mov x1, 0x1

  mov x4, 0x0 // set counter to 0

next_digit:
  mov x2, x0 // use x2 as temp reg
  mov x0, x1
  add x1, x1, x2 
  add x4, x4, 0x1

  cmp x4, x3
  B.LT next_digit // branch if counter (x4) still less than nth fib digit (x3)

return:
  mov x0, x1
  ret
