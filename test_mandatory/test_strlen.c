#include "../test.h"


extern int		ft_strlen(char *str);

void    test_strlen1(){
    char	*str = "";
    int		result = ft_strlen(str);
    int		result_real = strlen(str);

	printf("========TEST 1 STRLEN========\n");
    printf("il risultato della mia strlen e' %i\n", result);
    printf("il risultato di strlen e' %i\n", result_real);
	printf("=============================\n\n");
}

void    test_strlen2(){
    char	*str = "ciao";
    int		result = ft_strlen(str);
    int		result_real = strlen(str);

	printf("========TEST 2 STRLEN========\n");
    printf("il risultato della mia strlen e' %i\n", result);
    printf("il risultato di strlen e' %i\n", result_real);
	printf("=============================\n\n");
}

void    test_strlen3(){
    char *str = "ciao mondooooooooooooooooooooooooooooo";
    int result = ft_strlen(str);
    int result_real = strlen(str);
	printf("========TEST 3 STRLEN========\n");
    printf("il risultato della mia strlen e' %i\n", result);
    printf("il risultato di strlen e' %i\n", result_real);
	printf("=============================\n\n");
}

void    test_strlen4(){
    char    *str = "\0";
    int     result = ft_strlen(str);
    int     result_real = strlen(str);

	printf("========TEST 4 STRLEN========\n");
    printf("il risultato della mia strlen e' %i\n", result);
    printf("il risultato di strlen e' %i\n", result_real);
	printf("=============================\n\n");
}