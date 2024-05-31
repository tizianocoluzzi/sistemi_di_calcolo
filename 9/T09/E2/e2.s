.globl crc32b
crc32b:
    pushl %ebx
    pushl %edi
    pushl %ebp
    subl $12, %esp

    movl 28(%esp), %ebx
    movl 32(%esp), %edi
    movl $-1, %ebp
L:
    testl %edi, %edi
    jle R
    decl %edi
    movl %ecx, 8(%esp)
    movb (%ebx), %dl
    movsbl %dl, %edx
    addl $1, %ebx
    movl %ebp, %eax
    xorl %edx, %eax
    andl $255, %eax
    movl %eax, 4(%esp)
    leal 8(%esp), %eax
    movl %eax, (%esp)
    call get_constant
    movl %ebp, %eax
    sarl $8, %eax
    movl 8(%esp), %ebp
    xorl %eax, %ebp
    jmp L


R:
    movl %ebp, %eax
    xorl $-1, %eax
    
    addl $12, %esp
    popl %ebp
    popl %edi
    popl %ebx
    ret


