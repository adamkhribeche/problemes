/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:30:04 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/15 01:02:50 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

long multiple_n_element(char *s, int n)
{
	int i = 0;
	long multip = 1;

	while (i < n)
	{
		multip *= s[i] - '0';
		//printf("------%c---------\n", s[i]);
		i++;
	}
	return (multip);
}

long get_max(char *s, int n)
{
	long max = 0;
	int i = 0;
	int limit;
	long tmp;
	int index;

	limit = 1000 - n;
	while (i <= limit)
	{
		//printf("-------%d-----\n", i);
		tmp = multiple_n_element(s + i, n);
		//if (i == 4)
		//	exit (0);
		//printf(" tmp = %ld\n", tmp);
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
		i++;
	}
	printf("max = %ld\n", max);
	printf("index = %d\n", index);
	return (max);
}

int main(int ac, char **av)
{
	int fd;
	char s[1001];
	int n = 13;
	long result;
	int i = 197;

	(void)ac;
	s[1000] = '\0';
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("");
		return (0);
	}
	read(fd, s, 1000);
	result = get_max(s, n);
	while (i < 197 + 13)
	{
		printf("-------%c-------\n", s[i]);
		i++;
	}
	//printf("index = %d\n", index);
	//result  = multiple_n_element(s + index, n);
	printf("the result is = %ld\n", result);
	close(fd);
	return (0);
}
