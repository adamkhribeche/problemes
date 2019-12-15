/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:43:44 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/15 15:30:03 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_prime(int x)
{
	int i = 1;
	int limit;

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

long  get_the_sum_ofall_primes_below_2million()
{
	long result;
	int i = -1;

	result = 0;
	while (++i < 2000000)
	{
		if (is_prime(i))
			result += i;
	}
	return (result);
}

int main()
{
	long result;

	result = get_the_sum_ofall_primes_below_2million();
	printf("the sum of all primes below 2million is -------> %ld\n", result);
	return (0);
}
