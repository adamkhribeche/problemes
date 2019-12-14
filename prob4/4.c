/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:38:38 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 22:48:40 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int is_palindromic_nbr(int x)
{
	char *s = ft_itoa(x);
	int len;
	int limit;
	int i = 0;

	len = ft_strlen(s);
	limit = len / 2;
	while (i < limit)
	{
		if (s[i] != s[len - 1])
			return (0);
		i++;
		len--;
	}
	return (1);
}

int main()
{
	int a;
	int b;
	int maxpal = 0;


	a = 999;
	while (a >= 100)
	{
		b = 999;
		while (b >= 100)
		{
			if (is_palindromic_nbr(a * b))
			{
				printf("----> %d * %d = %d\n", a, b, a * b);
				maxpal = maxpal >= a * b ? maxpal : a * b;
			}
			b--;
		}
		a--;
	}
	printf("----> maxpal %d\n",maxpal);
	return (0);
}
