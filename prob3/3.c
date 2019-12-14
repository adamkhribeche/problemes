/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:43:44 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 21:36:30 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_prime(long x)
{
	long i = 1;
	long limit;

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

int is_divisible(long nbr, int d)
{
	if (nbr % d == 0)
		return (1);
	return (0);
}

long get_prime_factor(long x)
{
	long i;
	long limit;

	i = 2;
	limit = x / 2;
	while (i <= limit)
	{
		if (is_divisible(x, i) && is_prime(i))
			return (i);
		i++;
	}
	return (0);
}
int main()
{
	//long x = 13195;
	long x = 600851475143;
	long max = 0;
	long tmp;

	while (!is_prime(x))
	{
		//printf("%ld\n", x);
		tmp = get_prime_factor(x);
		printf("prime factor = %ld\n", tmp);
		max = tmp > max ? tmp : max;
		x /= tmp;
	}
	printf("prime factor = %ld\n", x);
	max = x > max ? x : max;
	printf("the largest prime factor is -------> %ld\n", max);
	return (0);
}
