[BITS 64]
default rel
global ft_list_sort

; in RDI c'e' **begin_list
; in RSI (cmp())
; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15

; rbx => *begin_list
; r12 => cmp()
; flag per capire se ho finito => r13

section .text
ft_list_sort:
    push    rbp
    mov     rbp, rsp

    push    rbx
    push    r12
    push    r13
    push    r14
    
    ; controlli per evitare segfault
    cmp     rdi, 0x00
    je      .end

    cmp     rsi, 0x00
    je      .end

    ; inizializzo la flag in un registro a 32 bit dato che e' un int
    xor     r13d, r13d
    ; salvo *begin list in un registro safe
    mov     rbx, [rdi]
    ; salvo cmp() in un registro safe
    mov     r12, rsi

    ; controllo se begin_list == NULL
    cmp     rbx, 0x00
    je      .end


.loop:
    ; ora mi serve un registro di appoggio per salvare *current = *begin_list
    mov     r14, rbx      
    xor     r13d, r13d

.loop_list:
    ; qword sta per Quad-Word ovvero 64 bit (un puntatore)
    cmp qword     [r14 + 8], 0x00
    je      .check_flag

    jmp     .swap

.check_flag:
    cmp     r13d, 0
    je      .end

    jmp     .loop

.swap:
    ; metto in rdi current->data
    mov     rdi, [r14]

    ; salvo in rsi current->next temporaneamente
    mov     rsi, [r14 + 8]

    ; metto in rsi current->next->data
    mov     rsi, [rsi]

    call    r12

    ; se in eax c e un valore > 0 devo mettere la flag a 1 e swappare i data
    cmp     eax, 0
    jg      .handle_swap
    
    mov     r14, [r14 + 8]
    jmp     .loop_list

.handle_swap:
    ; imposto la flag a 1
    mov     r13d, 1

    ; salvo current->data in rax
    mov     rax, [r14]

    ; salvo current->next in r9
    mov     r9, [r14 + 8]
    ; salvo next->data in r10
    mov     r10, [r9]

    mov     [r14], r10
    mov     [r9], rax

    mov     r14, [r14 + 8]

    jmp     .loop_list

.end:
    pop     r14
    pop     r13
    pop     r12
    pop     rbx
    pop     rbp
    ret