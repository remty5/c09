#!/bin/sh

files="ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp"
for f in $files
do
	cc -Wall -Wextra -Werror -c $f.c -o $f.o
done
ar ruv libft.a $(for f in $files; do echo $f.o; done)
ranlib libft.a
