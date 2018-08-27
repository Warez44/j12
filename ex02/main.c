/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:50:35 by clingier          #+#    #+#             */
/*   Updated: 2018/08/27 15:50:51 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
#include <stdio.h>

int		ft_strcmp(char *a, char *b)
{
	while (*a && (*a == *b))
	{
		a++;
		b++;
	}
	return (*a - *b);
}

int		num_bytes(int argc, char **argv)
{
	int byte;

	byte = 0;
	byte = ft_atoi(argv[2]);
	return (byte);
}

void	ft_putstr(int out, char *str)
{
	while (*str)
		write (1, str++, 1);
}

int		ft_size(char *str)
{
	int c;
	int fd;
	char buf;

	c = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1))
			c++;
	return (c);
}

void	cat(int fd, char **argv, int size, int byte)
{
	
	int i;
	char buf;

	i = 0;
	if (argv[2][0] == '+')
	{
		while (i < byte)
		{
			read(fd, &buf, 1);
			i++;
		}
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
	}
	else
	{
		while (i < size - byte)
			i += read(fd, &buf, 1);
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
	}
}

void	putname(char *str)
{
	write (1, "==> ", 4);
	ft_putstr(1, str);
	write (1, " <==\n", 5);
}

int	main(int argc, char **argv)
{
	int i;
	int fd;
	int siz;
	int byte;

	byte = num_bytes(argc, argv);
	while (i < argc)
	{
		i = 0;
		fd = open(argv[i], O_RDONLY);
		siz = ft_size(argv[i]);
		if (errno != 0)
		{
			ft_putstr(2, "ft_tail: ");
			ft_putstr(2, argv[i]);
			write (2, ": ", 2); 
			if (errno == ENOENT)
				ft_putstr(2, "No such file or directory\n");
			if (errno == EACCES)
				ft_putstr(2, "Permission denied\n");
		}
		else 
		{
			(argc > 4)? putname(argv[i]):0;
			cat(fd, argv, siz, byte);
		}
		i++;
	}
}
