#include "fillit.h"

char **ft_rebuild_tetri(char **tetri)
{
  int i;
  int j;
  int width;
  int height;
  float start; // [x],[y]
  int max;
  char **tab;

  start = 0;

  // Determine height and start(Y) of shape and malloc first index of tab
  i = -1;
  height = 0;
  while (++i < 4)
    height += (ft_strchr(tetri[i], '#')) ? 1 : 0;

  i = 0;
  while (!(ft_strchr(tetri[i], '#')))
    i++;
  start = SET_Y(i);

  if (!(tab = (char**)malloc(sizeof(char*) * (height + 1))))
    return (NULL);
  tab[height] = NULL;

  // Print results
  ft_putendl("");
  ft_putstr("Start rebuild");
  ft_putendl("");
  ft_putstr("|- Height : ");
  ft_putnbr(height);
  ft_putendl("");
  ft_putstr("|- First # on y = ");
  ft_putnbr(GET_Y(start));

  // Determinate width and start(X) of shape
  i = -1;
  width = 0;
  while (++i < 4)
  {
    j = -1;
    max = 0;
    while (j < 4)
    {
      max += (tetri[i][++j] == '#') ? 1 : 0;
    }
    if (width < max)
      width = max;
  }

  i = 0;
  while (!(ft_strchr(tetri[i], '#')))
    i++;
  j = 0;
  while (tetri[i][j] != '#')
    j++;
  start = SET_X(j);

  // Print results
  ft_putendl("");
  ft_putstr("|- Width : ");
  ft_putnbr(width);
  ft_putendl("");
  ft_putstr("|- First # on x = ");
  ft_putnbr(GET_X(start));
  ft_putendl("");
  ft_putstr("|- i = ");
  ft_putnbr(i);
  ft_putendl("");

  // If a line contain a # copy it of width char
  j = 0;
  while (ft_strchr(tetri[i], '#'))
  {
    tab[j] = ft_strsub(tetri[i], GET_X(start), width);
    i++;
    j++;
  }
  // Print results
  i = 0;
  while (tab[i])
  {
    ft_putendl(tab[i]);
    i++;
  }
  ft_putendl("");
  return (tab);
}

int ft_create_list_element(char **tetri, t_tetri_list **list, char id)
{
  t_tetri_list *element;
  t_tetri_list *tmp_list;

  if (tetri)
  {
    // Search a position for the future element
    tmp_list = (*list);
    while (tmp_list && tmp_list->next)
      tmp_list = tmp_list->next;

    // Build of the element
    if ((element = (t_tetri_list*)malloc(sizeof(t_tetri_list))))
    {
  		//if (!(element->tetriminos = ft_rebuild_tetri(tetri)))
      //  return (0);
      ft_rebuild_tetri(tetri);
      element->id = id;
      element->placed = 0;
      element->next = NULL;
    }
    else
      return (0);

    // Add of the element.
    if (tmp_list)
      tmp_list->next = element;
    else
      (*list) = element;
  }
  return (1);
}


int   ft_create_list(char **tab, t_tetri_list **list)
{
  int i;
  char id;

  if (tab)
  {
    i = 0;
    id = 'A';
    while (tab[i - 1])
    {
      ft_create_list_element(&tab[i], list, id);
      i += (tab[i + 5]) ? 5 : 4;
      id++;
    }
  }
  return (0);
}
