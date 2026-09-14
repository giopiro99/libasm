[BITS 64]
default rel
global ft_list_size

; in RDI abbiamo *begin list
; registri usa e getta rax, rcx, rdx, rdi, rsi, r8, r9, r10, r11
; registri da ripristinare dopo la funzione rbx, rbp, r12, r13, r14, r15
section .text
ft_list_size:
    push    rbp
    mov     rbp, rsp
    ; come prima cosa, mettiamo in rax 0(sara' il contenitore del ritorno)
    xor rax, rax

.loop_list:
    cmp     rdi, 0x00
    je      .end

    add     rax, 1
    mov     rdi, [rdi + 8]

    jmp     .loop_list

.end:
    pop     rbp




