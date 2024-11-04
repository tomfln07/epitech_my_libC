##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Build libmy
##

LIB_SRC =	my_getnbr.c \
			my_putchar.c \
			my_showmem.c \
			my_strcapitalize.c \
			my_str_isalpha.c \
			my_str_isupper.c \
			my_strncmp.c \
			my_strupcase.c \
			my_compute_power_rec.c \
			my_put_nbr.c \
			my_showstr.c \
			my_strcat.c \
			my_str_islower.c \
			my_strlen.c \
			my_strncpy.c \
			my_swap.c \
			my_compute_square_root.c \
			my_isneg.c \
			my_putstr.c \
			my_show_word_array.c \
			my_strcmp.c \
			my_str_isnum.c \
			my_strlowcase.c \
			my_strstr.c \
			my_find_prime_sup.c \
			my_is_prime.c \
			my_revstr.c \
			my_sort_int_array.c \
			my_strcpy.c \
			my_str_isprintable.c \
			my_strncat.c \
			my_str_to_word_array.c \
			my_printf/float_specifiers.c \
			my_printf/formalize_precision.c \
			my_printf/formalize.c \
			my_printf/hexa.c \
			my_printf/hundle_flags.c \
			my_printf/int_specifiers.c \
			my_printf/my_printf.c \
			my_printf/my_put_unsigned_nbr.c \
			my_printf/octa.c \
			my_printf/pointer_specifier.c \
			my_printf/power_notation.c \
			my_printf/chars_specifiers.c \
			my_printf/print_scientific_notation.c \

BIN_NAME = libmy.a

LIB_OBJ = $(LIB_SRC:.c=.o)

libmy.a: $(LIB_OBJ)
		ar rc $(BIN_NAME) $(LIB_OBJ)

clean:
		rm -f $(LIB_OBJ)

fclean: clean
		rm $(BIN_NAME)
