.globl list_add_first
list_add_first:
    pushl %ebx
    pushl %ebp
    subl $4, %esp
    movl 16(%esp), %ebp
    movl (%ebp), %ebp
    movl $8, (%esp)
    call malloc
    movl %eax, %ebx
    movl $-1, %eax
    testl %ebx, %ebx
    je R
    #lo prendo dopo in modo che la malloc non modifichi edx
    movw 20(%esp), %dx #elem
    #uso eax come appoggio perche movs non puo usare la memoria
    movswl %dx, %eax
    movl %eax, (%ebx)
    movl %ebp, 4(%ebx)
    movl 16(%esp), %eax
    movl %ebx, (%eax)
    xorl %eax, %eax 

R:
    addl $4, %esp
    popl %ebp
    popl %ebx
ret
