/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:12:29 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 19:20:05 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_multipleof3_5(int x)
{
	if (x % 3 == 0 || x % 5 == 0)
		return (1);
	return (0);
}

int main()
{
	int n = 1000;
	int som = 0;
	int i = -1;

	while (++i < n)
	{
		if (is_multipleof3_5(i))
			som += i;
	}
	printf("%d\n", som);

}
