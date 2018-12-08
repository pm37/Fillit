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

#include "fillit.h"

void  ft_init_sol_tab(char ***tab, int sqr_size)
{
  int i;
  int j;
  //free memory
  ft_free_tab(tab);
  //allocate memory
  *tab = (char **)malloc(sizeof(**tab) * (sqr_size + 1));
  //complete tab with '.'
  i = 0;
  while (i < sqr_size)
  {
    tab[0][i] = (char *)malloc(sizeof(char) * (sqr_size + 1));
    j = 0;
    while (j < sqr_size)
    {
      tab[0][i][j] = '.';
      j++;
    }
    tab[0][i][j] = '\0';
    i++;
  }
tab[0][i] = NULL;
}

int   ft_get_min_sqr_size(t_tetri_list *list)
{
  int area;
  int sqr_size;

  area = 0;
  sqr_size = 0;
  if (!list)
    return (0);
  while (list)
  {
    list = list->next;
    area += 4;
  }
  while (area)
  {
      if ((sqr_size = ft_sqrt(area)))
        return (sqr_size);
    area++;
  }
  return(0);
}

void  ft_put_tetriminos(t_tetri_list *element, char **tab, float c)
{
  int i;
  int j;

  i = -1;
//  ft_putendl("PUT TETRI");
  while (element->tetriminos[++i])
  {
    //ft_putchar(element->id);
  //  printf("%p\n", element->tetriminos[i]);
    j = -1;
    while (element->tetriminos[i][++j])
    {
      if (element->tetriminos[i][j] == '#')
        tab[GET_Y(c) + i][GET_X(c) + j] = element->id;
    }
    //ft_putendl("iterate put_tetri");
  }
//  printf("%p\n", element->tetriminos[i]);
//  ft_putendl("END PUT TETRI");
  element->placed = 1;
}

void  ft_unput_tetriminos(t_tetri_list *element, char **tab, float c)
{
  int i;
  int j;

  i = 0;
  while (element->tetriminos[i])
  {
    j = 0;
    while (element->tetriminos[i][j])
    {
      if (element->tetriminos[i][j] == '#')
        tab[GET_Y(c) + i][GET_X(c) + j] = '.';
      j++;
    }
    i++;
  }
  element->placed = 0;
}

float ft_get_next_free_coor(char **tab, int x, int y)
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
      {
        /*ft_putstr("Y = ");
        ft_putnbr(j);
        ft_putstr(" - ");
        ft_putstr("X = ");
        ft_putnbr(i);
        ft_putendl("");*/
        return (SET_X(i) + SET_Y(j));
      }
      i++;
    }
    j++;
  }
  return (-1);
}


int   ft_is_complete(t_tetri_list *list)
{
  while(list && (list->placed))
    list = list->next;
  if (!list)
    return (1);
  return (0);
}

int   ft_complete_tetris(t_tetri_list **list, char **tab, float c, int sqr_size)
{
  t_tetri_list  *element;

  if (ft_is_complete(*list))
    return (1);
  if (!(element = ft_check_place(list, tab, c)) && c != -1)
    return (ft_complete_tetris(list, tab, ft_get_next_free_coor(tab, GET_X(c), GET_Y(c)), sqr_size));
  while (element)
  {
    ft_put_tetriminos(element, tab, c);
    ft_display_tab(tab);
    ft_putendl("");
    if (ft_complete_tetris(list, tab, ft_get_next_free_coor(tab, GET_X(c), GET_Y(c)), sqr_size))
    {
      ft_putendl("IT SEEMS IT WORKS");
      return (1);
    }

    ft_unput_tetriminos(element, tab, c);
    element = ft_check_place(&(element)->next, tab, c);
  }
  ft_putendl("DOES NOT WORK");
  return (0);
}
