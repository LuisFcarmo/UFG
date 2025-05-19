.section .rodata
fmt01: .string "'a' maior do que 'b'\n"
fmt02: .string "valor de 'b': %d\n"
.data
    .globl a
    .align 1
    a: .byte 97

    .globl b
    .align 1
    b: .byte 105



.globl max
max:


.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    # ret => %ecx
    movb a, %dil
    movb b, %sil
    call max
    movl %eax, %ecx
    movsbl a, %edx
    cmp %edx, %ecx
    jne begin_else

    jmp end_inf
    movq $fmt01, %rdi
    movl $0, %eax
    call printf

    begin_else:
    movq $fmt02, %rdi
    movl $0, %eax
    call printf
    end_inf:
    movl $0, %eax
    leave 
    ret