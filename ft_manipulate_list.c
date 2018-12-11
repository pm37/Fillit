#include "fillit.h"

static int ft_get_tetri_height(char **tetri, float *start)
{
  int i;
  int first;
  int height;

  if (tetri)
  {
    i = -1;
    height = 0;
    first = 0;
    while (++i < 4)
    {
      height += (ft_strchr(tetri[i], '#')) ? 1 : 0;
      if (height == 1 && first == 0)
      {
        *start += SET_Y(i);
        first = 1;
      }
    }
    return (height);
  }
  return (0);
}

static int ft_get_tetri_width(char **tetri, float *start)
{
  int i;
  int j;
  int min_j;
  int width;

  if (!tetri)
    return (0);
  width = 0;
  j = -1;
  min_j = 3;
  while (++j < 4)
  {
    i = -1;
    while (tetri[++i] && i < 4)
    {
      if (tetri[i][j] == '#')
      {
        min_j = (min_j > j) ? j : min_j;
        width++;
        break;
      }
    }
  }
  *start += SET_X(min_j);
  return (width);
}

static char **ft_rebuild_tetri(char **tetri)
{
  int i;
  int size;
  float start; // [x],[y]
  char **tab;

  start = 0;
  size = ft_get_tetri_height(tetri, &start); // height, [y]
  if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
    return (NULL);
  tab[size] = NULL;
  size = ft_get_tetri_width(tetri, &start); // width, [x]
  i = -1;
  while (tetri[(GET_Y(start) + (++i))] && ft_strchr(tetri[(GET_Y(start) + i)], '#'))
    tab[i] = ft_strsub(tetri[(GET_Y(start) + i)], GET_X(start), size);
  return (tab);
}

static int ft_create_list_element(char **tetri, t_tetri_list **list, char id)
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
      i += (tab[i + 4] == 0) ? 4 : 5;
    }
  }
  return (1);
}
