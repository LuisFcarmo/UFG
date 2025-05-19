.data
    .globl last
    .align 8
    last: .quad 0

    .globl values
    .align 8
    values: .quad 50, -10, 60, -20, 70

.text

.globl swap
swap:
    pushq %rbp
    movq %rsp, %rbp
    # int i;
    # int j = 4;
    movl $4, %edx
    # i -> ecx
    movl $0, %ecx

    begin_for:
    #    for (i = 0; i < j; i++, j--)

        cmpl %edx, %ecx
        jge end_for
        # long tmp = values[i];
        movq $values, %rdi # &values => rdi
        movslq %ecx, %rsi  # i =: rsi
        imulq $8, %rsi  # i *= 8 
        addq %rdi, %rsi 
        movq (%rsi), %r8 

        movq $values, %r9 # &values => r9
        movslq %edx, %r10 # j => r10
        imulq $8, %r10  
        addq %r9, %r10
        movq (%r10), %r11 # r11 -> values[j]

        movq $values, %rdi
        movslq %ecx, %rsi
        imulq $8, %rsi
        addq %rdi, %rsi 
        
        movq %r11, (%rsi) # values[i] = values[j]

        movq $values, %r9 # &values => r9
        movslq %edx, %r10
        imulq $8, %r10
        addq %r9, %r10

        movq %r8, (%r10)
        incl %ecx
        decl %edx

        jmp begin_for
    end_for:
    
    movq $values, %rdi
    movq 32(%rdi), %rax
    movq %rax, last

    leave
    ret