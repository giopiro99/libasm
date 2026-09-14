#include "../test.h"

extern int		ft_strcmp(const char *s1, const char *s2);

void	test_strcmp1(){

	const char	*s1 = "ciao";
	const char	*s2 = "ciaosa";

	printf("========TEST 1 STRCMP========\n");
	printf("risultato di strcmp: %i\n", strcmp(s1, s2));
	printf("risultato della mia strcmp: %i\n", ft_strcmp(s1, s2));
	printf("=============================\n\n");
}


void	test_strcmp2(){

	const char	*s1 = "ciao";
	const char	*s2 = "";

	printf("========TEST 2 STRCMP========\n");
	printf("risultato di strcmp: %i\n", strcmp(s1, s2));
	printf("risultato della mia strcmp: %i\n", ft_strcmp(s1, s2));
	printf("=============================\n\n");
}

void	test_strcmp3(){

	const char	*s1 = "ciao";
	const char	*s2 = "ciao";

	printf("========TEST 3 STRCMP========\n");
	printf("risultato di strcmp: %i\n", strcmp(s1, s2));
	printf("risultato della mia strcmp: %i\n", ft_strcmp(s1, s2));
	printf("=============================\n\n");
}

void	test_strcmp4(){

	const char	*s1 = "";
	const char	*s2 = "";

	printf("========TEST 4 STRCMP========\n");
	printf("risultato di strcmp: %i\n", strcmp(s1, s2));
	printf("risultato della mia strcmp: %i\n", ft_strcmp(s1, s2));
	printf("=============================\n\n");
}

void	test_strcmp5(){

	const char	*s1 = "";
	const char	*s2 = "ciao";

	printf("========TEST 5 STRCMP========\n");
	printf("risultato di strcmp: %i\n", strcmp(s1, s2));
	printf("risultato della mia strcmp: %i\n", ft_strcmp(s1, s2));
	printf("=============================\n\n");
}