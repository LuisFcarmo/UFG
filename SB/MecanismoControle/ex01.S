.section .rodata


.data
   # int a = 30;
   .globl a
   .align 4
   a: .int 30
   # int b = 45;
   .globl b
   .align 4
   b: .int 45
   # int c = -60;
   .globl c
   .align 4
   c: .int -60
   # int d = 25;
   .globl d
   .align 4
   d: .int 25



.text

.globl ex01

ex01:

   pushq %rbp

   movq  %rsp, %rbp
   # _if (a > b) =>  _if !(a > b) => _if(a <= b) <= temos que traduzir isso
   movl a, %eax
   cmpl b, %eax
   jle end_if_01_label
   # c = -c;
   movl c, %eax
   negl %eax
   movl %eax, c
   # d = c / 3;
   movl c, %eax
   cltd
   movl $3, %ecx
   idivl %ecx	
   movl %eax, d

   end_if_01_label:

   # _if !(b >= a) => _if (b > a) _if (a < b) 
   movl b, %edx
   cmpl a, %edx
   jl end_if_02_label
   
   movl a, %eax
   addl b, %eax
   imull c, %eax
   movl $1024, d

   end_if_02_label:

   leave
   ret