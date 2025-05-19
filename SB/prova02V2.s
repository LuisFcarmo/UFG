.section .rodata    
    fmt: .string "%d, %ld\n"

.data
    .globl values
    .align 4
    value: .int 10, 20, 10, 40, 20, 50, 30, 10


aux:

.globl process
process:
    pushq %rbp
    movq  %rsp, %rbp
    # int i => %ecx
    movl $7, %ecx

    # stamp = %edi
    # limit = %rsi
    # char = %dl               
    # process int stamp, long limit, char base
    begin_for:
        cmp $0, %ecx
        jl end_for
        # values[i]
        movq $values, %r9
        movslq %ecx, %r10
        imulq $4, %r10
        addq %r9, %r10
        movl (%r10), %ebx

        cmp %ebx, %edi
        jle begin_else

        # 2*limit
        movq %rsi, %r11
        imulq $2, %r11

        # aux((short)i, (values + i));
        movslw %ecx, %di # (short)i,

        # (values + i)
        movq $values, %rsi
        movslq %ecx, %r10
        imulq $4, %r10
        addq %rsi, %r10
        call aux
        # limit = (2*limit) + aux((short)i, (values + i));
        addq %rax, %r11
        movq  %r11, %rsi

        jmp end_if
        begin_else:
            # printf("%d, %ld\n", stamp, limit)
            # terceiro paramtro
            movq %rsi, %rdx
            # segundo parametro
            movl %edi, %esi
            # primeiro parametro
            movq $fmt, %rdi
            movl $0, %eax
            call printf

        end_if:

        decl %ecx
        jmp begin_for
    end_for:
    movq %rsi, %rax

    leave
    ret
    
