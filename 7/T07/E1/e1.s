.globl binsearch
binsearch:
    pushl %ebx
    pushl %edi
    xorl %edx, %edx
    movl 16(%esp), %ecx
    movl 12(%esp), %edi
    movl 20(%esp), %ebx
L:  xorl %eax, %eax
    cmpl %ecx, %edx 
    jge R
    addl %edx, %eax
    addl %ecx, %eax
    sarl $1, %eax
    cmpl (%edi, %eax, 4), %ebx
    jne N
    movl $1, %eax
    jmp R
N:  cmpl %ebx, (%edi, %eax, 4)
    jle E
    movl %eax, %ecx
    jmp L
E:  incl %eax
    movl %eax, %edx
    jmp L
R:  popl %edi
    popl %ebx
    ret
