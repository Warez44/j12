/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 08:46:43 by clingier          #+#    #+#             */
/*   Updated: 2018/08/27 09:12:21 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char buf;
	int fd;

	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
	}
	if (argc == 1)
	{
		write(2, "File name missing.\n", 20);
		return (1);
	}
}
