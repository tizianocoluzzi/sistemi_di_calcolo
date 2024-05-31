.globl find
find:
    movl 4(%esp), %eax;
    movl 12(%esp), %ecx;
    xorl %edx, %edx
L:
    cmpl %edx, 8(%esp)
    jle T
    cmpl (%eax, %edx, 4), %ecx
    jne F
    movl $1, %eax
    jmp R
F:
    incl %edx
    jmp L
T: 
    xorl %eax, %eax

R:
    ret
