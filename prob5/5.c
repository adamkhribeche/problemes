/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:49:56 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 23:06:24 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int is_divisible_by1_20(int x)
{
	int i = 0;

	while (++i <= 20)
	{
		if (x % i != 0)
			return (0);
	}
	return (1);
}

int main()
{
	int i = 2520;// bcs is the smallest nbr that can be divided by nbrs from 1 to 10

	while (++i < INT_MAX)
	{
		if (is_divisible_by1_20(i))
		{
			printf("----> %d\n", i);
			break ;
		}
	}
	return (0);
}
