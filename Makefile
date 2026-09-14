NAME = libasm.a
NAME_TESTER = tester

NAME_BONUS = libasm_bonus.a
NAME_TESTER_BONUS = tester_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

AC = nasm
AFLAGS = -f elf64

CMAIN = main.c
CSRC_MANDATORY = test_mandatory/test_strlen.c test_mandatory/test_strcpy.c \
			test_mandatory/test_strcmp.c test_mandatory/test_write.c \
			test_mandatory/test_read.c test_mandatory/test_strdup.c
ASRC = src/mandatory/ft_strlen.s src/mandatory/ft_strcpy.s \
		src/mandatory/ft_strcmp.s src/mandatory/ft_write.s \
		src/mandatory/ft_read.s src/mandatory/ft_strdup.s
AOBJ = $(ASRC:.s=.o)

CMAIN_BONUS = main_bonus.c
CSRC_BONUS = test_bonus/c_function/ft_atoi_base.c test_bonus/c_function/ft_list_push_front.c \
				test_bonus/c_function/ft_list_size.c test_bonus/c_function/ft_list_sort.c \
				test_bonus/test_atoi_base.c test_bonus/test_list_push_front.c test_bonus/test_list_size.c \
				test_bonus/test_list_sort.c

ASRC_BONUS = src/mandatory/ft_strlen.s src/mandatory/ft_strcmp.s src/bonus/ft_atoi_base.s src/bonus/ft_list_push_front.s \
				src/bonus/ft_list_size.s src/bonus/ft_list_sort.s
AOBJ_BONUS = $(ASRC_BONUS:.s=.o)

%.o: %.s
	$(AC) $(AFLAGS) $< -o $@

$(NAME): $(AOBJ)
		ar rcs $(NAME) $(AOBJ)

$(NAME_BONUS): $(AOBJ_BONUS)
		ar rcs $(NAME_BONUS) $(AOBJ_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

test: $(NAME)
	$(CC) $(CFLAGS) $(CMAIN) $(CSRC_MANDATORY) $(NAME) -o $(NAME_TESTER)

test_bonus: $(NAME_BONUS)
	$(CC) $(CFLAGS) $(CMAIN_BONUS) $(CSRC_BONUS) $(NAME_BONUS) -o $(NAME_TESTER_BONUS)

clean:
	@rm -f $(AOBJ)
	@rm -f $(AOBJ_BONUS)

fclean:
	@rm -f $(NAME)
	@rm -f $(AOBJ)
	@rm -f $(NAME_TESTER)
	@rm -f $(NAME_BONUS)
	@rm -f $(AOBJ_BONUS)
	@rm -f $(NAME_TESTER_BONUS)

re: fclean all

.PHONY: all clean fclean re