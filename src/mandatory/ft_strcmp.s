[BITS 64]
global  ft_strcmp
default rel

; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15

section .text
ft_strcmp:
    ; RDI contiene S1
    ; RSI contiene S2
    push    rbp
    push    rbx

    mov     rbp, rsp
    xor     rax, rax

.loop_str:
    ; salvo [il valore di rdi dentro al(registro a 8 bit = 1char = 1byte)]
    mov     al, [rdi]
    ; salvo [il valore di rsi dentro bl(registro a 8 bit = 1char = 1byte)]
    mov     bl, [rsi]

    ; sposto i puntatori rdi++ rsi++
    inc     rdi
    inc     rsi

    ; if (contenuto di al == contenuto di bl) are_equal()
    cmp     al, bl
    je      .are_equal
    ; else not_equal()
    jne     .not_equal

    jmp     .loop_str

.are_equal:
    ; se sono uguali e siamo al terminatore nullo, il risultato e' 0 result_zero()
    cmp     byte al, 0x00
    je      .result_zero
    ; senno' torno al loop
    jne     .loop_str

.result_zero:
    xor     rax, rax
    jmp     .end

.not_equal:
    sub     al, bl

    ; movsx propaga il segno senza sovrascriverlo
    movsx     rax, al
    jmp     .end

.end:
    pop     rbx
    pop     rbp
    ret