[BITS 64]
default rel
global  ft_list_push_front
extern  malloc

; in RDI abbiamo **begin list
; in RSI abbiamo *data
; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15

section .text
ft_list_push_front:
    push    rbp
    mov     rbp, rsp
    ; rbx => **begin list
    ; r12 => data
    ; r13 => indirizzo del nuovo nodo(data)

    push    rbx
    push    r12
    push    r13

    ; controllo se begin_list == NULL
    cmp     rdi, 0x00
    je      .end

    ; salvo gli argomenti della funzione
    mov     rbx, rdi
    mov     r12, rsi

    ; !! lo stack e' disallineato a 40 byte
    ; 4 push * 8 = 32 + push fatto dalla call esterna = 40 byte
    ; lo allineo tramite sub (lo stack cresce verso il basso)
    sub     rsp, 8
    mov     rdi, 16
    call    malloc wrt ..plt
    add     rsp, 8

    ; se malloc ritorna NULL
    cmp     rax, 0x00
    je      .end

    ; da qui in poi ho l indirizzo del nuovo nodo in rax lo metto in r13
    mov     r13, rax
    ; entro dentro l indirizzo e imposto data node->data
    mov     [r13], r12

    ; perche' non posso fare mov [r13 + 8], [rbx]?
    ; la cpu per muovere i dati da RAM a RAM ha bisogno di appoggiarsi per forza ad un registro
    mov     rdx, [rbx]
    mov     [r13 + 8], rdx
    mov     [rbx], r13

.end:
    pop     r13
    pop     r12
    pop     rbx
    pop     rbp
    ret