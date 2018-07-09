.section .data
    n: .long 0
    tmp: .long 0
    a: .long 0
    set: .long 0
    prev: .long 0
    minV: .long 100001
    maxV: .long -100001

.globl _start
_start:
    movl $10, %esi
while:
    movl $3, %eax
    movl $tmp, %ecx
    movl $1, %edx
    int $0x80
    cmp $10, tmp
    je while2
    cmp $32, tmp
    je while2

    movl n, %eax
    mull %esi
    movl %eax, n
    sub $48, tmp
    movl tmp, %ecx
    add %ecx, n
jmp while


while2:
    xor %edi, %edi
    movl $0, tmp
    movl $0, a
    while3:
        movl $3, %eax
        xor %ebx, %ebx
        movl $tmp, %ecx
        movl $1, %edx
        int $0x80
        cmp $10, tmp
        je cont2
        cmp $32, tmp
        je cont2
        cmp $45, tmp
        jne skip
            movl $1, %edi
            jmp while3
        skip:
        movl a, %eax
        mull %esi
        movl %eax, a
        sub $48, tmp
        movl tmp, %ecx
        add %ecx, a
    jmp while3
    cont2:

    cmp $1, %edi
    jne skip2
        movl a, %eax
        neg %eax
        movl %eax, a
    skip2:

    movl a, %eax
    xor prev, %eax
    movl a, %ebx
    movl %ebx, prev
    cmp minV, %eax
    jge skipMin
        movl %eax, minV
    skipMin:

    cmp maxV, %eax
    jle skipMax
        movl %eax, maxV
    skipMax:

    sub $1, n
    cmp $0, n
jnz while2

    movl maxV, %edi
    sub minV, %edi

    cmp $1000, %edi
    jl next0
        movl $1, set
        movl %edi, %eax
        xor %edx, %edx
        movl $1000, %ecx
        divl %ecx
        movl %eax, a
        add $48, a
        movl $1000, %esi
        mull %esi
        sub %eax, %edi
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
        cmp $100, %edi
        jge next0
            movl $48, a
            movl $4, %eax
            movl $1, %ebx
            movl $a, %ecx
            movl $1, %edx
            int $0x80
        jmp next1 
    next0:
    movl set, %eax
    cmp $1, %eax
    je do1
    cmp $100, %edi
    jl next1
        do1:
        movl $1, set
        movl %edi, %eax
        xor %edx, %edx
        movl $100, %ecx
        divl %ecx
        movl %eax, a
        add $48, a
        movl $100, %esi
        mull %esi
        sub %eax, %edi
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
        cmp $10, %edi
        jge next1
            movl $48, a
            movl $4, %eax
            movl $1, %ebx
            movl $a, %ecx
            movl $1, %edx
            int $0x80
        jmp next2
    next1:
    movl set, %eax
    cmp $1, %eax
    je do2
    cmp $10, %edi
    jl next2
        do2:
        movl %edi, %eax
        xor %edx, %edx
        movl $10, %ecx
        divl %ecx
        movl %eax, a
        add $48, a
        movl $10, %esi
        mull %esi
        sub %eax, %edi
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
    next2:
        movl %edi, %eax
        movl %eax, a
        add $48, a
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
        cmp $0, %edi
    next3:


_exit:
mov $1, %eax
xor %ebx, %ebx
int $0x80
