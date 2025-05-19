.section .rodata
str01: .fmt "%d\n"

.text

show: 
    pushq %rbp
    movq %rsp, %rbp
    

    # i -> ecx
    movl 0, %ecx
    begin_for:
        # i >= size
        cmp %ecx, %esi
        jge end_for

        # v[i]
        movq %rsi, %r8
        movslq %ecx, %r9
        imulq $4, %r9
        addq %r8, %r9
        
        movl (%r9), %esi # primeiro parametro
        movq $fmt, %rdi # segundo parametro
 
        movl %0, %eax
        call printf

        # i++
        incl %ecx

        jmp begin_for
    end_for:
