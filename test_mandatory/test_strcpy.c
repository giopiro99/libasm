#include "../test.h"


extern void		ft_strcpy(char *dest, const char *src);

void    test_strcpy1(){
    const char  *src = "ciao";
	int len = strlen((char *)src) + 1;
    char        dest[len];
    
	printf("========TEST 1 STRCPY========\n");
    strcpy(dest, src);
	printf("risultato di strcpy: %s\n", dest);
	ft_strcpy(dest, src);
	printf("risultato della mia strcpy: %s\n", dest);
	printf("=============================\n\n");
}

void    test_strcpy2(){
    const char  *src = "ciao mondooooooooooooooooooooooooooooo";
	int len = strlen((char *)src) + 1;
    char        dest[len];

	printf("========TEST 2 STRCPY========\n");
    strcpy(dest, src);
	printf("risultato di strcpy: %s\n", dest);

	ft_strcpy(dest, src);
	printf("risultato della mia strcpy: %s\n", dest);
	printf("=============================\n\n");
}

void    test_strcpy3(){
    const char  *src = "";
	int len = strlen((char *)src) + 1;
    char        dest[len];

	printf("========TEST 3 STRCPY========\n");
    strcpy(dest, src);
	printf("risultato di strcpy: %s\n", dest);

	ft_strcpy(dest, src);
	printf("risultato della mia strcpy: %s\n", dest);
	printf("=============================\n\n");
}

void    test_strcpy4(){
    const char  *src = "w";
	int len = strlen((char *)src) + 1;
    char        dest[len];

	printf("========TEST 4 STRCPY========\n");
    strcpy(dest, src);
	printf("risultato di strcpy: %s\n", dest);

	ft_strcpy(dest, src);
	printf("risultato della mia strcpy: %s\n", dest);
	printf("=============================\n\n");
}