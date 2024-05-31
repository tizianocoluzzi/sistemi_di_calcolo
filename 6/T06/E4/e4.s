.globl lcm
lcm:
movl 8(%esp), %ecx
cmpl %eax, 4(%esp)
cmovgl 4(%esp), %ecx
L:
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl 4(%esp)
    testl %edx, %edx
    jne E
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl 8(%esp)
    testl %edx, %edx
    jne E
    jmp R
E:
    incl %ecx
    jmp L
R:
    movl %ecx, %eax
    ret

