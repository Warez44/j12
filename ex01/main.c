/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:20:20 by clingier          #+#    #+#             */
/*   Updated: 2018/08/27 10:43:26 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"

void	ft_putstr(int out, char *str)
{
	while (*str)
		write (1, str++, 1);
}

int	main(int argc, char **argv)
{
	char buf;
	int fd;
	int i;
	
	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) != -1)
		{
			while (read(fd, &buf, 1))
				write(1, &buf, 1);
		}
		if (errno != 0)
		{
			ft_putstr(2, "ft_cat: ");
			ft_putstr(2, argv[i]);
			write (2, ": ", 2); 
			if (errno == ENOENT)
				ft_putstr(2, "No such file or directory\n");
			if (errno == EACCES)
				ft_putstr(2, "Permission denied\n");
		}
		i++;
	}
}
