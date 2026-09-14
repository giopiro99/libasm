[BITS 64]
global  ft_strlen
default rel

section .text
ft_strlen:
    push    rbp
    mov     rbp, rsp
    ; inizializzo rax a 0 che conterra' il valore di ritorno
    mov     rax, 0

.loop_str:
    cmp     byte [rdi], 0x00
    je      .loop_str_done
    inc     rdi
    inc     rax
    jmp     .loop_str

.loop_str_done:
    pop     rbp
    ret
