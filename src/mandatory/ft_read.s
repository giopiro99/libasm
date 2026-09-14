[BITS 64]
default rel
global ft_read
extern  __errno_location

section .text
ft_read:
    ; RDI contiene FD
    ; RSI contiene *buf
    ; RDX contiene count

    push    rbp
    mov     rbp, rsp

    ; 0 corrisponde alla chiamata al kernel read
    mov     rax, 0

    ; passiamo la palla al kernel che fara' read
    syscall

    cmp     rax, 0
    jl      .handle_error

    pop     rbp
    ret

.handle_error:
    ; come per write, rax contiene il valore di errno negativo, lo invertito
    neg     rax
    ; lo pusho nello stack
    push    rax

    ; adesso lo stack e' disallineato, le chiamate a funzioni di c, hanno
    ; bisogno che lo stack sia allineato a 16
    sub     rsp, 8
    call    __errno_location wrt ..plt
    ; torno al punto dov ero nello stack
    add     rsp, 8

    pop     rbx
    ; adesso in rax c e' l indirizzo di errno, setto il suo valore
    mov     [rax], ebx

    mov     rax, -1
    pop     rbp
    ret 