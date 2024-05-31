.globl is_suffix
is_suffix:
    pushl %ebx
    movl 8(%esp), %edx
    movl 12(%esp), %ecx
L1:
    movb (%edx), %al
    testb %al, %al
    je E1
    addl $1, %edx
    jmp L1
E1:
    addl $1,  %edx
L2:
    movb (%ecx), %al
    testb %al, %al
    je E2
    addl $1, %ecx
    jmp L2
E2:
    addl $1, %ecx
L3:
    subl $1, %edx
    subl $1, %ecx
    cmpl 8(%esp), %edx
    je E3
    cmpl 12(%esp), %ecx
    je E3
    movb (%edx), %al
    cmpb (%ecx), %al
    jne E3
    jmp L3
E3:
    cmpl 8(%esp), %edx
    seteb %al
    movsbl %al, %eax
    movb (%edx), %bl
    cmpb (%ecx), %bl
    je R
    xorl %eax, %eax
R:
    popl %ebx
    ret
