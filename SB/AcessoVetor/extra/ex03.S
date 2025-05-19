.data
# int size = 5;
    .globl size
    .align 4
size: .int 5

# short a[5] = {5, 1, 7, 2, 9};
    .globl a
    .align 2
a: .short 5, 1, 7, 2, 9

# int b[5] = {6, 3, 8, 4, 2};
    .globl b
    .align 4
b: .int 6, 3, 8, 4, 2

# long nums[5] = {0};
    .globl nums
    .align 8
nums: .quad 0, 0, 0, 0, 0

# short factor = 100;
    .globl factor
    .align 2
factor: .short 100

.text
.globl ex03
ex03:
    pushq   %rbp
    movq    %rsp, %rbp

    # int i = 0;
    movl    $0, %eax  # i = 0

    # short *ptr = a;
    movq    $a, %rdx  # ptr = a

    # while (i < size)
begin_while:
    cmp     size, %eax        # Compare i with size
    jge     end_while         # If i >= size, exit the loop

    # a[i]
    movq    $a, %r8          # r8 = address of a
    movslq  %eax, %r9        # r9 = i (long)
    imulq   $2, %r9          # r9 = i * sizeof(short)
    addq    %r8, %r9         # r9 = &a[i]
    movw    (%r9), %di       # di = a[i]

    # _if (a[i] > 6)
    cmp     $6, %di          # Compare a[i] with 6
    jle     begin_else       # If a[i] <= 6, go to else

    # nums[i] = b[0] + factor
    # b[0]
    movq    $b, %r10         # r10 = address of b
    movq    $0, %r11         # r11 = 0
    imulq   $4, %r11         # r11 = 0 * sizeof(int)
    addq    %r10, %r11       # r11 = &b[0]
    movl    (%r11), %ebx     # ebx = b[0]

    # (int)factor
    movswl  factor, %edx     # edx = (int)factor
    addl    %edx, %ebx       # ebx = b[0] + factor

    # nums[i] = (long)(b[0] + factor)
    movq    $nums, %r10      # r10 = address of nums
    movslq  %eax, %r11       # r11 = i (long)
    imulq   $8, %r11         # r11 = i * sizeof(long)
    addq    %r10, %r11       # r11 = &nums[i]
    movslq  %ebx, %r10       # r10 = (long)ebx
    movq    %r10, (%r11)     # nums[i] = (long)(b[0] + factor)

    jmp     end_if           # Jump to the end of if-else block

begin_else:
    # nums[i] = *ptr * b[i]
    # ptr points to a, so *ptr is a[i]
    movq    $a, %r8          # r8 = address of a
    movslq  %eax, %r9        # r9 = i (long)
    imulq   $2, %r9          # r9 = i * sizeof(short)
    addq    %r8, %r9         # r9 = &a[i]
    movw    (%r9), %si       # si = a[i]

    # b[i]
    movq    $b, %r8          # r8 = address of b
    movslq  %eax, %r9        # r9 = i (long)
    imulq   $4, %r9          # r9 = i * sizeof(int)
    addq    %r8, %r9         # r9 = &b[i]
    movl    (%r9), %edi      # edi = b[i]

    # *ptr * b[i]
    movswl  %si, %esi        # esi = (int)a[i]
    imull   %esi, %edi       # edi = a[i] * b[i]

    # nums[i] = (long)(a[i] * b[i])
    movq    $nums, %r8       # r8 = address of nums
    movslq  %eax, %r9        # r9 = i (long)
    imulq   $8, %r9          # r9 = i * sizeof(long)
    addq    %r8, %r9         # r9 = &nums[i]
    movslq  %edi, %rdi       # rdi = (long)edi
    movq    %rdi, (%r9)      # nums[i] = (long)(a[i] * b[i])

end_if:
    # i++
    incl    %eax             # Increment i

    # ptr++ (increment the pointer)
    addq    $2, %rdx         # ptr++ (a pointer to short increments by 2)

    jmp     begin_while      # Go back to the start of the while loop

end_while:
    leave
    ret
