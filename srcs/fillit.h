/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:40:40 by pimichau          #+#    #+#             */
/*   Updated: 2019/01/03 12:25:01 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct			s_tetri_list
{
	char				**tetri;
	char				id;
	float				dimension;
	struct s_tetri_list	*next;
}						t_tetri_list;

char					**ft_read_file(int fd, int i, int j, char **tab);
int						ft_check_errors(char **tab, int i, int sharp,
						int sides);
int						ft_create_list(char **tab, t_tetri_list **list);
void					ft_free_tab(char ***tab);
int						ft_get_min_sqr_size(t_tetri_list *list);
int						ft_init_sol_tab(char ***tab, int sqr_size);
int						ft_check_place(t_tetri_list *elem, char **tab,
						float c);
int						ft_complete_tetris(t_tetri_list *list, char **tab,
						float c);
void					ft_display_tab(char **tab);
void					ft_free_list(t_tetri_list **list);
int						ft_one_tetri(char *file);
int						get_y(float f);
int						get_x(float f);
float					set_x(int x);
float					set_y(int y);

#endif
