.section .rodata
fmt: .string "i = %d, sum = %d\n"

.data
    .globl max
    .align 4
    max: .int 256

    .globl lim
    .align 2
    lim: .short -3

    .globl timer
    .align 1
    timer: .byte 100

    .globl vet1
    .align 8
    vet1: .quad 1,0,2,3,4

    .globl vet2
    .align 4
    vet2: .int 0,0,0,0,0


.globl modify
# modify(int *v1, long *v2, char value)
modify:
    # v1 = %rdi
    # v2 = %rsi
    # value = %dl
    # long index => $r9
    begin_while:
        # calc(v2, v1)
        movq %rdi, %r8
        movq %rsi, %rdi
        movq %r8, %rsi
        call calc
        cmp %al, %dl
        jle end_while
            # _if
            movl max, %edi
            movw lim, %si
            movq rdi, %rdx
            call complex


        jmp begin_while
    end_while:
    # v1[ v2[index] ] = (int)value;


# basic(int sum) 
.globl basic
basic:
    # int sum = %edi
    # int i = %ecx
    pushq %rbp
    movq  %rsp, %rbp
    # long *ptr = vet1
    movq $vet1, %r10
    
    begin_while:    
        # sum < timer => sum >= timer
        movsbl timer, %r9d
        cmp %r9d, %edi
        jge end_while

        # _if (sum == 13) => (sum != 13)
        cmp 13$, %edi
        je end_while
        # i = 0
        movl $0, %ecx
 
        begin_for:
 
            cmp 10$, %ecx
            jge end_for
            movq $fmt, %rdi
            movq %ecx, %esi
            movq %edi, %edx
            movl $0, %eax
            call printf
            
            incl %ecx
            incl %edi
            jmp begin_for
 
        end_for:
        

        movq $vet2, %rdi
        movq %r10, %rsi
        movq timer, %cl
        call modify

        addq $8, %r10
        jmp begin_while
    end_while:


    leave 
    ret