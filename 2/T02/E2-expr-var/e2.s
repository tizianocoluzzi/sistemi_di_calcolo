# scrivere la soluzione qui...
.globl f
f:
movl $2, %eax
imull 4(%esp), %eax
imull 4(%esp), %eax
movl $7, %ecx
imull 4(%esp), %ecx
subl %ecx, %eax
incl %eax
ret
