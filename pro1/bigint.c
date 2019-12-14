/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:39:33 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/14 18:58:06 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *somme(char *a, char *b)// strlen a = 52, strlen b = 52
{
	char	*result;
	int		som;
	int		carry;
	int		i;

	i = 60;
	carry = 0;
	result = ft_strnew(sizeof(char) * 60);
	//printf("%zu, %zu \n", strlen(a), strlen(b));
	//exit (0);
	while (--i > 0)
	{
		som = (a[i] - '0') + (b[i] - '0') + carry;
		result[i] = som % 10 + '0';
		carry = som / 10;
	}
	result[i] = carry + '0';
	return (result);
}

char	*get_result(int fd)
{
	char	*s;
	char	str[61];
	char	*to_delete;
	char	*result;
	int		i;
	
	i = -1;
	result = ft_strnew(sizeof(char) * 60);
	memset(result, '0', 60);
	memset(str, '0', 60);
	str[60] = '\0';
	while (++i < 100)
	{
		printf("---------%d---------\n", i);
		get_next_line(fd, &s);
		ft_memcpy(str + 10, s, 50);
		to_delete = result;
		result = somme(result, str);
		printf("----> %s\n", str);
		printf("resul %s\n", result);

		//exit(0);
		ft_strdel(&s);
		ft_strdel(&to_delete);
	}
	return (result);
}

int main(int ac, char **av)
{
	char	*result;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("");
		return (0);
	}
	result = get_result(fd);
	printf("resul %s\n", result);
	close(fd);
	return (0);
}
