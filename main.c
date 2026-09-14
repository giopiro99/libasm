#include "test.h"

static inline void	make_test_strlen(){
    test_strlen1();
    test_strlen2();
    test_strlen3();
    test_strlen4();
}

static inline void	make_test_strcpy(){
	test_strcpy1();
	test_strcpy2();
	test_strcpy3();
	test_strcpy4();
}

static inline void	make_test_strcmp(){
	test_strcmp1();
	test_strcmp2();
	test_strcmp3();
	test_strcmp4();
	test_strcmp5();
}

static inline void	make_test_write(){
	test_write1();
	test_write2();
	test_write3();
	test_write4();
}

static inline void	make_test_read(){
	test_read1();
	test_read2();
	test_read3();
	test_read4();
}

static inline void	make_test_strdup(){
	test_strdup1();
	test_strdup2();
	test_strdup3();
	test_strdup4();
}

int main(){
	make_test_strlen();
	make_test_strcpy();
	make_test_strcmp();
	make_test_write();
	make_test_read();
	make_test_strdup();
}