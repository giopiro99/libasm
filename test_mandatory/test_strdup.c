#include "../test.h"

extern char		*ft_strdup(char *s);

void    test_strdup1(){
    char	*str = "";
    char		*result = ft_strdup(str);
    char		*result_real = strdup(str);

	printf("========TEST 1 STRDUP========\n");
    printf("il risultato della mia strdup e' %s\n", result);
    printf("il risultato di strdup e' %s\n", result_real);
	printf("=============================\n\n");

    free(result);
    free(result_real);
}

void    test_strdup2(){
    char	*str = "ciao";
    char		*result = ft_strdup(str);
    char		*result_real = strdup(str);

	printf("========TEST 2 STRDUP========\n");
    printf("il risultato della mia strdup e' %s\n", result);
    printf("il risultato di strdup e' %s\n", result_real);
	printf("=============================\n\n");
    free(result);
    free(result_real);
}

void    test_strdup3(){
    char *str = "ciao mondooooooooooooooooooooooooooooo";
    char *result = ft_strdup(str);
    char *result_real = strdup(str);
	printf("========TEST 3 STRDUP========\n");
    printf("il risultato della mia strdup e' %s\n", result);
    printf("il risultato di strdup e' %s\n", result_real);
	printf("=============================\n\n");
    free(result);
    free(result_real);
}

void    test_strdup4(){
    char    *str = "\0";
    char *    result = ft_strdup(str);
    char *    result_real = strdup(str);

	printf("========TEST 4 STRDUP========\n");
    printf("il risultato della mia strdup e' %s\n", result);
    printf("il risultato di strdup e' %s\n", result_real);
	printf("=============================\n\n");
    free(result);
    free(result_real);
}