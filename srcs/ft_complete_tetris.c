/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_tetris.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:31:07 by pimichau          #+#    #+#             */
/*   Updated: 2019/01/03 12:25:15 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_put_tetriminos(t_tetri_list *element, char **tab, float c)
{
	int i;
	int j;

	i = -1;
	while (element->tetri[++i])
	{
		j = -1;
		while (element->tetri[i][++j])
		{
			if (element->tetri[i][j] == '#')
				tab[get_y(c) + i][get_x(c) + j] = element->id;
		}
	}
}

static void		ft_unput_tetriminos(t_tetri_list *element, char **tab, float c)
{
	int i;
	int j;

	i = 0;
	while (element->tetri[i])
	{
		j = 0;
		while (element->tetri[i][j])
		{
			if (element->tetri[i][j] == '#')
				tab[get_y(c) + i][get_x(c) + j] = '.';
			j++;
		}
		i++;
	}
}

static float	ft_get_next_coor(char **tab, int x, int y)
{
	int i;
	int j;

	if (x == -1)
		return (-1);
	j = y;
	while (tab[j])
	{
		i = ((j == y) ? (x + 1) : 0);
		while (tab[j][i])
		{
			if (tab[j][i])
				return (set_x(i) + set_y(j));
			i++;
		}
		j++;
	}
	return (-1);
}

int				ft_complete_tetris(t_tetri_list *element, char **tab, float c)
{
	if (!element)
		return (1);
	while (c != -1)
	{
		if (ft_check_place(element, tab, c))
		{
			ft_put_tetriminos(element, tab, c);
			if (ft_complete_tetris(element->next, tab, 0))
				return (1);
			ft_unput_tetriminos(element, tab, c);
		}
		c = ft_get_next_coor(tab, get_x(c), get_y(c));
	}
	return (0);
}
