.data
    .globl vet
    .align 2
    vet: .short 50, 10, 67, 42
    
    .globl max
    .align 2
    max: .short 0

.text

.globl ex01
ex01:
	pushq	%rbp
	movq	%rsp, %rbp
    # char i;
    movb $0, %al

    begin_for:
    #   for (i < 4)   => i >= 4
    cmpb $4, %al
    jge end_for

    movq $vet, %r8
    movsbq %al, %r9
    imulq $2, %r9
    addq %r8, %r9 
    movw (%r9), %bx # bl = vet[i]

    # (vet[i] > max) = (vet[i] <= max)
    cmpw max, %bx
    jle end_if
        movw %bx, max


    end_if:
    incb %al 
    
    
    jmp begin_for

    end_for:

    leave
    ret