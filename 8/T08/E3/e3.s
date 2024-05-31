.globl count_digits
count_digits:
    movl 4(%esp), %edx
    xorl %eax, %eax
L:  movb (%edx), %cl
    testb %cl, %cl
    je R
    cmpb $48, (%edx)
    setge %ch
    movsbl %ch, %ecx
    cmpl  $1, %ecx
    jne E
    cmpb $57, (%edx)
    setle %ch
    movsbl %ch, %ecx
    addl %ecx, %eax
E:
    addl $1, %edx
    jmp L;
R:
    ret
