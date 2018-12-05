/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_tetris.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:31:07 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/04 16:31:11 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char  **ft_init_sol_tab(char ***tab)
{
  int i;
  int j;
  //free memory
  ft_free_tab(tab);
  //allocate memory

  //complete tab with '.'
}

int   ft_get_min_square_side(t_tetri_list **list)
{
  int sqr_size;

  sqr_size = 0;
  if (!list)
    return (0);
  while (list)
  {
    list = list->next;
    sqr_size++:
  }
  return(sqr_size);
}

int   ft_complete_tetris(t_tetri_list **list, int sqr_size)
{

}
