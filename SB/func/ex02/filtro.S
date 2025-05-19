.section .rodata
str01: .string "hello"

.data
    .globl val
    .align 4
    val: .int 432

    .globl age
    .align 2
    age: .short 4

    .globl r
    .align 4
    r: .int 0

    .globl err
    .align 8
    err: .quad 2048
.text

.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp


  

   leave

   ret