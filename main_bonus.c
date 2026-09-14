#include "test_bonus.h"

static inline void	make_test_push_front_list(){
	test_list_push_front1();
	test_list_push_front2();
	test_list_push_front3();
	test_list_push_front4();
}

static inline void	make_test_atoi_base(){
	test_atoi_base1();
	test_atoi_base2();
	test_atoi_base3();
	test_atoi_base4();
    test_atoi_base5();
}

static inline void	make_test_list_size(){
	test_list_size1();
	test_list_size2();
	test_list_size3();
	test_list_size4();
}

static inline void	make_test_list_sort(){
	test_list_sort1();
	test_my_list_sort1();
	test_list_sort2();
	test_my_list_sort2();
	test_list_sort3();
	test_my_list_sort3();
	test_list_sort4();
	test_my_list_sort4();
}

static inline void	make_test_list_remove_if(){
	test_list_remove_if1();
	test_list_remove_if2();
	test_list_remove_if3();
	test_list_remove_if4();
}

int main(){
    make_test_atoi_base();
	make_test_push_front_list();
	make_test_list_size();
	make_test_list_sort();
	make_test_list_remove_if();
}