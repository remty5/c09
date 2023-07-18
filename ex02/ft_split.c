/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:06:33 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/19 00:51:46 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_chartest(char c, char *charset)
{
	int	i;

	if (!c)
		return (1);
	i = 0;
	while (charset[i])
		i++;
	while (--i >= 0)
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_count_str(char *str, char *charset)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (str[++i] != '\0')
	{
		if (c && ft_chartest(str[i], charset) == 0)
		{
			n++;
			c = 0;
		}
		else if (ft_chartest(str[i], charset))
			c = 1;
	}
	printf("finished counting %d in: %s\n", n, str);
	return (n);
}

char	**ft_malloc_tab(unsigned long *tab, char *str, char *charset)
{
	int	i;
	int	n;
	int	c;

	printf("starting submallocs\n");
	i = -1;
	n = 0;
	c = 1;
	while (i++ == -1 || str[i - 1] != '\0')
	{
		printf("[PRE ] %s: i: %d, c: %c, n: %d, c: %d\n", str, i, str[i], n, c);
		if (c && !ft_chartest(str[i], charset))
		{
			tab[n] = 2;
			c = 0;
		}
		else if (!ft_chartest(str[i], charset))
			tab[n]++;
		else if (!c && ft_chartest(str[i], charset))
		{
			printf("creating string of bsize %lu\n", tab[n]);
			tab[n] = (unsigned long) malloc(tab[n]);
			n++;
			c = 1;
		}
		printf("[POST] %s: i: %d, c: %c, n: %d, c: %d\n", str, i, str[i], n, c);
	}
	tab[n] = 0;
	return ((char **) tab);
}

void	ft_strcpy_bis(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (ft_chartest(src[i], charset) == 0)
	{
		printf("COPY %s to %s, c: %c, i: %d\n", src, dest, src[i], i);
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		n;
	int		c;
	char	**tab;

	printf("starting malloc with size %d\n", (ft_count_str(str, charset) + 1));
	tab = malloc(sizeof(char *) * (ft_count_str(str, charset) + 1));
	ft_malloc_tab((unsigned long *) tab, str, charset);
	i = -1;
	n = 0;
	c = 1;
	while (str[++i] != '\0')
	{
		printf("MAIN LOOP: i:%d n:%d c:%d char: %c\n", i, n, c, str[i]);
		if (c && ft_chartest(str[i], charset) == 0)
		{
			printf("copying string %s, n %d, i %d\n", str + i, n, i);
			ft_strcpy_bis(tab[n], str + i, charset);
			c = 0;
		}
		else if (!c && ft_chartest(str[i], charset))
		{
			printf("incrementing and setting c to 1\n");
			n++;
			c = 1;
		}
		printf("MAIN POST: i:%d n:%d c:%d char: %c\n", i, n, c, str[i]);
	}
	return (tab);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**tab;

	if (argc == 3)
	{
		i = 0;
		tab = ft_split(argv[2], argv[1]);
		printf("size: %lu\n", sizeof(tab));
		while (tab[i] != 0)
		{
			printf("at address %p ", tab + i);
			printf("found: %s\n", tab[i++]);
		}
	}
	else
		printf("Usage: %s <seperators> <string>\n", argv[0]);
	return (0);
}
