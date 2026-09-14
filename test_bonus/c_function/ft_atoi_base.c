#include <stdio.h>

extern int  ft_strlen(char *s);

int check_base(char *base) {
    int     base_length = ft_strlen(base);
    if (base_length <= 1) return 0;

    while (*base != '\0'){
        if (*base == '+' || *base == '-') return 0;

        if (*base <= 32) return 0;

        char    *checker = base + 1;
        while (*checker != '\0'){
            if (*base == *checker){
                return 0;
            }
            checker++;
        }
        base++;
    }

    return base_length;
}

int get_char_index(char c, char *base) {
    int index = 0;
    while (*base != '\0'){
        if (*base == c){
            return index;
        }
        index++;
        base++;
    }

    return -1;
}

int is_space(char c){
    return (c == 32 || (c >= 9 && c <= 13));
}

int atoi_base(char *str, char *base) {
    int base_len = check_base(base);
    if (base_len == 0){
        return 0;
    }

    while (is_space(*str)){
        str++;
    }

    int sign = 1;
    while (*str == '+' || *str == '-' ){
        if (*str == '-'){
            sign *= -1;
        }
        str++;
    }

    int result = 0;
    while (*str != '\0'){
        int index = get_char_index(*str, base);
        printf("*str=%c, Result=%d  base_len=%d, index=%d\n", *str, result, base_len, index);
        if (index == -1) break ;

        result = (result * base_len) + index;
        str++;
    }

    return (result * sign);
}