[BITS 64]
default rel
extern  ft_strlen
global  ft_atoi_base

; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15

section .text
ft_atoi_base:
    ; RDI contiene il puntatore str
    ; RSI contiene il puntatore alla base
    push    rbp
    mov     rbp, rsp

    ; siccome voglio usare i registri protetti per salvare le variabili essenziali, 
    ; pusho tutti i loro valori nello stack, per poi ripristinarli alla fine
    ; ho bisogno di:
    ; 1 registro per *str => rbx
    ; 1 registro per *base => r12
    ; 1 registro per base_len => r13
    ; 1 registro per il segno => r14
    ; 1 registro per result => r15
    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15

    ; inizializzazione dei registri
    mov     rbx, rdi
    mov     r12, rsi
    mov     r13, 0
    mov     r14, 1
    mov     r15, 0

    ; come prima cosa devo calcolare la len della base, ft_strlen vuole in rdi (*s)
    mov     rdi, r12

    sub     rsp, 8
    call    ft_strlen
    add     rsp, 8

    ; rax ora contiene la len se e' <= 1 ritorno 0
    ; jle   jump less or equal 1
    cmp     rax, 1
    jle     .end

    ; se arriviamo qua, la len e' valida la salvo nel registro protetto
    mov     r13, rax

    ; ora dobbiamo loppare sulla base per vedere se contiene caratteri invalidi, ovvero:
    ; <= 32 || 43(+) || 45(-)
    ; metto in rcx la base cosi da non spostare il puntatore originale
    mov     rcx, r12
    jmp    .loop_base

.check_double:

    ; se siamo alla fine ritorno al loop principale
    mov     r8b, [rdx]
    cmp     r8b, 0x00
    je      .loop_base

    ; se il valore in r8b, e' uguale al valore in al c e' un doppione
    cmp     r8b, al
    je      .end

    inc     rdx
    jmp     .check_double

.loop_base:
    mov     al, [rcx]

    cmp     al, 0x00
    je      .success
    
    cmp     al, 32
    jle      .end

    cmp     al, 43
    je      .end
    
    cmp     al, 45
    je      .end

    ; con lea, entriamo all indirizzo di rcx + 1 e salviamo il valore dell indirizzo in rdx
    ; cosi' possiamo controllare i doppioni
    lea     rdx, [rcx + 1]
    inc     rcx
    jmp     .check_double

.success:
    ; se arriviamo qua sappiamo per certo che la base e' corretta, dobbiamo 
    ; loppare su str per saltare gli spazi e capire il segno finale
    ; salvo il puntatore str in un registro di appoggio
    mov     rcx, rbx

    jmp     .skip_spaces

.inc_ptr_spaces:
    inc     rcx
    jmp     .skip_spaces

.skip_spaces:
    mov     al, [rcx]
    cmp     al, 32
    je     .inc_ptr_spaces

    ; siccome devo controllare se il valore e' compreso tra 9 e 13 possiamo usare questo trucco
    ; sottraiamo da al 9 e controlliamo se il valore di al e' <= 4
    ; esempio: al 11(carattere da saltare), al - 9 = 2 => lo salto
    ; esempio: al 50(carattere valido), al - 9 = 41 => vado avanti
    sub     al, 9
    cmp     al, 4
    jbe     .inc_ptr_spaces

    jmp     .skip_sign

.inc_ptr_sign:
    inc     rcx
    jmp     .skip_sign

.inc_ptr_sign_neg:
    neg     r14
    inc     rcx
    jmp     .skip_sign

.skip_sign:
    mov     al, [rcx]

    cmp     al, 43
    je     .inc_ptr_sign

    cmp     al, 45
    je     .inc_ptr_sign_neg

    ; quando arriviamo qua, dovremmo aver saltato segni e spazi
    ; inizializzazione di index a 0 in un registro a 32 bit perche' e' un int
    mov     edx, 0
    ; mi serve anche una copia di base, per loppare in calc_index
    mov     rdi, r12
    jmp     .result_loop

.index_loop:
    mov     r8b, [rdi]
    cmp     r8b, 0x00
    je      .end

    cmp     r8b, al
    je      .calc_result

    inc     rdi
    add     edx, 1
    
    jmp     .index_loop

.result_loop:
    mov     al, [rcx]
    cmp     al, 0x00
    je      .end

    mov     edx, 0
    mov     rdi, r12
    jmp     .index_loop

.calc_result:
    imul    r15, r13
    mov     edx, edx
    add     r15, rdx

    inc     rcx
    jmp     .result_loop

.end:
    mov     rax, r15
    imul    rax, r14
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    pop     rbx
    pop     rbp
    ret
