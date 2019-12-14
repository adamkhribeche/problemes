/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:43:44 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 23:27:27 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_prime(long x)
{
	int  i = 1;
	int  limit;

	if (x == 0 || x == 1)
		return (0);
	limit = x / 2;
	while (++i <= limit)
	{
		if (x % i == 0)
			return (0);
	}
	return (1);
}

int main()
{
	int  count = 6;
	int  i = 13; // 13 is the 6th prime nbr

	while (count < 10001)
	{
		i++;
		if (is_prime(i))
			count++;
	}
	printf("the 10 001st prime nbr is -------> %d\n", i);
	return (0);
}
