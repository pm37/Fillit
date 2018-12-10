#include "fillit.h"

char **ft_rebuild_tetri(char **tetri)
{
  int i;
  int j;
  int width;
  int height;
  float start; // [x],[y]
  char **tab;

  start = 0;
  // Determine height and start(Y) of shape and malloc first index of tab
  i = -1;
  height = 0;
  while (++i < 4)
  {
    height += (ft_strchr(tetri[i], '#')) ? 1 : 0;
    if (height == 1 && start == 0)
      start = SET_Y(i);
  }
  if (!(tab = (char**)malloc(sizeof(char*) * (height + 1))))
    return (NULL);
  tab[height] = NULL;

  // Determinate width and start(X) of shape
  j = -1;
  width = 0;
  while (++j < 4)
  {
    i = -1;
    while (++i< 4)
    {
      if (tetri[i][j] == '#')
      {
        width++;
        break;
      }
    }
  }
  i = 0;
  while (!(ft_strchr(tetri[i], '#')))
    i++;
  j = 0;
  while ((tetri[i][j] == '.' && tetri[i + 1][j] == '.' && tetri[i + 2][j] == '.') || (tetri[i][j] == '.' && tetri[i + 1][j] == '.' && !tetri[i + 2][j]))
    j++;
  start = SET_X(j);

  // If a line contain a # copy it of width chars
  j = 0;
  while (tetri[i] && ft_strchr(tetri[i], '#'))
  {
    tab[j] = ft_strsub(tetri[i], GET_X(start), width);
    i++;
    j++;
  }
  return (tab);
}

int ft_create_list_element(char **tetri, t_tetri_list **list, char id)
{
  t_tetri_list *element;
  t_tetri_list *tmp_list;

  if (tetri)
  {
    tmp_list = (*list);
    while (tmp_list && tmp_list->next)
      tmp_list = tmp_list->next;
    if ((element = (t_tetri_list*)malloc(sizeof(t_tetri_list))))
    {
  		if (!(element->tetriminos = ft_rebuild_tetri(tetri)))
        return (0);
      element->id = id;
      element->placed = 0;
      element->next = NULL;
    }
    else
      return (0);
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
    while (tab[i])
    {
      ft_create_list_element(&tab[i], list, id++);
      i += (tab[i + 4]) ? 5 : 4;
    }
  }
  return (0);
}
