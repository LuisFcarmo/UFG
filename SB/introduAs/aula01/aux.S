.data
    # char c = -20;
    .globl c
    .align 1
    c: .byte -20
    # int i = -256;
    .globl i
    .align 4
    i: .int -256

    # int j = 512;
    .globl  j
    .align 4
    j: .int 512

    # long l = 128;
    .globl l
    .align 8
    l: .quad 128
    
    # unsigned short us = 111;
    .globl us
    .align 2
    us: .short 111

    # unsigned int ui = 1024;
    .globl ui
    .align 4
    ui: .int 1024
  
    # unsigned long ul = 2048;
    .globl ul
    .align 8
    ul: .quad 2048


.text



.globl aux

aux:

    pushq %rbp

    movq  %rsp, %rbp


    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    # Atribuições simples

    # j = 68000;
    movl $68000, j

    # l = 4096;
    movq $4096, l
    
    # i = j;
    movl j, %eax
    movl %eax, i

    # Expressões
    # j = 10 + i - 5;
    movl i, %ecx
    addl $10,%ecx 
    subl $5,%ecx 
    movl %ecx, j

    # i = (i * 2) - (j + 5);
    movl i, %edx 
    movl j, %edi 
    imull $2, %edx 
    addl $5, %edi 
    subl %edi, %edx 
    movl %edx, i 

    # Casts
    # ui = i;
    movl i, %esi
    movl %esi, ui
    
    #  j = c;
    movsbl c, %eax
    movl %eax, j

    # ul = ui;
    movl ui, %edx
    movq %rdx, ul

    # us = ul;
    movl ul, %eax
    movw %ax, us

	# c = i + j (trucamento)
    movl i, %ecx
    addl j, %ecx
    movb %cl, c
    
    # Ponteiros

	# long *ptr
	# ptr -> r10
	# ptr = &l
    movq $l, %r10
    movq $128, (%r10)

    movq $i, %r11
    movl j, %eax
    addl (%r11), %eax
    movl %eax, j

    leave

    ret