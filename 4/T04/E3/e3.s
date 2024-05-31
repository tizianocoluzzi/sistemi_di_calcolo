.globl my_strcmp
my_strcmp:
    movl 4(%esp), %edx
    movl 8(%esp), %ecx
L:
    movb (%edx), %al
    testb %al, %al
    je R
    cmpb %al, (%ecx)
    jne R
    incl %edx
    incl %ecx
    jmp L
R:
    movb (%edx), %al
    subb (%ecx), %al
    
    ret
