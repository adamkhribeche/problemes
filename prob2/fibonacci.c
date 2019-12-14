/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:23:48 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 19:38:41 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_even(int x)
{
	if (x % 2 == 0)
		return (1);
	return (0);
}

int main()
{
	int som = 0;
	int i = -1;
	int f0 = 1;
	int f1 = 1;
	int f2 = 2;

	while (f2 <= 4000000)
	{
		if (is_even(f2))
			som += f2;
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;
	}
	printf("%d\n", som);
	return (0);
}
