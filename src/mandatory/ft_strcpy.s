[BITS 64]
global  ft_strcpy
default rel

section .text
ft_strcpy:
    ; RDI contiene dest
    ; RSI contiene src
    ; valore di ritorno da mettere in RAX == DEST quindi RDI

    push    rbp
    mov     rbp, rsp

    ; salvo il puntatore all inizio di rdi nello stack
    push    rdi

.loop_str:
    ;
    mov     al, [rsi]
    mov     [rdi], al

    cmp     byte [rsi], 0x00
    je      .loop_str_done

    inc     rsi
    inc     rdi

    jmp     .loop_str

.loop_str_done:
    xor     rax, rax
    pop     rdi
    mov     rax, rdi
    pop     rbp
    ret