.section .data
    a: .long 0

.section .text
.globl _start
_start:
    xor %esi, %esi
    xor %ebx, %ebx
    movl $1, %edx

    movl $3, %eax
    movl $a, %ecx
    int $0x80
    movl a, %eax
    sub $48, %eax
    add %eax, %esi
    
    movl $3, %eax
    movl $a, %ecx
    int $0x80
    cmp $48, a
    jne next

    add $9, %esi
    movl $3, %eax
    movl $a, %ecx
    int $0x80   
    
next:
    movl $3, %eax
    movl $a, %ecx
    int $0x80
    movl a, %eax
    sub $48, %eax
    add %eax, %esi
    
    movl $3, %eax
    movl $a, %ecx
    int $0x80
    cmp $48, a
    jne next2
     
    add $9, %esi
    movl $3, %eax
    movl $a, %ecx
    int $0x80   
   
next2:     
    movl $3, %eax
    movl $a, %ecx
    int $0x80
    movl a, %eax
    sub $48, %eax
    add %eax, %esi

    movl $3, %eax
    movl $a, %ecx
    int $0x80
    cmp $48, a
    jne next3
    
    add $9, %esi
    movl $3, %eax
    movl $a, %ecx
    int $0x80   
 
next3:   
    movl %esi, %eax
    movl $0, %edx
    movl $3, %ecx
    divl %ecx
    movl %eax, %esi

    add $48, %esi
    movl $4, %eax
    movl $1, %ebx
    movl %esp, %ecx
    movl %esi, (%ecx)
    movl $1, %edx
    int $0x80

_exit:
mov $1, %eax
xor %ebx, %ebx
int $0x80
