/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:59:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/15 15:17:05 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void get_pythagorean_triplet(int *a, int *b, int *c)
{
	*a = 0;
	//while (++*a < 12)
	while (++*a < 999)
	{
		*b = 0;
		while (++*b < 999)
		{
			*c = 0;
			while (++*c < 999)
			{
				if (*a + *b + *c == 1000 && (*a * *a) + (*b * *b) == (*c * *c))
					return ;
			}
		}
	}
	*a = 0;
	*b = 0;
	*b = 0;
}

int main()
{
	int a;
	int b;
	int c;

	get_pythagorean_triplet(&a, &b, &c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("the multiplcation of pythagorean triplet is --> %d", a * b * c);
	return (0);
}
