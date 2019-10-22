.section .data
    a: .quad 0
    b: .quad 0
    n: .quad 0
    m: .quad 0
    p: .quad 0
    re: .quad 1
    set: .quad 0

.globl _start
_start:
    movq $10, %r13
    movq $readn, %r15
    movq $0, a
    jmp parse_int
readn:
    movq a, %rax
    movq %rax, n
    movq $readp, %r15
    movq $0, a
    jmp parse_int
readp:
    movq a, %rax
    movq %rax, p
    movq $readm, %r15
    movq $0, a
    jmp parse_int
readm:
    movq a, %rax
    movq %rax, m

pow:
    movq p, %rax
    and $1, %rax
    cmp $0, %rax
    jz skip1
        xor %rdx, %rdx
        movq n, %rax
        movq re, %r12
        mul %r12
        mov m, %r12
        idiv %r12
        movq %rdx, re
    skip1:
    xor %rdx, %rdx
    movq n, %rax
    movq n, %r12
    mul %r12
    mov m, %r12
    div %r12
    movq %rdx, n
    shrl $1, p
    cmp $0, p
jnz pow
    movq re, %rax
    movq %rax, a
    movq $_exit, %r15
    jmp print_int
_exit:
    mov $60, %rax
    xor %rdi, %rdi
    syscall

print_int:
    movq $0, set
    movq $1000000000, %r12
    print:
        cmp $1, set
        je forceprint
        cmp %r12, a
        jl skip2
        movq $1, set
        forceprint:
            movq a, %rax
            xor %rdx, %rdx
            div %r12
            xor %rdx, %rdx
            div %r13
            movq %rdx, b
            add $48, b
            movq $1, %rax
            movq $1, %rdi
            movq $b, %rsi
            movq $1, %rdx
            syscall
        skip2:
        xor %rdx, %rdx
        movq %r12, %rax
        movq $10, %r13
        div %r13
        movq %rax, %r12
        cmp $0, %r12
    jne print
    cmp $1, set
    je skip
        movq $48, a
        movq $1, %rax
        movq $1, %rdi
        movq $a, %rsi
        movq $1, %rdx
        syscall
    skip:
jmp fin

parse_int:
    movq $0, %rax
    xor %rdi, %rdi
    movq $b, %rsi
    movq $1, %rdx
    syscall
    cmp $10, b
    je fin
    cmp $32, b
    je fin

    movq a, %rax
    mul %r13
    movq %rax, a
    movq $1, %rdx
    sub $48, b
    movq b, %rcx
    add %rcx, a
jmp parse_int

fin:
    jmp *%r15
