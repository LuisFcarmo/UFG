.section .rodata


.data
    # short v1[4] = {32, 34, 27, 4};
    .globl v1
    .align 2
    v1: .short 32, 34, 27, 4

    # int   v2[5] = {12, 22, 31, 23, 6};
    .globl v2
    .align 4
    v2: .int 12, 22, 31, 23, 6

    # char  v3[4] = {0, 0, 0, 0};
    .globl v3
    .align 1

    v3: .byte 0, 0, 0, 0

    # long  v4[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    .globl v4
    .align 8
    v4: .quad 0, 0, 0, 0, 0, 0, 0, 0

    # int  i = 0;
    .globl i
    .align 4
    i: .int 0

    # short j = 0;
    .globl j
    .align 2
    j: .short 0


.text

.globl aux
aux:

    pushq %rbp
    movq  %rsp, %rbp

    movl $0, i

    # for (i = 0; i < 4; i++) => (i >= 4)
    begin_for:
        cmpl $4, i
        jge end_for
        #  j = 0;
        movw $0, j
        # while (j < 5) => (j >= 5)
        begin_while:
            cmpw $5, j
            jge end_while
            # _if (i == j) => (i!=j)
            movswl j, %edx
            cmpl %edx, i
            jne begin_else
                # v3[i] = v1[i] + v2[j];
                # v1[i]= (int) v1[i]
                movq $v1, %r8
                movslq i, %r9
                imulq $2, %r9
                addq %r8, %r9
                movswl (%r9), %edi # (int) v1[i]

                # v2[j]
                movq $v2, %r10
                movswq j, %r11
                imulq $4, %r11
                addq %r10, %r11
                movl (%r11), %esi # v2[j]

                # v3[i]
                movq $v3, %r10
                movslq i, %r11
                imulq $4, %r11
                addq %r10, %r11

                addl %eax, %ecx
                movb %al, (%r11)
                jmp end_if

            begin_else:
            # v4[i + j] += v1[i] + v2[j];
            # (int) v1[i] 
                movq $v1, %r8
                movslq i, %r9
                imulq $2, %r9
                addq %r8, %r9
                movswl  (%r9), %edx
            # v2[j]
                movq $v2, %r8
                movswq j, %r9
                imulq $4, %r9
                addq %r8, %r9
                movl (%r9), %esi

            # v4[i + j]
                movswl j, %r10d
                addl i, %r10d
                movq $v4, %r9
                movslq %r10d, %r11
                imulq $8, %r11
                addq %r9, %r11

	            addl	%esi, %edi				# edi = (int)v1[i] + v2[j]
                movslq %edi, %rdi
                addq (%r11), %rdi
                mov %rdi, (%r11)


            end_if:
            incw j

            jmp begin_while
        
        end_while:
        incl i

        jmp begin_for
    end_for:

        


    leave
    ret