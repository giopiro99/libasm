[BITS 64]
default rel
global ft_list_remove_if
extern free

; void list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15
; in RDI c'e' **begin_list
; in RSI *data_ref
; in rdx cmp()
; in rcx free_fct()

section .text
ft_remove_list:
    push    rbp
    mov     rbp, rsp

    push    rbx
    push    r12
    push    r13
    push    r14

    cmp     rdi, 0x00
    je      .end

    cmp     [rdi], 0x00
    je      .end

    cmp     rsi, 0x00
    je      .end

    cmp     rdx, 0x00
    je      .end

    cmp     rcx, 0x00
    je      .end

    ; salvo cosi i dati:
    ; rbx => **begin_list
    ; r12 => data_ref
    ; r13 => cmp()
    ; r14 => free_fct
    ; current => r15 inizializzato a *begin_list
    ; servirebbe un registro safe anche per current come posso fare?
    mov     rbx, rdi
    mov     r12, rsi
    mov     r13, rdx
    mov     r14, rcx
    mov     r15, [rbx]

.loop:
    cmp     r15, 0x00
    je      .end

    ; ora devo mettere in rdi current->data e in rsi data_ref
    mov     rdi, [r15]
    mov     rsi, r12

    call    r13
    cmp     rax, 0
    je      .free_node

.free_node:
    ; devo salvare il next di current prima di eliminarlo
    








.end
    pop     r14
    pop     r13
    pop     r12
    pop     rbx
    pop     rbp