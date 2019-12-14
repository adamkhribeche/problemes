/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:39:33 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 15:29:38 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct	s_big
{
	int tab[8];
	int size;
}				t_big;

int sizebig(t_big x)
{
	int i;

	i = 0;
	while (i < 8 && x.tab[i] != 0)
		i++;
	return (i);
}

int max(int a, int b)
{
	return (a >= b ? a : b);
}

void	printbig(t_big big)
{
	int i;

	//i = big.size;
	//while (big.size--)
	i = 8;
	while (i--)
	{
		printf("%d ", big.tab[i]);
	}
	printf("\n");
}

t_big somme(t_big a, t_big b)
{
	t_big result;
	long som;
	int carry;
	int maxsize;
	int i;

	//result = malloc(sizeof(*result));
	i = 0;
	carry = 0;
	maxsize = max(a.size, b.size);
	while (i < 8 && maxsize--)
	{
		som = a.tab[i] + b.tab[i] + carry;
		carry = som >> 32;
		result.tab[i] = som & 0xffffffff;
		result.size++;
		i++;
	}
	result.tab[i] = carry;
	if (carry != 0)
		result.size++;
	return (result);
}

void	bigindian(t_big *big)// octet faible en indice faible
{
	int i;
	int tmp;
	int fin;
	int start;

	start = 0;
	fin = big->size - 1;
	i = big->size / 2;
	while (i--)
	{
		tmp = big->tab[start];
		big->tab[start++] = big->tab[fin];
		big->tab[fin--] = tmp;
	}
}

t_big	get_big(int fd)
{
	t_big	result;
	char	*s;
	char	*tmp;
	int		i;
	int		len;
	
	i = -1;
	//result = malloc(sizeof(*result));
	ft_bzero(&result, sizeof(t_big));
	result.size = 0;
	get_next_line(fd, &s);
	len = ft_strlen(s);
	while (++i * 9 < len && i < 8)
	{
		tmp = ft_strsub(s, i * 9, 9);
		result.tab[i] = ft_atoi(tmp);
		result.size++;
	}
	printbig(result);
	bigindian(&result);
	printbig(result);
	ft_strdel(&tmp);
	ft_strdel(&s);
	return (result);
}

t_big	get_result(int fd)
{
	t_big	a;
	t_big	result;
	int		i;
	
	i = -1;
	ft_bzero(&result, sizeof(t_big));
	while (++i < 100)
	{
		a = get_big(fd);
		result = somme(result, a);
	}
	printbig(result);
	return (result);
}

int main(int ac, char **av)
{
	int		fd;
	t_big	a;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("");
		return (0);
	}
	//a = get_result(fd);
	//b = get_result(fd);*/
	
	a = get_big(fd);
	//b = get_big(fd);
	//printf("%d\n", a->tab[0]);
	//printf("%d\n", b->tab[0]);
	close(fd);
	return (0);
}
