.section .rodata
str01: .string "hello"
.data
# int val = 432;
   .globl val
   .align 4
   val: .int 432
# short age = 4;
   .globl age
   .align 2
   age: .short 4
# int r = 0;
   .globl r
   .align 4
   r: .int 0
# long err = 2048;
   .globl err
   .align 8
   err: .quad 2048
.text


.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp

   # val = sum("Hello", val, age, &r)
   movq $str01, %rdi # primeiro argumento
   movl val, %esi # segundo argumento
   movw age, %dx # terceiro argumento
   movq $r, %rcx # quarto argumento

   call sum # chamada da func

   # show(err, val, r);
   movq err, %rdi # primeiro argumento
   movl val, %esi # segundo argumento
   mol r, %edx # terceiro argumento

   call show # chamada da func
   
	# return 0
   movl $0, %eax

   leave

   ret