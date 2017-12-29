/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 06:26:11 by thou              #+#    #+#             */
/*   Updated: 2017/12/29 17:55:52 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <curses.h>
extern int	fd;

void	get_piece(t_env *e, char **str)
{
	int		y;

	free(*str);
	y = -1;
	while (++y < e->yp)
	{
		get_next_line(0, str);
		e->piece[y] = ft_strdup(*str);
		free(*str);
	}
	e->flag = 3;
}

void	get_tab(t_env *e, char **str)
{
	int		y;
	int		x;

	free(*str);
	y = -1;
	while (++y < e->y)
	{
		get_next_line(0, str);
		e->tab[y] = (char*)malloc(sizeof(char) * (e->x + 1));
		x = -1;
		while (++x < e->x)
			e->tab[y][x] = str[0][x + 4];
		e->tab[y][x] = 0;
		free(*str);
	}
	get_next_line(0, str);
}

void	get_piecesize(t_env *e, char **str)
{
	int		i;

	i = 5;
	e->yp = ft_atoi(str[0] + i);
	while (str[0][++i] != ' ')
		;
	e->xp = ft_atoi(str[0] + i);
	e->piece = (char**)malloc(sizeof(char*) * (e->yp + 1));
	e->flag = 2;
}

void	get_player(t_env *e, char **str)
{
	if (str[0][10] == '1')
	{
		e->p1 = 'O';
		e->p2 = 'X';
	}
	else
	{
		e->p1 = 'X';
		e->p2 = 'O';
	}
	free(*str);
}

void	get_plateau(t_env *e, char **str)
{
	int		i;

	i = 8;
	e->y = ft_atoi(str[0] + i);
	while (str[0][++i] != ' ')
		;
	e->x = ft_atoi(str[0] + i);
	free(*str);
	e->tab = (char**)malloc(sizeof(char*) * (e->y + 1));
	i = -1;
	e->flag = 1;
	get_next_line(0, str);
}
