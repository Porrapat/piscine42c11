/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int));

int		ft_less_than(int a, int b)
{
	return (b - a);
}

int		ft_more_than(int a, int b)
{
	return (a - b);
}

int		main(void)
{
	static int	tabx[] = { 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7 };
	int			index;
	int			*tab;
	int			length;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	printf("ft_is_sorted(1.........10) = %d\n", ft_is_sort(tab, length, &ft_less_than));
	index = 0;
	while (index < length)
	{
		tab[length - 1 - index] = index;
		index++;
	}
	printf("ft_is_sorted(10.........1) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 100;
	printf("ft_is_sorted(10...100...1) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 4;
	tab[9] = 100;
	printf("ft_is_sorted(10.....1.100) = %d\n", ft_is_sort(tab, length, &ft_more_than));
	printf("ft_is_sorted(.tabx.......) = %d\n", ft_is_sort(tabx, 13, &ft_more_than));
	printf("ft_is_sorted(.tabx.......) = %d\n", ft_is_sort(tabx, 13, &ft_less_than));
}
