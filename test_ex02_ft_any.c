/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (tab[index])
	{
		if ((*f)(tab[index]) != 0)
		{
			result = 1;
			break ;
		}
		index++;
	}
	return (result);
}

int	ft_function(char *str)
{
	if (*str == 'X')
		return (1);
	return (0);
}

int	main(void)
{
	char	**array;

	array = malloc(5 * sizeof(char *));
	array[0] = "O";
	array[1] = "O";
	array[2] = "O";
	array[3] = "X";
	array[4] = 0;
	printf("ft_any(...) = %d\n", ft_any(array, &ft_function));
}
