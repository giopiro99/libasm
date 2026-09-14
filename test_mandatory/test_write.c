#include "../test.h"

extern ssize_t	ft_write(int fd, const void *buf, size_t n);

void test_write1(){
	printf("========TEST 1 WRITE========\n");
    ssize_t result = write(1, "ciao\n", 5);
    printf("risultato di write e': %zi\n", result);

    result = ft_write(1, "ciao\n", 5);
    printf("risultato del mio write e': %zi\n", result);
	printf("=============================\n\n");
}

void test_write2(){
	printf("========TEST 2 WRITE========\n");
    ssize_t result = write(-1, "ciao\n", 5);
    printf("risultato di write e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_write(-1, "ciao\n", 5);
    printf("risultato del mio write e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}

void test_write3(){
    int fd = open("file_test_write", O_RDONLY);
	printf("========TEST 3 WRITE========\n");
    ssize_t result = write(fd, "ciao\n", 5);
    printf("risultato di write e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_write(fd, "ciao\n", 5);
    printf("risultato del mio write e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}

void test_write4(){
    char    *buf = NULL;
	printf("========TEST 3 WRITE========\n");
    ssize_t result = write(1, &buf, 3);
    printf("risultato di write e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_write(1, &buf, 3);
    printf("risultato del mio write e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}