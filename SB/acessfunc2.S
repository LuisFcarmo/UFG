.section .rodata

.data
    .globl i
    .align 4
    i: .int 0

    .globl v
    .align 2
    v: .short 0

    .globl vetA
    .align 2
    vetA: .short 28,42,16,23,47
    
    .globl vetB
    .align 4
    vetB: .int 0,0,0,0,0

.globl main
main:
    # int i = %ecx
    begin_while:
        cmp $5, %ecx
        jge end_while

        movq $vetA, %r8
        movslq %ecx, %r9
        imulq $2, %r9
        addq %r8, %r9
        movw (%r9), %r10w

        shlw $2, %r10w  	# r10w = r10w << 2
        movw %r10w, v

        movl %edi
        movw %si
        
        movq $vetB, %r8
        movslq %ecx, %r9
        imulq $4, %r9
        addq %r8, %r9
        movl %r9, %rdx

        call process
        incl %ecx
        jmp begin_while
    end_while:
    movl $0, %eax
    leave ret