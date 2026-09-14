[BITS 64]
default rel

extern  ft_strcpy
extern  ft_strlen
extern  malloc

global  ft_strdup

; char *strdup(const char *s);
section     .text
ft_strdup:
    push    rbp
    mov     rbp, rsp

    ; RDI contiene il puntatore a s
    ; la size di s viene messa in RAX, la devo spostare in RDI,
    ; prima pusho nello stack il puntatore a s
    push    rdi

    ; calcolo la size di s, per passarla a malloc
    call    ft_strlen

    ; adesso rax contiene la size di s
    ; la salvo in rdi, perche' malloc la vuole come primo argomento
    ; allineo la memoria perche' l ho sfasata pushando nello stack
    mov     rdi, rax
    inc     rdi ; incremento rdi, per il terminatore nullo
    sub     rsp, 8
    call    malloc wrt ..plt
    add     rsp, 8

    ; adesso RAX contiene il puntatore allocato
    ; controllo se e' nullo
    cmp    rax, 0x00
    ; jump if zero
    je      .handle_error

    ; se arriviamo qua, sappiamo per certo che malloc ha funzionato e in rax c e' il nuovo puntatore
    ; ora dobbiamo chiamare ft_strcpy, che vuole in rdi DEST e in rsi SRC
    pop     rsi
    mov     rdi, rax
    call    ft_strcpy
    pop     rbp
    ret

.handle_error:
    pop     rbx
    pop     rbp
    ret