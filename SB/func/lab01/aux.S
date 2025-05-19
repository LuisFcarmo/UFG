.section .rodata
str01: .fmt "Valor: x = %ld, i = %d\n"


.data 
    .globl x
    .align 8
    x: .quad 10
.text



.globl aux
aux:
    pushq %rbp
    movq %rsp, %rbp
    


