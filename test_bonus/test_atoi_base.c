#include "../test_bonus.h"
#include <stdio.h>

extern int ft_atoi_base(char *str, char *base);
// Assumo che atoi_base sia la tua funzione C di riferimento o inclusa in un'altra libreria

void    test_atoi_base1(){
    // Test: Esadecimale standard con spazi e segni
    char    str[] = " \t\n\r\v\f  ---++--2A";
    char    base[] = "0123456789ABCDEF"; // Base 16 corretta
    
    printf("========TEST 1: Hex========\n");
    int result = atoi_base(str, base);
    printf("risultato C: %i\n", result);
    result = ft_atoi_base(str, base);
    printf("risultato ASM: %i\n", result);
    printf("==========================================\n\n");
}

void    test_atoi_base2(){
    // Test: Base non valida (Stringa vuota o un solo carattere)
    char    str[] = "42";
    char    base[] = "0"; // Errore: la base deve avere almeno 2 caratteri
    
    printf("========TEST 2: Base troppo corta========\n");
    int result = atoi_base(str, base);
    printf("risultato C: %i\n", result);
    result = ft_atoi_base(str, base);
    printf("risultato ASM: %i\n", result);
    printf("=========================================\n\n");
}

void    test_atoi_base3(){
    // Test: Base non valida (Caratteri duplicati o segni)
    char    str[] = "123";
    char    base[] = "01234556789"; // Errore: il '5' è duplicato
    
    printf("========TEST 3: Base con duplicati========\n");
    int result = atoi_base(str, base);
    printf("risultato C: %i\n", result);
    result = ft_atoi_base(str, base);
    printf("risultato ASM: %i\n", result);
    printf("==========================================\n\n");
}

void    test_atoi_base4(){
    char    str[] = "yv"; // 37
    char    base[] = "poneyvif";
    
    printf("========TEST 4: Base custom poneyvif========\n");
    int result = atoi_base(str, base);
    printf("risultato C: %i\n", result);
    result = ft_atoi_base(str, base);
    printf("risultato ASM: %i\n", result);
    printf("============================================\n\n");
}

void    test_atoi_base5(){
    // Test: Interruzione al primo carattere non appartenente alla base
    char    str[] = "1010201"; 
    char    base[] = "01"; // Si deve fermare al '2' (non fa parte di 01) e calcolare "1010"
    
    printf("========TEST 5: Carattere fuori base========\n");
    int result = atoi_base(str, base);
    printf("risultato C: %i\n", result);
    result = ft_atoi_base(str, base);
    printf("risultato ASM: %i\n", result);
    printf("============================================\n\n");
}