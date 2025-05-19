.section .rodata

.data
    .globl vet
    .align 4
    vet: .int 10,20,10,40,20

.globl calc

process:


calc:
    pushq %rbp
    movq  %rsp, %rbp
    # int *resp = rdi 1 parametro, int mark = esi 2 parametro
    # int i = 0 => %ebx
    movl $0, %ebx
    begin_while: # (while i < 5) => ( i >= 5)
        cmpl $5, %ebx
        jge end_while
        # vet[i]    
        movq $vet, %r9
        movslq %ebx, %r10
        imulq $4, %r10
        addq %r9, %r10
        movl (%r10), %ecx
        # vet[i] == mark => vet[i] != mark
        cmp %esi, %ecx
        jne begin_else
            movq $vet, %r9
            movslq %ebx, %r10
            imulq $4, %r10
            addq %r9, %r10 # (&vet[i]
            movq %r10, %rdi
            call process
            
            movl %eax, (%rdi) # *resp = process(&vet[i]
        jmp end_if
        begin_else:
            movl (%rdi), %esi
        end_if:

        incl %ebx

        jmp begin_while
    end_while:


    leave
    ret