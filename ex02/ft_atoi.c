/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:11:59 by clingier          #+#    #+#             */
/*   Updated: 2018/08/27 14:12:10 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int isnegative;
	int nb;

	nb = 0;
	isnegative = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			isnegative++;
		if (str[i] <= 32 || str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] > 47 && str[i] < 59)
		{
			nb = (nb * 10);
			nb += (str[i] - '0');
			i++;
		}
		if (str[i] > 57 || str[i] < 48)
			return (nb);
	}
	if (isnegative)
		return (-nb);
	return (nb);
}
