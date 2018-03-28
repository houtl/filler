/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 03:29:05 by thou              #+#    #+#             */
/*   Updated: 2018/03/28 03:02:30 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	get_plateau(t_env *e, char **str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[0][++i]) == 0);
	e->y = ft_atoi(str[0] + i);
	while (ft_isdigit(str[0][++i]) == 1);
	e->x = ft_atoi(str[0] + i);
	free(*str);
	get_next_line(0, str);
	e->flag = 1;
}

void	get_player_name(t_env *e, char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(str[0]);
	while (str[0][i] != '/' && str[0][i] != '[')
		i--;
	i++;
	j = ft_strlen(str[0]) - i;
	tmp = (char*)malloc(sizeof(char) * j);
	tmp[--j] = 0;
	while (--j >= 0)
		tmp[j] = str[0][i + j];
	str[0][10] == '1' ? (e->p1 = tmp) : (e->p2 = tmp);
}

void	get_put(t_env *e, char **str)
{
	char	c;
	int		i;
	int		j;

	i = 11;
	c = str[0][6];
	e->aws[0] = ft_atoi(str[0] + 11);
	while (ft_isdigit(str[0][i]))
		i++;
	while (!ft_isdigit(str[0][i]))
		i++;
	e->aws[1] = ft_atoi(str[0] + i);
	j = 0;
	while (++j < e->yp)
	{
		i = 0;
		while (++i < e->xp)
			if (e->piece[j][i] == '*')
				e->tab[e->aws[0] + j][e->aws[1] + i] = c;
	}
	free(*str);
	get_next_line(0, str);
	e->flag = 3;
}

void	get_tab(t_env *e, char **str)
{
	int		i;
	int		j;

	i = -1;
	if (e->tab != NULL)
		free_tab(e);
	e->tab = (char**)malloc(sizeof(char*) * (e->y + 1));
	while (++i < e->y)
	{
		free(*str);
		get_next_line(0, str);
		e->tab[i] = (char*)malloc(sizeof(char) * (e->x + 1));
		j = -1;
		while (++j < e->x)
			e->tab[i][j] = str[0][j + 5];
		e->tab[i][j] = 0;
	}
	e->tab[i] = NULL;
	free(*str);
	get_next_line(0, str);
}
