#include "fillit.h"

t_tetri_list   *ft_check_place(t_tetri_list **list, char **tab, float c)
{
  int           is_ok;
  int           i;
  int           j;

  if (tab && list)
  {
    while (*list)
    {
      //ft_putstr("Check this shape :"); // Terminal log.
      is_ok = 1;
      if ((*list)->placed == 0)
      {
        i = 0;
        while ((*list)->tetriminos[i])
        {
          //ft_putendl((*list)->tetriminos[i]); // Terminal log.
          j = 0;
          while (tab[GET_Y(c) + i] && j < ft_strlen((*list)->tetriminos[i]))
          {
            if (!(tab[GET_Y(c) + i][GET_X(c) + j]) || (tab[GET_Y(c) + i][GET_X(c) + j] != '.' && (*list)->tetriminos[i][j] != '.'))
            {
              is_ok = 0;
              break ;
            }
            j++;
          }
          if (is_ok == 0 || !tab[GET_Y(c) + i])
          {
            is_ok = 0;
            break;
          }
          //ft_putstr("Check this shape :"); // Terminal log.
          i++;
        }
        /*ft_putendl("");
        ft_putchar((*list)->id);
        ft_putstr(" | y = ");
        ft_putnbr(GET_Y(c));
        ft_putstr(" & i = ");
        ft_putnbr(i);
        ft_putendl("");
        ft_putstr("is_ok ?");
        is_ok == 1 ? ft_putendl("yes") : ft_putendl("no");
        ft_putendl("");*/
        if (is_ok == 1 && tab[GET_Y(c) + i - 1])
        {
          // ft_putendl("IT'S OK");
          return (*list);
        }
      }
      list = &(*list)->next;
    }
  }
  return (NULL);
}
