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
# define SET_X(x) ((float)x)
# define SET_Y(y) ((float)y / 10)
# define GET_X(f) (int)(f)
# define GET_Y(f) (int)((f - (int)f) * 10)

# include <stdio.h>

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"


typedef struct		s_tetri_list
{
	char			**tetriminos;
  char      id;
	int 			placed;
	float 		dimension;
	struct s_tetri_list	*next;
}					t_tetri_list;

char	**ft_read_file(int fd);
int		ft_check_errors(char **tab);
int		ft_check_errors_2(char **tab, int i, int *sharp);
int		ft_create_list(char **tab, t_tetri_list **list);
void ft_free_tab(char ***tab);
int   ft_get_min_sqr_size(t_tetri_list **list);
void  ft_init_sol_tab(char ***tab, int sqr_size);
void  ft_display_tab(char ***tab);
char   ft_check_place(t_tetri_list **list, char ***tab, float *c);

#endif
