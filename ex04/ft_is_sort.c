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

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		index;
	int		sorted;

	sorted = 1;
	index = 0;
	while (index < length - 1 && sorted)
	{
		if ((*f)(tab[index], tab[index + 1]) < 0)
			sorted = 0;
		index++;
	}
	if (sorted != 1)
	{
		sorted = 1;
		index = 0;
		while (index < length - 1)
		{
			if ((*f)(tab[index], tab[index + 1]) > 0)
				return (0);
			index++;
		}
	}
	return (1);
}
