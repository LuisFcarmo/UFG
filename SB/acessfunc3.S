.section .rodata

.data
    .globl i
    .align 4
    i: .int 0

    .globl bias
    .align 8
    bias: .quad 256

    .globl vet
    .align 1
    vet: .byte 12,3,20,8

.text


.globl
.main
    pushq %rbp
    movq %rsp, %rbp
    
    begin_for:
        cmp $5, i
        jge end_for

        # vet[i]
        movq $vet, %r8
        movslq i, %r9
        imulq $1, %r9
        addq %r8, %r9

        movb (%r9), %dil
        movw $10, %si
        movq bias, %rdx
        call filtro 
        movq %rax, bias

        incl i
        jmp begin_for
    end_for:
    movl $0, %eax
    leave
    ret
