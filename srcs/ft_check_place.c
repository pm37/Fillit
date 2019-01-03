/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:29:20 by pimichau          #+#    #+#             */
/*   Updated: 2019/01/03 12:25:15 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_on_line(t_tetri_list *element, char **tab, float c, int i)
{
	int		j;
	size_t	length;

	length = ft_strlen(element->tetri[i]);
	j = -1;
	while (tab[get_y(c) + i] && (size_t)(++j) < length)
	{
		if (!(tab[get_y(c) + i][get_x(c) + j]) || (tab[get_y(c) + i]
		[get_x(c) + j] != '.' && element->tetri[i][j] != '.'))
			return (0);
	}
	return (1);
}

int			ft_check_place(t_tetri_list *elem, char **tab, float c)
{
	int	is_ok;
	int	i;

	if (elem && tab)
	{
		is_ok = 1;
		i = -1;
		while (elem->tetri[++i])
		{
			if ((ft_on_line(elem, tab, c, i)) == 0 || !tab[get_y(c) + i])
			{
				is_ok = 0;
				break ;
			}
		}
		return ((is_ok == 1 && tab[get_y(c) + i - 1]) ? 1 : 0);
	}
	return (0);
}
