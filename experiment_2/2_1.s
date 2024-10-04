.section .data
buf1: .byte 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 
buf2: .fill 10, 1, 0 
buf3: .fill 10, 1, 0
buf4: .fill 10, 1, 0
str1: .ascii "Press any key to begin!"
str2: .ascii ""
.section .text
.global  _start
_start: 
    mov  $4, %eax
    mov  $1, %ebx
    mov  $str1, %ecx
    mov  $23, %edx
    int  $0x80

    mov  $3, %eax
    mov  $1, %ebx
    mov  $str2, %ecx
    mov  $1, %edx
    int  $0x80

    mov  $buf1, %esi
    mov  $buf2, %edi 
    mov  $buf3, %ebx 
    mov  $buf4, %edx 
    mov  $10, %ecx 

lopa:
    mov  (%esi), %al 
    mov  %al, (%edi) 
    inc  %al
    mov  %al, (%ebx)
    add  $3,  %al 
    mov  %al, (%edx)
    inc  %esi
    inc  %edi
    inc  %ebx
    inc  %edx
    dec  %ecx
jnz  lopa 

mov  $1, %eax
movl $0, %ebx
int  $0x80

