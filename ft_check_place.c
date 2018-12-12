/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:29:20 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/12 17:03:24 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_place(t_tetri_list *ele, char **tab, int x, int y)
{
	int	is_ok;
	int	i;
	int	j;

	if (ele && tab)
	{
		is_ok = 1;
		i = -1;
		while (ele->tetriminos[++i])
		{
			j = -1;
			while (tab[y + i] && (size_t)(++j) < ft_strlen(ele->tetriminos[i]))
			{
				if (!(tab[y + i][x + j]) || (tab[y + i][x + j] != '.' && ele->tetriminos[i][j] != '.'))
				{
					is_ok = 0;
					break ;
				}
			}
			if (is_ok == 0 || !tab[y + i])
			{
				is_ok = 0;
				break ;
			}
		}
		if (is_ok == 1 && tab[y + i - 1])
			return (1);
	}
	return (0);
}
