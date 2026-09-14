#include "../test.h"

extern ssize_t ft_read(int fd, void *buf, size_t nbytes);

void test_read1(){
    char    buf[1024];
	printf("========TEST 1 READ========\n");
    ssize_t result = read(1, &buf, 5);
    printf("risultato di read e': %zi\n", result);

    result = ft_read(1, &buf, 5);
    printf("risultato del mio read e': %zi\n", result);
	printf("=============================\n\n");
}

void test_read2(){
    char    buf[1024];
	printf("========TEST 2 READ========\n");
    ssize_t result = read(-1, &buf, 5);
    printf("risultato di read e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_read(-1, &buf, 5);
    printf("risultato del mio read e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}

void test_read3(){
    char    buf[1024];
    int     fd = open("file_test_read", O_WRONLY);
	printf("========TEST 3 READ========\n");
    ssize_t result = read(fd, &buf, 5);
    printf("risultato di read e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_read(fd, &buf, 5);
    printf("risultato del mio read e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}

void test_read4(){
    char    *buf = NULL;
	printf("========TEST 4 READ========\n");
    ssize_t result = read(1, &buf, 3);
    printf("risultato di read e': %zi\n", result);
    printf("valore errno': %i\n", errno);

    result = ft_read(1, &buf, 3);
    printf("risultato del mio read e': %zi\n", result);
    printf("valore mio di errno': %i\n", errno);
	printf("=============================\n\n");
}