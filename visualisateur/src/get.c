/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 03:29:05 by thou              #+#    #+#             */
/*   Updated: 2018/03/27 18:22:55 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	get_plateau(t_env *e, char *str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[++i] == 0));
	e->x = ft_atoi(str + i);
	while (ft_isdigit(str[++i]) == 1);
	e->y = ft_atoi(str + i);
	free(str);
	get_next_line(0, &str);
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
	str[0][10] == '1' ? (p1 = tmp) : (p2 = tmp);
}

void	get_put(t_env e, char **str)
{
	char	c;
	int		i;
	int		j;

	i = 11;
	c = str[0][6];
	e->aws[0] = ft_atoi(str[0] + 11);
	while (ft_isnb(str[0][i]))
		i++;
	while (!ft_isnb(str[0][i]))
		i++;
	e->aws[1] = ft_atoi(str[0] + i);
	j = 0;
	while (++j < e->yp)
	{
		i = 0;
		while (++i < e->xp)
			if (e->piece[j][i] = '*')
				e->tab[e->aws[0] + j][e->aws[1] + i] = c;
	}
	e->flag = 3;
}

void	get_tab(t_env *e, char **str)
{
	int		i;
	int		j;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * (e->y + 1))
	while (++i < e->y)
	{
		free(*str);
		get_next_line(0, str);
		e->tab[i] = (char*)malloc(sizeof(char) * (e->x + 1));
		j = -1;
		while (++j < e->x)
			e->tab[i][j] = str[j + 5];
	}
	ft_graphic(e);
}
