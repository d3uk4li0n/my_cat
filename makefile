my_cat: my_cat.c
	gcc -o my_cat my_cat.c -Wall -Wextra -Werror -g3 -fsanitize=address
