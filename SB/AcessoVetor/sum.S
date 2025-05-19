.data
    .globl s
    .align 4
    s: .int 0

    .globl nums
    .align 4
    nums: .int 65, -105, 111, 34

.text


.globl sum

sum:

    pushq %rbp

    movq  %rsp, %rbp

    movl $0, %ecx
    #  while (i < 4) => (i >= 4) 
    loop_while:
        cmpl $4, %ecx
        jge end_while
        # pegando o endreço de nums
        movq $nums, %rdx
        movslq %ecx, %r8
        imulq $4, %r8
        addq %rdx, %r8

        movl (%r8), %eax
        addl %eax, s
        addl $1, %ecx

        jmp loop_while
    end_while:

    leave

    ret