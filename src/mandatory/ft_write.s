[BITS 64]
default rel
global ft_write
extern __errno_location

section .text
    ; RDI contiene FD
    ; RSI contiene *buf
    ; RDX contiene count

ft_write:
    push    rbp
    mov     rbp, rsp

    ; azzeriamo il registro rax per convenzione
    xor     rax, rax
    ; 1 e' il valore che il kernel riconosce per write, vedi:
    ; cat /usr/include/x86_64-linux-gnu/asm/unistd_64.h
    ; per riconoscerlo, deve essere in RAX
    mov     rax, 1

    ; chiamando syscall il kernel prende il controllo
    syscall

    cmp     rax, 0
    ; jl sta per minore(considera anche i negativi), quindi se il ritorno di write e' minore di 0
    jl      .handle_error
    pop     rbp
    ret

.handle_error:
    ; in questo momento rax contiene il valore di errno
    ; lo pusho nello stack invertito di segno (il kernel ritorna per esempio -9, ma errno deve essere positivo)
    neg     rax
    push    rax

    ; allineo il puntatore allo stack a 16, avevo spostato il puntatore di 8 byte pushando rax
    sub     rsp, 8
    ; wrt ..plt 
    call    __errno_location wrt ..plt
    add     rsp, 8
    ; adesso rax contiene l indirizzo di errno

    ; prendo il valore di errno dallo stack
    pop     rbx
    ; salvo il valore di errno dentro l indirizzo di rax
    ; uso ebx perche' errno e' un int (4 byte) e non ho bisogno del registro a 64, basta uno a 32
    mov     [rax], ebx

    ; metto come valore di ritorno in caso di fallimento -1, come da manuale
    mov     rax, -1
    pop     rbp

    ret

