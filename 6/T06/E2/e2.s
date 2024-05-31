.globl list_equal
list_equal:
    movl 4(%esp), %edx
    movl 8(%esp), %ecx
L:
    testl %edx, %edx
    setz %al
    testl %ecx, %ecx
    setz %ah
    orb %ah, %al
    testb %al, %al #if
    jne F
    movw (%ecx), %ax
    testw %ax, (%edx)
    xorl %eax, %eax #riannullo eax 
    jne R
    movl 4(%edx), %edx
    movl 4(%ecx), %ecx
    jmp L

F:
    testl %edx, %edx
    setz %al
    testl %ecx, %ecx
    setz %ah
    andb %ah, %al
    movsbl %al, %eax
R:
    ret


