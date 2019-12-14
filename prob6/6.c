/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:07:20 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 23:17:15 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int square(int x)
{
	return (x * x);
}

int main()
{
	int sum_of_sq = 0;
	int sq_of_sum = 0;
	int i = 0;

	while (++i <= 100)
	{
		sum_of_sq += square(i);
		sq_of_sum += i;
	}
	sq_of_sum = square(sq_of_sum);
	printf("result ---> %d\n", sq_of_sum - sum_of_sq);
	return (0);
}
