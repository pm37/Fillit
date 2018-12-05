/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:40:40 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/04 12:11:59 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "get_next_line.h"


typedef struct		s_tetri_list
{
	char			**tetriminos;
  char      id;
	struct s_tetri_list	*next;
}					t_tetri_list;

char	**ft_check_file(int fd);
int		ft_check_errors(char **tab);
int		ft_check_errors_2(char **tab, int i, int *sharp);
int		ft_create_list(char **tab, t_tetri_list **list);
int		ft_get_min_square_side(t_tetri_list **list);

#endif
