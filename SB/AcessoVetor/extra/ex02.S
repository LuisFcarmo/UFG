.data
    .globl letters
    .align 1
    letters: .string "abcdefghij"

    .globl even
    .align 4
    even: .int 0

    .globl odd
    .align 4
    odd: .int 0


.text

.globl ex02
ex02:
    #  unsigned int count = 0;
    pushq	%rbp
	movq	%rsp, %rbp
    
    movl $0, %eax

    begin_while:
        # letters[count]
        movq $letters, %r8
        movl %eax, %r9d
        imulq $1, %r9
        addq %r8, %r9
        movb (%r9), %dl # dl = letters[count]
        
        cmpb $0, %dl 
        je end_while

        # letters[count++]
        movl %eax, %r9d
        incl %eax

        movq $letters, %r8
        imulq $1, %r9
        addq %r8, %r9
        movb (%r9), %dl
        # letters[count++] & 1
        andb $1, %dl
        cmpb $0, %dl
        je elseif01
            # odd++
            incl odd
            # se entrar aqui tem que pular o else
            jmp end_if01

        elseif01:
            incl even

        end_if01:

        jmp begin_while    

    end_while:

    leave
    ret