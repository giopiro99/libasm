#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

/*======TEST PER STRLEN======*/
void    test_strlen1();
void    test_strlen2();
void    test_strlen3();
void    test_strlen4();

/*======TEST PER STRCPY======*/
void    test_strcpy1();
void    test_strcpy2();
void    test_strcpy3();
void    test_strcpy4();

/*======TEST PER STRCMP======*/
void	test_strcmp1();
void	test_strcmp2();
void	test_strcmp3();
void	test_strcmp4();
void	test_strcmp5();

/*======TEST PER WRITE======*/
void test_write1();
void test_write2();
void test_write3();
void test_write4();

/*======TEST PER READ======*/
void test_read1();
void test_read2();
void test_read3();
void test_read4();

/*======TEST PER STRUP======*/
void test_strdup1();
void test_strdup2();
void test_strdup3();
void test_strdup4();

#endif