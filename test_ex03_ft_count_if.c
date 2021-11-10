/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if ((*f)(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}

int	ft_is_first_x(char *str)
{
	if (*str == 'X')
		return (1);
	return (0);
}

int	main(void)
{
	int		length;
	char	**array;

	length = 5;
	array = malloc(length * sizeof(char *));
	array[0] = "O";
	array[1] = "X";
	array[2] = "O";
	array[3] = "X";
	array[4] = "O";
	printf("ft_count_if(...) = %d\n",
		ft_count_if(array, length, &ft_is_first_x));
}
