.section .data
    a: .long 0
    b: .long 0
    c: .long 0
    minV: .long 127
    maxV: .long -128

.globl _start
_start:
    movl $10, %esi
while:
    movl $3, %eax
    movl $b, %ecx
    movl $1, %edx
    int $0x80
    cmp $10, b
    je cont
    cmp $32, b
    je cont

    movl a, %eax
    mull %esi
    movl %eax, a
    movl $1, %edx
    sub $48, b
    movl b, %ecx
    add %ecx, a
jmp while
cont:
    xor %edi, %edi
    movl $0, b
    movl $0, c
    while2:
        movl $3, %eax
        xor %ebx, %ebx
        movl $b, %ecx
        movl $1, %edx
        int $0x80
        cmp $10, b
        je cont2
        cmp $32, b
        je cont2
        cmp $45, b
        jne skip
            movl $1, %edi
            jmp while2
        skip:
        movl c, %eax
        mull %esi
        movl %eax, c
        sub $48, b
        movl b, %ecx
        add %ecx, c
    jmp while2
    cont2:

    cmp $1, %edi
    jne skip2
        movl c, %eax
        movl $2, %edi
        mull %edi
        sub %eax, c
    skip2:
    movl c, %eax
    cmp minV, %eax
    jge skipMin
        movl %eax, minV
    skipMin:
    cmp maxV, %eax
    jle skipMax
        movl %eax, maxV
    skipMax:
    sub $1, a
    cmp $0, a
jnz cont
    cmp $0, minV
    jge skip3
        movl $45, a
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80  
        movl minV, %eax
        movl $-1, %esi
        imull %esi
        movl %eax, minV      
    skip3:
    movl $0, b
    movl minV, %edi
    jmp func
    return:

    movl $32, a
    movl $4, %eax
    movl $1, %ebx
    movl $a, %ecx
    movl $1, %edx
    int $0x80

    cmp $0, maxV
    jge skip4
        movl $45, a
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80  
        movl maxV, %eax
        movl $-1, %esi
        imull %esi
        movl %eax, maxV      
    skip4:
    movl $1, b
    movl maxV, %edi
    jmp func

    func:
    cmp $100, %edi
    jl next1
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
    cmp $10, %edi
    jl next2
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
    cmp $1, b
    jne return

_exit:
mov $1, %eax
xor %ebx, %ebx
int $0x80
